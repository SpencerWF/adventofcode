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
CMAKE_BINARY_DIR = /home/spencerwf/adventofcode/build

# Include any dependencies generated for this target.
include CMakeFiles/star1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/star1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/star1.dir/flags.make

CMakeFiles/star1.dir/star1.cpp.o: CMakeFiles/star1.dir/flags.make
CMakeFiles/star1.dir/star1.cpp.o: /home/spencerwf/adventofcode/C++/2018/star1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spencerwf/adventofcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/star1.dir/star1.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/star1.dir/star1.cpp.o -c /home/spencerwf/adventofcode/C++/2018/star1.cpp

CMakeFiles/star1.dir/star1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/star1.dir/star1.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spencerwf/adventofcode/C++/2018/star1.cpp > CMakeFiles/star1.dir/star1.cpp.i

CMakeFiles/star1.dir/star1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/star1.dir/star1.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spencerwf/adventofcode/C++/2018/star1.cpp -o CMakeFiles/star1.dir/star1.cpp.s

# Object files for target star1
star1_OBJECTS = \
"CMakeFiles/star1.dir/star1.cpp.o"

# External object files for target star1
star1_EXTERNAL_OBJECTS =

star1: CMakeFiles/star1.dir/star1.cpp.o
star1: CMakeFiles/star1.dir/build.make
star1: CMakeFiles/star1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/spencerwf/adventofcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable star1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/star1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/star1.dir/build: star1

.PHONY : CMakeFiles/star1.dir/build

CMakeFiles/star1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/star1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/star1.dir/clean

CMakeFiles/star1.dir/depend:
	cd /home/spencerwf/adventofcode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/spencerwf/adventofcode/C++/2018 /home/spencerwf/adventofcode/C++/2018 /home/spencerwf/adventofcode/build /home/spencerwf/adventofcode/build /home/spencerwf/adventofcode/build/CMakeFiles/star1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/star1.dir/depend

