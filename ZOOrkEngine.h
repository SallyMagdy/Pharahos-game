//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_ZOORKENGINE_H
#define ZOORK_ZOORKENGINE_H

#include "Player.h"
#include "Location.h"
#include "Passage.h"
#include "GameState.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class ZOOrkEngine {
public:
    ZOOrkEngine(std::unique_ptr<GameState>);

    void run();

private:
    std::unique_ptr<GameState> gameState;
    bool gameOver = false;
    Player *player;

    void handleGoCommand(std::vector<std::string>);

    void handleLookCommand(std::vector<std::string>);

    void handleTakeCommand(std::vector<std::string>);

    void handleDropCommand(std::vector<std::string>);

    void handleUseCommand(std::vector<std::string>);

    void handleOpenCommand(std::vector<std::string>);

    void handleInventoryCommand();

    void handleQuitCommand(const std::vector<std::string>&);

    static std::vector<std::string> tokenizeString(const std::string&);

    static std::string makeLowercase(std::string);
};


#endif //ZOORK_ZOORKENGINE_H
