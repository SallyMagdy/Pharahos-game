
// Created by Sally on 18/05/2023.


#ifndef ZOORK_WORLDBUILDER_H
#define ZOORK_WORLDBUILDER_H


#include "GameObjectFactory.h"

class WorldBuilder {
public:
    WorldBuilder();
    void createRoom(const std::string&, const std::string&);
    void createItem(const std::string&, const std::string&, const std::string&);
    void createPassage(const std::string &, const std::string &, const std::string &, bool);
//    void createCharacter(const std::string&, const std::string&);
    void setStartRoom(const std::string&);
    std::unique_ptr<GameState> build();

private:
    std::unique_ptr<GameState> gameState;
    GameObjectFactory gameObjectFactory;
};


#endif //ZOORK_WORLDBUILDER_H
