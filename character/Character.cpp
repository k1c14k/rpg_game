//
// Created by marek on 19.10.23.
//



#include <utility>
#include <random>
#include "../include/character/character.h"

BaseCharacter::BaseCharacter(std::string name, unsigned int health, const std::map<std::string, Ability *> &abilities)
        : name(std::move(name)),
          abilities(abilities),
          health(health) {}

const std::string &BaseCharacter::get_name() const {
    return name;
}

unsigned int BaseCharacter::get_health() const {
    return health;
}

const std::map<std::string, Ability *> &BaseCharacter::get_abilities() const {
    return abilities;
}

void BaseCharacter::take_damage(unsigned long damage) {
    unsigned long damage_taken = damage * 60;
    health -= damage_taken > health ? health : damage_taken;
}

Ability *BaseCharacter::get_ability(const std::string &ability) {
    return abilities[ability];
}

bool BaseCharacter::is_alive() const {
    return health > 0;
}