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
public:

    [[nodiscard]] virtual const std::string &get_name() const = 0;

    [[nodiscard]] virtual const std::map<std::string, Ability *> &get_abilities() const = 0;

    virtual std::string character_class() = 0;

    [[nodiscard]] virtual unsigned long get_attack() const = 0;

    virtual void take_damage(unsigned long damage) = 0;

    virtual Ability *get_ability(const std::string &ability) = 0;

    [[nodiscard]] virtual bool is_alive() const = 0;

    [[nodiscard]] virtual unsigned int get_health() const = 0;
};

class BaseCharacter : public Character {
private:
    std::string name;
    unsigned int health;
    std::map<std::string, Ability *> abilities;
protected:
public:
    [[nodiscard]] const std::string &get_name() const override;

    [[nodiscard]] unsigned int get_health() const override;

    [[nodiscard]] const std::map<std::string, Ability *> &get_abilities() const override;

    void take_damage(unsigned long damage) override;

    Ability *get_ability(const std::string &ability) override;

    [[nodiscard]] bool is_alive() const override;

    BaseCharacter(std::string name, unsigned int health,
                  const std::map<std::string, Ability *> &abilities);
};

class Warrior : public BaseCharacter {
public:
    explicit Warrior(const std::string &name, const std::map<std::string, Ability *> &abilities)
            : BaseCharacter(name, 150, abilities) {};

    std::string character_class() override;

    [[nodiscard]] unsigned long get_attack() const override;
};


class Mage : public BaseCharacter {
public:
    explicit Mage(const std::string &name, const std::map<std::string, Ability *> &abilities)
            : BaseCharacter(name, 75, abilities) {};

    std::string character_class() override;

    [[nodiscard]] unsigned long get_attack() const override;
};


class Archer : public BaseCharacter {
public:
    explicit Archer(const std::string &name, const std::map<std::string, Ability *> &abilities)
            : BaseCharacter(name, 100, abilities) {};

    std::string character_class() override;

    [[nodiscard]] unsigned long get_attack() const override;
};

class PlayerCharacter : public Character {
private:
    Character *character;
    unsigned int level;
    unsigned int experience;
public:
    explicit PlayerCharacter(Character *character, unsigned int level, unsigned int experience) : character(character),
                                                                                                  level(level),
                                                                                                  experience(
                                                                                                          experience) {};

    [[nodiscard]] const std::string &get_name() const override;

    [[nodiscard]] const std::map<std::string, Ability *> &get_abilities() const override;

    std::string character_class() override;

    [[nodiscard]] unsigned long get_attack() const override;

    void take_damage(unsigned long damage) override;

    Ability *get_ability(const std::string &ability) override;

    [[nodiscard]] bool is_alive() const override;

    [[nodiscard]] unsigned int get_health() const override;

    [[nodiscard]] unsigned int get_level() const;

    [[nodiscard]] unsigned int get_experience() const;

    void add_experience(unsigned int experience_gained);

    void subtract_experience(int experience_lost);
};

#endif //RPG_GAME_CHARACTER_H
