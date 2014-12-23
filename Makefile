# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:
.PHONY : .NOTPARALLEL

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eugen/Kurs/BomberMan

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eugen/Kurs/BomberMan

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip
.PHONY : install/strip/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/eugen/Kurs/BomberMan/CMakeFiles /home/eugen/Kurs/BomberMan/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/eugen/Kurs/BomberMan/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named bin

# Build rule for target.
bin: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 bin
.PHONY : bin

# fast build rule for target.
bin/fast:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/build
.PHONY : bin/fast

#=============================================================================
# Target rules for targets named tinyxml

# Build rule for target.
tinyxml: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 tinyxml
.PHONY : tinyxml

# fast build rule for target.
tinyxml/fast:
	$(MAKE) -f lib/TinyXML/CMakeFiles/tinyxml.dir/build.make lib/TinyXML/CMakeFiles/tinyxml.dir/build
.PHONY : tinyxml/fast

src/Application.o: src/Application.cpp.o
.PHONY : src/Application.o

# target to build an object file
src/Application.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Application.cpp.o
.PHONY : src/Application.cpp.o

src/Application.i: src/Application.cpp.i
.PHONY : src/Application.i

# target to preprocess a source file
src/Application.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Application.cpp.i
.PHONY : src/Application.cpp.i

src/Application.s: src/Application.cpp.s
.PHONY : src/Application.s

# target to generate assembly for a file
src/Application.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Application.cpp.s
.PHONY : src/Application.cpp.s

src/Common/Button.o: src/Common/Button.cpp.o
.PHONY : src/Common/Button.o

# target to build an object file
src/Common/Button.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Common/Button.cpp.o
.PHONY : src/Common/Button.cpp.o

src/Common/Button.i: src/Common/Button.cpp.i
.PHONY : src/Common/Button.i

# target to preprocess a source file
src/Common/Button.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Common/Button.cpp.i
.PHONY : src/Common/Button.cpp.i

src/Common/Button.s: src/Common/Button.cpp.s
.PHONY : src/Common/Button.s

# target to generate assembly for a file
src/Common/Button.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Common/Button.cpp.s
.PHONY : src/Common/Button.cpp.s

src/Common/Interfaces/IAppState.o: src/Common/Interfaces/IAppState.cpp.o
.PHONY : src/Common/Interfaces/IAppState.o

# target to build an object file
src/Common/Interfaces/IAppState.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Common/Interfaces/IAppState.cpp.o
.PHONY : src/Common/Interfaces/IAppState.cpp.o

src/Common/Interfaces/IAppState.i: src/Common/Interfaces/IAppState.cpp.i
.PHONY : src/Common/Interfaces/IAppState.i

# target to preprocess a source file
src/Common/Interfaces/IAppState.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Common/Interfaces/IAppState.cpp.i
.PHONY : src/Common/Interfaces/IAppState.cpp.i

src/Common/Interfaces/IAppState.s: src/Common/Interfaces/IAppState.cpp.s
.PHONY : src/Common/Interfaces/IAppState.s

# target to generate assembly for a file
src/Common/Interfaces/IAppState.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Common/Interfaces/IAppState.cpp.s
.PHONY : src/Common/Interfaces/IAppState.cpp.s

src/Common/Interfaces/IEventManager.o: src/Common/Interfaces/IEventManager.cpp.o
.PHONY : src/Common/Interfaces/IEventManager.o

# target to build an object file
src/Common/Interfaces/IEventManager.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Common/Interfaces/IEventManager.cpp.o
.PHONY : src/Common/Interfaces/IEventManager.cpp.o

src/Common/Interfaces/IEventManager.i: src/Common/Interfaces/IEventManager.cpp.i
.PHONY : src/Common/Interfaces/IEventManager.i

# target to preprocess a source file
src/Common/Interfaces/IEventManager.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Common/Interfaces/IEventManager.cpp.i
.PHONY : src/Common/Interfaces/IEventManager.cpp.i

src/Common/Interfaces/IEventManager.s: src/Common/Interfaces/IEventManager.cpp.s
.PHONY : src/Common/Interfaces/IEventManager.s

# target to generate assembly for a file
src/Common/Interfaces/IEventManager.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Common/Interfaces/IEventManager.cpp.s
.PHONY : src/Common/Interfaces/IEventManager.cpp.s

