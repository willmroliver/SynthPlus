# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/willoliver/Play/music

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/willoliver/Play/music/build

# Include any dependencies generated for this target.
include CMakeFiles/test_exec.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_exec.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_exec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_exec.dir/flags.make

CMakeFiles/test_exec.dir/test/main.cc.o: CMakeFiles/test_exec.dir/flags.make
CMakeFiles/test_exec.dir/test/main.cc.o: /Users/willoliver/Play/music/test/main.cc
CMakeFiles/test_exec.dir/test/main.cc.o: CMakeFiles/test_exec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/willoliver/Play/music/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_exec.dir/test/main.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_exec.dir/test/main.cc.o -MF CMakeFiles/test_exec.dir/test/main.cc.o.d -o CMakeFiles/test_exec.dir/test/main.cc.o -c /Users/willoliver/Play/music/test/main.cc

CMakeFiles/test_exec.dir/test/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_exec.dir/test/main.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/willoliver/Play/music/test/main.cc > CMakeFiles/test_exec.dir/test/main.cc.i

CMakeFiles/test_exec.dir/test/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_exec.dir/test/main.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/willoliver/Play/music/test/main.cc -o CMakeFiles/test_exec.dir/test/main.cc.s

# Object files for target test_exec
test_exec_OBJECTS = \
"CMakeFiles/test_exec.dir/test/main.cc.o"

# External object files for target test_exec
test_exec_EXTERNAL_OBJECTS =

test_exec: CMakeFiles/test_exec.dir/test/main.cc.o
test_exec: CMakeFiles/test_exec.dir/build.make
test_exec: libMusicPlus.a
test_exec: CMakeFiles/test_exec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/willoliver/Play/music/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_exec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_exec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_exec.dir/build: test_exec
.PHONY : CMakeFiles/test_exec.dir/build

CMakeFiles/test_exec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_exec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_exec.dir/clean

CMakeFiles/test_exec.dir/depend:
	cd /Users/willoliver/Play/music/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/willoliver/Play/music /Users/willoliver/Play/music /Users/willoliver/Play/music/build /Users/willoliver/Play/music/build /Users/willoliver/Play/music/build/CMakeFiles/test_exec.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_exec.dir/depend

