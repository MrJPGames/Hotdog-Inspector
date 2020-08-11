# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jwism\Documents\GitHub\Hotdog-Inspector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jwism\Documents\GitHub\Hotdog-Inspector

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	"C:\Program Files\CMake\bin\cmake-gui.exe" -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\CMake\bin\cmake.exe" --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Users\jwism\Documents\GitHub\Hotdog-Inspector\CMakeFiles C:\Users\jwism\Documents\GitHub\Hotdog-Inspector\CMakeFiles\progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Users\jwism\Documents\GitHub\Hotdog-Inspector\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Hotdog_Inspector

# Build rule for target.
Hotdog_Inspector: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 Hotdog_Inspector
.PHONY : Hotdog_Inspector

# fast build rule for target.
Hotdog_Inspector/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/build
.PHONY : Hotdog_Inspector/fast

src/animation.obj: src/animation.cpp.obj

.PHONY : src/animation.obj

# target to build an object file
src/animation.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/animation.cpp.obj
.PHONY : src/animation.cpp.obj

src/animation.i: src/animation.cpp.i

.PHONY : src/animation.i

# target to preprocess a source file
src/animation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/animation.cpp.i
.PHONY : src/animation.cpp.i

src/animation.s: src/animation.cpp.s

.PHONY : src/animation.s

# target to generate assembly for a file
src/animation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/animation.cpp.s
.PHONY : src/animation.cpp.s

src/camera.obj: src/camera.cpp.obj

.PHONY : src/camera.obj

# target to build an object file
src/camera.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/camera.cpp.obj
.PHONY : src/camera.cpp.obj

src/camera.i: src/camera.cpp.i

.PHONY : src/camera.i

# target to preprocess a source file
src/camera.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/camera.cpp.i
.PHONY : src/camera.cpp.i

src/camera.s: src/camera.cpp.s

.PHONY : src/camera.s

# target to generate assembly for a file
src/camera.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/camera.cpp.s
.PHONY : src/camera.cpp.s

src/character.obj: src/character.cpp.obj

.PHONY : src/character.obj

# target to build an object file
src/character.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/character.cpp.obj
.PHONY : src/character.cpp.obj

src/character.i: src/character.cpp.i

.PHONY : src/character.i

# target to preprocess a source file
src/character.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/character.cpp.i
.PHONY : src/character.cpp.i

src/character.s: src/character.cpp.s

.PHONY : src/character.s

# target to generate assembly for a file
src/character.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/character.cpp.s
.PHONY : src/character.cpp.s

src/controls.obj: src/controls.cpp.obj

.PHONY : src/controls.obj

# target to build an object file
src/controls.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/controls.cpp.obj
.PHONY : src/controls.cpp.obj

src/controls.i: src/controls.cpp.i

.PHONY : src/controls.i

# target to preprocess a source file
src/controls.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/controls.cpp.i
.PHONY : src/controls.cpp.i

src/controls.s: src/controls.cpp.s

.PHONY : src/controls.s

# target to generate assembly for a file
src/controls.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/controls.cpp.s
.PHONY : src/controls.cpp.s

src/conveyor.obj: src/conveyor.cpp.obj

.PHONY : src/conveyor.obj

# target to build an object file
src/conveyor.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/conveyor.cpp.obj
.PHONY : src/conveyor.cpp.obj

src/conveyor.i: src/conveyor.cpp.i

.PHONY : src/conveyor.i

# target to preprocess a source file
src/conveyor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/conveyor.cpp.i
.PHONY : src/conveyor.cpp.i

src/conveyor.s: src/conveyor.cpp.s

.PHONY : src/conveyor.s

# target to generate assembly for a file
src/conveyor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/conveyor.cpp.s
.PHONY : src/conveyor.cpp.s

src/cursor.obj: src/cursor.cpp.obj

.PHONY : src/cursor.obj

# target to build an object file
src/cursor.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/cursor.cpp.obj
.PHONY : src/cursor.cpp.obj

src/cursor.i: src/cursor.cpp.i

.PHONY : src/cursor.i

# target to preprocess a source file
src/cursor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/cursor.cpp.i
.PHONY : src/cursor.cpp.i

src/cursor.s: src/cursor.cpp.s

.PHONY : src/cursor.s

# target to generate assembly for a file
src/cursor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/cursor.cpp.s
.PHONY : src/cursor.cpp.s

src/game.obj: src/game.cpp.obj

.PHONY : src/game.obj

# target to build an object file
src/game.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/game.cpp.obj
.PHONY : src/game.cpp.obj

src/game.i: src/game.cpp.i

.PHONY : src/game.i

# target to preprocess a source file
src/game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/game.cpp.i
.PHONY : src/game.cpp.i

src/game.s: src/game.cpp.s

.PHONY : src/game.s

# target to generate assembly for a file
src/game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/game.cpp.s
.PHONY : src/game.cpp.s

src/gameworld.obj: src/gameworld.cpp.obj