src/Game/Attributes/PlayerEventHandler.o: src/Game/Attributes/PlayerEventHandler.cpp.o
.PHONY : src/Game/Attributes/PlayerEventHandler.o

# target to build an object file
src/Game/Attributes/PlayerEventHandler.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/Attributes/PlayerEventHandler.cpp.o
.PHONY : src/Game/Attributes/PlayerEventHandler.cpp.o

src/Game/Attributes/PlayerEventHandler.i: src/Game/Attributes/PlayerEventHandler.cpp.i
.PHONY : src/Game/Attributes/PlayerEventHandler.i

# target to preprocess a source file
src/Game/Attributes/PlayerEventHandler.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/Attributes/PlayerEventHandler.cpp.i
.PHONY : src/Game/Attributes/PlayerEventHandler.cpp.i

src/Game/Attributes/PlayerEventHandler.s: src/Game/Attributes/PlayerEventHandler.cpp.s
.PHONY : src/Game/Attributes/PlayerEventHandler.s

# target to generate assembly for a file
src/Game/Attributes/PlayerEventHandler.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/Attributes/PlayerEventHandler.cpp.s
.PHONY : src/Game/Attributes/PlayerEventHandler.cpp.s

src/Game/Attributes/PlayerEventManager.o: src/Game/Attributes/PlayerEventManager.cpp.o
.PHONY : src/Game/Attributes/PlayerEventManager.o

# target to build an object file
src/Game/Attributes/PlayerEventManager.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/Attributes/PlayerEventManager.cpp.o
.PHONY : src/Game/Attributes/PlayerEventManager.cpp.o

src/Game/Attributes/PlayerEventManager.i: src/Game/Attributes/PlayerEventManager.cpp.i
.PHONY : src/Game/Attributes/PlayerEventManager.i

# target to preprocess a source file
src/Game/Attributes/PlayerEventManager.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/Attributes/PlayerEventManager.cpp.i
.PHONY : src/Game/Attributes/PlayerEventManager.cpp.i

src/Game/Attributes/PlayerEventManager.s: src/Game/Attributes/PlayerEventManager.cpp.s
.PHONY : src/Game/Attributes/PlayerEventManager.s

# target to generate assembly for a file
src/Game/Attributes/PlayerEventManager.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/Attributes/PlayerEventManager.cpp.s
.PHONY : src/Game/Attributes/PlayerEventManager.cpp.s

src/Game/CollisionManager.o: src/Game/CollisionManager.cpp.o
.PHONY : src/Game/CollisionManager.o

# target to build an object file
src/Game/CollisionManager.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/CollisionManager.cpp.o
.PHONY : src/Game/CollisionManager.cpp.o

src/Game/CollisionManager.i: src/Game/CollisionManager.cpp.i
.PHONY : src/Game/CollisionManager.i

# target to preprocess a source file
src/Game/CollisionManager.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/CollisionManager.cpp.i
.PHONY : src/Game/CollisionManager.cpp.i

src/Game/CollisionManager.s: src/Game/CollisionManager.cpp.s
.PHONY : src/Game/CollisionManager.s

# target to generate assembly for a file
src/Game/CollisionManager.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/CollisionManager.cpp.s
.PHONY : src/Game/CollisionManager.cpp.s

src/Game/GameLevel.o: src/Game/GameLevel.cpp.o
.PHONY : src/Game/GameLevel.o

# target to build an object file
src/Game/GameLevel.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/GameLevel.cpp.o
.PHONY : src/Game/GameLevel.cpp.o

src/Game/GameLevel.i: src/Game/GameLevel.cpp.i
.PHONY : src/Game/GameLevel.i

# target to preprocess a source file
src/Game/GameLevel.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/GameLevel.cpp.i
.PHONY : src/Game/GameLevel.cpp.i

src/Game/GameLevel.s: src/Game/GameLevel.cpp.s
.PHONY : src/Game/GameLevel.s

# target to generate assembly for a file
src/Game/GameLevel.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/GameLevel.cpp.s
.PHONY : src/Game/GameLevel.cpp.s

src/Game/Map/Cell.o: src/Game/Map/Cell.cpp.o
.PHONY : src/Game/Map/Cell.o

# target to build an object file
src/Game/Map/Cell.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/Map/Cell.cpp.o
.PHONY : src/Game/Map/Cell.cpp.o

src/Game/Map/Cell.i: src/Game/Map/Cell.cpp.i
.PHONY : src/Game/Map/Cell.i

