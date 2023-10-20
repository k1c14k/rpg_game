//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_ABILITY_H
#define RPG_GAME_ABILITY_H

#include <string>

class Ability {
protected:
    explicit Ability(unsigned int level) : level(level) {}

    unsigned int level;
public:
    virtual std::string get_title() = 0;

    [[nodiscard]] unsigned int get_level() const;

    void set_level(unsigned long i);

    [[nodiscard]] virtual unsigned long get_damage() const = 0;
};

class FireballAbility : public Ability {
public:
    std::string get_title() override;

    explicit FireballAbility(unsigned int level) : Ability(level) {};

    [[nodiscard]] unsigned long get_damage() const override;
};

class IceballAbility : public Ability {
public:
    std::string get_title() override;

    explicit IceballAbility(unsigned int level) : Ability(level) {};

    [[nodiscard]] unsigned long get_damage() const override;
};

class SwordAbility : public Ability {
public:
    std::string get_title() override;

    [[nodiscard]] unsigned long get_damage() const override;

    explicit SwordAbility(unsigned int level) : Ability(level) {};
};

class DaggerAbility : public Ability {
public:
    std::string get_title() override;

    [[nodiscard]] unsigned long get_damage() const override;

    explicit DaggerAbility(unsigned int level) : Ability(level) {};
};

class BowAbility : public Ability {
public:
    std::string get_title() override;

    [[nodiscard]] unsigned long get_damage() const override;

    explicit BowAbility(unsigned int level) : Ability(level) {};
};

class CrossBowAbility : public Ability {
public:
    std::string get_title() override;

    [[nodiscard]] unsigned long get_damage() const override;

    explicit CrossBowAbility(unsigned int level) : Ability(level) {};
};

#endif //RPG_GAME_ABILITY_H
