//
// Created by marek on 21.10.23.
//

#include "../../include/character/factory.h"
#include "../../include/util.h"

Character *WarriorCharacterFactory::create_player(std::string &name) {
    std::string weapon_name = prompt_for_choice("Pick your preferred weapon:", WEAPON_CHOICES);

    std::map<std::string, Ability *> abilities;
    if (weapon_name == "sword") {
        abilities["sword"] = Ability::of("sword", 3);
        abilities["dagger"] = Ability::of("dagger", 1);
    } else if (weapon_name == "dagger") {
        abilities["sword"] = Ability::of("sword", 1);
        abilities["dagger"] = Ability::of("dagger", 3);
    }

    return new Warrior(name, abilities);
}

Character *WarriorCharacterFactory::create_random_opponent(unsigned int level) {
    static std::vector<std::string> NAMES = {"Goblin", "Orc", "Troll"};
    std::map<std::string, Ability *> abilities;
    unsigned int ability_points = level * 4;
    unsigned int ability1 = random_uint(ability_points);
    unsigned int ability2 = ability_points - ability1;
    abilities["sword"] = Ability::of("sword", ability1);
    abilities["dagger"] = Ability::of("dagger", ability2);
    auto *warrior = new Warrior(random_choice(NAMES), abilities, level);
    return warrior;
}
