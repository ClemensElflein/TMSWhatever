//#define DEMO
#include <drones/ardrone2/ardrone2.h>
#include <drones/bebop/bebop.h>
#include <commands.h>

#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include "joystick.hh"
#include "DroneController.h"

#define GLFW_INCLUDE_GLU
//#include <glfw/glfw3.h>
//#include <GL/glew.h>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <pthread.h>

using namespace std;


Drone* dronePtr;
DroneController* controller;

mutex frameMutex;
cv::Mat currentFrame;
bool hasFrame;
int wWidth = 500, wHeight = 500;

class StatusListener:public IStatusListener {
public:
    virtual void statusUpdateAvailable(int status) override {

    }
};
class NavdataListener:public INavdataListener {
public:
    virtual void navdataAvailable(std::shared_ptr<const drone::navdata> navdata) override {
        //cout << "f:" << navdata->flying << ", alt:" << navdata->altitude << ", link:" << navdata->linkquality << '\r';
        //cout << "f:" << navdata->flying << ", lvel:[" << navdata->linearvelocity(0) << ", " << navdata->linearvelocity(1) << ", " << navdata->linearvelocity(2) << "], att:["
        //     << navdata->attitude(0) << ", " << navdata->attitude(1) << ", " << navdata->attitude(2) << "]                    \r";

    }
};


class ARListener : public IVideoListener
{
public:
    virtual void videoFrameAvailable(cv::Mat frame) override {
        frameMutex.lock();
        hasFrame = true;
   //     frame.copyTo(currentFrame);
        currentFrame = frame;
        frameMutex.unlock();
    }
};

void draw() {
    // Get the frame
    cv::Mat frame;

    frameMutex.lock();
    if(!hasFrame) {
        frameMutex.unlock();
        return;
    }
    frame = currentFrame;
    //currentFrame.copyTo(frame);
    frameMutex.unlock();

    // Get window width/height
    // Video aspect ratio
    // Get the pixel zoom
    float aspectRatio = (float)frame.cols/(float)frame.rows;
    float pixelZoom = min((float)wWidth/frame.cols, (float)wHeight/frame.rows );

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // draw background image
    glDisable( GL_DEPTH_TEST );

    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D( 0.0, frame.cols, 0.0, frame.rows);

    glRasterPos2i( 0, frame.rows );

    glPixelZoom( pixelZoom, -pixelZoom );
    glDrawPixels( frame.cols, frame.rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, frame.data );

    glPopMatrix();



    // BEGIN HUD
    float centerLine[] = {
            -.5f,.5f,
            .5f,.5f
    };
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D( 0.0, 1, 0.0, 1);
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    glOrtho( 0, w, h, 0, -1, 1);

    glPushMatrix();

//    glRasterPos2i(100,100);
//    glutBitmap(3,3,1);

    glLineWidth(2);
    glScaled(.2,-.2,.2);
    glTranslated(10,-120,0);
    glutStrokeString(GLUT_STROKE_ROMAN, (const unsigned char*)"Test");
//    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, (const unsigned char*)"Test");
    glPopMatrix();

    glEnable(GL_DEPTH_TEST);

    /*

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glColor3f(1,1,0);
    glLineWidth(10);
    glBegin(GL_QUADS);
//    glVertex2f(0,0);
//    glVertex2f(1,1);
    glVertex2i( 0, 0 );
    glVertex2i(  10, 0 );
    glVertex2i(  10,  10 );
    glVertex2i(0,  10 );
    glEnd();

     */

    glFlush();

    // END HUD


    glutSwapBuffers();
    glutPostRedisplay();
}

void reshape(int width, int height) {
    wWidth = width;
    wHeight = height;

    glViewport(0,0,width, height);
}

void initGlut(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(wWidth, wHeight);
    glutCreateWindow("DroneShooter");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);

    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glShadeModel(GL_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);

    glPixelStorei( GL_PACK_ALIGNMENT,   1 ); // for glReadPixels​
    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 ); // for glTexImage2D​
    glPixelZoom( 1.0, -1.0 );

    glutMainLoop();
}

void* controlThreadFunc(void* arg) {
    while(1) {
        controller->loop();
    }
}

int main(int argc, char **argv)
{
    frameMutex.lock();
    hasFrame = false;
    frameMutex.unlock();

    ARDrone2* drone = new ARDrone2("./");

    controller = new DroneController(drone);

    if(!controller->setup()) {
        delete controller;
        delete drone;
        return 1;
    }
    drone->addNavdataListener(new NavdataListener());
    drone->addStatusListener(new StatusListener());

#ifndef DEMO
    drone->addVideoListener(new ARListener());
#else
    // Get one image from the webcam
    cv::VideoCapture cap(0);
    frameMutex.lock();
    cap >> currentFrame;
    hasFrame = true;
    frameMutex.unlock();
#endif
    pthread_t controllerThread;
    pthread_create(&controllerThread, NULL, controlThreadFunc, NULL);

    initGlut(argc, argv);
    while(1);

    pthread_cancel(controllerThread);
    return 0;
}
