# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anand/git/ObservableCache

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anand/git/ObservableCache

# Include any dependencies generated for this target.
include CMakeFiles/ObservableCache.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ObservableCache.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ObservableCache.dir/flags.make

CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o: CMakeFiles/ObservableCache.dir/flags.make
CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o: ObservableCache.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anand/git/ObservableCache/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o -c /home/anand/git/ObservableCache/ObservableCache.cpp

CMakeFiles/ObservableCache.dir/ObservableCache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ObservableCache.dir/ObservableCache.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anand/git/ObservableCache/ObservableCache.cpp > CMakeFiles/ObservableCache.dir/ObservableCache.cpp.i

CMakeFiles/ObservableCache.dir/ObservableCache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ObservableCache.dir/ObservableCache.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anand/git/ObservableCache/ObservableCache.cpp -o CMakeFiles/ObservableCache.dir/ObservableCache.cpp.s

CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o.requires:

.PHONY : CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o.requires

CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o.provides: CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o.requires
	$(MAKE) -f CMakeFiles/ObservableCache.dir/build.make CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o.provides.build
.PHONY : CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o.provides

CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o.provides.build: CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o


CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o: CMakeFiles/ObservableCache.dir/flags.make
CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o: ThreadSafeCache.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anand/git/ObservableCache/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o -c /home/anand/git/ObservableCache/ThreadSafeCache.cpp

CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anand/git/ObservableCache/ThreadSafeCache.cpp > CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.i

CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anand/git/ObservableCache/ThreadSafeCache.cpp -o CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.s

CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o.requires:

.PHONY : CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o.requires

CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o.provides: CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o.requires
	$(MAKE) -f CMakeFiles/ObservableCache.dir/build.make CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o.provides.build
.PHONY : CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o.provides

CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o.provides.build: CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o


# Object files for target ObservableCache
ObservableCache_OBJECTS = \
"CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o" \
"CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o"

# External object files for target ObservableCache
ObservableCache_EXTERNAL_OBJECTS =

libObservableCache.so: CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o
libObservableCache.so: CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o
libObservableCache.so: CMakeFiles/ObservableCache.dir/build.make
libObservableCache.so: CMakeFiles/ObservableCache.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anand/git/ObservableCache/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libObservableCache.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ObservableCache.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ObservableCache.dir/build: libObservableCache.so

.PHONY : CMakeFiles/ObservableCache.dir/build

CMakeFiles/ObservableCache.dir/requires: CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o.requires
CMakeFiles/ObservableCache.dir/requires: CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o.requires

.PHONY : CMakeFiles/ObservableCache.dir/requires

CMakeFiles/ObservableCache.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ObservableCache.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ObservableCache.dir/clean

CMakeFiles/ObservableCache.dir/depend:
	cd /home/anand/git/ObservableCache && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anand/git/ObservableCache /home/anand/git/ObservableCache /home/anand/git/ObservableCache /home/anand/git/ObservableCache /home/anand/git/ObservableCache/CMakeFiles/ObservableCache.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ObservableCache.dir/depend

