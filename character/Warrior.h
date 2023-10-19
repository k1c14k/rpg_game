//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_WARRIOR_H
#define RPG_GAME_WARRIOR_H

#include "Character.h"

class Warrior: public Character {
public:
    explicit Warrior(const std::string& name): Character(name, 1, 150, 0, {}) {};

    std::string character_class() override;
};

class SwordAbility: public Ability {
public:
    std::string get_title() override;
    explicit SwordAbility(unsigned int level): Ability(level) {};
};

class DaggerAbility: public Ability {
public:
    std::string get_title() override;
    explicit DaggerAbility(unsigned int level): Ability(level) {};
};


#endif //RPG_GAME_WARRIOR_H
