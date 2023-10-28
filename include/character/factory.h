//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_FACTORY_H
#define RPG_GAME_FACTORY_H

#include <vector>
#include "character.h"

class AbstractCharacterFactory {
public:
    virtual PlayerCharacter * create_player(std::string &name) = 0;

    virtual BaseCharacter *create_random_opponent(unsigned int level) = 0;

    static BaseCharacter *create_opponent(unsigned int level);

    static AbstractCharacterFactory *get_factory(const std::string &character_class);
};

class WarriorCharacterFactory : public AbstractCharacterFactory {
private:
    std::vector<std::string> WEAPON_CHOICES = {"sword", "dagger"};
public:
    PlayerCharacter * create_player(std::string &name) override;

    BaseCharacter *create_random_opponent(unsigned int level) override;
};

class MageCharacterFactory : public AbstractCharacterFactory {
private:
    std::vector<std::string> MAGIC_CHOICES = {"fire", "ice"};
public:
    PlayerCharacter * create_player(std::string &name) override;

    BaseCharacter *create_random_opponent(unsigned int level) override;
};

class ArcherCharacterFactory : public AbstractCharacterFactory {
public:
    PlayerCharacter * create_player(std::string &name) override;

    BaseCharacter *create_random_opponent(unsigned int level) override;
};

#endif //RPG_GAME_FACTORY_H