# target to preprocess a source file
src/Game/Map/Cell.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/Map/Cell.cpp.i
.PHONY : src/Game/Map/Cell.cpp.i

src/Game/Map/Cell.s: src/Game/Map/Cell.cpp.s
.PHONY : src/Game/Map/Cell.s

# target to generate assembly for a file
src/Game/Map/Cell.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/Map/Cell.cpp.s
.PHONY : src/Game/Map/Cell.cpp.s

src/Game/Map/GameMap.o: src/Game/Map/GameMap.cpp.o
.PHONY : src/Game/Map/GameMap.o

# target to build an object file
src/Game/Map/GameMap.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/Map/GameMap.cpp.o
.PHONY : src/Game/Map/GameMap.cpp.o

src/Game/Map/GameMap.i: src/Game/Map/GameMap.cpp.i
.PHONY : src/Game/Map/GameMap.i

# target to preprocess a source file
src/Game/Map/GameMap.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/Map/GameMap.cpp.i
.PHONY : src/Game/Map/GameMap.cpp.i

src/Game/Map/GameMap.s: src/Game/Map/GameMap.cpp.s
.PHONY : src/Game/Map/GameMap.s

# target to generate assembly for a file
src/Game/Map/GameMap.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/Map/GameMap.cpp.s
.PHONY : src/Game/Map/GameMap.cpp.s

src/Game/WObjects/Actor.o: src/Game/WObjects/Actor.cpp.o
.PHONY : src/Game/WObjects/Actor.o

# target to build an object file
src/Game/WObjects/Actor.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Actor.cpp.o
.PHONY : src/Game/WObjects/Actor.cpp.o

src/Game/WObjects/Actor.i: src/Game/WObjects/Actor.cpp.i
.PHONY : src/Game/WObjects/Actor.i

# target to preprocess a source file
src/Game/WObjects/Actor.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Actor.cpp.i
.PHONY : src/Game/WObjects/Actor.cpp.i

src/Game/WObjects/Actor.s: src/Game/WObjects/Actor.cpp.s
.PHONY : src/Game/WObjects/Actor.s

# target to generate assembly for a file
src/Game/WObjects/Actor.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Actor.cpp.s
.PHONY : src/Game/WObjects/Actor.cpp.s

src/Game/WObjects/Bomb.o: src/Game/WObjects/Bomb.cpp.o
.PHONY : src/Game/WObjects/Bomb.o

# target to build an object file
src/Game/WObjects/Bomb.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Bomb.cpp.o
.PHONY : src/Game/WObjects/Bomb.cpp.o

src/Game/WObjects/Bomb.i: src/Game/WObjects/Bomb.cpp.i
.PHONY : src/Game/WObjects/Bomb.i

# target to preprocess a source file
src/Game/WObjects/Bomb.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Bomb.cpp.i
.PHONY : src/Game/WObjects/Bomb.cpp.i

src/Game/WObjects/Bomb.s: src/Game/WObjects/Bomb.cpp.s
.PHONY : src/Game/WObjects/Bomb.s

# target to generate assembly for a file
src/Game/WObjects/Bomb.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Bomb.cpp.s
.PHONY : src/Game/WObjects/Bomb.cpp.s

src/Game/WObjects/Fire.o: src/Game/WObjects/Fire.cpp.o
.PHONY : src/Game/WObjects/Fire.o

# target to build an object file
src/Game/WObjects/Fire.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Fire.cpp.o
.PHONY : src/Game/WObjects/Fire.cpp.o

src/Game/WObjects/Fire.i: src/Game/WObjects/Fire.cpp.i
.PHONY : src/Game/WObjects/Fire.i

# target to preprocess a source file
src/Game/WObjects/Fire.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Fire.cpp.i
.PHONY : src/Game/WObjects/Fire.cpp.i

src/Game/WObjects/Fire.s: src/Game/WObjects/Fire.cpp.s
.PHONY : src/Game/WObjects/Fire.s

# target to generate assembly for a file
src/Game/WObjects/Fire.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Fire.cpp.s
.PHONY : src/Game/WObjects/Fire.cpp.s

src/Game/WObjects/IWorldsObject.o: src/Game/WObjects/IWorldsObject.cpp.o
.PHONY : src/Game/WObjects/IWorldsObject.o

