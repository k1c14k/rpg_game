//
// Created by marek on 20.10.23.
//

#include <iostream>
#include "../include/battle.h"
#include "../include/character/factory.h"

void BattleCommand::run(std::string params) {
    std::cout << "Pick opponent difficulty: " << std::endl;
    std::cout << "Possible options: easy, normal, hard" << std::endl;
    std::cout << "Choose difficulty: ";
    std::string difficulty;
    do {
        std::cin >> difficulty;
    } while (!is_valid_difficulty(difficulty));

    unsigned int opponent_level = 0;

    if (difficulty == "easy") {
        opponent_level = player_character->get_level() - 1;
    } else if (difficulty == "normal") {
        opponent_level = player_character->get_level();
    } else if (difficulty == "hard") {
        opponent_level = player_character->get_level() + 1;
    }

    opponent_level = opponent_level >= 1 ? opponent_level : 1;

    auto *factory = new OpponentCharacterFactory();
    Character *opponent = factory->createRandomOpponent(opponent_level);
    BattleSystem::start_battle(player_character, opponent);
}

std::string BattleCommand::get_title() {
    return "Start battle";
}

bool BattleCommand::is_valid_difficulty(const std::string &basicString) {
    if (basicString == "easy" || basicString == "normal" || basicString == "hard") {
        return true;
    }
    std::cout << "Invalid difficulty. Choose again: ";
    return false;
}
