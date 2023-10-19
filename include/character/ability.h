//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_ABILITY_H
#define RPG_GAME_ABILITY_H

#include <string>

class Ability {
private:
    unsigned int level;
protected:
    explicit Ability(unsigned int level) : level(level) {}

public:
    virtual std::string get_title() = 0;

    unsigned int get_level() const;
};

class FireballAbility : public Ability {
public:
    std::string get_title() override;

    explicit FireballAbility(unsigned int level) : Ability(level) {};
};

class IceballAbility : public Ability {
public:
    std::string get_title() override;

    explicit IceballAbility(unsigned int level) : Ability(level) {};
};

class SwordAbility : public Ability {
public:
    std::string get_title() override;

    explicit SwordAbility(unsigned int level) : Ability(level) {};
};

class DaggerAbility : public Ability {
public:
    std::string get_title() override;

    explicit DaggerAbility(unsigned int level) : Ability(level) {};
};

#endif //RPG_GAME_ABILITY_H
