//
// Created by clemens on 09.10.16.
//

#ifndef LIBDRONE_DRONECONTROLLER_H
#define LIBDRONE_DRONECONTROLLER_H

#include <drones/ardrone2/ardrone2.h>
#include <drones/bebop/bebop.h>
#include <commands.h>

#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include "joystick.hh"

#define IS_OUTDOOR true

#define BTN_ARM 4
#define BTN_FLY 5
#define BTN_EMERGENCY 6
#define BTN_TRIM 7
#define AXIS_ROLL 2
#define AXIS_NICK 3
#define AXIS_YAW 0
#define AXIS_VSPEED 1

#define NICK_FACTOR .4
#define ROLL_FACTOR .4
#define VSPEED_FACTOR 2
#define YAW_FACTOR 4.0

//#define VERBOSE

#define DEBUG
//#define DEMO


class DroneController {
private:
    Joystick stick;
    Drone* dronePtr;

    bool armed;
    bool fly;
    double vspeed, nick, roll, yaw;
    long lastCalled = 0;
    bool updatedValues;

    bool handleEvent(JoystickEvent &event);
public:
    DroneController(Drone* d);

    // Connect to joystick and drone, returns true if everythings alrihgt. Prints errors if it failed
    bool setup();
    void loop();
};

#endif //LIBDRONE_DRONECONTROLLER_H
