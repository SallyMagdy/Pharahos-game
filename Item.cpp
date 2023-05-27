//
// Created by Richard Skarbez on 5/7/23.
//

#include "Item.h"
#include "ItemDefaultUseCommand.h"
#include "ItemOpenCommand.h"

#include <utility>

Item::Item(const std::string &n, const std::string &d, bool movable)
: GameObject(n, d),useCommand(std::make_shared<NullCommand>()), openCommand(std::make_shared<NullCommand>()) {}

//Item::Item(const std::string &n, const std::string &d,const std::string &u, const std::string &o)
//: GameObject(n, d), useCommand(std::make_shared<NullCommand>()), openCommand(std::make_shared<NullCommand>()) {
//}

Item::Item(const std::string& n, const std::string& d, const std::string& use, const std::string& open, bool isMovable)
        : GameObject(n, d), useText(use), openText(open), movable(isMovable) {
    if(!useText.empty()){
        setUseCommand(std::make_shared<ItemDefaultUseCommand>(this));
    }
    if(!openText.empty()){
    setOpenCommand(std::make_shared<ItemOpenCommand>(this));
    }
}

void Item::use() {
    if (useCommand) {
        if (!useText.empty()) {
            std::cout << useText << std::endl;
        }
        useCommand->execute();
    } else {
        std::cout << "You cannot use this item." << std::endl;
    }
}

void Item::open() {
    if (openCommand) {
        if (!openText.empty()) {
            std::cout << openText << std::endl;
        }
        openCommand->execute();
    } else {
        std::cout << "You cannot open this item." << std::endl;
    }
}

void Item::setUseCommand(std::shared_ptr<Command> c) {
    useCommand = std::move(c);
}

void Item::setOpenCommand(std::shared_ptr<Command> c) {
    openCommand = std::move(c);
}

std::string Item::getUseText() {
    return useText;
}

std::string Item::getOpenText() {
    return openText;
}

bool Item::isMovable(){
    return movable;
}