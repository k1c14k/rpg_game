//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_CHARACTER_H
#define RPG_GAME_CHARACTER_H

#include <string>
#include <map>
#include <utility>
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

    [[nodiscard]] unsigned long get_attack() const;

    void take_damage(unsigned long damage);

    void add_experience(unsigned long experience_gained);

    void subtract_experience(unsigned long experience_lost);

    Ability *get_ability(const std::string &ability);

    [[nodiscard]] bool is_alive() const;
};

class Warrior : public Character {
public:
    explicit Warrior(const std::string &name, const std::map<std::string, Ability *> &abilities, unsigned int level = 1)
            : Character(name, level, 150, 0, abilities) {};

    std::string character_class() override;
};



class Mage : public Character {
public:
    explicit Mage(const std::string &name, const std::map<std::string, Ability *> &abilities, unsigned int level = 1)
            : Character(name, level, 75, 0, abilities) {};

    std::string character_class() override;
};


class Archer : public Character {
public:
    explicit Archer(const std::string &name, const std::map<std::string, Ability *> &abilities, unsigned int level = 1)
            : Character(name, level, 100, 0, abilities) {};

    std::string character_class() override;
};

#endif //RPG_GAME_CHARACTER_H
