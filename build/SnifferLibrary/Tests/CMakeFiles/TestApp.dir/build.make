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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/krizhik/Downloads/Sniffer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/krizhik/Downloads/Sniffer/build

# Include any dependencies generated for this target.
include SnifferLibrary/Tests/CMakeFiles/TestApp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include SnifferLibrary/Tests/CMakeFiles/TestApp.dir/compiler_depend.make

# Include the progress variables for this target.
include SnifferLibrary/Tests/CMakeFiles/TestApp.dir/progress.make

# Include the compile flags for this target's objects.
include SnifferLibrary/Tests/CMakeFiles/TestApp.dir/flags.make

SnifferLibrary/Tests/CMakeFiles/TestApp.dir/tmain.cpp.o: SnifferLibrary/Tests/CMakeFiles/TestApp.dir/flags.make
SnifferLibrary/Tests/CMakeFiles/TestApp.dir/tmain.cpp.o: ../SnifferLibrary/Tests/tmain.cpp
SnifferLibrary/Tests/CMakeFiles/TestApp.dir/tmain.cpp.o: SnifferLibrary/Tests/CMakeFiles/TestApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krizhik/Downloads/Sniffer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object SnifferLibrary/Tests/CMakeFiles/TestApp.dir/tmain.cpp.o"
	cd /home/krizhik/Downloads/Sniffer/build/SnifferLibrary/Tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT SnifferLibrary/Tests/CMakeFiles/TestApp.dir/tmain.cpp.o -MF CMakeFiles/TestApp.dir/tmain.cpp.o.d -o CMakeFiles/TestApp.dir/tmain.cpp.o -c /home/krizhik/Downloads/Sniffer/SnifferLibrary/Tests/tmain.cpp

SnifferLibrary/Tests/CMakeFiles/TestApp.dir/tmain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestApp.dir/tmain.cpp.i"
	cd /home/krizhik/Downloads/Sniffer/build/SnifferLibrary/Tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krizhik/Downloads/Sniffer/SnifferLibrary/Tests/tmain.cpp > CMakeFiles/TestApp.dir/tmain.cpp.i

SnifferLibrary/Tests/CMakeFiles/TestApp.dir/tmain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestApp.dir/tmain.cpp.s"
	cd /home/krizhik/Downloads/Sniffer/build/SnifferLibrary/Tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krizhik/Downloads/Sniffer/SnifferLibrary/Tests/tmain.cpp -o CMakeFiles/TestApp.dir/tmain.cpp.s

# Object files for target TestApp
TestApp_OBJECTS = \
"CMakeFiles/TestApp.dir/tmain.cpp.o"

# External object files for target TestApp
TestApp_EXTERNAL_OBJECTS =

SnifferLibrary/Tests/TestApp: SnifferLibrary/Tests/CMakeFiles/TestApp.dir/tmain.cpp.o
SnifferLibrary/Tests/TestApp: SnifferLibrary/Tests/CMakeFiles/TestApp.dir/build.make
SnifferLibrary/Tests/TestApp: lib/libgtest_main.a
SnifferLibrary/Tests/TestApp: libSnifferLib.a
SnifferLibrary/Tests/TestApp: lib/libgtest.a
SnifferLibrary/Tests/TestApp: _deps/pcapplusplus-build/Pcap++/libPcap++.a
SnifferLibrary/Tests/TestApp: /usr/lib/x86_64-linux-gnu/libpcap.so
SnifferLibrary/Tests/TestApp: _deps/pcapplusplus-build/Packet++/libPacket++.a
SnifferLibrary/Tests/TestApp: _deps/pcapplusplus-build/Common++/libCommon++.a
SnifferLibrary/Tests/TestApp: SnifferLibrary/Tests/CMakeFiles/TestApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/krizhik/Downloads/Sniffer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestApp"
	cd /home/krizhik/Downloads/Sniffer/build/SnifferLibrary/Tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestApp.dir/link.txt --verbose=$(VERBOSE)
	cd /home/krizhik/Downloads/Sniffer/build/SnifferLibrary/Tests && /usr/bin/cmake -D TEST_TARGET=TestApp -D TEST_EXECUTABLE=/home/krizhik/Downloads/Sniffer/build/SnifferLibrary/Tests/TestApp -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/krizhik/Downloads/Sniffer/build/SnifferLibrary/Tests -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=TestApp_TESTS -D CTEST_FILE=/home/krizhik/Downloads/Sniffer/build/SnifferLibrary/Tests/TestApp[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.22/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
SnifferLibrary/Tests/CMakeFiles/TestApp.dir/build: SnifferLibrary/Tests/TestApp
.PHONY : SnifferLibrary/Tests/CMakeFiles/TestApp.dir/build

SnifferLibrary/Tests/CMakeFiles/TestApp.dir/clean:
	cd /home/krizhik/Downloads/Sniffer/build/SnifferLibrary/Tests && $(CMAKE_COMMAND) -P CMakeFiles/TestApp.dir/cmake_clean.cmake
.PHONY : SnifferLibrary/Tests/CMakeFiles/TestApp.dir/clean

SnifferLibrary/Tests/CMakeFiles/TestApp.dir/depend:
	cd /home/krizhik/Downloads/Sniffer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/krizhik/Downloads/Sniffer /home/krizhik/Downloads/Sniffer/SnifferLibrary/Tests /home/krizhik/Downloads/Sniffer/build /home/krizhik/Downloads/Sniffer/build/SnifferLibrary/Tests /home/krizhik/Downloads/Sniffer/build/SnifferLibrary/Tests/CMakeFiles/TestApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : SnifferLibrary/Tests/CMakeFiles/TestApp.dir/depend
