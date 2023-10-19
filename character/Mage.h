//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_MAGE_H
#define RPG_GAME_MAGE_H


#include "Character.h"

class Mage: public Character {
public:
    explicit Mage(const std::string& name): Character(name, 1, 75, 0, {}) {};
    std::string character_class() override;
};

class FireballAbility: public Ability {
public:
    std::string get_title() override;
    explicit FireballAbility(unsigned int level): Ability(level) {};
};

class IceballAbility: public Ability {
public:
    std::string get_title() override;
    explicit IceballAbility(unsigned int level): Ability(level) {};
};

#endif //RPG_GAME_MAGE_H
