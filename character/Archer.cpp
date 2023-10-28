//
// Created by diabolic on 20.10.23.
//
#include "../include/character/character.h"
#include "../include/util.h"

std::string Archer::character_class() {
    return "archer";
}

unsigned long Archer::get_attack() const {
    return random_uint(20);
}
