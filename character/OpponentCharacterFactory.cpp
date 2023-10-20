//
// Created by marek on 20.10.23.
//


#include <random>
#include "../include/character/character.h"
#include "../include/character/factory.h"

Character *OpponentCharacterFactory::createWarrior(const std::string &name) {
    return new Warrior(name);
}

Character *OpponentCharacterFactory::createMage(const std::string &name) {
    return new Mage(name);
}

Character *OpponentCharacterFactory::createArcher(const std::string &name) {
    return new Archer(name);
}

Character *OpponentCharacterFactory::createRandomOpponent(const unsigned long level) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 2);
    unsigned long character_class = dist(mt);
    std::string name = generate_random_name();

    Character *character;
    switch (character_class) {
        case 0:
            character = createWarrior(name);
            break;
        case 1:
            character = createMage(name);
            break;
        case 2:
            character = createArcher(name);
            break;
        default:
            character = createWarrior(name);
    }

    unsigned long ability_points = level * 4;
    distribute_ability_points(character, ability_points);
}

std::string OpponentCharacterFactory::generate_random_name() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 2);
    unsigned long name = dist(mt);
    switch (name) {
        case 0:
            return "Goblin";
        case 1:
            return "Orc";
        case 2:
            return "Troll";
        default:
            return "Blob";
    }
}

void OpponentCharacterFactory::distribute_ability_points(Character *pCharacter, unsigned long points) {
    auto abilities = pCharacter->get_abilities();
    std::random_device rd;
    std::mt19937 mt(rd());
    for (auto &ability: abilities) {
        std::uniform_int_distribution<unsigned int> dist(0, points);
        unsigned long ability_points = dist(mt);
        points -= ability_points;
        ability.second->set_level(ability_points);
    }
}
