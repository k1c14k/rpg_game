//
// Created by marek on 19.10.23.
//


#include <stdexcept>
#include "../include/character/ability.h"

unsigned int Ability::get_level() const {
    return level;
}

void Ability::set_level(unsigned long i) {
    level = i;
}

Ability *Ability::of(const char *name, unsigned int level) {
    static std::map<std::string, Ability *> TEMPLATES;

    if (TEMPLATES.empty()) {
        TEMPLATES = set_templates();
    }

    Ability *template_ability = TEMPLATES[name];
    if (template_ability == nullptr) {
        throw std::invalid_argument("Invalid ability name");
    }
    auto *result = new Ability(*template_ability, level);
    result->set_level(level);
    return result;
}

Ability::Ability(Ability &template_ability) {
    level = template_ability.level;
    title = template_ability.title;
}

std::string Ability::get_title() const {
    return title;
}

unsigned long Ability::get_damage() const {
    return level * 10;
}

std::map<std::string, Ability *> Ability::set_templates() {
    std::map<std::string, Ability *> result;
    result["sword"] = new Ability(1, "Sword fight");
    result["dagger"] = new Ability(1, "Dagger fight");
    result["bow"] = new Ability(1, "Bow fight");
    result["crossbow"] = new Ability(1, "Crossbow fight");
    result["fireball"] = new Ability(1, "Fireball");
    result["iceball"] = new Ability(1, "Ice ball");
    return result;
}

Ability::Ability(Ability ability, unsigned int level) : Ability(ability) {
    set_level(level);
}
