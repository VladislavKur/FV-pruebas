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
CMAKE_SOURCE_DIR = /home/magiic/Escritorio/ranjamp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/magiic/Escritorio/ranjamp/build

# Include any dependencies generated for this target.
include CMakeFiles/recoger.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/recoger.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/recoger.dir/flags.make

CMakeFiles/recoger.dir/recoger.cpp.o: CMakeFiles/recoger.dir/flags.make
CMakeFiles/recoger.dir/recoger.cpp.o: ../recoger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/magiic/Escritorio/ranjamp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/recoger.dir/recoger.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/recoger.dir/recoger.cpp.o -c /home/magiic/Escritorio/ranjamp/recoger.cpp

CMakeFiles/recoger.dir/recoger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/recoger.dir/recoger.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/magiic/Escritorio/ranjamp/recoger.cpp > CMakeFiles/recoger.dir/recoger.cpp.i

CMakeFiles/recoger.dir/recoger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/recoger.dir/recoger.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/magiic/Escritorio/ranjamp/recoger.cpp -o CMakeFiles/recoger.dir/recoger.cpp.s

CMakeFiles/recoger.dir/recoger.cpp.o.requires:

.PHONY : CMakeFiles/recoger.dir/recoger.cpp.o.requires

CMakeFiles/recoger.dir/recoger.cpp.o.provides: CMakeFiles/recoger.dir/recoger.cpp.o.requires
	$(MAKE) -f CMakeFiles/recoger.dir/build.make CMakeFiles/recoger.dir/recoger.cpp.o.provides.build
.PHONY : CMakeFiles/recoger.dir/recoger.cpp.o.provides

CMakeFiles/recoger.dir/recoger.cpp.o.provides.build: CMakeFiles/recoger.dir/recoger.cpp.o


# Object files for target recoger
recoger_OBJECTS = \
"CMakeFiles/recoger.dir/recoger.cpp.o"

# External object files for target recoger
recoger_EXTERNAL_OBJECTS =

recoger: CMakeFiles/recoger.dir/recoger.cpp.o
recoger: CMakeFiles/recoger.dir/build.make
recoger: /usr/lib/x86_64-linux-gnu/libsfml-system.so
recoger: /usr/lib/x86_64-linux-gnu/libsfml-window.so
recoger: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
recoger: /usr/lib/x86_64-linux-gnu/libsfml-network.so
recoger: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
recoger: CMakeFiles/recoger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/magiic/Escritorio/ranjamp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable recoger"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/recoger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/recoger.dir/build: recoger

.PHONY : CMakeFiles/recoger.dir/build

CMakeFiles/recoger.dir/requires: CMakeFiles/recoger.dir/recoger.cpp.o.requires

.PHONY : CMakeFiles/recoger.dir/requires

CMakeFiles/recoger.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/recoger.dir/cmake_clean.cmake
.PHONY : CMakeFiles/recoger.dir/clean

CMakeFiles/recoger.dir/depend:
	cd /home/magiic/Escritorio/ranjamp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/magiic/Escritorio/ranjamp /home/magiic/Escritorio/ranjamp /home/magiic/Escritorio/ranjamp/build /home/magiic/Escritorio/ranjamp/build /home/magiic/Escritorio/ranjamp/build/CMakeFiles/recoger.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/recoger.dir/depend

