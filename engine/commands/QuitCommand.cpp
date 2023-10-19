//
// Created by marek on 18.10.23.
//


#include "../../include/command/engine_commands.h"

void QuitCommand::run(std::string params) {
    engine->set_finished(true);
}

std::string QuitCommand::get_title() {
    return "Quits the game";
}
