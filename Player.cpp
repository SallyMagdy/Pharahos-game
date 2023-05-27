//
// Created by Richard Skarbez on 5/7/23.
//

#include "Player.h"
#include "NullItem.h"

Player *Player::playerInstance = nullptr;

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::addItem(Item* item){
    inventory.push_back(item);
    std::cout<<"Taken.\n";
}

bool Player::removeItem(Item* item) {
    auto it = std::find(inventory.begin(), inventory.end(), item);

    if (it != inventory.end()) {
        inventory.erase(it);
        return true;
    } else {
        return false;
    }
};

Item* Player::retrieveItem(const std::string& item) {
    auto it = std::find_if(inventory.begin(), inventory.end(), [&item](const Item* obj) {
        return obj->getName() == item;
    });

    if (it != inventory.end()) {
        return *it;
    } else {
        // Return a special value, such as a NullItem object
        return new NullItem(); // Create and return a NullItem object
    }
}

void Player::checkInventory() {
    if(inventory.empty()){
        std::cout << "You are not carrying anything.\n";
        return;
    }else{
        std::cout << "You are carrying:\n";

    }
    for (const auto& item : inventory) {
        std::cout << "-"<<item->getName() + "\n";
    }
};

int Player::inverntorySize() {
    return inventory.size();
};