# target to build an object file
src/Game/WObjects/IWorldsObject.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/IWorldsObject.cpp.o
.PHONY : src/Game/WObjects/IWorldsObject.cpp.o

src/Game/WObjects/IWorldsObject.i: src/Game/WObjects/IWorldsObject.cpp.i
.PHONY : src/Game/WObjects/IWorldsObject.i

# target to preprocess a source file
src/Game/WObjects/IWorldsObject.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/IWorldsObject.cpp.i
.PHONY : src/Game/WObjects/IWorldsObject.cpp.i

src/Game/WObjects/IWorldsObject.s: src/Game/WObjects/IWorldsObject.cpp.s
.PHONY : src/Game/WObjects/IWorldsObject.s

# target to generate assembly for a file
src/Game/WObjects/IWorldsObject.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/IWorldsObject.cpp.s
.PHONY : src/Game/WObjects/IWorldsObject.cpp.s

src/Game/WObjects/Item.o: src/Game/WObjects/Item.cpp.o
.PHONY : src/Game/WObjects/Item.o

# target to build an object file
src/Game/WObjects/Item.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Item.cpp.o
.PHONY : src/Game/WObjects/Item.cpp.o

src/Game/WObjects/Item.i: src/Game/WObjects/Item.cpp.i
.PHONY : src/Game/WObjects/Item.i

# target to preprocess a source file
src/Game/WObjects/Item.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Item.cpp.i
.PHONY : src/Game/WObjects/Item.cpp.i

src/Game/WObjects/Item.s: src/Game/WObjects/Item.cpp.s
.PHONY : src/Game/WObjects/Item.s

# target to generate assembly for a file
src/Game/WObjects/Item.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Item.cpp.s
.PHONY : src/Game/WObjects/Item.cpp.s

src/Game/WObjects/Player.o: src/Game/WObjects/Player.cpp.o
.PHONY : src/Game/WObjects/Player.o

# target to build an object file
src/Game/WObjects/Player.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Player.cpp.o
.PHONY : src/Game/WObjects/Player.cpp.o

src/Game/WObjects/Player.i: src/Game/WObjects/Player.cpp.i
.PHONY : src/Game/WObjects/Player.i

# target to preprocess a source file
src/Game/WObjects/Player.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Player.cpp.i
.PHONY : src/Game/WObjects/Player.cpp.i

src/Game/WObjects/Player.s: src/Game/WObjects/Player.cpp.s
.PHONY : src/Game/WObjects/Player.s

# target to generate assembly for a file
src/Game/WObjects/Player.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Player.cpp.s
.PHONY : src/Game/WObjects/Player.cpp.s

src/Game/WObjects/Wall.o: src/Game/WObjects/Wall.cpp.o
.PHONY : src/Game/WObjects/Wall.o

# target to build an object file
src/Game/WObjects/Wall.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Wall.cpp.o
.PHONY : src/Game/WObjects/Wall.cpp.o

src/Game/WObjects/Wall.i: src/Game/WObjects/Wall.cpp.i
.PHONY : src/Game/WObjects/Wall.i

# target to preprocess a source file
src/Game/WObjects/Wall.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Wall.cpp.i
.PHONY : src/Game/WObjects/Wall.cpp.i

src/Game/WObjects/Wall.s: src/Game/WObjects/Wall.cpp.s
.PHONY : src/Game/WObjects/Wall.s

# target to generate assembly for a file
src/Game/WObjects/Wall.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Game/WObjects/Wall.cpp.s
.PHONY : src/Game/WObjects/Wall.cpp.s

src/GlobalEventManager.o: src/GlobalEventManager.cpp.o
.PHONY : src/GlobalEventManager.o

# target to build an object file
src/GlobalEventManager.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/GlobalEventManager.cpp.o
.PHONY : src/GlobalEventManager.cpp.o

src/GlobalEventManager.i: src/GlobalEventManager.cpp.i
.PHONY : src/GlobalEventManager.i

# target to preprocess a source file
src/GlobalEventManager.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/GlobalEventManager.cpp.i
.PHONY : src/GlobalEventManager.cpp.i

src/GlobalEventManager.s: src/GlobalEventManager.cpp.s
.PHONY : src/GlobalEventManager.s

# target to generate assembly for a file
src/GlobalEventManager.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/GlobalEventManager.cpp.s
.PHONY : src/GlobalEventManager.cpp.s

src/Rendering/Animation.o: src/Rendering/Animation.cpp.o
.PHONY : src/Rendering/Animation.o

