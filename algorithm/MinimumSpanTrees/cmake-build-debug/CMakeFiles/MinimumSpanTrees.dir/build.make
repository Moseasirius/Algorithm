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
CMAKE_SOURCE_DIR = E:\AlgorithmAndDataStructure\algorithm\MinimumSpanTrees

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\AlgorithmAndDataStructure\algorithm\MinimumSpanTrees\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MinimumSpanTrees.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MinimumSpanTrees.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MinimumSpanTrees.dir/flags.make

CMakeFiles/MinimumSpanTrees.dir/main.cpp.obj: CMakeFiles/MinimumSpanTrees.dir/flags.make
CMakeFiles/MinimumSpanTrees.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\AlgorithmAndDataStructure\algorithm\MinimumSpanTrees\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MinimumSpanTrees.dir/main.cpp.obj"
	"D:\Program Files(x86)\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MinimumSpanTrees.dir\main.cpp.obj -c E:\AlgorithmAndDataStructure\algorithm\MinimumSpanTrees\main.cpp

CMakeFiles/MinimumSpanTrees.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MinimumSpanTrees.dir/main.cpp.i"
	"D:\Program Files(x86)\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\AlgorithmAndDataStructure\algorithm\MinimumSpanTrees\main.cpp > CMakeFiles\MinimumSpanTrees.dir\main.cpp.i

CMakeFiles/MinimumSpanTrees.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MinimumSpanTrees.dir/main.cpp.s"
	"D:\Program Files(x86)\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\AlgorithmAndDataStructure\algorithm\MinimumSpanTrees\main.cpp -o CMakeFiles\MinimumSpanTrees.dir\main.cpp.s

# Object files for target MinimumSpanTrees
MinimumSpanTrees_OBJECTS = \
"CMakeFiles/MinimumSpanTrees.dir/main.cpp.obj"

# External object files for target MinimumSpanTrees
MinimumSpanTrees_EXTERNAL_OBJECTS =

MinimumSpanTrees.exe: CMakeFiles/MinimumSpanTrees.dir/main.cpp.obj
MinimumSpanTrees.exe: CMakeFiles/MinimumSpanTrees.dir/build.make
MinimumSpanTrees.exe: CMakeFiles/MinimumSpanTrees.dir/linklibs.rsp
MinimumSpanTrees.exe: CMakeFiles/MinimumSpanTrees.dir/objects1.rsp
MinimumSpanTrees.exe: CMakeFiles/MinimumSpanTrees.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\AlgorithmAndDataStructure\algorithm\MinimumSpanTrees\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MinimumSpanTrees.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MinimumSpanTrees.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MinimumSpanTrees.dir/build: MinimumSpanTrees.exe

.PHONY : CMakeFiles/MinimumSpanTrees.dir/build

CMakeFiles/MinimumSpanTrees.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MinimumSpanTrees.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MinimumSpanTrees.dir/clean

CMakeFiles/MinimumSpanTrees.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\AlgorithmAndDataStructure\algorithm\MinimumSpanTrees E:\AlgorithmAndDataStructure\algorithm\MinimumSpanTrees E:\AlgorithmAndDataStructure\algorithm\MinimumSpanTrees\cmake-build-debug E:\AlgorithmAndDataStructure\algorithm\MinimumSpanTrees\cmake-build-debug E:\AlgorithmAndDataStructure\algorithm\MinimumSpanTrees\cmake-build-debug\CMakeFiles\MinimumSpanTrees.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MinimumSpanTrees.dir/depend

