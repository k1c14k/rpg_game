//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_CHARACTER_H
#define RPG_GAME_CHARACTER_H

#include <string>
#include <map>
#include "ability.h"

class Character {
private:
    std::string name;
    unsigned int level;
    unsigned int health;
    unsigned int experience;
    std::map<std::string, Ability *> abilities;
protected:
public:
    Character(std::string name, unsigned int level, unsigned int health, unsigned int experience,
              const std::map<std::string, Ability *> &abilities);

    [[nodiscard]] const std::string &get_name() const;

    [[nodiscard]] unsigned int get_level() const;

    [[nodiscard]] unsigned int get_health() const;

    [[nodiscard]] unsigned int get_experience() const;

    [[nodiscard]] const std::map<std::string, Ability *> &get_abilities() const;

    virtual std::string character_class() = 0;

    void add_ability(const char *string, Ability *pAbility);

    [[nodiscard]] unsigned long get_attack() const;

    void take_damage(unsigned long damage);

    Ability *get_ability(const std::string &ability);
};

class Warrior : public Character {
public:
    explicit Warrior(const std::string &name) : Character(name, 1, 150, 0, {}) {};

    std::string character_class() override;
};



class Mage : public Character {
public:
    explicit Mage(const std::string &name) : Character(name, 1, 75, 0, {}) {};

    std::string character_class() override;
};


class Archer : public Character {
public:
    explicit Archer(const std::string &name) : Character(name, 1, 100, 0, {}) {};

    std::string character_class() override;
};

#endif //RPG_GAME_CHARACTER_H
