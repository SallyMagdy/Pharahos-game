//
// Created by Sally on 23/05/2023.
//

#include "GameObjectFactory.h"

GameState GameDictioary;
GameObjectFactory::GameObjectFactory() {}

std::shared_ptr<Room> GameObjectFactory::createRoom(const std::string& name, const std::string& description) {
    std::shared_ptr<Room> room = std::make_shared<Room>(name, description);
    return room;
}

std::shared_ptr<Item> GameObjectFactory::createItem(const std::string& name, const std::string& description, bool isMovable) {
    std::shared_ptr<Item> item = std::make_shared<Item>(name, description, isMovable);
    return item;
}

std::shared_ptr<Item> GameObjectFactory::createItem(const std::string& name, const std::string& description,const std::string& useText,const std::string& openText, bool isMovable) {
    std::shared_ptr<Item> item = std::make_shared<Item>(name, description, useText, openText, isMovable);
    return item;
}

//std::shared_ptr<Item> GameObjectFactory::createItem(const std::string& name, const std::string& description, const std::string& itemLocation, const std::string& command) {
//    std::shared_ptr<Item> item = std::make_shared<Item>(name, description);
//    item->setUseCommand()
//    return item;
//}

std::shared_ptr<Character> GameObjectFactory::createCharacter(const std::string& name, const std::string& description) {
    std::shared_ptr<Character> character = std::make_shared<Character>(name, description);
    return character;
}
