//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_ENGINE_H
#define RPG_GAME_ENGINE_H

#include "command/command.h"
#include "character/character.h"

class GameEngine {
public:
    [[maybe_unused]] explicit GameEngine(std::string title);;
    void run();

    void set_finished(bool value);

    std::map<std::string, Command *> get_commands();

    void set_player_character(PlayerCharacter *pCharacter);

    void add_command(const char *string, Command *pCommand);

    PlayerCharacter *get_player_character();

private:
    std::string title;
    bool finished = false;
    std::map<std::string, Command*> commands;
    PlayerCharacter *player_character = nullptr;

};
#endif //RPG_GAME_ENGINE_H
