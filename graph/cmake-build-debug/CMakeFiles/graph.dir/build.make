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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\third_semestr\CiAOD\CiAOD homework\graph"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\third_semestr\CiAOD\CiAOD homework\graph\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\graph.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\graph.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\graph.dir\flags.make

CMakeFiles\graph.dir\main.cpp.obj: CMakeFiles\graph.dir\flags.make
CMakeFiles\graph.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\third_semestr\CiAOD\CiAOD homework\graph\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graph.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\graph.dir\main.cpp.obj /FdCMakeFiles\graph.dir\ /FS -c "D:\third_semestr\CiAOD\CiAOD homework\graph\main.cpp"
<<

CMakeFiles\graph.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\graph.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\third_semestr\CiAOD\CiAOD homework\graph\main.cpp"
<<

CMakeFiles\graph.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\graph.dir\main.cpp.s /c "D:\third_semestr\CiAOD\CiAOD homework\graph\main.cpp"
<<

# Object files for target graph
graph_OBJECTS = \
"CMakeFiles\graph.dir\main.cpp.obj"

# External object files for target graph
graph_EXTERNAL_OBJECTS =

graph.exe: CMakeFiles\graph.dir\main.cpp.obj
graph.exe: CMakeFiles\graph.dir\build.make
graph.exe: CMakeFiles\graph.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\third_semestr\CiAOD\CiAOD homework\graph\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable graph.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\graph.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\graph.dir\objects1.rsp @<<
 /out:graph.exe /implib:graph.lib /pdb:"D:\third_semestr\CiAOD\CiAOD homework\graph\cmake-build-debug\graph.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\graph.dir\build: graph.exe
.PHONY : CMakeFiles\graph.dir\build

CMakeFiles\graph.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\graph.dir\cmake_clean.cmake
.PHONY : CMakeFiles\graph.dir\clean

CMakeFiles\graph.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\third_semestr\CiAOD\CiAOD homework\graph" "D:\third_semestr\CiAOD\CiAOD homework\graph" "D:\third_semestr\CiAOD\CiAOD homework\graph\cmake-build-debug" "D:\third_semestr\CiAOD\CiAOD homework\graph\cmake-build-debug" "D:\third_semestr\CiAOD\CiAOD homework\graph\cmake-build-debug\CMakeFiles\graph.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\graph.dir\depend

