//
// Created by marek on 28.10.23.
//

#include "../include/character/character.h"

const std::string &PlayerCharacter::get_name() const {
    return character->get_name();
}

const std::map<std::string, Ability *> &PlayerCharacter::get_abilities() const {
    return character->get_abilities();
}

void PlayerCharacter::take_damage(unsigned long damage) {
    character->take_damage(damage);
}

Ability *PlayerCharacter::get_ability(const std::string &ability) {
    return character->get_ability(ability);
}

bool PlayerCharacter::is_alive() const {
    return character->is_alive();
}

std::string PlayerCharacter::character_class() {
    return character->character_class();
}

unsigned long PlayerCharacter::get_attack() const {
    return character->get_attack();
}

unsigned int PlayerCharacter::get_health() const {
    return character->get_health();
}

unsigned int PlayerCharacter::get_level() const {
    return level;
}

unsigned int PlayerCharacter::get_experience() const {
    return experience;
}

void PlayerCharacter::add_experience(unsigned int experience_gained) {
    experience += experience_gained;
    if (experience >= level * 100) {
        level++;
        experience = 0;
    }
}

void PlayerCharacter::subtract_experience(int experience_lost) {
    experience -= experience_lost;
    if (experience < 0) {
        level--;
        experience = level * 100 - experience;
    }
}
