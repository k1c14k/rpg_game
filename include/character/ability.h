//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_ABILITY_H
#define RPG_GAME_ABILITY_H

#include <string>
#include <map>
#include <utility>

class Ability {
private:
    Ability(Ability ability, unsigned int level);

    static std::map<std::string, Ability *> set_templates();

    Ability(Ability &template_ability);
protected:
    explicit Ability(unsigned int level, std::string title) : level(level), title(std::move(title)) {}

    unsigned int level;
    std::string title;
public:
    [[nodiscard]] std::string get_title() const;

    [[nodiscard]] unsigned int get_level() const;

    void set_level(unsigned long i);

    [[nodiscard]] unsigned long get_damage() const;

    static Ability *of(const char *name, unsigned int level);
};

#endif //RPG_GAME_ABILITY_H
