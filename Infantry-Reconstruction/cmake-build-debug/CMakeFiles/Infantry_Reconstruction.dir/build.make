# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/moonmisty/CLionProjects/Infantry-Reconstruction

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Infantry_Reconstruction.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Infantry_Reconstruction.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Infantry_Reconstruction.dir/flags.make

CMakeFiles/Infantry_Reconstruction.dir/main.c.o: CMakeFiles/Infantry_Reconstruction.dir/flags.make
CMakeFiles/Infantry_Reconstruction.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Infantry_Reconstruction.dir/main.c.o"
	/usr/local/Cellar/gcc/8.2.0/bin/gcc-8 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Infantry_Reconstruction.dir/main.c.o   -c /Users/moonmisty/CLionProjects/Infantry-Reconstruction/main.c

CMakeFiles/Infantry_Reconstruction.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Infantry_Reconstruction.dir/main.c.i"
	/usr/local/Cellar/gcc/8.2.0/bin/gcc-8 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moonmisty/CLionProjects/Infantry-Reconstruction/main.c > CMakeFiles/Infantry_Reconstruction.dir/main.c.i

CMakeFiles/Infantry_Reconstruction.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Infantry_Reconstruction.dir/main.c.s"
	/usr/local/Cellar/gcc/8.2.0/bin/gcc-8 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moonmisty/CLionProjects/Infantry-Reconstruction/main.c -o CMakeFiles/Infantry_Reconstruction.dir/main.c.s

# Object files for target Infantry_Reconstruction
Infantry_Reconstruction_OBJECTS = \
"CMakeFiles/Infantry_Reconstruction.dir/main.c.o"

# External object files for target Infantry_Reconstruction
Infantry_Reconstruction_EXTERNAL_OBJECTS =

Infantry_Reconstruction: CMakeFiles/Infantry_Reconstruction.dir/main.c.o
Infantry_Reconstruction: CMakeFiles/Infantry_Reconstruction.dir/build.make
Infantry_Reconstruction: CMakeFiles/Infantry_Reconstruction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Infantry_Reconstruction"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Infantry_Reconstruction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Infantry_Reconstruction.dir/build: Infantry_Reconstruction

.PHONY : CMakeFiles/Infantry_Reconstruction.dir/build

CMakeFiles/Infantry_Reconstruction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Infantry_Reconstruction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Infantry_Reconstruction.dir/clean

CMakeFiles/Infantry_Reconstruction.dir/depend:
	cd /Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/moonmisty/CLionProjects/Infantry-Reconstruction /Users/moonmisty/CLionProjects/Infantry-Reconstruction /Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug /Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug /Users/moonmisty/CLionProjects/Infantry-Reconstruction/cmake-build-debug/CMakeFiles/Infantry_Reconstruction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Infantry_Reconstruction.dir/depend