# target to build an object file
src/Rendering/Animation.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Rendering/Animation.cpp.o
.PHONY : src/Rendering/Animation.cpp.o

src/Rendering/Animation.i: src/Rendering/Animation.cpp.i
.PHONY : src/Rendering/Animation.i

# target to preprocess a source file
src/Rendering/Animation.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Rendering/Animation.cpp.i
.PHONY : src/Rendering/Animation.cpp.i

src/Rendering/Animation.s: src/Rendering/Animation.cpp.s
.PHONY : src/Rendering/Animation.s

# target to generate assembly for a file
src/Rendering/Animation.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Rendering/Animation.cpp.s
.PHONY : src/Rendering/Animation.cpp.s

src/Rendering/AnimationManager.o: src/Rendering/AnimationManager.cpp.o
.PHONY : src/Rendering/AnimationManager.o

# target to build an object file
src/Rendering/AnimationManager.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Rendering/AnimationManager.cpp.o
.PHONY : src/Rendering/AnimationManager.cpp.o

src/Rendering/AnimationManager.i: src/Rendering/AnimationManager.cpp.i
.PHONY : src/Rendering/AnimationManager.i

# target to preprocess a source file
src/Rendering/AnimationManager.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Rendering/AnimationManager.cpp.i
.PHONY : src/Rendering/AnimationManager.cpp.i

src/Rendering/AnimationManager.s: src/Rendering/AnimationManager.cpp.s
.PHONY : src/Rendering/AnimationManager.s

# target to generate assembly for a file
src/Rendering/AnimationManager.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/Rendering/AnimationManager.cpp.s
.PHONY : src/Rendering/AnimationManager.cpp.s

src/StateStack.o: src/StateStack.cpp.o
.PHONY : src/StateStack.o

# target to build an object file
src/StateStack.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/StateStack.cpp.o
.PHONY : src/StateStack.cpp.o

src/StateStack.i: src/StateStack.cpp.i
.PHONY : src/StateStack.i

# target to preprocess a source file
src/StateStack.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/StateStack.cpp.i
.PHONY : src/StateStack.cpp.i

src/StateStack.s: src/StateStack.cpp.s
.PHONY : src/StateStack.s

# target to generate assembly for a file
src/StateStack.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/StateStack.cpp.s
.PHONY : src/StateStack.cpp.s

src/States/GameMenuState.o: src/States/GameMenuState.cpp.o
.PHONY : src/States/GameMenuState.o

# target to build an object file
src/States/GameMenuState.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/States/GameMenuState.cpp.o
.PHONY : src/States/GameMenuState.cpp.o

src/States/GameMenuState.i: src/States/GameMenuState.cpp.i
.PHONY : src/States/GameMenuState.i

# target to preprocess a source file
src/States/GameMenuState.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/States/GameMenuState.cpp.i
.PHONY : src/States/GameMenuState.cpp.i

src/States/GameMenuState.s: src/States/GameMenuState.cpp.s
.PHONY : src/States/GameMenuState.s

# target to generate assembly for a file
src/States/GameMenuState.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/States/GameMenuState.cpp.s
.PHONY : src/States/GameMenuState.cpp.s

src/States/GameState.o: src/States/GameState.cpp.o
.PHONY : src/States/GameState.o

# target to build an object file
src/States/GameState.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/States/GameState.cpp.o
.PHONY : src/States/GameState.cpp.o

src/States/GameState.i: src/States/GameState.cpp.i
.PHONY : src/States/GameState.i

# target to preprocess a source file
src/States/GameState.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/States/GameState.cpp.i
.PHONY : src/States/GameState.cpp.i

src/States/GameState.s: src/States/GameState.cpp.s
.PHONY : src/States/GameState.s

# target to generate assembly for a file
src/States/GameState.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/States/GameState.cpp.s
.PHONY : src/States/GameState.cpp.s

src/States/MainMenuState.o: src/States/MainMenuState.cpp.o
.PHONY : src/States/MainMenuState.o

# target to build an object file
src/States/MainMenuState.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/States/MainMenuState.cpp.o
.PHONY : src/States/MainMenuState.cpp.o

src/States/MainMenuState.i: src/States/MainMenuState.cpp.i
.PHONY : src/States/MainMenuState.i

# target to preprocess a source file
src/States/MainMenuState.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/States/MainMenuState.cpp.i
.PHONY : src/States/MainMenuState.cpp.i

