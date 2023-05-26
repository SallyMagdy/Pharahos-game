//
// Created by Sally on 23/05/2023.
//

#ifndef ZOORK_GAMESTATE_H
#define ZOORK_GAMESTATE_H


#include <string>
#include <memory>
#include <map>
#include <iostream>
#include "GameObject.h"
#include "Room.h"

class GameState {
public:
    GameState() = default;
    explicit GameState(const std::map<std::string, std::shared_ptr<GameObject>>& objects){}; // Constructor taking map as parameter
    void setStartRoom(const std::string&);
    Room* getStartRoom();
    Room* getCurrentRoom(const std::string&);
    GameObject* getObject(const std::string&);

    void addObject(const std::string& name, std::shared_ptr<GameObject> object);
    void printGameState() const;
private:
    std::map<std::string, std::shared_ptr<GameObject>> gameDictionary;
    std::string startRoom;

};


#endif //ZOORK_GAMESTATE_H
