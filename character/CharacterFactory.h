//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_CHARACTERFACTORY_H
#define RPG_GAME_CHARACTERFACTORY_H


#include "Character.h"

class CharacterFactory {
public:
    virtual Character *createWarrior(const std::string &name) = 0;
    virtual Character *createMage(const std::string &name) = 0;
    virtual Character *createArcher(const std::string &name) = 0;

    Character *create(const std::string& character_class, const std::string& name);
};

class PlayerCharacterFactory: public CharacterFactory {
public:
    Character *createWarrior(const std::string &name) override;
    Character *createMage(const std::string &name) override;
    Character *createArcher(const std::string &name) override;

    static bool is_valid_weapon(const std::string& basicString);

    static bool is_valid_magic_type(std::string magic);
};


#endif //RPG_GAME_CHARACTERFACTORY_H
