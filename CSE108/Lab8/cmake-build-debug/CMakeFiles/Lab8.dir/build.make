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
CMAKE_SOURCE_DIR = C:\Users\15400\CLionProjects\CSE108\Lab8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\15400\CLionProjects\CSE108\Lab8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab8.dir/flags.make

CMakeFiles/Lab8.dir/main.c.obj: CMakeFiles/Lab8.dir/flags.make
CMakeFiles/Lab8.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\15400\CLionProjects\CSE108\Lab8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab8.dir/main.c.obj"
	C:\MYPROG~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Lab8.dir\main.c.obj   -c C:\Users\15400\CLionProjects\CSE108\Lab8\main.c

CMakeFiles/Lab8.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab8.dir/main.c.i"
	C:\MYPROG~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\15400\CLionProjects\CSE108\Lab8\main.c > CMakeFiles\Lab8.dir\main.c.i

CMakeFiles/Lab8.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab8.dir/main.c.s"
	C:\MYPROG~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\15400\CLionProjects\CSE108\Lab8\main.c -o CMakeFiles\Lab8.dir\main.c.s

# Object files for target Lab8
Lab8_OBJECTS = \
"CMakeFiles/Lab8.dir/main.c.obj"

# External object files for target Lab8
Lab8_EXTERNAL_OBJECTS =

Lab8.exe: CMakeFiles/Lab8.dir/main.c.obj
Lab8.exe: CMakeFiles/Lab8.dir/build.make
Lab8.exe: CMakeFiles/Lab8.dir/linklibs.rsp
Lab8.exe: CMakeFiles/Lab8.dir/objects1.rsp
Lab8.exe: CMakeFiles/Lab8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\15400\CLionProjects\CSE108\Lab8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Lab8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab8.dir/build: Lab8.exe

.PHONY : CMakeFiles/Lab8.dir/build

CMakeFiles/Lab8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab8.dir/clean

CMakeFiles/Lab8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\15400\CLionProjects\CSE108\Lab8 C:\Users\15400\CLionProjects\CSE108\Lab8 C:\Users\15400\CLionProjects\CSE108\Lab8\cmake-build-debug C:\Users\15400\CLionProjects\CSE108\Lab8\cmake-build-debug C:\Users\15400\CLionProjects\CSE108\Lab8\cmake-build-debug\CMakeFiles\Lab8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab8.dir/depend

