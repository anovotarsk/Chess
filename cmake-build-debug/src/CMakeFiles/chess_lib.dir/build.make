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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\novot\Documents\Chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\novot\Documents\Chess\cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/chess_lib.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/chess_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/chess_lib.dir/flags.make

src/CMakeFiles/chess_lib.dir/chess_lib_autogen/mocs_compilation.cpp.obj: src/CMakeFiles/chess_lib.dir/flags.make
src/CMakeFiles/chess_lib.dir/chess_lib_autogen/mocs_compilation.cpp.obj: src/CMakeFiles/chess_lib.dir/includes_CXX.rsp
src/CMakeFiles/chess_lib.dir/chess_lib_autogen/mocs_compilation.cpp.obj: src/chess_lib_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\novot\Documents\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/chess_lib.dir/chess_lib_autogen/mocs_compilation.cpp.obj"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && C:\Qt\Tools\mingw810_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\chess_lib.dir\chess_lib_autogen\mocs_compilation.cpp.obj -c C:\Users\novot\Documents\Chess\cmake-build-debug\src\chess_lib_autogen\mocs_compilation.cpp

src/CMakeFiles/chess_lib.dir/chess_lib_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess_lib.dir/chess_lib_autogen/mocs_compilation.cpp.i"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\novot\Documents\Chess\cmake-build-debug\src\chess_lib_autogen\mocs_compilation.cpp > CMakeFiles\chess_lib.dir\chess_lib_autogen\mocs_compilation.cpp.i

src/CMakeFiles/chess_lib.dir/chess_lib_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess_lib.dir/chess_lib_autogen/mocs_compilation.cpp.s"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\novot\Documents\Chess\cmake-build-debug\src\chess_lib_autogen\mocs_compilation.cpp -o CMakeFiles\chess_lib.dir\chess_lib_autogen\mocs_compilation.cpp.s

src/CMakeFiles/chess_lib.dir/mainwindow.cpp.obj: src/CMakeFiles/chess_lib.dir/flags.make
src/CMakeFiles/chess_lib.dir/mainwindow.cpp.obj: src/CMakeFiles/chess_lib.dir/includes_CXX.rsp
src/CMakeFiles/chess_lib.dir/mainwindow.cpp.obj: ../src/mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\novot\Documents\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/chess_lib.dir/mainwindow.cpp.obj"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && C:\Qt\Tools\mingw810_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\chess_lib.dir\mainwindow.cpp.obj -c C:\Users\novot\Documents\Chess\src\mainwindow.cpp

src/CMakeFiles/chess_lib.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess_lib.dir/mainwindow.cpp.i"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\novot\Documents\Chess\src\mainwindow.cpp > CMakeFiles\chess_lib.dir\mainwindow.cpp.i

src/CMakeFiles/chess_lib.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess_lib.dir/mainwindow.cpp.s"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\novot\Documents\Chess\src\mainwindow.cpp -o CMakeFiles\chess_lib.dir\mainwindow.cpp.s

src/CMakeFiles/chess_lib.dir/chessboard.cpp.obj: src/CMakeFiles/chess_lib.dir/flags.make
src/CMakeFiles/chess_lib.dir/chessboard.cpp.obj: src/CMakeFiles/chess_lib.dir/includes_CXX.rsp
src/CMakeFiles/chess_lib.dir/chessboard.cpp.obj: ../src/chessboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\novot\Documents\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/chess_lib.dir/chessboard.cpp.obj"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && C:\Qt\Tools\mingw810_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\chess_lib.dir\chessboard.cpp.obj -c C:\Users\novot\Documents\Chess\src\chessboard.cpp

src/CMakeFiles/chess_lib.dir/chessboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess_lib.dir/chessboard.cpp.i"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\novot\Documents\Chess\src\chessboard.cpp > CMakeFiles\chess_lib.dir\chessboard.cpp.i

src/CMakeFiles/chess_lib.dir/chessboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess_lib.dir/chessboard.cpp.s"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\novot\Documents\Chess\src\chessboard.cpp -o CMakeFiles\chess_lib.dir\chessboard.cpp.s

src/CMakeFiles/chess_lib.dir/chesslogic.cpp.obj: src/CMakeFiles/chess_lib.dir/flags.make
src/CMakeFiles/chess_lib.dir/chesslogic.cpp.obj: src/CMakeFiles/chess_lib.dir/includes_CXX.rsp
src/CMakeFiles/chess_lib.dir/chesslogic.cpp.obj: ../src/chesslogic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\novot\Documents\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/chess_lib.dir/chesslogic.cpp.obj"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && C:\Qt\Tools\mingw810_64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\chess_lib.dir\chesslogic.cpp.obj -c C:\Users\novot\Documents\Chess\src\chesslogic.cpp

src/CMakeFiles/chess_lib.dir/chesslogic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess_lib.dir/chesslogic.cpp.i"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\novot\Documents\Chess\src\chesslogic.cpp > CMakeFiles\chess_lib.dir\chesslogic.cpp.i

src/CMakeFiles/chess_lib.dir/chesslogic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess_lib.dir/chesslogic.cpp.s"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\novot\Documents\Chess\src\chesslogic.cpp -o CMakeFiles\chess_lib.dir\chesslogic.cpp.s

# Object files for target chess_lib
chess_lib_OBJECTS = \
"CMakeFiles/chess_lib.dir/chess_lib_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/chess_lib.dir/mainwindow.cpp.obj" \
"CMakeFiles/chess_lib.dir/chessboard.cpp.obj" \
"CMakeFiles/chess_lib.dir/chesslogic.cpp.obj"

# External object files for target chess_lib
chess_lib_EXTERNAL_OBJECTS =

src/libchess_lib.a: src/CMakeFiles/chess_lib.dir/chess_lib_autogen/mocs_compilation.cpp.obj
src/libchess_lib.a: src/CMakeFiles/chess_lib.dir/mainwindow.cpp.obj
src/libchess_lib.a: src/CMakeFiles/chess_lib.dir/chessboard.cpp.obj
src/libchess_lib.a: src/CMakeFiles/chess_lib.dir/chesslogic.cpp.obj
src/libchess_lib.a: src/CMakeFiles/chess_lib.dir/build.make
src/libchess_lib.a: src/CMakeFiles/chess_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\novot\Documents\Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libchess_lib.a"
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\chess_lib.dir\cmake_clean_target.cmake
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\chess_lib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/chess_lib.dir/build: src/libchess_lib.a

.PHONY : src/CMakeFiles/chess_lib.dir/build

src/CMakeFiles/chess_lib.dir/clean:
	cd /d C:\Users\novot\Documents\Chess\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\chess_lib.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/chess_lib.dir/clean

src/CMakeFiles/chess_lib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\novot\Documents\Chess C:\Users\novot\Documents\Chess\src C:\Users\novot\Documents\Chess\cmake-build-debug C:\Users\novot\Documents\Chess\cmake-build-debug\src C:\Users\novot\Documents\Chess\cmake-build-debug\src\CMakeFiles\chess_lib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/chess_lib.dir/depend

