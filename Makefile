# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anand/git/ObservableCache

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anand/git/ObservableCache

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/anand/git/ObservableCache/CMakeFiles /home/anand/git/ObservableCache/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/anand/git/ObservableCache/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named examples/Example5.out

# Build rule for target.
examples/Example5.out: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 examples/Example5.out
.PHONY : examples/Example5.out

# fast build rule for target.
examples/Example5.out/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example5.out.dir/build.make CMakeFiles/examples/Example5.out.dir/build
.PHONY : examples/Example5.out/fast

#=============================================================================
# Target rules for targets named examples/Example7.out

# Build rule for target.
examples/Example7.out: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 examples/Example7.out
.PHONY : examples/Example7.out

# fast build rule for target.
examples/Example7.out/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example7.out.dir/build.make CMakeFiles/examples/Example7.out.dir/build
.PHONY : examples/Example7.out/fast

#=============================================================================
# Target rules for targets named examples/Example1.out

# Build rule for target.
examples/Example1.out: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 examples/Example1.out
.PHONY : examples/Example1.out

# fast build rule for target.
examples/Example1.out/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example1.out.dir/build.make CMakeFiles/examples/Example1.out.dir/build
.PHONY : examples/Example1.out/fast

#=============================================================================
# Target rules for targets named examples/Example6.out

# Build rule for target.
examples/Example6.out: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 examples/Example6.out
.PHONY : examples/Example6.out

# fast build rule for target.
examples/Example6.out/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example6.out.dir/build.make CMakeFiles/examples/Example6.out.dir/build
.PHONY : examples/Example6.out/fast

#=============================================================================
# Target rules for targets named ObservableCache

# Build rule for target.
ObservableCache: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 ObservableCache
.PHONY : ObservableCache

# fast build rule for target.
ObservableCache/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ObservableCache.dir/build.make CMakeFiles/ObservableCache.dir/build
.PHONY : ObservableCache/fast

#=============================================================================
# Target rules for targets named examples/Example2.out

# Build rule for target.
examples/Example2.out: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 examples/Example2.out
.PHONY : examples/Example2.out

# fast build rule for target.
examples/Example2.out/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example2.out.dir/build.make CMakeFiles/examples/Example2.out.dir/build
.PHONY : examples/Example2.out/fast

#=============================================================================
# Target rules for targets named examples/Example3.out

# Build rule for target.
examples/Example3.out: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 examples/Example3.out
.PHONY : examples/Example3.out

# fast build rule for target.
examples/Example3.out/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example3.out.dir/build.make CMakeFiles/examples/Example3.out.dir/build
.PHONY : examples/Example3.out/fast

#=============================================================================
# Target rules for targets named examples/Example4.out

# Build rule for target.
examples/Example4.out: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 examples/Example4.out
.PHONY : examples/Example4.out

# fast build rule for target.
examples/Example4.out/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example4.out.dir/build.make CMakeFiles/examples/Example4.out.dir/build
.PHONY : examples/Example4.out/fast

ObservableCache.o: ObservableCache.cpp.o

.PHONY : ObservableCache.o

# target to build an object file
ObservableCache.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ObservableCache.dir/build.make CMakeFiles/ObservableCache.dir/ObservableCache.cpp.o
.PHONY : ObservableCache.cpp.o

ObservableCache.i: ObservableCache.cpp.i

.PHONY : ObservableCache.i

# target to preprocess a source file
ObservableCache.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ObservableCache.dir/build.make CMakeFiles/ObservableCache.dir/ObservableCache.cpp.i
.PHONY : ObservableCache.cpp.i

ObservableCache.s: ObservableCache.cpp.s

.PHONY : ObservableCache.s

# target to generate assembly for a file
ObservableCache.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ObservableCache.dir/build.make CMakeFiles/ObservableCache.dir/ObservableCache.cpp.s
.PHONY : ObservableCache.cpp.s

ThreadSafeCache.o: ThreadSafeCache.cpp.o

.PHONY : ThreadSafeCache.o

# target to build an object file
ThreadSafeCache.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ObservableCache.dir/build.make CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.o
.PHONY : ThreadSafeCache.cpp.o

