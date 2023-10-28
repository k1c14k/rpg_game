//
// Created by marek on 19.10.23.
//

#ifndef RPG_GAME_ENGINE_COMMANDS_H
#define RPG_GAME_ENGINE_COMMANDS_H

#include "command.h"
#include "../engine.h"

class HelpCommand : public Command {
    void run(std::string params) override;

    std::string get_title() override;

    GameEngine *engine;
public:
    explicit HelpCommand(GameEngine *engine);
};

class QuitCommand : public Command {
    void run(std::string params) override;

public:
    std::string get_title() override;

public:
    explicit QuitCommand(GameEngine *pEngine) : engine(pEngine) {};

private:
    GameEngine *engine;
};

class StartNewGameCommand : public Command {
    void run(std::string params) override;

    GameEngine *engine;
public:
    std::string get_title() override;

    explicit StartNewGameCommand(GameEngine *pEngine) : engine(pEngine) {};
private:
    static std::string prompt_for_name();

    static std::string prompt_for_class();

    static bool is_valid_class(const std::string &basicString);
};

class InfoCommand : public Command {
    void run(std::string params) override;

    GameEngine *engine;
public:

    std::string get_title() override;

    explicit InfoCommand(GameEngine *pEngine) : engine(pEngine) {};
};

#endif //RPG_GAME_ENGINE_COMMANDS_H
