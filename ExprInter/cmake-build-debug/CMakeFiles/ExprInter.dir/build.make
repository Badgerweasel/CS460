# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Shipw\CLionProjects\CS460\ExprInter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\ExprInter.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\ExprInter.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\ExprInter.dir\flags.make

CMakeFiles\ExprInter.dir\main.cpp.obj: CMakeFiles\ExprInter.dir\flags.make
CMakeFiles\ExprInter.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ExprInter.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ExprInter.dir\main.cpp.obj /FdCMakeFiles\ExprInter.dir\ /FS -c C:\Users\Shipw\CLionProjects\CS460\ExprInter\main.cpp
<<

CMakeFiles\ExprInter.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\ExprInter.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Shipw\CLionProjects\CS460\ExprInter\main.cpp
<<

CMakeFiles\ExprInter.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ExprInter.dir\main.cpp.s /c C:\Users\Shipw\CLionProjects\CS460\ExprInter\main.cpp
<<

CMakeFiles\ExprInter.dir\Token.cpp.obj: CMakeFiles\ExprInter.dir\flags.make
CMakeFiles\ExprInter.dir\Token.cpp.obj: ..\Token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ExprInter.dir/Token.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ExprInter.dir\Token.cpp.obj /FdCMakeFiles\ExprInter.dir\ /FS -c C:\Users\Shipw\CLionProjects\CS460\ExprInter\Token.cpp
<<

CMakeFiles\ExprInter.dir\Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/Token.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\ExprInter.dir\Token.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Shipw\CLionProjects\CS460\ExprInter\Token.cpp
<<

CMakeFiles\ExprInter.dir\Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/Token.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ExprInter.dir\Token.cpp.s /c C:\Users\Shipw\CLionProjects\CS460\ExprInter\Token.cpp
<<

CMakeFiles\ExprInter.dir\Tokenizer.cpp.obj: CMakeFiles\ExprInter.dir\flags.make
CMakeFiles\ExprInter.dir\Tokenizer.cpp.obj: ..\Tokenizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ExprInter.dir/Tokenizer.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ExprInter.dir\Tokenizer.cpp.obj /FdCMakeFiles\ExprInter.dir\ /FS -c C:\Users\Shipw\CLionProjects\CS460\ExprInter\Tokenizer.cpp
<<

CMakeFiles\ExprInter.dir\Tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/Tokenizer.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\ExprInter.dir\Tokenizer.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Shipw\CLionProjects\CS460\ExprInter\Tokenizer.cpp
<<

CMakeFiles\ExprInter.dir\Tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/Tokenizer.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ExprInter.dir\Tokenizer.cpp.s /c C:\Users\Shipw\CLionProjects\CS460\ExprInter\Tokenizer.cpp
<<

CMakeFiles\ExprInter.dir\Parser.cpp.obj: CMakeFiles\ExprInter.dir\flags.make
CMakeFiles\ExprInter.dir\Parser.cpp.obj: ..\Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ExprInter.dir/Parser.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ExprInter.dir\Parser.cpp.obj /FdCMakeFiles\ExprInter.dir\ /FS -c C:\Users\Shipw\CLionProjects\CS460\ExprInter\Parser.cpp
<<

CMakeFiles\ExprInter.dir\Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/Parser.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\ExprInter.dir\Parser.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Shipw\CLionProjects\CS460\ExprInter\Parser.cpp
<<

CMakeFiles\ExprInter.dir\Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/Parser.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ExprInter.dir\Parser.cpp.s /c C:\Users\Shipw\CLionProjects\CS460\ExprInter\Parser.cpp
<<

CMakeFiles\ExprInter.dir\Expr.cpp.obj: CMakeFiles\ExprInter.dir\flags.make
CMakeFiles\ExprInter.dir\Expr.cpp.obj: ..\Expr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ExprInter.dir/Expr.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ExprInter.dir\Expr.cpp.obj /FdCMakeFiles\ExprInter.dir\ /FS -c C:\Users\Shipw\CLionProjects\CS460\ExprInter\Expr.cpp
<<

CMakeFiles\ExprInter.dir\Expr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/Expr.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\ExprInter.dir\Expr.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Shipw\CLionProjects\CS460\ExprInter\Expr.cpp
<<

