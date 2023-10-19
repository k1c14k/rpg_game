//
// Created by marek on 19.10.23.
//

#include <stdexcept>
#include <iostream>
#include "CharacterFactory.h"
#include "Warrior.h"
#include "Mage.h"

Character *PlayerCharacterFactory::createWarrior(const std::string &name) {
    auto *warrior = new Warrior(name);
    std::cout << "Pick your preferred weapon:" << std::endl;
    std::cout << "Possible options: sword, dagger" << std::endl;
    std::string weapon;
    do {
        std::cin >> weapon;
    } while (!is_valid_weapon(weapon));

    if (weapon == "sword") {
        warrior->add_ability("sword", new SwordAbility(3));
        warrior->add_ability("dagger", new DaggerAbility(1));
    } else if (weapon == "dagger") {
        warrior->add_ability("sword", new SwordAbility(1));
        warrior->add_ability("dagger", new DaggerAbility(3));
    }

    return warrior;
}

Character *PlayerCharacterFactory::createMage(const std::string &name) {
    auto mage = new Mage(name);
    std::cout << "Pick your flavor of magic:" << std::endl;
    std::cout << "Possible options: fire, ice" << std::endl;
    std::string magic;
    do {
        std::cin >> magic;
    } while (!is_valid_magic_type(magic));

    if (magic == "fire") {
        mage->add_ability("fireball", new FireballAbility(3));
        mage->add_ability("iceball", new IceballAbility(1));
    } else if (magic == "ice") {
        mage->add_ability("fireball", new FireballAbility(1));
        mage->add_ability("iceball", new IceballAbility(3));
    }
    return mage;
}

Character *PlayerCharacterFactory::createArcher(const std::string &name) {
    auto *archer = new Archer(name);
    return archer;
}

bool PlayerCharacterFactory::is_valid_weapon(const std::string& basicString) {
    if (basicString == "sword" || basicString == "dagger") {
        return true;
    }
    std::cout << "Invalid weapon. Pick again: " << std::endl;
    return false;
}

bool PlayerCharacterFactory::is_valid_magic_type(std::string magic) {
    if (magic != "fire" && magic != "ice") {
        std::cout << "Invalid magic type. Pick again: " << std::endl;
        return false;
    }
    return true;
}

Character *CharacterFactory::create(const std::string &character_class, const std::string &name) {
    if (character_class == "warrior") {
        return createWarrior(name);
    } else if (character_class == "mage") {
        return createMage(name);
    } else if (character_class == "archer") {
        return createArcher(name);
    } else {
        throw std::invalid_argument("Invalid class");
    }
}
