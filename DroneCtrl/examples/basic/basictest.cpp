#include <drones/ardrone2/ardrone2.h>
#include <drones/bebop/bebop.h>
#include <commands.h>

#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include "joystick.hh"

using namespace std;


Drone* dronePtr;

#define IS_OUTDOOR false

#define BTN_ARM 4
#define BTN_FLY 5
#define BTN_EMERGENCY 6
#define BTN_TRIM 7
#define AXIS_ROLL 2
#define AXIS_NICK 3
#define AXIS_YAW 0
#define AXIS_VSPEED 1

#define DEBUG
//#define DEMO

class ARListener : public IVideoListener
{
public:
    virtual void videoFrameAvailable(cv::Mat frame) override {
        imshow("theFrame", frame);
        cv::waitKey(1);
    }
};

class NavdataListener : public INavdataListener
{
	public:
	void navdataAvailable(std::shared_ptr<const drone::navdata> navdata)
	{
		// Generic navdata
		cout << "Altitude: " << navdata->altitude << "m" << endl;

		// Drone specific navdata
		cout << "Acceleration (z Axis): " << static_pointer_cast<const ardrone2::navdata>(navdata)->acceleration << "" << endl;
	}
};

class DroneController {
private:
    Joystick stick;
    Drone* dronePtr;

    bool armed;
    bool fly;
    double vspeed, nick, roll, yaw;

public:
    DroneController(Drone* d) {
        this->dronePtr = d;

        armed = fly = false;
        vspeed = nick = roll = yaw = 0;
    }

    // Connect to joystick and drone, returns true if everythings alrihgt. Prints errors if it failed
    bool setup() {
        if(!stick.isFound()) {
            cerr << "No Gamepad Found. Plug in Gamepad!" << endl;
            return false;
        }
#ifndef DEMO
        drone::connectionstatus status = dronePtr->connect();
        if(status != drone::connectionstatus::CONNECTION_ESTABLISHED)
        {
            cerr << "[ERROR] Could not connect to drone!" << endl;
            return false;
        }
        else
        {
            cout << "[INFO]  Connection established!" << endl;
        }

        // Configure for in/outdoor
        {
            drone::config current = dronePtr->getConfig();
            current.outdoor = IS_OUTDOOR;
            dronePtr->setConfig(current);
        }

        dronePtr->addCommand(ardrone2::commands::configuration(ardrone2::config::VIDEO_CODEC, to_string(ardrone2::config::codec::H264_AUTO_RESIZE)));

        dronePtr->startUpdateLoop();
#else
        cout << "ATTENTION! DEMO MODE! NO FLYING!" << endl;
#endif
        return true;
    }


    bool handleEvent(JoystickEvent &event) {
        if (event.isButton())
        {
            if(event.value) {
                switch (event.number) {
                    case BTN_ARM:
                        armed = !armed;
                        fly = false;
                        cout << "Armed = " << armed << endl;
                        nick = roll = yaw = vspeed = 0;
#ifndef DEMO
                        if(armed) {
                            dronePtr->arm();
                        } else {
                            dronePtr->addCommand(drone::commands::land());
                            dronePtr->disarm();
                        }
#endif
                        break;
                    case BTN_FLY:
                        fly = !fly & armed;
                        if(!armed) {
                            cout << "[INFO] ARM the drone first!" << endl;
                            break;
                        } else {
                            cout << "Fly = " << fly << endl;
                        }
#ifndef DEMO
                        dronePtr->addCommand(fly ? (drone::command)drone::commands::takeoff() : (drone::command)drone::commands::land());
#endif
                        break;
                    case BTN_EMERGENCY:
                        cerr << "EMERGENCY!!!" << endl;
#ifndef DEMO
                        dronePtr->addCommand(drone::commands::emergency());
#endif
                        break;
                    case BTN_TRIM:
                        cout << "Trim" << endl;
#ifndef DEMO
                        dronePtr->addCommand(drone::commands::fttrim());
#endif
                        break;
                    default:
                        cout << "Button: " << (int)event.number << " not assigned" << endl;
                        break;
                }
            }
        }
        else if (event.isAxis())
        {
            double* toChange = NULL;
            switch(event.number) {
                case AXIS_NICK:
                    toChange = &nick;
                    break;
                case AXIS_VSPEED:
                    toChange = &vspeed;
                    break;
                case AXIS_ROLL:
                    toChange = &roll;
                    break;
                case AXIS_YAW:
                    toChange = &yaw;
                    break;
                default:
                    return false;
            }

            double value = (double)event.value / INT16_MAX;
            *toChange = value*.3;
            return true;
        }
    }

    void loop() {
        bool updatedValues = false;
        JoystickEvent event;
        if(stick.sample(&event))
            updatedValues = handleEvent(event);
#ifndef DEMO
        if(fly && updatedValues) {
            dronePtr->addCommand(drone::commands::attitude(Eigen::Vector3f(nick, roll, yaw), (float)-vspeed));
        }
#endif
        if(updatedValues)
            cout << "[vspeed:" << (vspeed) << ", n:" << nick << ", r:" << roll << ", y:" << yaw << "]" << endl;
        usleep(1000);
    }
};

int main(int argc, char **argv)
{
    ARDrone2* drone = new ARDrone2("./");

    DroneController controller(drone);

    if(!controller.setup())
        return 1;

#ifndef DEMO
    drone->addVideoListener(new ARListener());
    //drone->addCommand(ardrone2::commands::configuration("video:camif_fps", "2"));
    //drone->addCommand(ardrone2::commands::configuration("video:codec_fps", "2"));

#endif

    while(true) {
        controller.loop();
    }


	bool fly = false;

	dronePtr = new ARDrone2("./");

//	NavdataListener listener;
//	dronePtr->addNavdataListener(&listener);


	dronePtr->arm();

	cout << "[INFO]  Drone Armed!" << endl;
	cout << "----------------------------------" << endl;

	// Do stuff!
	dronePtr->startUpdateLoop();

	while(true) {

	}


//
//	/*if(!fly) // Not allowed to fly.
//	{
//		this_thread::sleep_for(chrono::milliseconds(20000));
//	}
//	else*/ // Flying is allowed. Take off, wait 6 seconds and land.
//	{
//
//		drone::command takeOff = drone::commands::takeoff();
//		drone::command land = drone::commands::land();
//
//		cout << "[INFO]  Taking off" << endl;
//		dronePtr->addCommand(takeOff);
//		this_thread::sleep_for(chrono::milliseconds(1000));
//		dronePtr->addCommand(land);
//		cout << "[INFO]  Landing" << endl;
//		this_thread::sleep_for(chrono::milliseconds(1000));
//
//	 }


	// Don't know which one is the right one, needs testing. Better twice..
	dronePtr->disarm();
	dronePtr->stopUpdateLoop();
	dronePtr->disarm();

	cout << "----------------------------------" << endl;
	cout << "[INFO]  Update loop stopped" << endl;

	return 0;
}
