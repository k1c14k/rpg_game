//
// Created by marek on 18.10.23.
//

#ifndef RPG_GAME_QUITCOMMAND_H
#define RPG_GAME_QUITCOMMAND_H


#include "../Command.h"
#include "../GameEngine.h"

class QuitCommand: public Command {
    void run(std::string params) override;

public:
    std::string get_title() override;

public:
    explicit QuitCommand(GameEngine *pEngine): engine(pEngine) {};

private:
    GameEngine* engine;
};


#endif //RPG_GAME_QUITCOMMAND_H
