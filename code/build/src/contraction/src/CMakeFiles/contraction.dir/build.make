# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build

# Include any dependencies generated for this target.
include src/contraction/src/CMakeFiles/contraction.dir/depend.make

# Include the progress variables for this target.
include src/contraction/src/CMakeFiles/contraction.dir/progress.make

# Include the compile flags for this target's objects.
include src/contraction/src/CMakeFiles/contraction.dir/flags.make

src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o: src/contraction/src/CMakeFiles/contraction.dir/flags.make
src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o: ../src/contraction/src/contraction.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o"
	cd /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/contraction/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/contraction.dir/contraction.c.o   -c /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/src/contraction/src/contraction.c

src/contraction/src/CMakeFiles/contraction.dir/contraction.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/contraction.dir/contraction.c.i"
	cd /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/contraction/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/src/contraction/src/contraction.c > CMakeFiles/contraction.dir/contraction.c.i

src/contraction/src/CMakeFiles/contraction.dir/contraction.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/contraction.dir/contraction.c.s"
	cd /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/contraction/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/src/contraction/src/contraction.c -o CMakeFiles/contraction.dir/contraction.c.s

src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o.requires:
.PHONY : src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o.requires

src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o.provides: src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o.requires
	$(MAKE) -f src/contraction/src/CMakeFiles/contraction.dir/build.make src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o.provides.build
.PHONY : src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o.provides

src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o.provides.build: src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o

src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o: src/contraction/src/CMakeFiles/contraction.dir/flags.make
src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o: ../src/contraction/src/contract_function.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o"
	cd /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/contraction/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/contraction.dir/contract_function.cpp.o -c /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/src/contraction/src/contract_function.cpp

src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/contraction.dir/contract_function.cpp.i"
	cd /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/contraction/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/src/contraction/src/contract_function.cpp > CMakeFiles/contraction.dir/contract_function.cpp.i

src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/contraction.dir/contract_function.cpp.s"
	cd /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/contraction/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/src/contraction/src/contract_function.cpp -o CMakeFiles/contraction.dir/contract_function.cpp.s

src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o.requires:
.PHONY : src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o.requires

src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o.provides: src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o.requires
	$(MAKE) -f src/contraction/src/CMakeFiles/contraction.dir/build.make src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o.provides.build
.PHONY : src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o.provides

src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o.provides.build: src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o

contraction: src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o
contraction: src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o
contraction: src/contraction/src/CMakeFiles/contraction.dir/build.make
.PHONY : contraction

# Rule to build all files generated by this target.
src/contraction/src/CMakeFiles/contraction.dir/build: contraction
.PHONY : src/contraction/src/CMakeFiles/contraction.dir/build

src/contraction/src/CMakeFiles/contraction.dir/requires: src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o.requires
src/contraction/src/CMakeFiles/contraction.dir/requires: src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o.requires
.PHONY : src/contraction/src/CMakeFiles/contraction.dir/requires

src/contraction/src/CMakeFiles/contraction.dir/clean:
	cd /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/contraction/src && $(CMAKE_COMMAND) -P CMakeFiles/contraction.dir/cmake_clean.cmake
.PHONY : src/contraction/src/CMakeFiles/contraction.dir/clean

src/contraction/src/CMakeFiles/contraction.dir/depend:
	cd /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/src/contraction/src /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/contraction/src /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/contraction/src/CMakeFiles/contraction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/contraction/src/CMakeFiles/contraction.dir/depend

