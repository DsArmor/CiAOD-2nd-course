# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\zelez\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5284.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\zelez\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5284.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\binary_operation.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\binary_operation.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\binary_operation.dir\flags.make

CMakeFiles\binary_operation.dir\main.cpp.obj: CMakeFiles\binary_operation.dir\flags.make
CMakeFiles\binary_operation.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/binary_operation.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\binary_operation.dir\main.cpp.obj /FdCMakeFiles\binary_operation.dir\ /FS -c "D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation\main.cpp"
<<

CMakeFiles\binary_operation.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binary_operation.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\binary_operation.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation\main.cpp"
<<

CMakeFiles\binary_operation.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binary_operation.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\binary_operation.dir\main.cpp.s /c "D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation\main.cpp"
<<

# Object files for target binary_operation
binary_operation_OBJECTS = \
"CMakeFiles\binary_operation.dir\main.cpp.obj"

# External object files for target binary_operation
binary_operation_EXTERNAL_OBJECTS =

binary_operation.exe: CMakeFiles\binary_operation.dir\main.cpp.obj
binary_operation.exe: CMakeFiles\binary_operation.dir\build.make
binary_operation.exe: CMakeFiles\binary_operation.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable binary_operation.exe"
	C:\Users\zelez\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5284.51\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\binary_operation.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\binary_operation.dir\objects1.rsp @<<
 /out:binary_operation.exe /implib:binary_operation.lib /pdb:"D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation\cmake-build-debug\binary_operation.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\binary_operation.dir\build: binary_operation.exe
.PHONY : CMakeFiles\binary_operation.dir\build

CMakeFiles\binary_operation.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\binary_operation.dir\cmake_clean.cmake
.PHONY : CMakeFiles\binary_operation.dir\clean

CMakeFiles\binary_operation.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation" "D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation" "D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation\cmake-build-debug" "D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation\cmake-build-debug" "D:\third_semestr\CiAOD\CiAOD homework\binary_operation_all\binary_operation\cmake-build-debug\CMakeFiles\binary_operation.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\binary_operation.dir\depend

