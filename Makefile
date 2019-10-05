# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /home/edavis/Apps/clion-2018.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/edavis/Apps/clion-2018.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/edavis/Work/proto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/edavis/Work/proto

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/home/edavis/Apps/clion-2018.1.2/bin/cmake/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/home/edavis/Apps/clion-2018.1.2/bin/cmake/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/edavis/Work/proto/CMakeFiles /home/edavis/Work/proto/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/edavis/Work/proto/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named multigrid

# Build rule for target.
multigrid: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 multigrid
.PHONY : multigrid

# fast build rule for target.
multigrid/fast:
	$(MAKE) -f CMakeFiles/multigrid.dir/build.make CMakeFiles/multigrid.dir/build
.PHONY : multigrid/fast

#=============================================================================
# Target rules for targets named euler

# Build rule for target.
euler: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 euler
.PHONY : euler

# fast build rule for target.
euler/fast:
	$(MAKE) -f CMakeFiles/euler.dir/build.make CMakeFiles/euler.dir/build
.PHONY : euler/fast

examples/Euler/exec/Euler.o: examples/Euler/exec/Euler.cpp.o

.PHONY : examples/Euler/exec/Euler.o

# target to build an object file
examples/Euler/exec/Euler.cpp.o:
	$(MAKE) -f CMakeFiles/euler.dir/build.make CMakeFiles/euler.dir/examples/Euler/exec/Euler.cpp.o
.PHONY : examples/Euler/exec/Euler.cpp.o

examples/Euler/exec/Euler.i: examples/Euler/exec/Euler.cpp.i

.PHONY : examples/Euler/exec/Euler.i

# target to preprocess a source file
examples/Euler/exec/Euler.cpp.i:
	$(MAKE) -f CMakeFiles/euler.dir/build.make CMakeFiles/euler.dir/examples/Euler/exec/Euler.cpp.i
.PHONY : examples/Euler/exec/Euler.cpp.i

examples/Euler/exec/Euler.s: examples/Euler/exec/Euler.cpp.s

.PHONY : examples/Euler/exec/Euler.s

# target to generate assembly for a file
examples/Euler/exec/Euler.cpp.s:
	$(MAKE) -f CMakeFiles/euler.dir/build.make CMakeFiles/euler.dir/examples/Euler/exec/Euler.cpp.s
.PHONY : examples/Euler/exec/Euler.cpp.s

examples/Euler/src/EulerOp.o: examples/Euler/src/EulerOp.cpp.o

.PHONY : examples/Euler/src/EulerOp.o

# target to build an object file
examples/Euler/src/EulerOp.cpp.o:
	$(MAKE) -f CMakeFiles/euler.dir/build.make CMakeFiles/euler.dir/examples/Euler/src/EulerOp.cpp.o
.PHONY : examples/Euler/src/EulerOp.cpp.o

examples/Euler/src/EulerOp.i: examples/Euler/src/EulerOp.cpp.i

.PHONY : examples/Euler/src/EulerOp.i

# target to preprocess a source file
examples/Euler/src/EulerOp.cpp.i:
	$(MAKE) -f CMakeFiles/euler.dir/build.make CMakeFiles/euler.dir/examples/Euler/src/EulerOp.cpp.i
.PHONY : examples/Euler/src/EulerOp.cpp.i

examples/Euler/src/EulerOp.s: examples/Euler/src/EulerOp.cpp.s

.PHONY : examples/Euler/src/EulerOp.s

# target to generate assembly for a file
examples/Euler/src/EulerOp.cpp.s:
	$(MAKE) -f CMakeFiles/euler.dir/build.make CMakeFiles/euler.dir/examples/Euler/src/EulerOp.cpp.s
.PHONY : examples/Euler/src/EulerOp.cpp.s

examples/Euler/src/EulerRK4.o: examples/Euler/src/EulerRK4.cpp.o

.PHONY : examples/Euler/src/EulerRK4.o

# target to build an object file
examples/Euler/src/EulerRK4.cpp.o:
	$(MAKE) -f CMakeFiles/euler.dir/build.make CMakeFiles/euler.dir/examples/Euler/src/EulerRK4.cpp.o
.PHONY : examples/Euler/src/EulerRK4.cpp.o

examples/Euler/src/EulerRK4.i: examples/Euler/src/EulerRK4.cpp.i

.PHONY : examples/Euler/src/EulerRK4.i

