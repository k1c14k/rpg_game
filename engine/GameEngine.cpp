//
// Created by marek on 18.10.23.
//

#include <iostream>
#include "../include/engine.h"
#include "../include/command/engine_commands.h"

void GameEngine::run() {
    std::cout << "Welcome to " << title << std::endl;
    while (!finished) {
        std::string command;
        std::cin >> command;
        unsigned long separator_position = command.find(' ');
        std::string first_word = command.substr(0, separator_position);
        std::string params = command.substr(separator_position + 1);
        
        Command *&pCommand = commands[first_word];
        if (pCommand == nullptr) {
            std::cout << "Unknown command: " << first_word << std::endl;
            continue;
        }
        
        pCommand->run(params);
    }
}

void GameEngine::set_finished(bool value) {
    finished = value;
}

[[maybe_unused]] GameEngine::GameEngine(std::string title) : title(std::move(title)) {
    auto *pQuitCommand = new QuitCommand(this);
    commands["exit"] = pQuitCommand;
    commands["quit"] = pQuitCommand;
    auto *pStartNewGameCommand = new StartNewGameCommand(this);
    commands["start"] = pStartNewGameCommand;
    auto *pHelpCommand = new HelpCommand(this);
    commands["help"] = pHelpCommand;
}

std::map<std::string, Command*> GameEngine::get_commands() {
    return commands;
}

void GameEngine::set_player_character(PlayerCharacter *pCharacter) {
    player_character = pCharacter;
}

void GameEngine::add_command(const char *string, Command *pCommand) {
    commands[string] = pCommand;
}

PlayerCharacter *GameEngine::get_player_character() {
    return player_character;
}