ThreadSafeCache.i: ThreadSafeCache.cpp.i

.PHONY : ThreadSafeCache.i

# target to preprocess a source file
ThreadSafeCache.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ObservableCache.dir/build.make CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.i
.PHONY : ThreadSafeCache.cpp.i

ThreadSafeCache.s: ThreadSafeCache.cpp.s

.PHONY : ThreadSafeCache.s

# target to generate assembly for a file
ThreadSafeCache.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ObservableCache.dir/build.make CMakeFiles/ObservableCache.dir/ThreadSafeCache.cpp.s
.PHONY : ThreadSafeCache.cpp.s

examples/Example1.o: examples/Example1.cpp.o

.PHONY : examples/Example1.o

# target to build an object file
examples/Example1.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example1.out.dir/build.make CMakeFiles/examples/Example1.out.dir/examples/Example1.cpp.o
.PHONY : examples/Example1.cpp.o

examples/Example1.i: examples/Example1.cpp.i

.PHONY : examples/Example1.i

# target to preprocess a source file
examples/Example1.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example1.out.dir/build.make CMakeFiles/examples/Example1.out.dir/examples/Example1.cpp.i
.PHONY : examples/Example1.cpp.i

examples/Example1.s: examples/Example1.cpp.s

.PHONY : examples/Example1.s

# target to generate assembly for a file
examples/Example1.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example1.out.dir/build.make CMakeFiles/examples/Example1.out.dir/examples/Example1.cpp.s
.PHONY : examples/Example1.cpp.s

examples/Example2.o: examples/Example2.cpp.o

.PHONY : examples/Example2.o

# target to build an object file
examples/Example2.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example2.out.dir/build.make CMakeFiles/examples/Example2.out.dir/examples/Example2.cpp.o
.PHONY : examples/Example2.cpp.o

examples/Example2.i: examples/Example2.cpp.i

.PHONY : examples/Example2.i

# target to preprocess a source file
examples/Example2.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example2.out.dir/build.make CMakeFiles/examples/Example2.out.dir/examples/Example2.cpp.i
.PHONY : examples/Example2.cpp.i

examples/Example2.s: examples/Example2.cpp.s

.PHONY : examples/Example2.s

# target to generate assembly for a file
examples/Example2.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example2.out.dir/build.make CMakeFiles/examples/Example2.out.dir/examples/Example2.cpp.s
.PHONY : examples/Example2.cpp.s

examples/Example3.o: examples/Example3.cpp.o

.PHONY : examples/Example3.o

# target to build an object file
examples/Example3.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example3.out.dir/build.make CMakeFiles/examples/Example3.out.dir/examples/Example3.cpp.o
.PHONY : examples/Example3.cpp.o

examples/Example3.i: examples/Example3.cpp.i

.PHONY : examples/Example3.i

# target to preprocess a source file
examples/Example3.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example3.out.dir/build.make CMakeFiles/examples/Example3.out.dir/examples/Example3.cpp.i
.PHONY : examples/Example3.cpp.i

examples/Example3.s: examples/Example3.cpp.s

.PHONY : examples/Example3.s

# target to generate assembly for a file
examples/Example3.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example3.out.dir/build.make CMakeFiles/examples/Example3.out.dir/examples/Example3.cpp.s
.PHONY : examples/Example3.cpp.s

examples/Example4.o: examples/Example4.cpp.o

.PHONY : examples/Example4.o

# target to build an object file
examples/Example4.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example4.out.dir/build.make CMakeFiles/examples/Example4.out.dir/examples/Example4.cpp.o
.PHONY : examples/Example4.cpp.o

examples/Example4.i: examples/Example4.cpp.i

.PHONY : examples/Example4.i

# target to preprocess a source file
examples/Example4.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example4.out.dir/build.make CMakeFiles/examples/Example4.out.dir/examples/Example4.cpp.i
.PHONY : examples/Example4.cpp.i

examples/Example4.s: examples/Example4.cpp.s

.PHONY : examples/Example4.s

# target to generate assembly for a file
examples/Example4.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example4.out.dir/build.make CMakeFiles/examples/Example4.out.dir/examples/Example4.cpp.s
.PHONY : examples/Example4.cpp.s

