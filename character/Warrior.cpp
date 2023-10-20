//
// Created by marek on 19.10.23.
//

#include "../include/character/character.h"

std::string Warrior::character_class() {
    return "warrior";
}

std::string SwordAbility::get_title() {
    return "Sword fight";
}

unsigned long SwordAbility::get_damage() const {
    return level * 10;
}

std::string DaggerAbility::get_title() {
    return "Dagger fight";
}

unsigned long DaggerAbility::get_damage() const {
    return level * 5;
}
