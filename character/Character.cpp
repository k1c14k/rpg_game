//
// Created by marek on 19.10.23.
//



#include <utility>
#include "../include/character/character.h"

Character::Character(std::string name, unsigned int level, unsigned int health, unsigned int experience,
                     const std::map<std::string, Ability *> &abilities) : name(std::move(name)), level(level), health(health),
                                                                          experience(experience),
                                                                          abilities(abilities) {}

const std::string &Character::get_name() const {
    return name;
}

unsigned int Character::get_level() const {
    return level;
}

unsigned int Character::get_health() const {
    return health;
}

unsigned int Character::get_experience() const {
    return experience;
}

const std::map<std::string, Ability *> &Character::get_abilities() const {
    return abilities;
}

void Character::add_ability(const char *string, Ability *pAbility) {
    abilities[string] = pAbility;
}

