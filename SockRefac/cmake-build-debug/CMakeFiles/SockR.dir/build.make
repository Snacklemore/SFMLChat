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
CMAKE_SOURCE_DIR = C:\Users\Chapo\CLionProjects\SockRefac

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SockR.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SockR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SockR.dir/flags.make

CMakeFiles/SockR.dir/main.cpp.obj: CMakeFiles/SockR.dir/flags.make
CMakeFiles/SockR.dir/main.cpp.obj: CMakeFiles/SockR.dir/includes_CXX.rsp
CMakeFiles/SockR.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SockR.dir/main.cpp.obj"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SockR.dir\main.cpp.obj -c C:\Users\Chapo\CLionProjects\SockRefac\main.cpp

CMakeFiles/SockR.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SockR.dir/main.cpp.i"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chapo\CLionProjects\SockRefac\main.cpp > CMakeFiles\SockR.dir\main.cpp.i

CMakeFiles/SockR.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SockR.dir/main.cpp.s"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chapo\CLionProjects\SockRefac\main.cpp -o CMakeFiles\SockR.dir\main.cpp.s

CMakeFiles/SockR.dir/ClientObject.cpp.obj: CMakeFiles/SockR.dir/flags.make
CMakeFiles/SockR.dir/ClientObject.cpp.obj: CMakeFiles/SockR.dir/includes_CXX.rsp
CMakeFiles/SockR.dir/ClientObject.cpp.obj: ../ClientObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SockR.dir/ClientObject.cpp.obj"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SockR.dir\ClientObject.cpp.obj -c C:\Users\Chapo\CLionProjects\SockRefac\ClientObject.cpp

CMakeFiles/SockR.dir/ClientObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SockR.dir/ClientObject.cpp.i"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chapo\CLionProjects\SockRefac\ClientObject.cpp > CMakeFiles\SockR.dir\ClientObject.cpp.i

CMakeFiles/SockR.dir/ClientObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SockR.dir/ClientObject.cpp.s"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chapo\CLionProjects\SockRefac\ClientObject.cpp -o CMakeFiles\SockR.dir\ClientObject.cpp.s

CMakeFiles/SockR.dir/MessageObject.cpp.obj: CMakeFiles/SockR.dir/flags.make
CMakeFiles/SockR.dir/MessageObject.cpp.obj: CMakeFiles/SockR.dir/includes_CXX.rsp
CMakeFiles/SockR.dir/MessageObject.cpp.obj: ../MessageObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SockR.dir/MessageObject.cpp.obj"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SockR.dir\MessageObject.cpp.obj -c C:\Users\Chapo\CLionProjects\SockRefac\MessageObject.cpp

CMakeFiles/SockR.dir/MessageObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SockR.dir/MessageObject.cpp.i"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chapo\CLionProjects\SockRefac\MessageObject.cpp > CMakeFiles\SockR.dir\MessageObject.cpp.i

CMakeFiles/SockR.dir/MessageObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SockR.dir/MessageObject.cpp.s"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chapo\CLionProjects\SockRefac\MessageObject.cpp -o CMakeFiles\SockR.dir\MessageObject.cpp.s

CMakeFiles/SockR.dir/ClientClass.cpp.obj: CMakeFiles/SockR.dir/flags.make
CMakeFiles/SockR.dir/ClientClass.cpp.obj: CMakeFiles/SockR.dir/includes_CXX.rsp
CMakeFiles/SockR.dir/ClientClass.cpp.obj: ../ClientClass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SockR.dir/ClientClass.cpp.obj"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SockR.dir\ClientClass.cpp.obj -c C:\Users\Chapo\CLionProjects\SockRefac\ClientClass.cpp

CMakeFiles/SockR.dir/ClientClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SockR.dir/ClientClass.cpp.i"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chapo\CLionProjects\SockRefac\ClientClass.cpp > CMakeFiles\SockR.dir\ClientClass.cpp.i

CMakeFiles/SockR.dir/ClientClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SockR.dir/ClientClass.cpp.s"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chapo\CLionProjects\SockRefac\ClientClass.cpp -o CMakeFiles\SockR.dir\ClientClass.cpp.s

CMakeFiles/SockR.dir/ServerClass.cpp.obj: CMakeFiles/SockR.dir/flags.make
CMakeFiles/SockR.dir/ServerClass.cpp.obj: CMakeFiles/SockR.dir/includes_CXX.rsp
CMakeFiles/SockR.dir/ServerClass.cpp.obj: ../ServerClass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SockR.dir/ServerClass.cpp.obj"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SockR.dir\ServerClass.cpp.obj -c C:\Users\Chapo\CLionProjects\SockRefac\ServerClass.cpp

CMakeFiles/SockR.dir/ServerClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SockR.dir/ServerClass.cpp.i"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chapo\CLionProjects\SockRefac\ServerClass.cpp > CMakeFiles\SockR.dir\ServerClass.cpp.i

CMakeFiles/SockR.dir/ServerClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SockR.dir/ServerClass.cpp.s"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chapo\CLionProjects\SockRefac\ServerClass.cpp -o CMakeFiles\SockR.dir\ServerClass.cpp.s

CMakeFiles/SockR.dir/TextField.cpp.obj: CMakeFiles/SockR.dir/flags.make
CMakeFiles/SockR.dir/TextField.cpp.obj: CMakeFiles/SockR.dir/includes_CXX.rsp
CMakeFiles/SockR.dir/TextField.cpp.obj: ../TextField.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SockR.dir/TextField.cpp.obj"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SockR.dir\TextField.cpp.obj -c C:\Users\Chapo\CLionProjects\SockRefac\TextField.cpp

