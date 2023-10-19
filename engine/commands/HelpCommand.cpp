//
// Created by marek on 18.10.23.
//

#include <iostream>
#include "HelpCommand.h"

void HelpCommand::run(std::string params) {
    std::cout << "Available commands:" << std::endl;
    for (auto &command : engine->get_commands()) {
        std::cout << command.first << " - " << command.second->get_title() << std::endl;
    }
}

HelpCommand::HelpCommand(GameEngine *engine) : engine(engine) {}

std::string HelpCommand::get_title() {
    return "Prints this help";
}
