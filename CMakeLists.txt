cmake_minimum_required(VERSION 3.26)
project(rpg_game)

set(CMAKE_CXX_STANDARD 23)

add_executable(rpg_game main.cpp
        engine/GameEngine.cpp
        engine/commands/QuitCommand.cpp
        engine/commands/StartNewGameCommand.cpp
        engine/commands/HelpCommand.cpp
        character/Character.cpp
        character/Ability.cpp
        character/Warrior.cpp
        character/Mage.cpp
        include/engine.h
        include/command/engine_commands.h
        include/command/command.h
        include/character/character.h
        include/character/ability.h
        include/character/factory.h
        character/Archer.cpp
        battle/BattleSystem.cpp
        include/battle.h
        battle/BattleCommand.cpp
        character/factory/AbstractCharacterFactory.cpp
        character/factory/WarriorCharacterFactory.cpp
        character/factory/MageCharacterFactory.cpp
        character/factory/ArcherCharacterFactory.cpp
        include/util.h
        util.cpp
        character/PlayerCharacter.cpp)