CMakeFiles/SockR.dir/TextField.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SockR.dir/TextField.cpp.i"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chapo\CLionProjects\SockRefac\TextField.cpp > CMakeFiles\SockR.dir\TextField.cpp.i

CMakeFiles/SockR.dir/TextField.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SockR.dir/TextField.cpp.s"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chapo\CLionProjects\SockRefac\TextField.cpp -o CMakeFiles\SockR.dir\TextField.cpp.s

CMakeFiles/SockR.dir/Cursor.cpp.obj: CMakeFiles/SockR.dir/flags.make
CMakeFiles/SockR.dir/Cursor.cpp.obj: CMakeFiles/SockR.dir/includes_CXX.rsp
CMakeFiles/SockR.dir/Cursor.cpp.obj: ../Cursor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SockR.dir/Cursor.cpp.obj"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SockR.dir\Cursor.cpp.obj -c C:\Users\Chapo\CLionProjects\SockRefac\Cursor.cpp

CMakeFiles/SockR.dir/Cursor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SockR.dir/Cursor.cpp.i"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chapo\CLionProjects\SockRefac\Cursor.cpp > CMakeFiles\SockR.dir\Cursor.cpp.i

CMakeFiles/SockR.dir/Cursor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SockR.dir/Cursor.cpp.s"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chapo\CLionProjects\SockRefac\Cursor.cpp -o CMakeFiles\SockR.dir\Cursor.cpp.s

CMakeFiles/SockR.dir/MessageWidget.cpp.obj: CMakeFiles/SockR.dir/flags.make
CMakeFiles/SockR.dir/MessageWidget.cpp.obj: CMakeFiles/SockR.dir/includes_CXX.rsp
CMakeFiles/SockR.dir/MessageWidget.cpp.obj: ../MessageWidget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SockR.dir/MessageWidget.cpp.obj"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SockR.dir\MessageWidget.cpp.obj -c C:\Users\Chapo\CLionProjects\SockRefac\MessageWidget.cpp

CMakeFiles/SockR.dir/MessageWidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SockR.dir/MessageWidget.cpp.i"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chapo\CLionProjects\SockRefac\MessageWidget.cpp > CMakeFiles\SockR.dir\MessageWidget.cpp.i

CMakeFiles/SockR.dir/MessageWidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SockR.dir/MessageWidget.cpp.s"
	C:\Users\Chapo\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chapo\CLionProjects\SockRefac\MessageWidget.cpp -o CMakeFiles\SockR.dir\MessageWidget.cpp.s

# Object files for target SockR
SockR_OBJECTS = \
"CMakeFiles/SockR.dir/main.cpp.obj" \
"CMakeFiles/SockR.dir/ClientObject.cpp.obj" \
"CMakeFiles/SockR.dir/MessageObject.cpp.obj" \
"CMakeFiles/SockR.dir/ClientClass.cpp.obj" \
"CMakeFiles/SockR.dir/ServerClass.cpp.obj" \
"CMakeFiles/SockR.dir/TextField.cpp.obj" \
"CMakeFiles/SockR.dir/Cursor.cpp.obj" \
"CMakeFiles/SockR.dir/MessageWidget.cpp.obj"

# External object files for target SockR
SockR_EXTERNAL_OBJECTS =

SockR.exe: CMakeFiles/SockR.dir/main.cpp.obj
SockR.exe: CMakeFiles/SockR.dir/ClientObject.cpp.obj
SockR.exe: CMakeFiles/SockR.dir/MessageObject.cpp.obj
SockR.exe: CMakeFiles/SockR.dir/ClientClass.cpp.obj
SockR.exe: CMakeFiles/SockR.dir/ServerClass.cpp.obj
SockR.exe: CMakeFiles/SockR.dir/TextField.cpp.obj
SockR.exe: CMakeFiles/SockR.dir/Cursor.cpp.obj
SockR.exe: CMakeFiles/SockR.dir/MessageWidget.cpp.obj
SockR.exe: CMakeFiles/SockR.dir/build.make
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libsfml-graphics-s-d.a
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libsfml-system-s-d.a
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libsfml-window-s-d.a
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libsfml-audio-s-d.a
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libsfml-network-s-d.a
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libfreetype.a
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libopenal32.a
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libvorbisfile.a
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libvorbisenc.a
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libvorbis.a
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libogg.a
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libFLAC.a
SockR.exe: C:/Users/Chapo/Downloads/x86_64-7.3.0-release-posix-seh-rt_v5-rev0/mingw64/SFML-2.5.1/lib/libsfml-system-s-d.a
SockR.exe: CMakeFiles/SockR.dir/linklibs.rsp
SockR.exe: CMakeFiles/SockR.dir/objects1.rsp
SockR.exe: CMakeFiles/SockR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable SockR.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SockR.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SockR.dir/build: SockR.exe

.PHONY : CMakeFiles/SockR.dir/build

CMakeFiles/SockR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SockR.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SockR.dir/clean

CMakeFiles/SockR.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Chapo\CLionProjects\SockRefac C:\Users\Chapo\CLionProjects\SockRefac C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug C:\Users\Chapo\CLionProjects\SockRefac\cmake-build-debug\CMakeFiles\SockR.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SockR.dir/depend

