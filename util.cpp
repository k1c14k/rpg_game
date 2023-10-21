//
// Created by marek on 21.10.23.
//
#include <iostream>
#include <random>
#include "include/util.h"

std::string prompt_for_choice(const std::string &prompt, std::vector<std::string> &choices) {
    std::cout << prompt << std::endl;
    std::cout << "Possible options: ";
    std::string last_choice = choices.back();
    for (auto &choice: choices) {
        if (choice == last_choice) {
            std::cout << choice << std::endl;
        } else {
            std::cout << choice << ", ";
        }
    }

    std::string input;
    do {
        std::cout << "Your choice: ";
        std::cin >> input;
    } while (std::find(choices.begin(), choices.end(), input) == choices.end());

    return input;
}

std::string random_choice(std::vector<std::string> &choices) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dis(0, choices.size() - 1);
    return choices[dis(gen)];
}

unsigned int random_uint(unsigned int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dis(0, max);
    return dis(gen);
}

