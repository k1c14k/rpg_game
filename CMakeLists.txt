cmake_minimum_required(VERSION 3.26)
project(rpg_game)

set(CMAKE_CXX_STANDARD 23)

add_executable(rpg_game main.cpp
        engine/GameEngine.cpp
        engine/GameEngine.h
        engine/Command.h
        engine/commands/QuitCommand.cpp
        engine/commands/QuitCommand.h
        engine/commands/StartNewGameCommand.cpp
        engine/commands/StartNewGameCommand.h
        engine/commands/HelpCommand.cpp
        engine/commands/HelpCommand.h
        character/Character.cpp
        character/Character.h
        character/Ability.cpp
        character/Ability.h
        character/CharacterFactory.cpp
        character/CharacterFactory.h
        character/Warrior.cpp
        character/Warrior.h
        character/Mage.cpp
        character/Mage.h)
