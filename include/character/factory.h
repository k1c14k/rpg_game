//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_FACTORY_H
#define RPG_GAME_FACTORY_H

#include "character.h"

class CharacterFactory {
public:
    virtual Character *createWarrior(const std::string &name) = 0;

    virtual Character *createMage(const std::string &name) = 0;

    virtual Character *createArcher(const std::string &name) = 0;

    Character *create(const std::string &character_class, const std::string &name);
};

class PlayerCharacterFactory : public CharacterFactory {
public:
    Character *createWarrior(const std::string &name) override;

    Character *createMage(const std::string &name) override;

    Character *createArcher(const std::string &name) override;

    static bool is_valid_weapon(const std::string &basicString);

    static bool is_valid_magic_type(const std::string &magic);

    static bool is_valid_tension_weapon(std::string &basicString);
};

#endif //RPG_GAME_FACTORY_H
