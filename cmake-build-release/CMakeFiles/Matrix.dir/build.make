# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "F:\CLion\CLion 2022.3.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "F:\CLion\CLion 2022.3.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Matrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Matrix\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/Matrix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Matrix.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Matrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Matrix.dir/flags.make

CMakeFiles/Matrix.dir/main.cpp.obj: CMakeFiles/Matrix.dir/flags.make
CMakeFiles/Matrix.dir/main.cpp.obj: F:/Matrix/main.cpp
CMakeFiles/Matrix.dir/main.cpp.obj: CMakeFiles/Matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Matrix\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Matrix.dir/main.cpp.obj"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Matrix.dir/main.cpp.obj -MF CMakeFiles\Matrix.dir\main.cpp.obj.d -o CMakeFiles\Matrix.dir\main.cpp.obj -c F:\Matrix\main.cpp

CMakeFiles/Matrix.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Matrix.dir/main.cpp.i"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Matrix\main.cpp > CMakeFiles\Matrix.dir\main.cpp.i

CMakeFiles/Matrix.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Matrix.dir/main.cpp.s"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Matrix\main.cpp -o CMakeFiles\Matrix.dir\main.cpp.s

CMakeFiles/Matrix.dir/Matrix.cpp.obj: CMakeFiles/Matrix.dir/flags.make
CMakeFiles/Matrix.dir/Matrix.cpp.obj: F:/Matrix/Matrix.cpp
CMakeFiles/Matrix.dir/Matrix.cpp.obj: CMakeFiles/Matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Matrix\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Matrix.dir/Matrix.cpp.obj"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Matrix.dir/Matrix.cpp.obj -MF CMakeFiles\Matrix.dir\Matrix.cpp.obj.d -o CMakeFiles\Matrix.dir\Matrix.cpp.obj -c F:\Matrix\Matrix.cpp

CMakeFiles/Matrix.dir/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Matrix.dir/Matrix.cpp.i"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Matrix\Matrix.cpp > CMakeFiles\Matrix.dir\Matrix.cpp.i

CMakeFiles/Matrix.dir/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Matrix.dir/Matrix.cpp.s"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Matrix\Matrix.cpp -o CMakeFiles\Matrix.dir\Matrix.cpp.s

CMakeFiles/Matrix.dir/file_reader.cpp.obj: CMakeFiles/Matrix.dir/flags.make
CMakeFiles/Matrix.dir/file_reader.cpp.obj: F:/Matrix/file_reader.cpp
CMakeFiles/Matrix.dir/file_reader.cpp.obj: CMakeFiles/Matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Matrix\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Matrix.dir/file_reader.cpp.obj"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Matrix.dir/file_reader.cpp.obj -MF CMakeFiles\Matrix.dir\file_reader.cpp.obj.d -o CMakeFiles\Matrix.dir\file_reader.cpp.obj -c F:\Matrix\file_reader.cpp

CMakeFiles/Matrix.dir/file_reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Matrix.dir/file_reader.cpp.i"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Matrix\file_reader.cpp > CMakeFiles\Matrix.dir\file_reader.cpp.i

CMakeFiles/Matrix.dir/file_reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Matrix.dir/file_reader.cpp.s"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Matrix\file_reader.cpp -o CMakeFiles\Matrix.dir\file_reader.cpp.s

CMakeFiles/Matrix.dir/file_writer.cpp.obj: CMakeFiles/Matrix.dir/flags.make
CMakeFiles/Matrix.dir/file_writer.cpp.obj: F:/Matrix/file_writer.cpp
CMakeFiles/Matrix.dir/file_writer.cpp.obj: CMakeFiles/Matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Matrix\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Matrix.dir/file_writer.cpp.obj"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Matrix.dir/file_writer.cpp.obj -MF CMakeFiles\Matrix.dir\file_writer.cpp.obj.d -o CMakeFiles\Matrix.dir\file_writer.cpp.obj -c F:\Matrix\file_writer.cpp

CMakeFiles/Matrix.dir/file_writer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Matrix.dir/file_writer.cpp.i"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Matrix\file_writer.cpp > CMakeFiles\Matrix.dir\file_writer.cpp.i

CMakeFiles/Matrix.dir/file_writer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Matrix.dir/file_writer.cpp.s"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Matrix\file_writer.cpp -o CMakeFiles\Matrix.dir\file_writer.cpp.s

CMakeFiles/Matrix.dir/gaussian_elimination.cpp.obj: CMakeFiles/Matrix.dir/flags.make
CMakeFiles/Matrix.dir/gaussian_elimination.cpp.obj: F:/Matrix/gaussian_elimination.cpp
CMakeFiles/Matrix.dir/gaussian_elimination.cpp.obj: CMakeFiles/Matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Matrix\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Matrix.dir/gaussian_elimination.cpp.obj"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Matrix.dir/gaussian_elimination.cpp.obj -MF CMakeFiles\Matrix.dir\gaussian_elimination.cpp.obj.d -o CMakeFiles\Matrix.dir\gaussian_elimination.cpp.obj -c F:\Matrix\gaussian_elimination.cpp

