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

using namespace std;


Drone* dronePtr;

mutex frameMutex;
cv::Mat currentFrame;
bool hasFrame;

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


    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // draw background image
    glDisable( GL_DEPTH_TEST );

    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D( 0.0, frame.cols, 0.0, frame.rows);

    glRasterPos2i( 0, frame.rows-1 );

    glDrawPixels( frame.cols, frame.rows, GL_BGR_EXT, GL_UNSIGNED_BYTE, frame.data );

    glPopMatrix();

    glEnable(GL_DEPTH_TEST);


    glutSwapBuffers();
    glutPostRedisplay();
}


void initGlut(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500,500);
    glutCreateWindow("DroneShooter");
    glutDisplayFunc(draw);

    glClearColor( 1.0, 0.0, 0.0, 1.0 );
    glPixelStorei( GL_PACK_ALIGNMENT,   1 ); // for glReadPixels​
    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 ); // for glTexImage2D​
    glPixelZoom( 1.0, -1.0 );

    glutMainLoop();
}

int main(int argc, char **argv)
{
    frameMutex.lock();
    hasFrame = true;
    currentFrame = cv::Mat(500,500,CV_8UC3, cv::Scalar(0,255,0));
    frameMutex.unlock();

    ARDrone2* drone = new ARDrone2("./");

    DroneController controller(drone);

    if(!controller.setup())
        return 1;

#ifndef DEMO
    drone->addVideoListener(new ARListener());
#endif


    initGlut(argc, argv);
    return 0;



    while(true) {
        controller.loop();
    }

	return 0;
}
