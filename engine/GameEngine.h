//
// Created by marek on 18.10.23.
//

#ifndef RPG_GAME_GAMEENGINE_H
#define RPG_GAME_GAMEENGINE_H


#include <string>
#include <utility>
#include <map>
#include "Command.h"
#include "../character/Character.h"

class GameEngine {
public:
    [[maybe_unused]] explicit GameEngine(std::string title);;
    void run();

    void set_finished(bool value);

    std::map<std::string, Command *> get_commands();

    void set_player_character(Character *pCharacter);

    void add_command(const char *string, Command *pCommand);

    Character * get_player_character();

private:
    std::string title;
    bool finished = false;
    std::map<std::string, Command*> commands;
    Character *player_character;

};


#endif //RPG_GAME_GAMEENGINE_H
