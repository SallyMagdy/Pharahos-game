//
// Created by Sally on 23/05/2023.
//

#include "GameState.h"

#include <utility>
#include "NullRoom.h"
#include "NullItem.h"

void GameState::addObject(const std::string& name, std::shared_ptr<GameObject> object) {
    gameDictionary[name] = std::move(object);
}

void GameState::setStartRoom(const std::string& roomName) {
    startRoom = roomName;
}

Room *GameState::getStartRoom() {
    return getCurrentRoom(startRoom);
}

Room *GameState::getCurrentRoom(const std::string& currentRoom) {
    auto it = gameDictionary.find(currentRoom);
    if (it != gameDictionary.end()) {
        auto obj = it->second;
        auto room = std::dynamic_pointer_cast<Room>(obj);
        if (room) {
            return room.get();
        }
        else {
            std::cout << obj->getName() << " is not a room.\n";
            return new NullRoom();
        }
    }
    else {
        std::cout << currentRoom << " is not a room.\n";
        return new NullRoom();
    }
}

GameObject *GameState::getObject(const std::string & currentObject) {
    auto it = gameDictionary.find(currentObject);
    if (it != gameDictionary.end()) {
        auto obj = it->second;
        if (obj) {
            return obj.get();
        }
        else {
            std::cout << obj->getName() << " humm, I don't really understand this word\n";
            return new NullItem();
        }
    }
    else {
        std::cout << currentObject << " humm, I don't really understand this word\n";
        return new NullItem();
    }
}

//Testing purposes
void GameState::printGameState() const {
    for (const auto& [name, object] : gameDictionary) {
        std::cout << name << ": " << object->getDescription() << std::endl;
    }
}