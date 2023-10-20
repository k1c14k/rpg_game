//
// Created by marek on 19.10.23.
//



#include "../include/character/character.h"

std::string Mage::character_class() {
    return "mage";
}

std::string FireballAbility::get_title() {
    return "fireball";
}

unsigned long FireballAbility::get_damage() const {
    return level * 10;
}

std::string IceballAbility::get_title() {
    return "ice ball";
}

unsigned long IceballAbility::get_damage() const {
    return level * 5;
}
