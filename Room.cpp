//
// Created by Richard Skarbez on 5/7/23.
//

#include "NullPassage.h"
#include "NullItem.h"
#include "Room.h"


Room::Room(const std::string &n, const std::string &d) : Location(n, d) {
    enterCommand = std::make_shared<RoomDefaultEnterCommand>(this);
}

std::string Room::getDescription() const {
    std::string fullDescription = description;

    if (!items.empty()) {
        fullDescription += "You see the following Items in the room:\n";
        for (const auto& item : items) {
            fullDescription += "- " + item->getName() + "\n";
        }
    }

    return description;
}

Room::Room(const std::string &n, const std::string &d, std::shared_ptr<Command> c) : Location(n, d, std::move(c)) {}

void Room::addPassage(const std::string &direction, std::shared_ptr<Passage> p) {
    passageMap[direction] = std::move(p);
}

void Room::removePassage(const std::string &direction) {
    if (passageMap.contains(direction)) {
        passageMap.erase(direction);
    }
}

std::shared_ptr<Passage> Room::getPassage(const std::string &direction) {
    if (passageMap.contains(direction)) {
        return passageMap[direction];
    } else {
        std::cout << "It is impossible to go " << direction << "!\n";
        return std::make_shared<NullPassage>(this);
    }
}

void Room::addItem(Item* item){
    items.push_back(item);
}

bool Room::removeItem(Item* item) {
    auto it = std::find(items.begin(), items.end(), item);

    if (it != items.end()) {
        items.erase(it);
        return true;
    } else {
        return false;
    }
};

Item* Room::getItem(const std::string& item) {
    auto it = std::find_if(items.begin(), items.end(), [&item](const Item* obj) {
        return obj->getName() == item;
    });

    if (it != items.end()) {
        return *it;
    } else {
        // Return a special value, such as a NullItem object
        return nullptr;
    }
}

int Room::inventorySize() {
    return items.size();
};
//Item* Room::retrieveItem(const std::string&);