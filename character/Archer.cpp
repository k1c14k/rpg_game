//
// Created by diabolic on 20.10.23.
//
#include "../include/character/character.h"

std::string Archer::character_class() {
    return "archer";
}

std::string BowAbility::get_title() {
    return "Bow fight";
}

unsigned long BowAbility::get_damage() const {
    return level * 10;
}

std::string CrossBowAbility::get_title() {
    return "CrossBow fight";
}

unsigned long CrossBowAbility::get_damage() const {
    return level * 5;
}
