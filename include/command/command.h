//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_COMMAND_H
#define RPG_GAME_COMMAND_H

#include <string>

class Command {
public:
    virtual void run(std::string params) = 0;

    virtual std::string get_title() = 0;
};

#endif //RPG_GAME_COMMAND_H