examples/Example5.o: examples/Example5.cpp.o

.PHONY : examples/Example5.o

# target to build an object file
examples/Example5.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example5.out.dir/build.make CMakeFiles/examples/Example5.out.dir/examples/Example5.cpp.o
.PHONY : examples/Example5.cpp.o

examples/Example5.i: examples/Example5.cpp.i

.PHONY : examples/Example5.i

# target to preprocess a source file
examples/Example5.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example5.out.dir/build.make CMakeFiles/examples/Example5.out.dir/examples/Example5.cpp.i
.PHONY : examples/Example5.cpp.i

examples/Example5.s: examples/Example5.cpp.s

.PHONY : examples/Example5.s

# target to generate assembly for a file
examples/Example5.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example5.out.dir/build.make CMakeFiles/examples/Example5.out.dir/examples/Example5.cpp.s
.PHONY : examples/Example5.cpp.s

examples/Example6.o: examples/Example6.cpp.o

.PHONY : examples/Example6.o

# target to build an object file
examples/Example6.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example6.out.dir/build.make CMakeFiles/examples/Example6.out.dir/examples/Example6.cpp.o
.PHONY : examples/Example6.cpp.o

examples/Example6.i: examples/Example6.cpp.i

.PHONY : examples/Example6.i

# target to preprocess a source file
examples/Example6.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example6.out.dir/build.make CMakeFiles/examples/Example6.out.dir/examples/Example6.cpp.i
.PHONY : examples/Example6.cpp.i

examples/Example6.s: examples/Example6.cpp.s

.PHONY : examples/Example6.s

# target to generate assembly for a file
examples/Example6.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example6.out.dir/build.make CMakeFiles/examples/Example6.out.dir/examples/Example6.cpp.s
.PHONY : examples/Example6.cpp.s

examples/Example7.o: examples/Example7.cpp.o

.PHONY : examples/Example7.o

# target to build an object file
examples/Example7.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example7.out.dir/build.make CMakeFiles/examples/Example7.out.dir/examples/Example7.cpp.o
.PHONY : examples/Example7.cpp.o

examples/Example7.i: examples/Example7.cpp.i

.PHONY : examples/Example7.i

# target to preprocess a source file
examples/Example7.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example7.out.dir/build.make CMakeFiles/examples/Example7.out.dir/examples/Example7.cpp.i
.PHONY : examples/Example7.cpp.i

examples/Example7.s: examples/Example7.cpp.s

.PHONY : examples/Example7.s

# target to generate assembly for a file
examples/Example7.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/examples/Example7.out.dir/build.make CMakeFiles/examples/Example7.out.dir/examples/Example7.cpp.s
.PHONY : examples/Example7.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... ObservableCache"
	@echo "... examples/Example1.out"
	@echo "... examples/Example2.out"
	@echo "... examples/Example3.out"
	@echo "... examples/Example4.out"
	@echo "... examples/Example5.out"
	@echo "... examples/Example6.out"
	@echo "... examples/Example7.out"
	@echo "... ObservableCache.o"
	@echo "... ObservableCache.i"
	@echo "... ObservableCache.s"
	@echo "... ThreadSafeCache.o"
	@echo "... ThreadSafeCache.i"
	@echo "... ThreadSafeCache.s"
	@echo "... examples/Example1.o"
	@echo "... examples/Example1.i"
	@echo "... examples/Example1.s"
	@echo "... examples/Example2.o"
	@echo "... examples/Example2.i"
	@echo "... examples/Example2.s"
	@echo "... examples/Example3.o"
	@echo "... examples/Example3.i"
	@echo "... examples/Example3.s"
	@echo "... examples/Example4.o"
	@echo "... examples/Example4.i"
	@echo "... examples/Example4.s"
	@echo "... examples/Example5.o"
	@echo "... examples/Example5.i"
	@echo "... examples/Example5.s"
	@echo "... examples/Example6.o"
	@echo "... examples/Example6.i"
	@echo "... examples/Example6.s"
	@echo "... examples/Example7.o"
	@echo "... examples/Example7.i"
	@echo "... examples/Example7.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

