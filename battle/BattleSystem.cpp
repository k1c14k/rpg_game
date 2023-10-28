//
// Created by marek on 20.10.23.
//

#include <iostream>
#include "../include/battle.h"


void BattleSystem::start_battle(PlayerCharacter *player, BaseCharacter *opponent) {
    std::cout << "Battle started!" << std::endl;

    while (player->is_alive() && opponent->is_alive()) {
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
    if (!opponent->is_alive()) {
        std::cout << "You won!" << std::endl;
        player->add_experience(experience_for_level(player->get_level()));
    }
    if (!player->is_alive()) {
        std::cout << "You lost!" << std::endl;
        player->subtract_experience(15);
    }
}

unsigned int BattleSystem::experience_for_level(unsigned int level) {
    return level * 50;
}

