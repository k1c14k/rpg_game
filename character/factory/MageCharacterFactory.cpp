//
// Created by marek on 21.10.23.
//

#include "../../include/character/factory.h"
#include "../../include/util.h"

Character *MageCharacterFactory::create_player(std::string &name) {
    std::string magic = prompt_for_choice("Pick your flavor of magic:", MAGIC_CHOICES);

    std::map<std::string, Ability *> abilities;

    if (magic == "fire") {
        abilities["fire"] = Ability::of("fire", 3);
        abilities["ice"] = Ability::of("ice", 1);
    } else if (magic == "ice") {
        abilities["fire"] = Ability::of("fire", 1);
        abilities["ice"] = Ability::of("ice", 3);
    }

    return new Mage(name, abilities);
}

Character *MageCharacterFactory::create_random_opponent(unsigned int level) {
    static std::vector<std::string> NAMES = {"Merlin", "Harry", "Gandalf"};
    std::map<std::string, Ability *> abilities;
    unsigned int ability_points = level * 4;
    unsigned int ability1 = random_uint(ability_points);
    unsigned int ability2 = ability_points - ability1;
    abilities["fire"] = Ability::of("fireball", ability1);
    abilities["ice"] = Ability::of("iceball", ability2);
    return new Mage(random_choice(NAMES), abilities, level);
}