# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\15400\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\201.6668.126\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\15400\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\201.6668.126\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\15400\CLionProjects\CSE108\TestDP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\15400\CLionProjects\CSE108\TestDP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TestDP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestDP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestDP.dir/flags.make

CMakeFiles/TestDP.dir/main.cpp.obj: CMakeFiles/TestDP.dir/flags.make
CMakeFiles/TestDP.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\15400\CLionProjects\CSE108\TestDP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestDP.dir/main.cpp.obj"
	C:\MYPROG~1\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TestDP.dir\main.cpp.obj -c C:\Users\15400\CLionProjects\CSE108\TestDP\main.cpp

CMakeFiles/TestDP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestDP.dir/main.cpp.i"
	C:\MYPROG~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\15400\CLionProjects\CSE108\TestDP\main.cpp > CMakeFiles\TestDP.dir\main.cpp.i

CMakeFiles/TestDP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestDP.dir/main.cpp.s"
	C:\MYPROG~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\15400\CLionProjects\CSE108\TestDP\main.cpp -o CMakeFiles\TestDP.dir\main.cpp.s

# Object files for target TestDP
TestDP_OBJECTS = \
"CMakeFiles/TestDP.dir/main.cpp.obj"

# External object files for target TestDP
TestDP_EXTERNAL_OBJECTS =

TestDP.exe: CMakeFiles/TestDP.dir/main.cpp.obj
TestDP.exe: CMakeFiles/TestDP.dir/build.make
TestDP.exe: CMakeFiles/TestDP.dir/linklibs.rsp
TestDP.exe: CMakeFiles/TestDP.dir/objects1.rsp
TestDP.exe: CMakeFiles/TestDP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\15400\CLionProjects\CSE108\TestDP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestDP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TestDP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestDP.dir/build: TestDP.exe

.PHONY : CMakeFiles/TestDP.dir/build

CMakeFiles/TestDP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TestDP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TestDP.dir/clean

CMakeFiles/TestDP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\15400\CLionProjects\CSE108\TestDP C:\Users\15400\CLionProjects\CSE108\TestDP C:\Users\15400\CLionProjects\CSE108\TestDP\cmake-build-debug C:\Users\15400\CLionProjects\CSE108\TestDP\cmake-build-debug C:\Users\15400\CLionProjects\CSE108\TestDP\cmake-build-debug\CMakeFiles\TestDP.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestDP.dir/depend

