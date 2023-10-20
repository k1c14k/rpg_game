//
// Created by marek on 20.10.23.
//

#ifndef RPG_GAME_BATTLE_H
#define RPG_GAME_BATTLE_H

#include "command/command.h"
#include "character/character.h"

class BattleCommand : public Command {
private:
    Character *player_character;
public:
    void run(std::string params) override;

    std::string get_title() override;

    explicit BattleCommand(Character *pCharacter) : player_character(pCharacter) {};

    static bool is_valid_difficulty(const std::string &basicString);
};

class BattleSystem {

public:
    static BattleSystem *getInstance();

    static void start_battle(Character *player, Character *opponent);
};

#endif //RPG_GAME_BATTLE_H
