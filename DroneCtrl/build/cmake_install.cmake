# Install script for directory: /home/clemens/TMSWhatever/DroneCtrl

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdrone.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdrone.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdrone.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/clemens/TMSWhatever/DroneCtrl/build/libdrone.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdrone.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdrone.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdrone.so"
         OLD_RPATH "/usr/local/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdrone.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libdrone" TYPE FILE FILES
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/constants.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/bebop.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/fpvdrone.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/fpvtypes.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/ardrone2.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/constants.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/configuration.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/istatuslistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/inavdatalistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/ivideolistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/iconnectionstatuslistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drone.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/dronehelper.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/dronevisitor.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libdrone/drones" TYPE FILE FILES
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/constants.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/bebop.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/fpvdrone.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/fpvtypes.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/ardrone2.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/constants.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/configuration.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/istatuslistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/inavdatalistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/ivideolistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/iconnectionstatuslistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drone.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/dronehelper.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/dronevisitor.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libdrone/drones/ardrone2" TYPE FILE FILES
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/constants.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/bebop.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/fpvdrone.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/fpvtypes.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/ardrone2.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/constants.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/configuration.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/istatuslistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/inavdatalistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/ivideolistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/iconnectionstatuslistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drone.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/dronehelper.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/dronevisitor.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libdrone/drones/bebop" TYPE FILE FILES
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/constants.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/bebop.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/fpvdrone.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/fpvtypes.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/ardrone2.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/constants.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/configuration.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/istatuslistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/inavdatalistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/ivideolistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/iconnectionstatuslistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drone.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/dronehelper.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/dronevisitor.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libdrone/drones" TYPE FILE FILES
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/constants.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/bebop.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/fpvdrone.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/fpvtypes.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/ardrone2.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/constants.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/configuration.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/istatuslistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/inavdatalistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/ivideolistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/iconnectionstatuslistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drone.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/dronehelper.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/dronevisitor.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libdrone/interface" TYPE FILE FILES
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/constants.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/bebop/bebop.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/fpvdrone.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/fpvtypes.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/ardrone2.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/constants.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/configuration.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drones/ardrone2/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/istatuslistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/inavdatalistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/ivideolistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/interface/iconnectionstatuslistener.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/drone.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/dronehelper.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/types.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/commands.h"
    "/home/clemens/TMSWhatever/DroneCtrl/include/dronevisitor.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/clemens/TMSWhatever/DroneCtrl/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
