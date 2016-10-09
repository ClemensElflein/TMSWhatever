//
// Created by clemens on 09.10.16.
//

#include "DroneController.h"

using namespace std;

DroneController::DroneController(Drone* d) {
    this->dronePtr = d;

    armed = fly = false;
    vspeed = nick = roll = yaw = 0;
    lastCalled = 0;
    updatedValues = false;
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
    /*{
        drone::config current = dronePtr->getConfig();
        current.outdoor = IS_OUTDOOR;
        dronePtr->setConfig(current);
    }*/

    //dronePtr->addCommand(ardrone2::commands::configuration(ardrone2::config::VIDEO_CODEC, to_string(ardrone2::config::codec::H264_AUTO_RESIZE)));
    //dronePtr->addCommand(ardrone2::commands::configuration(ardrone2::config::ALTITUDE_MAX, "20"));
    //dronePtr->addCommand(ardrone2::commands::configuration(ardrone2::config::VERTICAL_SPEED_MAX, to_string(2)));
    //dronePtr->addCommand(ardrone2::commands::configuration(ardrone2::config::TILT_MAX, to_string(1)));
    //dronePtr->addCommand(ardrone2::commands::configuration(ardrone2::config::YAW_SPEED_MAX, to_string(1)));
    {
        drone::limits limits;
        limits.altitude = 4000;
        limits.vspeed = (int)(VSPEED_FACTOR*1000);
        limits.angle = NICK_FACTOR;
        limits.yawspeed = YAW_FACTOR;
        dronePtr->setLimits(limits);
    }
    drone::limits limits = dronePtr->getLimits();
    cout << "Limit Alt: " << limits.altitude << endl;
    cout << "Limit Vspeed: " << limits.vspeed << endl;
    cout << "Limit Angle: " << limits.angle << endl;
    cout << "Limit Yawspeed: " << limits.yawspeed << endl;



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
#ifdef VERBOSE
                    cout << "Armed = " << armed << endl;
#endif
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
#ifdef VERBOSE
                        cout << "[INFO] ARM the drone first!" << endl;
#endif
                        break;
                    }
#ifdef VERBOSE
                    else {
                        cout << "Fly = " << fly << endl;
                    }
#endif

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
#ifdef VERBOSE
                    cout << "Button: " << (int)event.number << " not assigned" << endl;
#endif
                    break;
            }
        }
    }
    else if (event.isAxis())
    {
        double value = (double)event.value / INT16_MAX;
        switch(event.number) {
            case AXIS_NICK:
                nick = value * NICK_FACTOR;
                break;
            case AXIS_VSPEED:
                vspeed = value;
                break;
            case AXIS_ROLL:
                roll = value * ROLL_FACTOR;
                break;
            case AXIS_YAW:
                yaw = value * YAW_FACTOR;
                break;
            default:
                return false;
        }
        return true;
    }
}

void DroneController::loop() {
    JoystickEvent event;
    if(stick.sample(&event))
        updatedValues |= handleEvent(event);
    //if(updatedValues)
    //    cout << "[vspeed:" << (vspeed) << ", n:" << nick << ", r:" << roll << ", y:" << yaw << "]" << endl;
    usleep(1000);

    long now = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count();

    if(now - lastCalled > 30) {
        lastCalled = now;
#ifdef VERBOSE
        if(updatedValues)
            cout << "[vspeed:" << (vspeed) << ", n:" << nick << ", r:" << roll << ", y:" << yaw << "]" << endl;
#endif
#ifndef DEMO
        if(updatedValues) {
            dronePtr->addCommand(drone::commands::attitude(Eigen::Vector3f(nick, roll, yaw), (float)-vspeed));
        }
#endif
        updatedValues = false;
     //   cout << "tick" << endl;
    }

}
