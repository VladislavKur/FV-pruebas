# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/fv/Desktop/FV-pruebas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fv/Desktop/FV-pruebas/build

# Include any dependencies generated for this target.
include CMakeFiles/murcielago.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/murcielago.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/murcielago.dir/flags.make

CMakeFiles/murcielago.dir/enemMurcielago.cpp.o: CMakeFiles/murcielago.dir/flags.make
CMakeFiles/murcielago.dir/enemMurcielago.cpp.o: ../enemMurcielago.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fv/Desktop/FV-pruebas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/murcielago.dir/enemMurcielago.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/murcielago.dir/enemMurcielago.cpp.o -c /home/fv/Desktop/FV-pruebas/enemMurcielago.cpp

CMakeFiles/murcielago.dir/enemMurcielago.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/murcielago.dir/enemMurcielago.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fv/Desktop/FV-pruebas/enemMurcielago.cpp > CMakeFiles/murcielago.dir/enemMurcielago.cpp.i

CMakeFiles/murcielago.dir/enemMurcielago.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/murcielago.dir/enemMurcielago.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fv/Desktop/FV-pruebas/enemMurcielago.cpp -o CMakeFiles/murcielago.dir/enemMurcielago.cpp.s

CMakeFiles/murcielago.dir/enemMurcielago.cpp.o.requires:

.PHONY : CMakeFiles/murcielago.dir/enemMurcielago.cpp.o.requires

CMakeFiles/murcielago.dir/enemMurcielago.cpp.o.provides: CMakeFiles/murcielago.dir/enemMurcielago.cpp.o.requires
	$(MAKE) -f CMakeFiles/murcielago.dir/build.make CMakeFiles/murcielago.dir/enemMurcielago.cpp.o.provides.build
.PHONY : CMakeFiles/murcielago.dir/enemMurcielago.cpp.o.provides

CMakeFiles/murcielago.dir/enemMurcielago.cpp.o.provides.build: CMakeFiles/murcielago.dir/enemMurcielago.cpp.o


# Object files for target murcielago
murcielago_OBJECTS = \
"CMakeFiles/murcielago.dir/enemMurcielago.cpp.o"

# External object files for target murcielago
murcielago_EXTERNAL_OBJECTS =

murcielago: CMakeFiles/murcielago.dir/enemMurcielago.cpp.o
murcielago: CMakeFiles/murcielago.dir/build.make
murcielago: liblibClases.a
murcielago: /usr/lib/x86_64-linux-gnu/libsfml-system.so
murcielago: /usr/lib/x86_64-linux-gnu/libsfml-window.so
murcielago: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
murcielago: /usr/lib/x86_64-linux-gnu/libsfml-network.so
murcielago: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
murcielago: CMakeFiles/murcielago.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fv/Desktop/FV-pruebas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable murcielago"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/murcielago.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/murcielago.dir/build: murcielago

.PHONY : CMakeFiles/murcielago.dir/build

CMakeFiles/murcielago.dir/requires: CMakeFiles/murcielago.dir/enemMurcielago.cpp.o.requires

.PHONY : CMakeFiles/murcielago.dir/requires

CMakeFiles/murcielago.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/murcielago.dir/cmake_clean.cmake
.PHONY : CMakeFiles/murcielago.dir/clean

CMakeFiles/murcielago.dir/depend:
	cd /home/fv/Desktop/FV-pruebas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fv/Desktop/FV-pruebas /home/fv/Desktop/FV-pruebas /home/fv/Desktop/FV-pruebas/build /home/fv/Desktop/FV-pruebas/build /home/fv/Desktop/FV-pruebas/build/CMakeFiles/murcielago.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/murcielago.dir/depend

