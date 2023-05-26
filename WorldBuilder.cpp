//
// Created by Sally on 18/05/2023.
//

//#include "WorldBuilder.h"

#include <string>
#include "Room.h"
#include "Item.h"
#include "Character.h"
#include "Passage.h"
#include "WorldBuilder.h"


WorldBuilder::WorldBuilder() : gameState(std::make_unique<GameState>()){

};

void WorldBuilder::createRoom(const std::string& name, const std::string& description) {
    std::shared_ptr<Room> newRoom = GameObjectFactory::createRoom(name, description);
    std::string lower_case_name = "";
    for(auto s:name){
        lower_case_name += tolower(s);
    }
    gameState->addObject(lower_case_name, newRoom);
}

void WorldBuilder::createItem(const std::string& name, const std::string& description, const std::string& roomName) {
    auto newItem = GameObjectFactory::createItem(name, description, roomName);
    auto itemLocation = gameState->getCurrentRoom(roomName);
    itemLocation->addItem(newItem.get());
    std::string lower_case_name = "";
    for(auto s:name){
        lower_case_name += tolower(s);
    }
    gameState->addObject(lower_case_name, newItem);
}

void WorldBuilder::createPassage(const std::string &  roomFrom, const std::string &  roomTo, const std::string & direction, bool bidirectional){
    auto roomFromItem  = gameState->getCurrentRoom(roomFrom);
    auto roomToItem  = gameState->getCurrentRoom(roomTo);
    Passage::createBasicPassage(roomFromItem, roomToItem, direction, bidirectional);
}

//void WorldBuilder::createCharacter(const std::string& name, const std::string& description, const std::string& roomName) {
//    std::shared_ptr<Room> newCharacter = GameObjectFactory::createCharacter(name, description, roomName);
//    auto itemLocation = gameState->getCurrentRoom(roomName);
//    itemLocation->addCharacter(newCharacter.get());
//    gameState->addObject(name, newCharacter);
//}

void WorldBuilder::setStartRoom(const std::string& name){
    gameState->setStartRoom(name);
}

std::unique_ptr<GameState> WorldBuilder::build() {
    return std::move(gameState);
}