# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Programs\2023-2024\C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Programs\2023-2024\C++\build

# Include any dependencies generated for this target.
include 1/CALCULATOR/CMakeFiles/calculator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 1/CALCULATOR/CMakeFiles/calculator.dir/compiler_depend.make

# Include the progress variables for this target.
include 1/CALCULATOR/CMakeFiles/calculator.dir/progress.make

# Include the compile flags for this target's objects.
include 1/CALCULATOR/CMakeFiles/calculator.dir/flags.make

1/CALCULATOR/CMakeFiles/calculator.dir/calculator.cpp.obj: 1/CALCULATOR/CMakeFiles/calculator.dir/flags.make
1/CALCULATOR/CMakeFiles/calculator.dir/calculator.cpp.obj: 1/CALCULATOR/CMakeFiles/calculator.dir/includes_CXX.rsp
1/CALCULATOR/CMakeFiles/calculator.dir/calculator.cpp.obj: D:/Programs/2023-2024/C++/1/CALCULATOR/calculator.cpp
1/CALCULATOR/CMakeFiles/calculator.dir/calculator.cpp.obj: 1/CALCULATOR/CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Programs\2023-2024\C++\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 1/CALCULATOR/CMakeFiles/calculator.dir/calculator.cpp.obj"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && "D:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 1/CALCULATOR/CMakeFiles/calculator.dir/calculator.cpp.obj -MF CMakeFiles\calculator.dir\calculator.cpp.obj.d -o CMakeFiles\calculator.dir\calculator.cpp.obj -c D:\Programs\2023-2024\C++\1\CALCULATOR\calculator.cpp

1/CALCULATOR/CMakeFiles/calculator.dir/calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calculator.dir/calculator.cpp.i"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && "D:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programs\2023-2024\C++\1\CALCULATOR\calculator.cpp > CMakeFiles\calculator.dir\calculator.cpp.i

1/CALCULATOR/CMakeFiles/calculator.dir/calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/calculator.cpp.s"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && "D:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programs\2023-2024\C++\1\CALCULATOR\calculator.cpp -o CMakeFiles\calculator.dir\calculator.cpp.s

1/CALCULATOR/CMakeFiles/calculator.dir/main_grammar_functions.cpp.obj: 1/CALCULATOR/CMakeFiles/calculator.dir/flags.make
1/CALCULATOR/CMakeFiles/calculator.dir/main_grammar_functions.cpp.obj: 1/CALCULATOR/CMakeFiles/calculator.dir/includes_CXX.rsp
1/CALCULATOR/CMakeFiles/calculator.dir/main_grammar_functions.cpp.obj: D:/Programs/2023-2024/C++/1/CALCULATOR/main_grammar_functions.cpp
1/CALCULATOR/CMakeFiles/calculator.dir/main_grammar_functions.cpp.obj: 1/CALCULATOR/CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Programs\2023-2024\C++\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object 1/CALCULATOR/CMakeFiles/calculator.dir/main_grammar_functions.cpp.obj"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && "D:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 1/CALCULATOR/CMakeFiles/calculator.dir/main_grammar_functions.cpp.obj -MF CMakeFiles\calculator.dir\main_grammar_functions.cpp.obj.d -o CMakeFiles\calculator.dir\main_grammar_functions.cpp.obj -c D:\Programs\2023-2024\C++\1\CALCULATOR\main_grammar_functions.cpp

1/CALCULATOR/CMakeFiles/calculator.dir/main_grammar_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calculator.dir/main_grammar_functions.cpp.i"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && "D:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programs\2023-2024\C++\1\CALCULATOR\main_grammar_functions.cpp > CMakeFiles\calculator.dir\main_grammar_functions.cpp.i

1/CALCULATOR/CMakeFiles/calculator.dir/main_grammar_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/main_grammar_functions.cpp.s"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && "D:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programs\2023-2024\C++\1\CALCULATOR\main_grammar_functions.cpp -o CMakeFiles\calculator.dir\main_grammar_functions.cpp.s

1/CALCULATOR/CMakeFiles/calculator.dir/Names.cpp.obj: 1/CALCULATOR/CMakeFiles/calculator.dir/flags.make
1/CALCULATOR/CMakeFiles/calculator.dir/Names.cpp.obj: 1/CALCULATOR/CMakeFiles/calculator.dir/includes_CXX.rsp
1/CALCULATOR/CMakeFiles/calculator.dir/Names.cpp.obj: D:/Programs/2023-2024/C++/1/CALCULATOR/Names.cpp
1/CALCULATOR/CMakeFiles/calculator.dir/Names.cpp.obj: 1/CALCULATOR/CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Programs\2023-2024\C++\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object 1/CALCULATOR/CMakeFiles/calculator.dir/Names.cpp.obj"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && "D:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 1/CALCULATOR/CMakeFiles/calculator.dir/Names.cpp.obj -MF CMakeFiles\calculator.dir\Names.cpp.obj.d -o CMakeFiles\calculator.dir\Names.cpp.obj -c D:\Programs\2023-2024\C++\1\CALCULATOR\Names.cpp

