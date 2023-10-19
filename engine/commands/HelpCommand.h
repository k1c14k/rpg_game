//
// Created by marek on 18.10.23.
//

#ifndef RPG_GAME_HELPCOMMAND_H
#define RPG_GAME_HELPCOMMAND_H


#include "../Command.h"
#include "../GameEngine.h"

class HelpCommand: public Command {
    void run(std::string params) override;

    std::string get_title() override;

    GameEngine* engine;
public:
    explicit HelpCommand(GameEngine *engine);
};


#endif //RPG_GAME_HELPCOMMAND_H
