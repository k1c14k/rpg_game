//
// Created by marek on 21.10.23.
//

#ifndef RPG_GAME_UTIL_H
#define RPG_GAME_UTIL_H

#include <string>
#include <vector>

std::string prompt_for_choice(const std::string &prompt, std::vector<std::string> &choices);

std::string random_choice(std::vector<std::string> &choices);

unsigned int random_uint(unsigned int max);

#endif //RPG_GAME_UTIL_H