# target to preprocess a source file
examples/Euler/src/EulerRK4.cpp.i:
	$(MAKE) -f CMakeFiles/euler.dir/build.make CMakeFiles/euler.dir/examples/Euler/src/EulerRK4.cpp.i
.PHONY : examples/Euler/src/EulerRK4.cpp.i

examples/Euler/src/EulerRK4.s: examples/Euler/src/EulerRK4.cpp.s

.PHONY : examples/Euler/src/EulerRK4.s

# target to generate assembly for a file
examples/Euler/src/EulerRK4.cpp.s:
	$(MAKE) -f CMakeFiles/euler.dir/build.make CMakeFiles/euler.dir/examples/Euler/src/EulerRK4.cpp.s
.PHONY : examples/Euler/src/EulerRK4.cpp.s

examples/Multigrid/exec/Multigrid.o: examples/Multigrid/exec/Multigrid.cpp.o

.PHONY : examples/Multigrid/exec/Multigrid.o

# target to build an object file
examples/Multigrid/exec/Multigrid.cpp.o:
	$(MAKE) -f CMakeFiles/multigrid.dir/build.make CMakeFiles/multigrid.dir/examples/Multigrid/exec/Multigrid.cpp.o
.PHONY : examples/Multigrid/exec/Multigrid.cpp.o

examples/Multigrid/exec/Multigrid.i: examples/Multigrid/exec/Multigrid.cpp.i

.PHONY : examples/Multigrid/exec/Multigrid.i

# target to preprocess a source file
examples/Multigrid/exec/Multigrid.cpp.i:
	$(MAKE) -f CMakeFiles/multigrid.dir/build.make CMakeFiles/multigrid.dir/examples/Multigrid/exec/Multigrid.cpp.i
.PHONY : examples/Multigrid/exec/Multigrid.cpp.i

examples/Multigrid/exec/Multigrid.s: examples/Multigrid/exec/Multigrid.cpp.s

.PHONY : examples/Multigrid/exec/Multigrid.s

# target to generate assembly for a file
examples/Multigrid/exec/Multigrid.cpp.s:
	$(MAKE) -f CMakeFiles/multigrid.dir/build.make CMakeFiles/multigrid.dir/examples/Multigrid/exec/Multigrid.cpp.s
.PHONY : examples/Multigrid/exec/Multigrid.cpp.s

examples/common/SGMultigrid.o: examples/common/SGMultigrid.cpp.o

.PHONY : examples/common/SGMultigrid.o

# target to build an object file
examples/common/SGMultigrid.cpp.o:
	$(MAKE) -f CMakeFiles/multigrid.dir/build.make CMakeFiles/multigrid.dir/examples/common/SGMultigrid.cpp.o
.PHONY : examples/common/SGMultigrid.cpp.o

examples/common/SGMultigrid.i: examples/common/SGMultigrid.cpp.i

.PHONY : examples/common/SGMultigrid.i

# target to preprocess a source file
examples/common/SGMultigrid.cpp.i:
	$(MAKE) -f CMakeFiles/multigrid.dir/build.make CMakeFiles/multigrid.dir/examples/common/SGMultigrid.cpp.i
.PHONY : examples/common/SGMultigrid.cpp.i

examples/common/SGMultigrid.s: examples/common/SGMultigrid.cpp.s

.PHONY : examples/common/SGMultigrid.s

# target to generate assembly for a file
examples/common/SGMultigrid.cpp.s:
	$(MAKE) -f CMakeFiles/multigrid.dir/build.make CMakeFiles/multigrid.dir/examples/common/SGMultigrid.cpp.s
.PHONY : examples/common/SGMultigrid.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... multigrid"
	@echo "... euler"
	@echo "... examples/Euler/exec/Euler.o"
	@echo "... examples/Euler/exec/Euler.i"
	@echo "... examples/Euler/exec/Euler.s"
	@echo "... examples/Euler/src/EulerOp.o"
	@echo "... examples/Euler/src/EulerOp.i"
	@echo "... examples/Euler/src/EulerOp.s"
	@echo "... examples/Euler/src/EulerRK4.o"
	@echo "... examples/Euler/src/EulerRK4.i"
	@echo "... examples/Euler/src/EulerRK4.s"
	@echo "... examples/Multigrid/exec/Multigrid.o"
	@echo "... examples/Multigrid/exec/Multigrid.i"
	@echo "... examples/Multigrid/exec/Multigrid.s"
	@echo "... examples/common/SGMultigrid.o"
	@echo "... examples/common/SGMultigrid.i"
	@echo "... examples/common/SGMultigrid.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

