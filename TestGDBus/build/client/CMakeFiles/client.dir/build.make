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
include client/CMakeFiles/client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include client/CMakeFiles/client.dir/compiler_depend.make

# Include the progress variables for this target.
include client/CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include client/CMakeFiles/client.dir/flags.make

client/CMakeFiles/client.dir/client.c.o: client/CMakeFiles/client.dir/flags.make
client/CMakeFiles/client.dir/client.c.o: ../client/client.c
client/CMakeFiles/client.dir/client.c.o: client/CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cg/GitHub/GDBus-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object client/CMakeFiles/client.dir/client.c.o"
	cd /home/cg/GitHub/GDBus-master/build/client && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT client/CMakeFiles/client.dir/client.c.o -MF CMakeFiles/client.dir/client.c.o.d -o CMakeFiles/client.dir/client.c.o -c /home/cg/GitHub/GDBus-master/client/client.c

client/CMakeFiles/client.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/client.dir/client.c.i"
	cd /home/cg/GitHub/GDBus-master/build/client && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cg/GitHub/GDBus-master/client/client.c > CMakeFiles/client.dir/client.c.i

client/CMakeFiles/client.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/client.dir/client.c.s"
	cd /home/cg/GitHub/GDBus-master/build/client && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cg/GitHub/GDBus-master/client/client.c -o CMakeFiles/client.dir/client.c.s

client/CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.o: client/CMakeFiles/client.dir/flags.make
client/CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.o: ../gdbus/gdbusdemo_gen.c
client/CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.o: client/CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cg/GitHub/GDBus-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object client/CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.o"
	cd /home/cg/GitHub/GDBus-master/build/client && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT client/CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.o -MF CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.o.d -o CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.o -c /home/cg/GitHub/GDBus-master/gdbus/gdbusdemo_gen.c

client/CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.i"
	cd /home/cg/GitHub/GDBus-master/build/client && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cg/GitHub/GDBus-master/gdbus/gdbusdemo_gen.c > CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.i

client/CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.s"
	cd /home/cg/GitHub/GDBus-master/build/client && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cg/GitHub/GDBus-master/gdbus/gdbusdemo_gen.c -o CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/client.c.o" \
"CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client/client: client/CMakeFiles/client.dir/client.c.o
client/client: client/CMakeFiles/client.dir/__/gdbus/gdbusdemo_gen.c.o
client/client: client/CMakeFiles/client.dir/build.make
client/client: client/CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cg/GitHub/GDBus-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable client"
	cd /home/cg/GitHub/GDBus-master/build/client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
client/CMakeFiles/client.dir/build: client/client
.PHONY : client/CMakeFiles/client.dir/build

client/CMakeFiles/client.dir/clean:
	cd /home/cg/GitHub/GDBus-master/build/client && $(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : client/CMakeFiles/client.dir/clean

client/CMakeFiles/client.dir/depend:
	cd /home/cg/GitHub/GDBus-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cg/GitHub/GDBus-master /home/cg/GitHub/GDBus-master/client /home/cg/GitHub/GDBus-master/build /home/cg/GitHub/GDBus-master/build/client /home/cg/GitHub/GDBus-master/build/client/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : client/CMakeFiles/client.dir/depend

