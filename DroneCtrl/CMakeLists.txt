cmake_minimum_required(VERSION 2.8.9)
project(libdrone)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DBOOST_LOG_DYN_LINK")

# Library
find_package(Boost 1.53 COMPONENTS system filesystem log thread chrono date_time timer REQUIRED)
find_package(FFMPEG REQUIRED)
find_package(OpenCV 3.0 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(OpenGL)
find_package(GLEW)
find_package(GLUT)

include_directories(${EIGEN3_INCLUDE_DIR})

file(GLOB_RECURSE LIBDRONE_SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/*.h
    ${PROJECT_SOURCE_DIR}/src/*.hpp
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE LIBDRONE_INCLUDE_FILES
    ${PROJECT_SOURCE_DIR}/include/*.h
    ${PROJECT_SOURCE_DIR}/include/*.hpp
)

add_library(
    drone
    SHARED
    ${LIBDRONE_SRC_FILES}
    ${LIBDRONE_INCLUDE_FILES}
)

target_link_libraries(drone ${Boost_LIBRARIES})
target_link_libraries(drone ${FFMPEG_LIBRARIES})
target_link_libraries(drone ${OpenCV_LIBRARIES})

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

# Example binary
set(EXAMPLE_TEST_SOURCE_FILES ${PROJECT_SOURCE_DIR}/examples/basic/basictest.cpp ${PROJECT_SOURCE_DIR}/examples/basic/joystick.hh ${PROJECT_SOURCE_DIR}/examples/basic/joystick.cc examples/basic/DroneController.cpp examples/basic/DroneController.h)
add_executable(basictest ${EXAMPLE_TEST_SOURCE_FILES})
target_link_libraries(basictest ${Boost_LIBRARIES})
target_link_libraries(basictest ${FFMPEG_LIBRARIES})
target_link_libraries(basictest ${OpenCV_LIBRARIES})
target_link_libraries(basictest ${OPENGL_LIBRARIES}
        ${GLUT_LIBRARY} ${GLEW_LIBRARY})
target_link_libraries(basictest drone)

# Install Library
install(TARGETS drone LIBRARY DESTINATION lib)
install(FILES ${LIBDRONE_INCLUDE_FILES} DESTINATION include/libdrone/)
install(FILES ${LIBDRONE_INCLUDE_FILES} DESTINATION include/libdrone/drones)
install(FILES ${LIBDRONE_INCLUDE_FILES} DESTINATION include/libdrone/drones/ardrone2)
install(FILES ${LIBDRONE_INCLUDE_FILES} DESTINATION include/libdrone/drones/bebop)
install(FILES ${LIBDRONE_INCLUDE_FILES} DESTINATION include/libdrone/drones)
install(FILES ${LIBDRONE_INCLUDE_FILES} DESTINATION include/libdrone/interface)
