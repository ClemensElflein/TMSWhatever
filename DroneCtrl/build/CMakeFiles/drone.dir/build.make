# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/clemens/Downloads/libdrone-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/clemens/Downloads/libdrone-master/build

# Include any dependencies generated for this target.
include CMakeFiles/drone.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/drone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/drone.dir/flags.make

CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o: ../src/drones/bebop/bebop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drones/bebop/bebop.cpp

CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drones/bebop/bebop.cpp > CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.i

CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drones/bebop/bebop.cpp -o CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.s

CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o.requires

CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o.provides: CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o.provides

CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o.provides.build: CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o


CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o: ../src/drones/bebop/fullnavdata.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drones/bebop/fullnavdata.cpp

CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drones/bebop/fullnavdata.cpp > CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.i

CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drones/bebop/fullnavdata.cpp -o CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.s

CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o.requires

CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o.provides: CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o.provides

CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o.provides.build: CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o


CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o: ../src/drones/bebop/videodecoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drones/bebop/videodecoder.cpp

CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drones/bebop/videodecoder.cpp > CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.i

CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drones/bebop/videodecoder.cpp -o CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.s

CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o.requires

CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o.provides: CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o.provides

CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o.provides.build: CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o


CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o: ../src/drones/bebop/commandcomposer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drones/bebop/commandcomposer.cpp

CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drones/bebop/commandcomposer.cpp > CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.i

CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drones/bebop/commandcomposer.cpp -o CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.s

CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o.requires

CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o.provides: CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o.provides

CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o.provides.build: CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o


CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o: ../src/drones/bebop/controllink.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drones/bebop/controllink.cpp

CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drones/bebop/controllink.cpp > CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.i

CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drones/bebop/controllink.cpp -o CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.s

CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o.requires

CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o.provides: CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o.provides

CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o.provides.build: CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o


CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o: ../src/drones/fpvdrone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drones/fpvdrone.cpp

CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drones/fpvdrone.cpp > CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.i

CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drones/fpvdrone.cpp -o CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.s

CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o.requires

CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o.provides: CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o.provides

CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o.provides.build: CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o


CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o: ../src/drones/ardrone2/video/videomanager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/video/videomanager.cpp

CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/video/videomanager.cpp > CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.i

CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/video/videomanager.cpp -o CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.s

CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o.requires

CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o.provides: CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o.provides

CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o.provides.build: CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o


CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o: ../src/drones/ardrone2/video/framereconstructor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/video/framereconstructor.cpp

CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/video/framereconstructor.cpp > CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.i

CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/video/framereconstructor.cpp -o CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.s

CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o.requires

CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o.provides: CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o.provides

CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o.provides.build: CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o


CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o: ../src/drones/ardrone2/ardrone2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/ardrone2.cpp

CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/ardrone2.cpp > CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.i

CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/ardrone2.cpp -o CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.s

CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o.requires

CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o.provides: CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o.provides

CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o.provides.build: CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o


CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o: ../src/drones/ardrone2/atcommands/atcommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/atcommands/atcommand.cpp

CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/atcommands/atcommand.cpp > CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.i

CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/atcommands/atcommand.cpp -o CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.s

CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o.requires

CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o.provides: CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o.provides

CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o.provides.build: CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o


CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o: ../src/drones/ardrone2/navdata/navdatamanager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/navdata/navdatamanager.cpp

CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/navdata/navdatamanager.cpp > CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.i

CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/navdata/navdatamanager.cpp -o CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.s

CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o.requires

CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o.provides: CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o.provides

CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o.provides.build: CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o


CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o: ../src/drones/ardrone2/controllink.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/controllink.cpp

CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/controllink.cpp > CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.i

CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drones/ardrone2/controllink.cpp -o CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.s

CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o.requires

CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o.provides: CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o.provides

CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o.provides.build: CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o


CMakeFiles/drone.dir/src/drone.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/drone.cpp.o: ../src/drone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/drone.dir/src/drone.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/drone.cpp.o -c /home/clemens/Downloads/libdrone-master/src/drone.cpp

CMakeFiles/drone.dir/src/drone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/drone.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/drone.cpp > CMakeFiles/drone.dir/src/drone.cpp.i

CMakeFiles/drone.dir/src/drone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/drone.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/drone.cpp -o CMakeFiles/drone.dir/src/drone.cpp.s

CMakeFiles/drone.dir/src/drone.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/drone.cpp.o.requires

CMakeFiles/drone.dir/src/drone.cpp.o.provides: CMakeFiles/drone.dir/src/drone.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/drone.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/drone.cpp.o.provides

