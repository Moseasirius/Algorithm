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
CMAKE_SOURCE_DIR = E:\AlgorithmAndDataStructure\CSP\CSP2015

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\AlgorithmAndDataStructure\CSP\CSP2015\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CSP2015.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CSP2015.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CSP2015.dir/flags.make

CMakeFiles/CSP2015.dir/main.cpp.obj: CMakeFiles/CSP2015.dir/flags.make
CMakeFiles/CSP2015.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\AlgorithmAndDataStructure\CSP\CSP2015\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CSP2015.dir/main.cpp.obj"
	"D:\Program Files(x86)\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CSP2015.dir\main.cpp.obj -c E:\AlgorithmAndDataStructure\CSP\CSP2015\main.cpp

CMakeFiles/CSP2015.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSP2015.dir/main.cpp.i"
	"D:\Program Files(x86)\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\AlgorithmAndDataStructure\CSP\CSP2015\main.cpp > CMakeFiles\CSP2015.dir\main.cpp.i

CMakeFiles/CSP2015.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSP2015.dir/main.cpp.s"
	"D:\Program Files(x86)\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\AlgorithmAndDataStructure\CSP\CSP2015\main.cpp -o CMakeFiles\CSP2015.dir\main.cpp.s

# Object files for target CSP2015
CSP2015_OBJECTS = \
"CMakeFiles/CSP2015.dir/main.cpp.obj"

# External object files for target CSP2015
CSP2015_EXTERNAL_OBJECTS =

CSP2015.exe: CMakeFiles/CSP2015.dir/main.cpp.obj
CSP2015.exe: CMakeFiles/CSP2015.dir/build.make
CSP2015.exe: CMakeFiles/CSP2015.dir/linklibs.rsp
CSP2015.exe: CMakeFiles/CSP2015.dir/objects1.rsp
CSP2015.exe: CMakeFiles/CSP2015.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\AlgorithmAndDataStructure\CSP\CSP2015\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CSP2015.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CSP2015.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CSP2015.dir/build: CSP2015.exe

.PHONY : CMakeFiles/CSP2015.dir/build

CMakeFiles/CSP2015.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CSP2015.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CSP2015.dir/clean

CMakeFiles/CSP2015.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\AlgorithmAndDataStructure\CSP\CSP2015 E:\AlgorithmAndDataStructure\CSP\CSP2015 E:\AlgorithmAndDataStructure\CSP\CSP2015\cmake-build-debug E:\AlgorithmAndDataStructure\CSP\CSP2015\cmake-build-debug E:\AlgorithmAndDataStructure\CSP\CSP2015\cmake-build-debug\CMakeFiles\CSP2015.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CSP2015.dir/depend

