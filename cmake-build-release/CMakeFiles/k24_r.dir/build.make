# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_SOURCE_DIR = /Users/karlkegel/CLionProjects/k24_r

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/karlkegel/CLionProjects/k24_r/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/k24_r.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/k24_r.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/k24_r.dir/flags.make

CMakeFiles/k24_r.dir/src/main.cpp.o: CMakeFiles/k24_r.dir/flags.make
CMakeFiles/k24_r.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/karlkegel/CLionProjects/k24_r/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/k24_r.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/k24_r.dir/src/main.cpp.o -c /Users/karlkegel/CLionProjects/k24_r/src/main.cpp

CMakeFiles/k24_r.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/k24_r.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/karlkegel/CLionProjects/k24_r/src/main.cpp > CMakeFiles/k24_r.dir/src/main.cpp.i

CMakeFiles/k24_r.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/k24_r.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/karlkegel/CLionProjects/k24_r/src/main.cpp -o CMakeFiles/k24_r.dir/src/main.cpp.s

CMakeFiles/k24_r.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/k24_r.dir/src/main.cpp.o.requires

CMakeFiles/k24_r.dir/src/main.cpp.o.provides: CMakeFiles/k24_r.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/k24_r.dir/build.make CMakeFiles/k24_r.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/k24_r.dir/src/main.cpp.o.provides

CMakeFiles/k24_r.dir/src/main.cpp.o.provides.build: CMakeFiles/k24_r.dir/src/main.cpp.o


CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o: CMakeFiles/k24_r.dir/flags.make
CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o: ../src/includes/bmp_edit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/karlkegel/CLionProjects/k24_r/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o -c /Users/karlkegel/CLionProjects/k24_r/src/includes/bmp_edit.cpp

CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/karlkegel/CLionProjects/k24_r/src/includes/bmp_edit.cpp > CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.i

CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/karlkegel/CLionProjects/k24_r/src/includes/bmp_edit.cpp -o CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.s

CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o.requires:

.PHONY : CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o.requires

CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o.provides: CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o.requires
	$(MAKE) -f CMakeFiles/k24_r.dir/build.make CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o.provides.build
.PHONY : CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o.provides

CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o.provides.build: CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o


CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o: CMakeFiles/k24_r.dir/flags.make
CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o: ../src/includes/k24_r.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/karlkegel/CLionProjects/k24_r/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o -c /Users/karlkegel/CLionProjects/k24_r/src/includes/k24_r.cpp

CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/karlkegel/CLionProjects/k24_r/src/includes/k24_r.cpp > CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.i

CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/karlkegel/CLionProjects/k24_r/src/includes/k24_r.cpp -o CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.s

CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o.requires:

.PHONY : CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o.requires

CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o.provides: CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o.requires
	$(MAKE) -f CMakeFiles/k24_r.dir/build.make CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o.provides.build
.PHONY : CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o.provides

CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o.provides.build: CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o


CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o: CMakeFiles/k24_r.dir/flags.make
CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o: ../src/classes/color_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/karlkegel/CLionProjects/k24_r/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o -c /Users/karlkegel/CLionProjects/k24_r/src/classes/color_handler.cpp

CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/karlkegel/CLionProjects/k24_r/src/classes/color_handler.cpp > CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.i

CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/karlkegel/CLionProjects/k24_r/src/classes/color_handler.cpp -o CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.s

CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o.requires:

.PHONY : CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o.requires

CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o.provides: CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o.requires
	$(MAKE) -f CMakeFiles/k24_r.dir/build.make CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o.provides.build
.PHONY : CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o.provides

CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o.provides.build: CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o


CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o: CMakeFiles/k24_r.dir/flags.make
CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o: ../src/classes/color_corpus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/karlkegel/CLionProjects/k24_r/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o -c /Users/karlkegel/CLionProjects/k24_r/src/classes/color_corpus.cpp

CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/karlkegel/CLionProjects/k24_r/src/classes/color_corpus.cpp > CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.i

CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/karlkegel/CLionProjects/k24_r/src/classes/color_corpus.cpp -o CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.s

CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o.requires:

.PHONY : CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o.requires

CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o.provides: CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o.requires
	$(MAKE) -f CMakeFiles/k24_r.dir/build.make CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o.provides.build
.PHONY : CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o.provides

CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o.provides.build: CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o


CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o: CMakeFiles/k24_r.dir/flags.make
CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o: ../src/includes/pixel_operations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/karlkegel/CLionProjects/k24_r/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o -c /Users/karlkegel/CLionProjects/k24_r/src/includes/pixel_operations.cpp

CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/karlkegel/CLionProjects/k24_r/src/includes/pixel_operations.cpp > CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.i

CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/karlkegel/CLionProjects/k24_r/src/includes/pixel_operations.cpp -o CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.s

CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o.requires:

.PHONY : CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o.requires

CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o.provides: CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o.requires
	$(MAKE) -f CMakeFiles/k24_r.dir/build.make CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o.provides.build
.PHONY : CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o.provides

CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o.provides.build: CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o


# Object files for target k24_r
k24_r_OBJECTS = \
"CMakeFiles/k24_r.dir/src/main.cpp.o" \
"CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o" \
"CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o" \
"CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o" \
"CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o" \
"CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o"

# External object files for target k24_r
k24_r_EXTERNAL_OBJECTS =

k24_r: CMakeFiles/k24_r.dir/src/main.cpp.o
k24_r: CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o
k24_r: CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o
k24_r: CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o
k24_r: CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o
k24_r: CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o
k24_r: CMakeFiles/k24_r.dir/build.make
k24_r: CMakeFiles/k24_r.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/karlkegel/CLionProjects/k24_r/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable k24_r"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/k24_r.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/k24_r.dir/build: k24_r

.PHONY : CMakeFiles/k24_r.dir/build

CMakeFiles/k24_r.dir/requires: CMakeFiles/k24_r.dir/src/main.cpp.o.requires
CMakeFiles/k24_r.dir/requires: CMakeFiles/k24_r.dir/src/includes/bmp_edit.cpp.o.requires
CMakeFiles/k24_r.dir/requires: CMakeFiles/k24_r.dir/src/includes/k24_r.cpp.o.requires
CMakeFiles/k24_r.dir/requires: CMakeFiles/k24_r.dir/src/classes/color_handler.cpp.o.requires
CMakeFiles/k24_r.dir/requires: CMakeFiles/k24_r.dir/src/classes/color_corpus.cpp.o.requires
CMakeFiles/k24_r.dir/requires: CMakeFiles/k24_r.dir/src/includes/pixel_operations.cpp.o.requires

.PHONY : CMakeFiles/k24_r.dir/requires

CMakeFiles/k24_r.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/k24_r.dir/cmake_clean.cmake
.PHONY : CMakeFiles/k24_r.dir/clean

CMakeFiles/k24_r.dir/depend:
	cd /Users/karlkegel/CLionProjects/k24_r/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/karlkegel/CLionProjects/k24_r /Users/karlkegel/CLionProjects/k24_r /Users/karlkegel/CLionProjects/k24_r/cmake-build-release /Users/karlkegel/CLionProjects/k24_r/cmake-build-release /Users/karlkegel/CLionProjects/k24_r/cmake-build-release/CMakeFiles/k24_r.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/k24_r.dir/depend

