//
// Created by Sally on 23/05/2023.
//

#ifndef ZOORK_GAMEOBJECTFACTORY_H
#define ZOORK_GAMEOBJECTFACTORY_H


#include <memory>
#include <utility>
#include "GameObject.h"
#include "Room.h"
#include "GameState.h"

class GameObjectFactory {
public:
    explicit GameObjectFactory();
    static std::shared_ptr<Room> createRoom(const std::string&, const std::string&);

    static std::shared_ptr<Item> createItem(const std::string&, const std::string&, bool );
    static std::shared_ptr<Item> createItem(const std::string&, const std::string&, const std::string&, const std::string&, bool);
//    static std::shared_ptr<Item> createItem(const std::string&, const std::string&, const std::string&, const std::string&);

    static std::shared_ptr<Character> createCharacter(const std::string&, const std::string&);


private:
//    GameState gameDictionary;
};


#endif //ZOORK_GAMEOBJECTFACTORY_H
