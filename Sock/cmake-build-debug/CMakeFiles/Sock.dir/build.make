# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Chapo\CLionProjects\Sock

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Chapo\CLionProjects\Sock\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Sock.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sock.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sock.dir/flags.make

CMakeFiles/Sock.dir/main.cpp.obj: CMakeFiles/Sock.dir/flags.make
CMakeFiles/Sock.dir/main.cpp.obj: CMakeFiles/Sock.dir/includes_CXX.rsp
CMakeFiles/Sock.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chapo\CLionProjects\Sock\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sock.dir/main.cpp.obj"
	C:\Users\Chapo\Downloads\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Sock.dir\main.cpp.obj -c C:\Users\Chapo\CLionProjects\Sock\main.cpp

CMakeFiles/Sock.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sock.dir/main.cpp.i"
	C:\Users\Chapo\Downloads\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chapo\CLionProjects\Sock\main.cpp > CMakeFiles\Sock.dir\main.cpp.i

CMakeFiles/Sock.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sock.dir/main.cpp.s"
	C:\Users\Chapo\Downloads\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chapo\CLionProjects\Sock\main.cpp -o CMakeFiles\Sock.dir\main.cpp.s

# Object files for target Sock
Sock_OBJECTS = \
"CMakeFiles/Sock.dir/main.cpp.obj"

# External object files for target Sock
Sock_EXTERNAL_OBJECTS =

Sock.exe: CMakeFiles/Sock.dir/main.cpp.obj
Sock.exe: CMakeFiles/Sock.dir/build.make
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libsfml-system-s-d.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libsfml-window-s-d.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libsfml-graphics-s-d.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libsfml-audio-s-d.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libsfml-network-s-d.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libsfml-window-s-d.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libfreetype.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libopenal32.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libvorbisfile.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libvorbisenc.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libvorbis.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libogg.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libFLAC.a
Sock.exe: C:/Users/Chapo/Downloads/i686-7.3.0-release-posix-dwarf-rt_v5-rev0/mingw32/SFML-2.5.1/lib/libsfml-system-s-d.a
Sock.exe: CMakeFiles/Sock.dir/linklibs.rsp
Sock.exe: CMakeFiles/Sock.dir/objects1.rsp
Sock.exe: CMakeFiles/Sock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Chapo\CLionProjects\Sock\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sock.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sock.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sock.dir/build: Sock.exe

.PHONY : CMakeFiles/Sock.dir/build

CMakeFiles/Sock.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sock.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Sock.dir/clean

CMakeFiles/Sock.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Chapo\CLionProjects\Sock C:\Users\Chapo\CLionProjects\Sock C:\Users\Chapo\CLionProjects\Sock\cmake-build-debug C:\Users\Chapo\CLionProjects\Sock\cmake-build-debug C:\Users\Chapo\CLionProjects\Sock\cmake-build-debug\CMakeFiles\Sock.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sock.dir/depend