.PHONY : src/gameworld.obj

# target to build an object file
src/gameworld.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/gameworld.cpp.obj
.PHONY : src/gameworld.cpp.obj

src/gameworld.i: src/gameworld.cpp.i

.PHONY : src/gameworld.i

# target to preprocess a source file
src/gameworld.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/gameworld.cpp.i
.PHONY : src/gameworld.cpp.i

src/gameworld.s: src/gameworld.cpp.s

.PHONY : src/gameworld.s

# target to generate assembly for a file
src/gameworld.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/gameworld.cpp.s
.PHONY : src/gameworld.cpp.s

src/imgui.obj: src/imgui.cpp.obj

.PHONY : src/imgui.obj

# target to build an object file
src/imgui.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui.cpp.obj
.PHONY : src/imgui.cpp.obj

src/imgui.i: src/imgui.cpp.i

.PHONY : src/imgui.i

# target to preprocess a source file
src/imgui.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui.cpp.i
.PHONY : src/imgui.cpp.i

src/imgui.s: src/imgui.cpp.s

.PHONY : src/imgui.s

# target to generate assembly for a file
src/imgui.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui.cpp.s
.PHONY : src/imgui.cpp.s

src/imgui_demo.obj: src/imgui_demo.cpp.obj

.PHONY : src/imgui_demo.obj

# target to build an object file
src/imgui_demo.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui_demo.cpp.obj
.PHONY : src/imgui_demo.cpp.obj

src/imgui_demo.i: src/imgui_demo.cpp.i

.PHONY : src/imgui_demo.i

# target to preprocess a source file
src/imgui_demo.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui_demo.cpp.i
.PHONY : src/imgui_demo.cpp.i

src/imgui_demo.s: src/imgui_demo.cpp.s

.PHONY : src/imgui_demo.s

# target to generate assembly for a file
src/imgui_demo.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui_demo.cpp.s
.PHONY : src/imgui_demo.cpp.s

src/imgui_draw.obj: src/imgui_draw.cpp.obj

.PHONY : src/imgui_draw.obj

# target to build an object file
src/imgui_draw.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui_draw.cpp.obj
.PHONY : src/imgui_draw.cpp.obj

src/imgui_draw.i: src/imgui_draw.cpp.i

.PHONY : src/imgui_draw.i

# target to preprocess a source file
src/imgui_draw.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui_draw.cpp.i
.PHONY : src/imgui_draw.cpp.i

src/imgui_draw.s: src/imgui_draw.cpp.s

.PHONY : src/imgui_draw.s

# target to generate assembly for a file
src/imgui_draw.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui_draw.cpp.s
.PHONY : src/imgui_draw.cpp.s

src/imgui_sdl.obj: src/imgui_sdl.cpp.obj

.PHONY : src/imgui_sdl.obj

# target to build an object file
src/imgui_sdl.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui_sdl.cpp.obj
.PHONY : src/imgui_sdl.cpp.obj

src/imgui_sdl.i: src/imgui_sdl.cpp.i

.PHONY : src/imgui_sdl.i

# target to preprocess a source file
src/imgui_sdl.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui_sdl.cpp.i
.PHONY : src/imgui_sdl.cpp.i

src/imgui_sdl.s: src/imgui_sdl.cpp.s

.PHONY : src/imgui_sdl.s

# target to generate assembly for a file
src/imgui_sdl.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui_sdl.cpp.s
.PHONY : src/imgui_sdl.cpp.s

src/imgui_widgets.obj: src/imgui_widgets.cpp.obj

.PHONY : src/imgui_widgets.obj

# target to build an object file
src/imgui_widgets.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui_widgets.cpp.obj
.PHONY : src/imgui_widgets.cpp.obj

src/imgui_widgets.i: src/imgui_widgets.cpp.i

.PHONY : src/imgui_widgets.i

# target to preprocess a source file
src/imgui_widgets.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui_widgets.cpp.i
.PHONY : src/imgui_widgets.cpp.i

src/imgui_widgets.s: src/imgui_widgets.cpp.s

.PHONY : src/imgui_widgets.s

# target to generate assembly for a file
src/imgui_widgets.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/imgui_widgets.cpp.s
.PHONY : src/imgui_widgets.cpp.s

src/jsoncpp.obj: src/jsoncpp.cpp.obj

.PHONY : src/jsoncpp.obj

# target to build an object file
src/jsoncpp.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/jsoncpp.cpp.obj
.PHONY : src/jsoncpp.cpp.obj

src/jsoncpp.i: src/jsoncpp.cpp.i

.PHONY : src/jsoncpp.i

# target to preprocess a source file
src/jsoncpp.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/jsoncpp.cpp.i
.PHONY : src/jsoncpp.cpp.i

src/jsoncpp.s: src/jsoncpp.cpp.s

.PHONY : src/jsoncpp.s