CMakeFiles\ExprInter.dir\Expr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/Expr.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ExprInter.dir\Expr.cpp.s /c C:\Users\Shipw\CLionProjects\CS460\ExprInter\Expr.cpp
<<

CMakeFiles\ExprInter.dir\SymTab.cpp.obj: CMakeFiles\ExprInter.dir\flags.make
CMakeFiles\ExprInter.dir\SymTab.cpp.obj: ..\SymTab.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ExprInter.dir/SymTab.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ExprInter.dir\SymTab.cpp.obj /FdCMakeFiles\ExprInter.dir\ /FS -c C:\Users\Shipw\CLionProjects\CS460\ExprInter\SymTab.cpp
<<

CMakeFiles\ExprInter.dir\SymTab.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/SymTab.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\ExprInter.dir\SymTab.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Shipw\CLionProjects\CS460\ExprInter\SymTab.cpp
<<

CMakeFiles\ExprInter.dir\SymTab.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/SymTab.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ExprInter.dir\SymTab.cpp.s /c C:\Users\Shipw\CLionProjects\CS460\ExprInter\SymTab.cpp
<<

CMakeFiles\ExprInter.dir\Statements.cpp.obj: CMakeFiles\ExprInter.dir\flags.make
CMakeFiles\ExprInter.dir\Statements.cpp.obj: ..\Statements.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ExprInter.dir/Statements.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ExprInter.dir\Statements.cpp.obj /FdCMakeFiles\ExprInter.dir\ /FS -c C:\Users\Shipw\CLionProjects\CS460\ExprInter\Statements.cpp
<<

CMakeFiles\ExprInter.dir\Statements.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExprInter.dir/Statements.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\ExprInter.dir\Statements.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Shipw\CLionProjects\CS460\ExprInter\Statements.cpp
<<

CMakeFiles\ExprInter.dir\Statements.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExprInter.dir/Statements.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ExprInter.dir\Statements.cpp.s /c C:\Users\Shipw\CLionProjects\CS460\ExprInter\Statements.cpp
<<

# Object files for target ExprInter
ExprInter_OBJECTS = \
"CMakeFiles\ExprInter.dir\main.cpp.obj" \
"CMakeFiles\ExprInter.dir\Token.cpp.obj" \
"CMakeFiles\ExprInter.dir\Tokenizer.cpp.obj" \
"CMakeFiles\ExprInter.dir\Parser.cpp.obj" \
"CMakeFiles\ExprInter.dir\Expr.cpp.obj" \
"CMakeFiles\ExprInter.dir\SymTab.cpp.obj" \
"CMakeFiles\ExprInter.dir\Statements.cpp.obj"

# External object files for target ExprInter
ExprInter_EXTERNAL_OBJECTS =

ExprInter.exe: CMakeFiles\ExprInter.dir\main.cpp.obj
ExprInter.exe: CMakeFiles\ExprInter.dir\Token.cpp.obj
ExprInter.exe: CMakeFiles\ExprInter.dir\Tokenizer.cpp.obj
ExprInter.exe: CMakeFiles\ExprInter.dir\Parser.cpp.obj
ExprInter.exe: CMakeFiles\ExprInter.dir\Expr.cpp.obj
ExprInter.exe: CMakeFiles\ExprInter.dir\SymTab.cpp.obj
ExprInter.exe: CMakeFiles\ExprInter.dir\Statements.cpp.obj
ExprInter.exe: CMakeFiles\ExprInter.dir\build.make
ExprInter.exe: CMakeFiles\ExprInter.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ExprInter.exe"
	"C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\ExprInter.dir --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\ExprInter.dir\objects1.rsp @<<
 /out:ExprInter.exe /implib:ExprInter.lib /pdb:C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug\ExprInter.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\ExprInter.dir\build: ExprInter.exe

.PHONY : CMakeFiles\ExprInter.dir\build

CMakeFiles\ExprInter.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ExprInter.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ExprInter.dir\clean

CMakeFiles\ExprInter.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Shipw\CLionProjects\CS460\ExprInter C:\Users\Shipw\CLionProjects\CS460\ExprInter C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug C:\Users\Shipw\CLionProjects\CS460\ExprInter\cmake-build-debug\CMakeFiles\ExprInter.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\ExprInter.dir\depend