CMakeFiles/drone.dir/src/drone.cpp.o.provides.build: CMakeFiles/drone.dir/src/drone.cpp.o


CMakeFiles/drone.dir/src/dronehelper.cpp.o: CMakeFiles/drone.dir/flags.make
CMakeFiles/drone.dir/src/dronehelper.cpp.o: ../src/dronehelper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/drone.dir/src/dronehelper.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drone.dir/src/dronehelper.cpp.o -c /home/clemens/Downloads/libdrone-master/src/dronehelper.cpp

CMakeFiles/drone.dir/src/dronehelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drone.dir/src/dronehelper.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemens/Downloads/libdrone-master/src/dronehelper.cpp > CMakeFiles/drone.dir/src/dronehelper.cpp.i

CMakeFiles/drone.dir/src/dronehelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drone.dir/src/dronehelper.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemens/Downloads/libdrone-master/src/dronehelper.cpp -o CMakeFiles/drone.dir/src/dronehelper.cpp.s

CMakeFiles/drone.dir/src/dronehelper.cpp.o.requires:

.PHONY : CMakeFiles/drone.dir/src/dronehelper.cpp.o.requires

CMakeFiles/drone.dir/src/dronehelper.cpp.o.provides: CMakeFiles/drone.dir/src/dronehelper.cpp.o.requires
	$(MAKE) -f CMakeFiles/drone.dir/build.make CMakeFiles/drone.dir/src/dronehelper.cpp.o.provides.build
.PHONY : CMakeFiles/drone.dir/src/dronehelper.cpp.o.provides

CMakeFiles/drone.dir/src/dronehelper.cpp.o.provides.build: CMakeFiles/drone.dir/src/dronehelper.cpp.o


# Object files for target drone
drone_OBJECTS = \
"CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o" \
"CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o" \
"CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o" \
"CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o" \
"CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o" \
"CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o" \
"CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o" \
"CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o" \
"CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o" \
"CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o" \
"CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o" \
"CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o" \
"CMakeFiles/drone.dir/src/drone.cpp.o" \
"CMakeFiles/drone.dir/src/dronehelper.cpp.o"

# External object files for target drone
drone_EXTERNAL_OBJECTS =

libdrone.so: CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/drone.cpp.o
libdrone.so: CMakeFiles/drone.dir/src/dronehelper.cpp.o
libdrone.so: CMakeFiles/drone.dir/build.make
libdrone.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libboost_log.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libboost_timer.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libboost_log_setup.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libboost_regex.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libpthread.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libavformat.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libavcodec.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libavutil.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libswscale.so
libdrone.so: /usr/lib/x86_64-linux-gnu/libz.so
libdrone.so: /usr/local/lib/libopencv_viz.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_videostab.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_superres.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_stitching.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_shape.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_photo.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_objdetect.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_calib3d.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_features2d.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_ml.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_highgui.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_videoio.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_flann.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_video.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_imgproc.so.3.1.0
libdrone.so: /usr/local/lib/libopencv_core.so.3.1.0
libdrone.so: CMakeFiles/drone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clemens/Downloads/libdrone-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX shared library libdrone.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/drone.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/drone.dir/build: libdrone.so

.PHONY : CMakeFiles/drone.dir/build

CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drones/bebop/bebop.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drones/bebop/fullnavdata.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drones/bebop/videodecoder.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drones/bebop/commandcomposer.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drones/bebop/controllink.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drones/fpvdrone.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drones/ardrone2/video/videomanager.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drones/ardrone2/video/framereconstructor.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drones/ardrone2/ardrone2.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drones/ardrone2/atcommands/atcommand.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drones/ardrone2/navdata/navdatamanager.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drones/ardrone2/controllink.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/drone.cpp.o.requires
CMakeFiles/drone.dir/requires: CMakeFiles/drone.dir/src/dronehelper.cpp.o.requires

.PHONY : CMakeFiles/drone.dir/requires

CMakeFiles/drone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/drone.dir/cmake_clean.cmake
.PHONY : CMakeFiles/drone.dir/clean

CMakeFiles/drone.dir/depend:
	cd /home/clemens/Downloads/libdrone-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clemens/Downloads/libdrone-master /home/clemens/Downloads/libdrone-master /home/clemens/Downloads/libdrone-master/build /home/clemens/Downloads/libdrone-master/build /home/clemens/Downloads/libdrone-master/build/CMakeFiles/drone.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/drone.dir/depend