# target to generate assembly for a file
src/jsoncpp.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/jsoncpp.cpp.s
.PHONY : src/jsoncpp.cpp.s

src/main.obj: src/main.cpp.obj

.PHONY : src/main.obj

# target to build an object file
src/main.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/main.cpp.obj
.PHONY : src/main.cpp.obj

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/math.obj: src/math.cpp.obj

.PHONY : src/math.obj

# target to build an object file
src/math.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/math.cpp.obj
.PHONY : src/math.cpp.obj

src/math.i: src/math.cpp.i

.PHONY : src/math.i

# target to preprocess a source file
src/math.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/math.cpp.i
.PHONY : src/math.cpp.i

src/math.s: src/math.cpp.s

.PHONY : src/math.s

# target to generate assembly for a file
src/math.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/math.cpp.s
.PHONY : src/math.cpp.s

src/particle.obj: src/particle.cpp.obj

.PHONY : src/particle.obj

# target to build an object file
src/particle.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/particle.cpp.obj
.PHONY : src/particle.cpp.obj

src/particle.i: src/particle.cpp.i

.PHONY : src/particle.i

# target to preprocess a source file
src/particle.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/particle.cpp.i
.PHONY : src/particle.cpp.i

src/particle.s: src/particle.cpp.s

.PHONY : src/particle.s

# target to generate assembly for a file
src/particle.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/particle.cpp.s
.PHONY : src/particle.cpp.s

src/renderwindow.obj: src/renderwindow.cpp.obj

.PHONY : src/renderwindow.obj

# target to build an object file
src/renderwindow.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/renderwindow.cpp.obj
.PHONY : src/renderwindow.cpp.obj

src/renderwindow.i: src/renderwindow.cpp.i

.PHONY : src/renderwindow.i

# target to preprocess a source file
src/renderwindow.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/renderwindow.cpp.i
.PHONY : src/renderwindow.cpp.i

src/renderwindow.s: src/renderwindow.cpp.s

.PHONY : src/renderwindow.s

# target to generate assembly for a file
src/renderwindow.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/renderwindow.cpp.s
.PHONY : src/renderwindow.cpp.s

src/sprite.obj: src/sprite.cpp.obj

.PHONY : src/sprite.obj

# target to build an object file
src/sprite.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/sprite.cpp.obj
.PHONY : src/sprite.cpp.obj

src/sprite.i: src/sprite.cpp.i

.PHONY : src/sprite.i

# target to preprocess a source file
src/sprite.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/sprite.cpp.i
.PHONY : src/sprite.cpp.i

src/sprite.s: src/sprite.cpp.s

.PHONY : src/sprite.s

# target to generate assembly for a file
src/sprite.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Hotdog_Inspector.dir\build.make CMakeFiles/Hotdog_Inspector.dir/src/sprite.cpp.s
.PHONY : src/sprite.cpp.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... Hotdog_Inspector
	@echo ... src/animation.obj
	@echo ... src/animation.i
	@echo ... src/animation.s
	@echo ... src/camera.obj
	@echo ... src/camera.i
	@echo ... src/camera.s
	@echo ... src/character.obj
	@echo ... src/character.i
	@echo ... src/character.s
	@echo ... src/controls.obj
	@echo ... src/controls.i
	@echo ... src/controls.s
	@echo ... src/conveyor.obj
	@echo ... src/conveyor.i
	@echo ... src/conveyor.s
	@echo ... src/cursor.obj
	@echo ... src/cursor.i
	@echo ... src/cursor.s
	@echo ... src/game.obj
	@echo ... src/game.i
	@echo ... src/game.s
	@echo ... src/gameworld.obj
	@echo ... src/gameworld.i
	@echo ... src/gameworld.s
	@echo ... src/imgui.obj
	@echo ... src/imgui.i
	@echo ... src/imgui.s
	@echo ... src/imgui_demo.obj
	@echo ... src/imgui_demo.i
	@echo ... src/imgui_demo.s
	@echo ... src/imgui_draw.obj
	@echo ... src/imgui_draw.i
	@echo ... src/imgui_draw.s
	@echo ... src/imgui_sdl.obj
	@echo ... src/imgui_sdl.i
	@echo ... src/imgui_sdl.s
	@echo ... src/imgui_widgets.obj
	@echo ... src/imgui_widgets.i
	@echo ... src/imgui_widgets.s
	@echo ... src/jsoncpp.obj
	@echo ... src/jsoncpp.i
	@echo ... src/jsoncpp.s
	@echo ... src/main.obj
	@echo ... src/main.i
	@echo ... src/main.s
	@echo ... src/math.obj
	@echo ... src/math.i
	@echo ... src/math.s
	@echo ... src/particle.obj
	@echo ... src/particle.i
	@echo ... src/particle.s
	@echo ... src/renderwindow.obj
	@echo ... src/renderwindow.i
	@echo ... src/renderwindow.s
	@echo ... src/sprite.obj
	@echo ... src/sprite.i
	@echo ... src/sprite.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system

