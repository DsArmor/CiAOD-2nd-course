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
CMAKE_SOURCE_DIR = "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\encode_decode.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\encode_decode.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\encode_decode.dir\flags.make

CMakeFiles\encode_decode.dir\main.cpp.obj: CMakeFiles\encode_decode.dir\flags.make
CMakeFiles\encode_decode.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/encode_decode.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\encode_decode.dir\main.cpp.obj /FdCMakeFiles\encode_decode.dir\ /FS -c "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\main.cpp"
<<

CMakeFiles\encode_decode.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/encode_decode.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\encode_decode.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\main.cpp"
<<

CMakeFiles\encode_decode.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/encode_decode.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\encode_decode.dir\main.cpp.s /c "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\main.cpp"
<<

CMakeFiles\encode_decode.dir\Huffman.cpp.obj: CMakeFiles\encode_decode.dir\flags.make
CMakeFiles\encode_decode.dir\Huffman.cpp.obj: ..\Huffman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/encode_decode.dir/Huffman.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\encode_decode.dir\Huffman.cpp.obj /FdCMakeFiles\encode_decode.dir\ /FS -c "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\Huffman.cpp"
<<

CMakeFiles\encode_decode.dir\Huffman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/encode_decode.dir/Huffman.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\encode_decode.dir\Huffman.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\Huffman.cpp"
<<

CMakeFiles\encode_decode.dir\Huffman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/encode_decode.dir/Huffman.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\encode_decode.dir\Huffman.cpp.s /c "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\Huffman.cpp"
<<

CMakeFiles\encode_decode.dir\Shannon_fano.cpp.obj: CMakeFiles\encode_decode.dir\flags.make
CMakeFiles\encode_decode.dir\Shannon_fano.cpp.obj: ..\Shannon_fano.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/encode_decode.dir/Shannon_fano.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\encode_decode.dir\Shannon_fano.cpp.obj /FdCMakeFiles\encode_decode.dir\ /FS -c "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\Shannon_fano.cpp"
<<

CMakeFiles\encode_decode.dir\Shannon_fano.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/encode_decode.dir/Shannon_fano.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\encode_decode.dir\Shannon_fano.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\Shannon_fano.cpp"
<<

CMakeFiles\encode_decode.dir\Shannon_fano.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/encode_decode.dir/Shannon_fano.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\encode_decode.dir\Shannon_fano.cpp.s /c "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\Shannon_fano.cpp"
<<

# Object files for target encode_decode
encode_decode_OBJECTS = \
"CMakeFiles\encode_decode.dir\main.cpp.obj" \
"CMakeFiles\encode_decode.dir\Huffman.cpp.obj" \
"CMakeFiles\encode_decode.dir\Shannon_fano.cpp.obj"

# External object files for target encode_decode
encode_decode_EXTERNAL_OBJECTS =

encode_decode.exe: CMakeFiles\encode_decode.dir\main.cpp.obj
encode_decode.exe: CMakeFiles\encode_decode.dir\Huffman.cpp.obj
encode_decode.exe: CMakeFiles\encode_decode.dir\Shannon_fano.cpp.obj
encode_decode.exe: CMakeFiles\encode_decode.dir\build.make
encode_decode.exe: CMakeFiles\encode_decode.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable encode_decode.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\encode_decode.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\encode_decode.dir\objects1.rsp @<<
 /out:encode_decode.exe /implib:encode_decode.lib /pdb:"D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\cmake-build-debug\encode_decode.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\encode_decode.dir\build: encode_decode.exe
.PHONY : CMakeFiles\encode_decode.dir\build

CMakeFiles\encode_decode.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\encode_decode.dir\cmake_clean.cmake
.PHONY : CMakeFiles\encode_decode.dir\clean

CMakeFiles\encode_decode.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode" "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode" "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\cmake-build-debug" "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\cmake-build-debug" "D:\third_semestr\CiAOD\CiAOD homework\coding_all\encode_decode\cmake-build-debug\CMakeFiles\encode_decode.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\encode_decode.dir\depend

