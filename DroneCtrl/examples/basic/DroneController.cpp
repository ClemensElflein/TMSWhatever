//
// Created by clemens on 09.10.16.
//

#include "DroneController.h"

using namespace std;

DroneController::DroneController(Drone* d) {
    this->dronePtr = d;

    armed = fly = false;
    vspeed = nick = roll = yaw = 0;
}

// Connect to joystick and drone, returns true if everythings alrihgt. Prints errors if it failed
bool DroneController::setup() {
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


bool DroneController::handleEvent(JoystickEvent &event) {
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

void DroneController::loop() {
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
