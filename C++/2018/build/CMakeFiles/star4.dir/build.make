# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/spencerwf/adventofcode/C++/2018

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/spencerwf/adventofcode/C++/2018/build

# Include any dependencies generated for this target.
include CMakeFiles/star4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/star4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/star4.dir/flags.make

CMakeFiles/star4.dir/star4.cpp.o: CMakeFiles/star4.dir/flags.make
CMakeFiles/star4.dir/star4.cpp.o: ../star4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spencerwf/adventofcode/C++/2018/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/star4.dir/star4.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/star4.dir/star4.cpp.o -c /home/spencerwf/adventofcode/C++/2018/star4.cpp

CMakeFiles/star4.dir/star4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/star4.dir/star4.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spencerwf/adventofcode/C++/2018/star4.cpp > CMakeFiles/star4.dir/star4.cpp.i

CMakeFiles/star4.dir/star4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/star4.dir/star4.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spencerwf/adventofcode/C++/2018/star4.cpp -o CMakeFiles/star4.dir/star4.cpp.s

# Object files for target star4
star4_OBJECTS = \
"CMakeFiles/star4.dir/star4.cpp.o"

# External object files for target star4
star4_EXTERNAL_OBJECTS =

star4: CMakeFiles/star4.dir/star4.cpp.o
star4: CMakeFiles/star4.dir/build.make
star4: CMakeFiles/star4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/spencerwf/adventofcode/C++/2018/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable star4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/star4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/star4.dir/build: star4

.PHONY : CMakeFiles/star4.dir/build

CMakeFiles/star4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/star4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/star4.dir/clean

CMakeFiles/star4.dir/depend:
	cd /home/spencerwf/adventofcode/C++/2018/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/spencerwf/adventofcode/C++/2018 /home/spencerwf/adventofcode/C++/2018 /home/spencerwf/adventofcode/C++/2018/build /home/spencerwf/adventofcode/C++/2018/build /home/spencerwf/adventofcode/C++/2018/build/CMakeFiles/star4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/star4.dir/depend

