//
// Created by marek on 19.10.23.
//

#include "../include/character/character.h"
#include "../include/util.h"

std::string Warrior::character_class() {
    return "warrior";
}

unsigned long Warrior::get_attack() const {
    return random_uint(30);
}
