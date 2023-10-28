//
// Created by marek on 19.10.23.
//



#include "../include/character/character.h"
#include "../include/util.h"

std::string Mage::character_class() {
    return "mage";
}

unsigned long Mage::get_attack() const {
    return random_uint(10);
}
