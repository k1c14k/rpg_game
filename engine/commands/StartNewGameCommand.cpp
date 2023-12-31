//
// Created by marek on 18.10.23.
//

#include <iostream>
#include "../../include/command/engine_commands.h"
#include "../../include/character/factory.h"
#include "../../include/battle.h"

void StartNewGameCommand::run(std::string params) {
    std::cout << "Starting new game..." << std::endl;
    std::string name = prompt_for_name();
    std::string character_class = prompt_for_class();
    AbstractCharacterFactory *factory = AbstractCharacterFactory::get_factory(character_class);
    PlayerCharacter *character = factory->create_player(name);

    engine->set_player_character(character);
    engine->add_command("info", new InfoCommand(engine));
    engine->add_command("battle", new BattleCommand(character));
}

std::string StartNewGameCommand::get_title() {
    return "Starts new game";
}

bool StartNewGameCommand::is_valid_class(const std::string& basicString) {
    if (basicString == "warrior" || basicString == "mage" || basicString == "archer") {
        return true;
    }
    std::cout << "Invalid class. Choose again: ";
    return false;
}

std::string StartNewGameCommand::prompt_for_name() {
    std::cout << "Choose your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;
    return name;
}

std::string StartNewGameCommand::prompt_for_class() {
    std::cout << "What is your character's class?" << std::endl;
    std::cout << "Possible options: warrior, mage, archer" << std::endl;
    std::cout << "Choose your class: ";
    std::string character_class;
    do {
        std::cin >> character_class;
    } while (!is_valid_class(character_class));
    return character_class;
}

void InfoCommand::run(std::string params) {
    std::cout << "Your character's name: " << engine->get_player_character()->get_name() << std::endl;
    std::cout << "Your character's class: " << engine->get_player_character()->character_class() << std::endl;
    std::cout << "Your character's level: " << engine->get_player_character()->get_level() << std::endl;
    std::cout << "Your character's experience: " << engine->get_player_character()->get_experience() << std::endl;
    std::cout << "Your character's health: " << engine->get_player_character()->get_health() << std::endl;
    std::cout << "Your character's abilities: " << std::endl;
    for (auto &ability : engine->get_player_character()->get_abilities()) {
        std::cout << ability.first << " - " << ability.second->get_title() << " level: " << ability.second->get_level() << std::endl;
    }
}

std::string InfoCommand::get_title() {
    return "Prints info about your character";
}