1/CALCULATOR/CMakeFiles/calculator.dir/Names.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calculator.dir/Names.cpp.i"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && "D:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programs\2023-2024\C++\1\CALCULATOR\Names.cpp > CMakeFiles\calculator.dir\Names.cpp.i

1/CALCULATOR/CMakeFiles/calculator.dir/Names.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/Names.cpp.s"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && "D:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programs\2023-2024\C++\1\CALCULATOR\Names.cpp -o CMakeFiles\calculator.dir\Names.cpp.s

1/CALCULATOR/CMakeFiles/calculator.dir/Token.cpp.obj: 1/CALCULATOR/CMakeFiles/calculator.dir/flags.make
1/CALCULATOR/CMakeFiles/calculator.dir/Token.cpp.obj: 1/CALCULATOR/CMakeFiles/calculator.dir/includes_CXX.rsp
1/CALCULATOR/CMakeFiles/calculator.dir/Token.cpp.obj: D:/Programs/2023-2024/C++/1/CALCULATOR/Token.cpp
1/CALCULATOR/CMakeFiles/calculator.dir/Token.cpp.obj: 1/CALCULATOR/CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Programs\2023-2024\C++\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object 1/CALCULATOR/CMakeFiles/calculator.dir/Token.cpp.obj"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && "D:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 1/CALCULATOR/CMakeFiles/calculator.dir/Token.cpp.obj -MF CMakeFiles\calculator.dir\Token.cpp.obj.d -o CMakeFiles\calculator.dir\Token.cpp.obj -c D:\Programs\2023-2024\C++\1\CALCULATOR\Token.cpp

1/CALCULATOR/CMakeFiles/calculator.dir/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calculator.dir/Token.cpp.i"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && "D:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programs\2023-2024\C++\1\CALCULATOR\Token.cpp > CMakeFiles\calculator.dir\Token.cpp.i

1/CALCULATOR/CMakeFiles/calculator.dir/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/Token.cpp.s"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && "D:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programs\2023-2024\C++\1\CALCULATOR\Token.cpp -o CMakeFiles\calculator.dir\Token.cpp.s

# Object files for target calculator
calculator_OBJECTS = \
"CMakeFiles/calculator.dir/calculator.cpp.obj" \
"CMakeFiles/calculator.dir/main_grammar_functions.cpp.obj" \
"CMakeFiles/calculator.dir/Names.cpp.obj" \
"CMakeFiles/calculator.dir/Token.cpp.obj"

# External object files for target calculator
calculator_EXTERNAL_OBJECTS =

1/CALCULATOR/calculator.exe: 1/CALCULATOR/CMakeFiles/calculator.dir/calculator.cpp.obj
1/CALCULATOR/calculator.exe: 1/CALCULATOR/CMakeFiles/calculator.dir/main_grammar_functions.cpp.obj
1/CALCULATOR/calculator.exe: 1/CALCULATOR/CMakeFiles/calculator.dir/Names.cpp.obj
1/CALCULATOR/calculator.exe: 1/CALCULATOR/CMakeFiles/calculator.dir/Token.cpp.obj
1/CALCULATOR/calculator.exe: 1/CALCULATOR/CMakeFiles/calculator.dir/build.make
1/CALCULATOR/calculator.exe: 1/CALCULATOR/CMakeFiles/calculator.dir/linkLibs.rsp
1/CALCULATOR/calculator.exe: 1/CALCULATOR/CMakeFiles/calculator.dir/objects1.rsp
1/CALCULATOR/calculator.exe: 1/CALCULATOR/CMakeFiles/calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Programs\2023-2024\C++\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable calculator.exe"
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\calculator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
1/CALCULATOR/CMakeFiles/calculator.dir/build: 1/CALCULATOR/calculator.exe
.PHONY : 1/CALCULATOR/CMakeFiles/calculator.dir/build

1/CALCULATOR/CMakeFiles/calculator.dir/clean:
	cd /d D:\Programs\2023-2024\C++\build\1\CALCULATOR && $(CMAKE_COMMAND) -P CMakeFiles\calculator.dir\cmake_clean.cmake
.PHONY : 1/CALCULATOR/CMakeFiles/calculator.dir/clean

1/CALCULATOR/CMakeFiles/calculator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Programs\2023-2024\C++ D:\Programs\2023-2024\C++\1\CALCULATOR D:\Programs\2023-2024\C++\build D:\Programs\2023-2024\C++\build\1\CALCULATOR D:\Programs\2023-2024\C++\build\1\CALCULATOR\CMakeFiles\calculator.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : 1/CALCULATOR/CMakeFiles/calculator.dir/depend

