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
CMAKE_SOURCE_DIR = "/Users/moonmisty/CLionProjects/Accelerate C++"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/moonmisty/CLionProjects/Accelerate C++/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Accelerate_C__.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Accelerate_C__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Accelerate_C__.dir/flags.make

CMakeFiles/Accelerate_C__.dir/main.cpp.o: CMakeFiles/Accelerate_C__.dir/flags.make
CMakeFiles/Accelerate_C__.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/moonmisty/CLionProjects/Accelerate C++/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Accelerate_C__.dir/main.cpp.o"
	/usr/local/Cellar/gcc/8.2.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Accelerate_C__.dir/main.cpp.o -c "/Users/moonmisty/CLionProjects/Accelerate C++/main.cpp"

CMakeFiles/Accelerate_C__.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Accelerate_C__.dir/main.cpp.i"
	/usr/local/Cellar/gcc/8.2.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/moonmisty/CLionProjects/Accelerate C++/main.cpp" > CMakeFiles/Accelerate_C__.dir/main.cpp.i

CMakeFiles/Accelerate_C__.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Accelerate_C__.dir/main.cpp.s"
	/usr/local/Cellar/gcc/8.2.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/moonmisty/CLionProjects/Accelerate C++/main.cpp" -o CMakeFiles/Accelerate_C__.dir/main.cpp.s

CMakeFiles/Accelerate_C__.dir/GradeBook.cpp.o: CMakeFiles/Accelerate_C__.dir/flags.make
CMakeFiles/Accelerate_C__.dir/GradeBook.cpp.o: ../GradeBook.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/moonmisty/CLionProjects/Accelerate C++/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Accelerate_C__.dir/GradeBook.cpp.o"
	/usr/local/Cellar/gcc/8.2.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Accelerate_C__.dir/GradeBook.cpp.o -c "/Users/moonmisty/CLionProjects/Accelerate C++/GradeBook.cpp"

CMakeFiles/Accelerate_C__.dir/GradeBook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Accelerate_C__.dir/GradeBook.cpp.i"
	/usr/local/Cellar/gcc/8.2.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/moonmisty/CLionProjects/Accelerate C++/GradeBook.cpp" > CMakeFiles/Accelerate_C__.dir/GradeBook.cpp.i

CMakeFiles/Accelerate_C__.dir/GradeBook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Accelerate_C__.dir/GradeBook.cpp.s"
	/usr/local/Cellar/gcc/8.2.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/moonmisty/CLionProjects/Accelerate C++/GradeBook.cpp" -o CMakeFiles/Accelerate_C__.dir/GradeBook.cpp.s

# Object files for target Accelerate_C__
Accelerate_C___OBJECTS = \
"CMakeFiles/Accelerate_C__.dir/main.cpp.o" \
"CMakeFiles/Accelerate_C__.dir/GradeBook.cpp.o"

# External object files for target Accelerate_C__
Accelerate_C___EXTERNAL_OBJECTS =

Accelerate_C__: CMakeFiles/Accelerate_C__.dir/main.cpp.o
Accelerate_C__: CMakeFiles/Accelerate_C__.dir/GradeBook.cpp.o
Accelerate_C__: CMakeFiles/Accelerate_C__.dir/build.make
Accelerate_C__: CMakeFiles/Accelerate_C__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/moonmisty/CLionProjects/Accelerate C++/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Accelerate_C__"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Accelerate_C__.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Accelerate_C__.dir/build: Accelerate_C__

.PHONY : CMakeFiles/Accelerate_C__.dir/build

CMakeFiles/Accelerate_C__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Accelerate_C__.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Accelerate_C__.dir/clean

CMakeFiles/Accelerate_C__.dir/depend:
	cd "/Users/moonmisty/CLionProjects/Accelerate C++/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/moonmisty/CLionProjects/Accelerate C++" "/Users/moonmisty/CLionProjects/Accelerate C++" "/Users/moonmisty/CLionProjects/Accelerate C++/cmake-build-debug" "/Users/moonmisty/CLionProjects/Accelerate C++/cmake-build-debug" "/Users/moonmisty/CLionProjects/Accelerate C++/cmake-build-debug/CMakeFiles/Accelerate_C__.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Accelerate_C__.dir/depend

