//
// Created by marek on 21.10.23.
//

#include "../../include/character/factory.h"
#include "../../include/util.h"

Character *ArcherCharacterFactory::create_player(std::string &name) {
    static std::vector<std::string> TENSION_WEAPON_CHOICES = {"bow", "crossbow"};
    std::string tension_weapon = prompt_for_choice("Pick your preferred weapon:", TENSION_WEAPON_CHOICES);

    std::map<std::string, Ability *> abilities;
    if (tension_weapon == "bow") {
        abilities["bow"] = Ability::of("bow", 3);
        abilities["crossbow"] = Ability::of("crossbow", 1);
    } else if (tension_weapon == "crossbow") {
        abilities["bow"] = Ability::of("bow", 1);
        abilities["crossbow"] = Ability::of("crossbow", 3);
    }

    return new Archer(name, abilities);
}

Character *ArcherCharacterFactory::create_random_opponent(unsigned int level) {
    static std::vector<std::string> NAMES = {"Robin", "Legolas", "Hawkeye", "William"};
    std::map<std::string, Ability *> abilities;
    unsigned int ability_points = level * 4;
    unsigned int ability1 = random_uint(ability_points);
    unsigned int ability2 = ability_points - ability1;
    abilities["bow"] = Ability::of("bow", ability1);
    abilities["crossbow"] = Ability::of("crossbow", ability2);
    auto *archer = new Archer(random_choice(NAMES), abilities, level);
    return archer;
}