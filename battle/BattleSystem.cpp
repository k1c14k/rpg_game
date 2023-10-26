//
// Created by marek on 20.10.23.
//

#include <iostream>
#include "../include/battle.h"

BattleSystem *BattleSystem::getInstance() {
    static BattleSystem instance;
    return &instance;
}

void BattleSystem::start_battle(Character *player, Character *opponent) {
    std::cout << "Battle started!" << std::endl;
    unsigned int initial_oponent_health = opponent->get_health();
    unsigned int initial_player_health = player->get_health();
    while ((player->get_health() > 0 && player->get_health() <= initial_player_health) &&
           (opponent->get_health() > 0 && opponent->get_health() <= initial_oponent_health)) {
        std::cout << "Player health: " << player->get_health() << std::endl;
        std::cout << "Opponent health: " << opponent->get_health() << std::endl;
        std::cout << "Choose action: " << std::endl;
        std::cout << "Possible options: attack, ability" << std::endl;
        std::cout << "Choose action: ";
        std::string action;
        do {
            std::cin >> action;
        } while (action != "attack" && action != "ability");

        if (action == "attack") {
            opponent->take_damage(player->get_attack());
        } else if (action == "ability") {
            std::cout << "Choose ability: " << std::endl;
            for (auto &ability: player->get_abilities()) {
                std::cout << ability.first << " - " << ability.second->get_title() << std::endl;
            }
            std::cout << "Choose ability: ";
            std::string ability;
            do {
                std::cin >> ability;
            } while (player->get_abilities().find(ability) == player->get_abilities().end());
            opponent->take_damage(player->get_ability(ability)->get_damage());
        }
    }
    if (opponent->get_health() > initial_oponent_health) {
        std::cout << "You won!" << std::endl;
        player->add_experience(opponent->get_level() * 10);
    }
    if (player->get_health() > initial_player_health) {
        std::cout << "You lost!" << std::endl;
        player->subtract_experience(opponent->get_level() * 2);
    }
}

