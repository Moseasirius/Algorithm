# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files(x86)\CLion\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files(x86)\CLion\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\AlgorithmAndDataStructure\algorithm\TextIO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\AlgorithmAndDataStructure\algorithm\TextIO\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TextIO.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TextIO.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TextIO.dir/flags.make

CMakeFiles/TextIO.dir/main.cpp.obj: CMakeFiles/TextIO.dir/flags.make
CMakeFiles/TextIO.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\AlgorithmAndDataStructure\algorithm\TextIO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TextIO.dir/main.cpp.obj"
	E:\Qt\Qt5.14.0\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TextIO.dir\main.cpp.obj -c E:\AlgorithmAndDataStructure\algorithm\TextIO\main.cpp

CMakeFiles/TextIO.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextIO.dir/main.cpp.i"
	E:\Qt\Qt5.14.0\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\AlgorithmAndDataStructure\algorithm\TextIO\main.cpp > CMakeFiles\TextIO.dir\main.cpp.i

CMakeFiles/TextIO.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextIO.dir/main.cpp.s"
	E:\Qt\Qt5.14.0\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\AlgorithmAndDataStructure\algorithm\TextIO\main.cpp -o CMakeFiles\TextIO.dir\main.cpp.s

CMakeFiles/TextIO.dir/Student.cpp.obj: CMakeFiles/TextIO.dir/flags.make
CMakeFiles/TextIO.dir/Student.cpp.obj: ../Student.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\AlgorithmAndDataStructure\algorithm\TextIO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TextIO.dir/Student.cpp.obj"
	E:\Qt\Qt5.14.0\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TextIO.dir\Student.cpp.obj -c E:\AlgorithmAndDataStructure\algorithm\TextIO\Student.cpp

CMakeFiles/TextIO.dir/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TextIO.dir/Student.cpp.i"
	E:\Qt\Qt5.14.0\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\AlgorithmAndDataStructure\algorithm\TextIO\Student.cpp > CMakeFiles\TextIO.dir\Student.cpp.i

CMakeFiles/TextIO.dir/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TextIO.dir/Student.cpp.s"
	E:\Qt\Qt5.14.0\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\AlgorithmAndDataStructure\algorithm\TextIO\Student.cpp -o CMakeFiles\TextIO.dir\Student.cpp.s

# Object files for target TextIO
TextIO_OBJECTS = \
"CMakeFiles/TextIO.dir/main.cpp.obj" \
"CMakeFiles/TextIO.dir/Student.cpp.obj"

# External object files for target TextIO
TextIO_EXTERNAL_OBJECTS =

TextIO.exe: CMakeFiles/TextIO.dir/main.cpp.obj
TextIO.exe: CMakeFiles/TextIO.dir/Student.cpp.obj
TextIO.exe: CMakeFiles/TextIO.dir/build.make
TextIO.exe: CMakeFiles/TextIO.dir/linklibs.rsp
TextIO.exe: CMakeFiles/TextIO.dir/objects1.rsp
TextIO.exe: CMakeFiles/TextIO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\AlgorithmAndDataStructure\algorithm\TextIO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TextIO.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TextIO.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TextIO.dir/build: TextIO.exe

.PHONY : CMakeFiles/TextIO.dir/build

CMakeFiles/TextIO.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TextIO.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TextIO.dir/clean

CMakeFiles/TextIO.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\AlgorithmAndDataStructure\algorithm\TextIO E:\AlgorithmAndDataStructure\algorithm\TextIO E:\AlgorithmAndDataStructure\algorithm\TextIO\cmake-build-debug E:\AlgorithmAndDataStructure\algorithm\TextIO\cmake-build-debug E:\AlgorithmAndDataStructure\algorithm\TextIO\cmake-build-debug\CMakeFiles\TextIO.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TextIO.dir/depend

