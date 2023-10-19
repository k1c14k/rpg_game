//
// Created by marek on 18.10.23.
//

#ifndef RPG_GAME_STARTNEWGAMECOMMAND_H
#define RPG_GAME_STARTNEWGAMECOMMAND_H


#include "../Command.h"
#include "../GameEngine.h"

class StartNewGameCommand : public Command {
    void run(std::string params) override;

    GameEngine *engine;
public:

    std::string get_title() override;

    static bool is_valid_class(const std::string &basicString);

    explicit StartNewGameCommand(GameEngine *pEngine) : engine(pEngine) {};
};

class InfoCommand : public Command {
    void run(std::string params) override;

    GameEngine *engine;
public:

    std::string get_title() override;

    explicit InfoCommand(GameEngine *pEngine) : engine(pEngine) {};
};

#endif //RPG_GAME_STARTNEWGAMECOMMAND_H
