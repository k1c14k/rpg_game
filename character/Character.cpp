//
// Created by marek on 19.10.23.
//



#include <utility>
#include <random>
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

unsigned long Character::get_attack() const {
    unsigned long max_attack = level < 5 ? level : 5;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<unsigned int> dist(0, max_attack);
    return dist(mt);
}

void Character::take_damage(unsigned long damage) {
    health -= damage;
}

Ability *Character::get_ability(const std::string &ability) {
    return abilities[ability];
}

