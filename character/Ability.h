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
    explicit Ability(unsigned int level): level(level) {}

public:
    virtual std::string get_title() = 0;

    unsigned int get_level();
};


#endif //RPG_GAME_ABILITY_H