CMakeFiles/Matrix.dir/gaussian_elimination.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Matrix.dir/gaussian_elimination.cpp.i"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Matrix\gaussian_elimination.cpp > CMakeFiles\Matrix.dir\gaussian_elimination.cpp.i

CMakeFiles/Matrix.dir/gaussian_elimination.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Matrix.dir/gaussian_elimination.cpp.s"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Matrix\gaussian_elimination.cpp -o CMakeFiles\Matrix.dir\gaussian_elimination.cpp.s

CMakeFiles/Matrix.dir/utility.cpp.obj: CMakeFiles/Matrix.dir/flags.make
CMakeFiles/Matrix.dir/utility.cpp.obj: F:/Matrix/utility.cpp
CMakeFiles/Matrix.dir/utility.cpp.obj: CMakeFiles/Matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Matrix\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Matrix.dir/utility.cpp.obj"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Matrix.dir/utility.cpp.obj -MF CMakeFiles\Matrix.dir\utility.cpp.obj.d -o CMakeFiles\Matrix.dir\utility.cpp.obj -c F:\Matrix\utility.cpp

CMakeFiles/Matrix.dir/utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Matrix.dir/utility.cpp.i"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Matrix\utility.cpp > CMakeFiles\Matrix.dir\utility.cpp.i

CMakeFiles/Matrix.dir/utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Matrix.dir/utility.cpp.s"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Matrix\utility.cpp -o CMakeFiles\Matrix.dir\utility.cpp.s

CMakeFiles/Matrix.dir/rational.cpp.obj: CMakeFiles/Matrix.dir/flags.make
CMakeFiles/Matrix.dir/rational.cpp.obj: F:/Matrix/rational.cpp
CMakeFiles/Matrix.dir/rational.cpp.obj: CMakeFiles/Matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Matrix\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Matrix.dir/rational.cpp.obj"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Matrix.dir/rational.cpp.obj -MF CMakeFiles\Matrix.dir\rational.cpp.obj.d -o CMakeFiles\Matrix.dir\rational.cpp.obj -c F:\Matrix\rational.cpp

CMakeFiles/Matrix.dir/rational.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Matrix.dir/rational.cpp.i"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Matrix\rational.cpp > CMakeFiles\Matrix.dir\rational.cpp.i

CMakeFiles/Matrix.dir/rational.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Matrix.dir/rational.cpp.s"
	"F:\CLion\CLion 2022.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Matrix\rational.cpp -o CMakeFiles\Matrix.dir\rational.cpp.s

# Object files for target Matrix
Matrix_OBJECTS = \
"CMakeFiles/Matrix.dir/main.cpp.obj" \
"CMakeFiles/Matrix.dir/Matrix.cpp.obj" \
"CMakeFiles/Matrix.dir/file_reader.cpp.obj" \
"CMakeFiles/Matrix.dir/file_writer.cpp.obj" \
"CMakeFiles/Matrix.dir/gaussian_elimination.cpp.obj" \
"CMakeFiles/Matrix.dir/utility.cpp.obj" \
"CMakeFiles/Matrix.dir/rational.cpp.obj"

# External object files for target Matrix
Matrix_EXTERNAL_OBJECTS =

Matrix.exe: CMakeFiles/Matrix.dir/main.cpp.obj
Matrix.exe: CMakeFiles/Matrix.dir/Matrix.cpp.obj
Matrix.exe: CMakeFiles/Matrix.dir/file_reader.cpp.obj
Matrix.exe: CMakeFiles/Matrix.dir/file_writer.cpp.obj
Matrix.exe: CMakeFiles/Matrix.dir/gaussian_elimination.cpp.obj
Matrix.exe: CMakeFiles/Matrix.dir/utility.cpp.obj
Matrix.exe: CMakeFiles/Matrix.dir/rational.cpp.obj
Matrix.exe: CMakeFiles/Matrix.dir/build.make
Matrix.exe: CMakeFiles/Matrix.dir/linklibs.rsp
Matrix.exe: CMakeFiles/Matrix.dir/objects1.rsp
Matrix.exe: CMakeFiles/Matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Matrix\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Matrix.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Matrix.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Matrix.dir/build: Matrix.exe
.PHONY : CMakeFiles/Matrix.dir/build

CMakeFiles/Matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Matrix.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Matrix.dir/clean

CMakeFiles/Matrix.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Matrix F:\Matrix F:\Matrix\cmake-build-release F:\Matrix\cmake-build-release F:\Matrix\cmake-build-release\CMakeFiles\Matrix.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Matrix.dir/depend

