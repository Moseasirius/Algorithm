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
CMAKE_SOURCE_DIR = E:\AlgorithmAndDataStructure\algorithm\STLUsageTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\AlgorithmAndDataStructure\algorithm\STLUsageTest\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/STLUsageTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/STLUsageTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/STLUsageTest.dir/flags.make

CMakeFiles/STLUsageTest.dir/main.cpp.obj: CMakeFiles/STLUsageTest.dir/flags.make
CMakeFiles/STLUsageTest.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\AlgorithmAndDataStructure\algorithm\STLUsageTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/STLUsageTest.dir/main.cpp.obj"
	"D:\Program Files(x86)\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\STLUsageTest.dir\main.cpp.obj -c E:\AlgorithmAndDataStructure\algorithm\STLUsageTest\main.cpp

CMakeFiles/STLUsageTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/STLUsageTest.dir/main.cpp.i"
	"D:\Program Files(x86)\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\AlgorithmAndDataStructure\algorithm\STLUsageTest\main.cpp > CMakeFiles\STLUsageTest.dir\main.cpp.i

CMakeFiles/STLUsageTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/STLUsageTest.dir/main.cpp.s"
	"D:\Program Files(x86)\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\AlgorithmAndDataStructure\algorithm\STLUsageTest\main.cpp -o CMakeFiles\STLUsageTest.dir\main.cpp.s

# Object files for target STLUsageTest
STLUsageTest_OBJECTS = \
"CMakeFiles/STLUsageTest.dir/main.cpp.obj"

# External object files for target STLUsageTest
STLUsageTest_EXTERNAL_OBJECTS =

STLUsageTest.exe: CMakeFiles/STLUsageTest.dir/main.cpp.obj
STLUsageTest.exe: CMakeFiles/STLUsageTest.dir/build.make
STLUsageTest.exe: CMakeFiles/STLUsageTest.dir/linklibs.rsp
STLUsageTest.exe: CMakeFiles/STLUsageTest.dir/objects1.rsp
STLUsageTest.exe: CMakeFiles/STLUsageTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\AlgorithmAndDataStructure\algorithm\STLUsageTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable STLUsageTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\STLUsageTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/STLUsageTest.dir/build: STLUsageTest.exe

.PHONY : CMakeFiles/STLUsageTest.dir/build

CMakeFiles/STLUsageTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\STLUsageTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/STLUsageTest.dir/clean

CMakeFiles/STLUsageTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\AlgorithmAndDataStructure\algorithm\STLUsageTest E:\AlgorithmAndDataStructure\algorithm\STLUsageTest E:\AlgorithmAndDataStructure\algorithm\STLUsageTest\cmake-build-debug E:\AlgorithmAndDataStructure\algorithm\STLUsageTest\cmake-build-debug E:\AlgorithmAndDataStructure\algorithm\STLUsageTest\cmake-build-debug\CMakeFiles\STLUsageTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/STLUsageTest.dir/depend
