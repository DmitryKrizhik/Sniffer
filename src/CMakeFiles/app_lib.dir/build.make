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
CMAKE_BINARY_DIR = /home/krizhik/Downloads/Sniffer/src

# Include any dependencies generated for this target.
include CMakeFiles/app_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/app_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/app_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app_lib.dir/flags.make

CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.o: CMakeFiles/app_lib.dir/flags.make
CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.o: ../myLib/lib_src/lib.cpp
CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.o: CMakeFiles/app_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krizhik/Downloads/Sniffer/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.o -MF CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.o.d -o CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.o -c /home/krizhik/Downloads/Sniffer/myLib/lib_src/lib.cpp

CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krizhik/Downloads/Sniffer/myLib/lib_src/lib.cpp > CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.i

CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krizhik/Downloads/Sniffer/myLib/lib_src/lib.cpp -o CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.s

# Object files for target app_lib
app_lib_OBJECTS = \
"CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.o"

# External object files for target app_lib
app_lib_EXTERNAL_OBJECTS =

libapp_lib.a: CMakeFiles/app_lib.dir/myLib/lib_src/lib.cpp.o
libapp_lib.a: CMakeFiles/app_lib.dir/build.make
libapp_lib.a: CMakeFiles/app_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/krizhik/Downloads/Sniffer/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libapp_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/app_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app_lib.dir/build: libapp_lib.a
.PHONY : CMakeFiles/app_lib.dir/build

CMakeFiles/app_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app_lib.dir/clean

CMakeFiles/app_lib.dir/depend:
	cd /home/krizhik/Downloads/Sniffer/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/krizhik/Downloads/Sniffer /home/krizhik/Downloads/Sniffer /home/krizhik/Downloads/Sniffer/src /home/krizhik/Downloads/Sniffer/src /home/krizhik/Downloads/Sniffer/src/CMakeFiles/app_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app_lib.dir/depend

