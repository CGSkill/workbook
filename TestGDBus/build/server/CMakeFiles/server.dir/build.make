# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cg/GitHub/GDBus-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cg/GitHub/GDBus-master/build

# Include any dependencies generated for this target.
include server/CMakeFiles/server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include server/CMakeFiles/server.dir/compiler_depend.make

# Include the progress variables for this target.
include server/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include server/CMakeFiles/server.dir/flags.make

server/CMakeFiles/server.dir/server.c.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/server.c.o: ../server/server.c
server/CMakeFiles/server.dir/server.c.o: server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cg/GitHub/GDBus-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object server/CMakeFiles/server.dir/server.c.o"
	cd /home/cg/GitHub/GDBus-master/build/server && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT server/CMakeFiles/server.dir/server.c.o -MF CMakeFiles/server.dir/server.c.o.d -o CMakeFiles/server.dir/server.c.o -c /home/cg/GitHub/GDBus-master/server/server.c

server/CMakeFiles/server.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/server.c.i"
	cd /home/cg/GitHub/GDBus-master/build/server && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cg/GitHub/GDBus-master/server/server.c > CMakeFiles/server.dir/server.c.i

server/CMakeFiles/server.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/server.c.s"
	cd /home/cg/GitHub/GDBus-master/build/server && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cg/GitHub/GDBus-master/server/server.c -o CMakeFiles/server.dir/server.c.s

server/CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.o: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.o: ../gdbus/gdbusdemo_gen.c
server/CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.o: server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cg/GitHub/GDBus-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object server/CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.o"
	cd /home/cg/GitHub/GDBus-master/build/server && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT server/CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.o -MF CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.o.d -o CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.o -c /home/cg/GitHub/GDBus-master/gdbus/gdbusdemo_gen.c

server/CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.i"
	cd /home/cg/GitHub/GDBus-master/build/server && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cg/GitHub/GDBus-master/gdbus/gdbusdemo_gen.c > CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.i

server/CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.s"
	cd /home/cg/GitHub/GDBus-master/build/server && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cg/GitHub/GDBus-master/gdbus/gdbusdemo_gen.c -o CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/server.c.o" \
"CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server/server: server/CMakeFiles/server.dir/server.c.o
server/server: server/CMakeFiles/server.dir/__/gdbus/gdbusdemo_gen.c.o
server/server: server/CMakeFiles/server.dir/build.make
server/server: server/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cg/GitHub/GDBus-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable server"
	cd /home/cg/GitHub/GDBus-master/build/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
server/CMakeFiles/server.dir/build: server/server
.PHONY : server/CMakeFiles/server.dir/build

server/CMakeFiles/server.dir/clean:
	cd /home/cg/GitHub/GDBus-master/build/server && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : server/CMakeFiles/server.dir/clean

server/CMakeFiles/server.dir/depend:
	cd /home/cg/GitHub/GDBus-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cg/GitHub/GDBus-master /home/cg/GitHub/GDBus-master/server /home/cg/GitHub/GDBus-master/build /home/cg/GitHub/GDBus-master/build/server /home/cg/GitHub/GDBus-master/build/server/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : server/CMakeFiles/server.dir/depend

