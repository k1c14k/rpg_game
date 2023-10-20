//
// Created by marek on 19.10.23.
//


#include "../include/character/ability.h"

unsigned int Ability::get_level() const {
    return level;
}

void Ability::set_level(unsigned long i) {
    level = i;
}
