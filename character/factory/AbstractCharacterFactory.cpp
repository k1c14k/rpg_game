//
// Created by marek on 21.10.23.
//

#include <stdexcept>
#include "../../include/character/factory.h"
#include "../../include/util.h"

AbstractCharacterFactory *AbstractCharacterFactory::get_factory(const std::string &character_class) {
    if (character_class == "warrior") {
        return new WarriorCharacterFactory();
    } else if (character_class == "mage") {
        return new MageCharacterFactory();
    } else if (character_class == "archer") {
        return new ArcherCharacterFactory();
    }
    throw std::invalid_argument("Invalid character class");
}

Character *AbstractCharacterFactory::create_opponent(unsigned int level) {
    static std::vector<std::string> CLASS_CHOICES = {"warrior", "mage", "archer"};
    auto character_class = random_choice(CLASS_CHOICES);
    AbstractCharacterFactory *factory = get_factory(character_class);
    return factory->create_random_opponent(level);
}
