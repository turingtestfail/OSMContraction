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
include CMakeFiles/myrouting_library.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myrouting_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myrouting_library.dir/flags.make

# Object files for target myrouting_library
myrouting_library_OBJECTS =

# External object files for target myrouting_library
myrouting_library_EXTERNAL_OBJECTS = \
"/home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/mydijkstra/src/CMakeFiles/mydijkstra.dir/dijkstra.c.o" \
"/home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/mydijkstra/src/CMakeFiles/mydijkstra.dir/dijkstra_function.cpp.o" \
"/home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o" \
"/home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o" \
"/home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/myastar/src/CMakeFiles/myastar.dir/my_astar.c.o" \
"/home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/myastar/src/CMakeFiles/myastar.dir/my_astar_wrapper.cpp.o" \
"/home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/src/common/src/CMakeFiles/common.dir/connection.c.o"

libmyrouting_library.so: src/mydijkstra/src/CMakeFiles/mydijkstra.dir/dijkstra.c.o
libmyrouting_library.so: src/mydijkstra/src/CMakeFiles/mydijkstra.dir/dijkstra_function.cpp.o
libmyrouting_library.so: src/contraction/src/CMakeFiles/contraction.dir/contraction.c.o
libmyrouting_library.so: src/contraction/src/CMakeFiles/contraction.dir/contract_function.cpp.o
libmyrouting_library.so: src/myastar/src/CMakeFiles/myastar.dir/my_astar.c.o
libmyrouting_library.so: src/myastar/src/CMakeFiles/myastar.dir/my_astar_wrapper.cpp.o
libmyrouting_library.so: src/common/src/CMakeFiles/common.dir/connection.c.o
libmyrouting_library.so: CMakeFiles/myrouting_library.dir/build.make
libmyrouting_library.so: CMakeFiles/myrouting_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libmyrouting_library.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myrouting_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myrouting_library.dir/build: libmyrouting_library.so
.PHONY : CMakeFiles/myrouting_library.dir/build

CMakeFiles/myrouting_library.dir/requires:
.PHONY : CMakeFiles/myrouting_library.dir/requires

CMakeFiles/myrouting_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myrouting_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myrouting_library.dir/clean

CMakeFiles/myrouting_library.dir/depend:
	cd /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build /home/rohith/mystuff/labwork/3-1/codes/OSMContraction/code/build/CMakeFiles/myrouting_library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myrouting_library.dir/depend

