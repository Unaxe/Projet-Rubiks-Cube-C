# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\pmher\Documents\GitHub\projet_C\ProjetC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pmher\Documents\GitHub\projet_C\ProjetC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjetC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjetC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjetC.dir/flags.make

CMakeFiles/ProjetC.dir/main.c.obj: CMakeFiles/ProjetC.dir/flags.make
CMakeFiles/ProjetC.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pmher\Documents\GitHub\projet_C\ProjetC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ProjetC.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjetC.dir\main.c.obj   -c C:\Users\pmher\Documents\GitHub\projet_C\ProjetC\main.c

CMakeFiles/ProjetC.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetC.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pmher\Documents\GitHub\projet_C\ProjetC\main.c > CMakeFiles\ProjetC.dir\main.c.i

CMakeFiles/ProjetC.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetC.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pmher\Documents\GitHub\projet_C\ProjetC\main.c -o CMakeFiles\ProjetC.dir\main.c.s

# Object files for target ProjetC
ProjetC_OBJECTS = \
"CMakeFiles/ProjetC.dir/main.c.obj"

# External object files for target ProjetC
ProjetC_EXTERNAL_OBJECTS =

ProjetC.exe: CMakeFiles/ProjetC.dir/main.c.obj
ProjetC.exe: CMakeFiles/ProjetC.dir/build.make
ProjetC.exe: CMakeFiles/ProjetC.dir/linklibs.rsp
ProjetC.exe: CMakeFiles/ProjetC.dir/objects1.rsp
ProjetC.exe: CMakeFiles/ProjetC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\pmher\Documents\GitHub\projet_C\ProjetC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ProjetC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ProjetC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjetC.dir/build: ProjetC.exe

.PHONY : CMakeFiles/ProjetC.dir/build

CMakeFiles/ProjetC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ProjetC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ProjetC.dir/clean

CMakeFiles/ProjetC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\pmher\Documents\GitHub\projet_C\ProjetC C:\Users\pmher\Documents\GitHub\projet_C\ProjetC C:\Users\pmher\Documents\GitHub\projet_C\ProjetC\cmake-build-debug C:\Users\pmher\Documents\GitHub\projet_C\ProjetC\cmake-build-debug C:\Users\pmher\Documents\GitHub\projet_C\ProjetC\cmake-build-debug\CMakeFiles\ProjetC.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjetC.dir/depend