src/States/MainMenuState.s: src/States/MainMenuState.cpp.s
.PHONY : src/States/MainMenuState.s

# target to generate assembly for a file
src/States/MainMenuState.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/States/MainMenuState.cpp.s
.PHONY : src/States/MainMenuState.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/bin.dir/build.make CMakeFiles/bin.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... bin"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... tinyxml"
	@echo "... src/Application.o"
	@echo "... src/Application.i"
	@echo "... src/Application.s"
	@echo "... src/Common/Button.o"
	@echo "... src/Common/Button.i"
	@echo "... src/Common/Button.s"
	@echo "... src/Common/Interfaces/IAppState.o"
	@echo "... src/Common/Interfaces/IAppState.i"
	@echo "... src/Common/Interfaces/IAppState.s"
	@echo "... src/Common/Interfaces/IEventManager.o"
	@echo "... src/Common/Interfaces/IEventManager.i"
	@echo "... src/Common/Interfaces/IEventManager.s"
	@echo "... src/Game/Attributes/PlayerEventHandler.o"
	@echo "... src/Game/Attributes/PlayerEventHandler.i"
	@echo "... src/Game/Attributes/PlayerEventHandler.s"
	@echo "... src/Game/Attributes/PlayerEventManager.o"
	@echo "... src/Game/Attributes/PlayerEventManager.i"
	@echo "... src/Game/Attributes/PlayerEventManager.s"
	@echo "... src/Game/CollisionManager.o"
	@echo "... src/Game/CollisionManager.i"
	@echo "... src/Game/CollisionManager.s"
	@echo "... src/Game/GameLevel.o"
	@echo "... src/Game/GameLevel.i"
	@echo "... src/Game/GameLevel.s"
	@echo "... src/Game/Map/Cell.o"
	@echo "... src/Game/Map/Cell.i"
	@echo "... src/Game/Map/Cell.s"
	@echo "... src/Game/Map/GameMap.o"
	@echo "... src/Game/Map/GameMap.i"
	@echo "... src/Game/Map/GameMap.s"
	@echo "... src/Game/WObjects/Actor.o"
	@echo "... src/Game/WObjects/Actor.i"
	@echo "... src/Game/WObjects/Actor.s"
	@echo "... src/Game/WObjects/Bomb.o"
	@echo "... src/Game/WObjects/Bomb.i"
	@echo "... src/Game/WObjects/Bomb.s"
	@echo "... src/Game/WObjects/Fire.o"
	@echo "... src/Game/WObjects/Fire.i"
	@echo "... src/Game/WObjects/Fire.s"
	@echo "... src/Game/WObjects/IWorldsObject.o"
	@echo "... src/Game/WObjects/IWorldsObject.i"
	@echo "... src/Game/WObjects/IWorldsObject.s"
	@echo "... src/Game/WObjects/Item.o"
	@echo "... src/Game/WObjects/Item.i"
	@echo "... src/Game/WObjects/Item.s"
	@echo "... src/Game/WObjects/Player.o"
	@echo "... src/Game/WObjects/Player.i"
	@echo "... src/Game/WObjects/Player.s"
	@echo "... src/Game/WObjects/Wall.o"
	@echo "... src/Game/WObjects/Wall.i"
	@echo "... src/Game/WObjects/Wall.s"
	@echo "... src/GlobalEventManager.o"
	@echo "... src/GlobalEventManager.i"
	@echo "... src/GlobalEventManager.s"
	@echo "... src/Rendering/Animation.o"
	@echo "... src/Rendering/Animation.i"
	@echo "... src/Rendering/Animation.s"
	@echo "... src/Rendering/AnimationManager.o"
	@echo "... src/Rendering/AnimationManager.i"
	@echo "... src/Rendering/AnimationManager.s"
	@echo "... src/StateStack.o"
	@echo "... src/StateStack.i"
	@echo "... src/StateStack.s"
	@echo "... src/States/GameMenuState.o"
	@echo "... src/States/GameMenuState.i"
	@echo "... src/States/GameMenuState.s"
	@echo "... src/States/GameState.o"
	@echo "... src/States/GameState.i"
	@echo "... src/States/GameState.s"
	@echo "... src/States/MainMenuState.o"
	@echo "... src/States/MainMenuState.i"
	@echo "... src/States/MainMenuState.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

