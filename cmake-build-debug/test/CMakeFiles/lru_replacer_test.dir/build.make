# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/junma/Desktop/15645pj/sqlite-fall2017

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/junma/Desktop/15645pj/sqlite-fall2017/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/lru_replacer_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/lru_replacer_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/lru_replacer_test.dir/flags.make

test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o: test/CMakeFiles/lru_replacer_test.dir/flags.make
test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o: ../test/buffer/lru_replacer_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/junma/Desktop/15645pj/sqlite-fall2017/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o"
	cd /Users/junma/Desktop/15645pj/sqlite-fall2017/cmake-build-debug/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o -c /Users/junma/Desktop/15645pj/sqlite-fall2017/test/buffer/lru_replacer_test.cpp

test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.i"
	cd /Users/junma/Desktop/15645pj/sqlite-fall2017/cmake-build-debug/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/junma/Desktop/15645pj/sqlite-fall2017/test/buffer/lru_replacer_test.cpp > CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.i

test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.s"
	cd /Users/junma/Desktop/15645pj/sqlite-fall2017/cmake-build-debug/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/junma/Desktop/15645pj/sqlite-fall2017/test/buffer/lru_replacer_test.cpp -o CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.s

test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o.requires:

.PHONY : test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o.requires

test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o.provides: test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/lru_replacer_test.dir/build.make test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o.provides.build
.PHONY : test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o.provides

test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o.provides.build: test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o


# Object files for target lru_replacer_test
lru_replacer_test_OBJECTS = \
"CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o"

# External object files for target lru_replacer_test
lru_replacer_test_EXTERNAL_OBJECTS =

test/lru_replacer_test: test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o
test/lru_replacer_test: test/CMakeFiles/lru_replacer_test.dir/build.make
test/lru_replacer_test: lib/libvtable.dylib
test/lru_replacer_test: lib/libsqlite3.dylib
test/lru_replacer_test: lib/libgtest.dylib
test/lru_replacer_test: test/CMakeFiles/lru_replacer_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/junma/Desktop/15645pj/sqlite-fall2017/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lru_replacer_test"
	cd /Users/junma/Desktop/15645pj/sqlite-fall2017/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lru_replacer_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/lru_replacer_test.dir/build: test/lru_replacer_test

.PHONY : test/CMakeFiles/lru_replacer_test.dir/build

test/CMakeFiles/lru_replacer_test.dir/requires: test/CMakeFiles/lru_replacer_test.dir/buffer/lru_replacer_test.cpp.o.requires

.PHONY : test/CMakeFiles/lru_replacer_test.dir/requires

test/CMakeFiles/lru_replacer_test.dir/clean:
	cd /Users/junma/Desktop/15645pj/sqlite-fall2017/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/lru_replacer_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/lru_replacer_test.dir/clean

test/CMakeFiles/lru_replacer_test.dir/depend:
	cd /Users/junma/Desktop/15645pj/sqlite-fall2017/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/junma/Desktop/15645pj/sqlite-fall2017 /Users/junma/Desktop/15645pj/sqlite-fall2017/test /Users/junma/Desktop/15645pj/sqlite-fall2017/cmake-build-debug /Users/junma/Desktop/15645pj/sqlite-fall2017/cmake-build-debug/test /Users/junma/Desktop/15645pj/sqlite-fall2017/cmake-build-debug/test/CMakeFiles/lru_replacer_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/lru_replacer_test.dir/depend

