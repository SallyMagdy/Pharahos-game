//
// Created by Richard Skarbez on 5/7/23.
//

#include "ZOOrkEngine.h"
#include "NullItem.h"

#include <utility>

ZOOrkEngine::ZOOrkEngine(std::unique_ptr<GameState> gs):gameState(std::move(gs)) {
    player = Player::instance();
    player->setCurrentRoom(gameState->getStartRoom());
    player->getCurrentRoom()->enter();
}

void ZOOrkEngine::run() {
    while (!gameOver) {
        std::cout << "> ";

        std::string input;
        std::getline(std::cin, input);

        std::vector<std::string> words = tokenizeString(input);
        std::string command = words[0];
        std::vector<std::string> arguments(words.begin() + 1, words.end());

        if (command == "go") {
            handleGoCommand(arguments);
        } else if ((command == "look") || (command == "inspect")) {
            handleLookCommand(arguments);
        } else if ((command == "take") || (command == "get")) {
            handleTakeCommand(arguments);
        } else if (command == "drop") {
            handleDropCommand(arguments);
        } else if (command == "inventory") {
            handleInventoryCommand();
        } else if (command == "use") {
            handleUseCommand(arguments);
        } else if (command == "open") {
            handleOpenCommand(arguments);
        } else if (command == "quit") {
            handleQuitCommand(arguments);
        } else {
            std::cout << "I don't understand that command.\n";
        }
    }
}

void ZOOrkEngine::handleGoCommand(std::vector<std::string> arguments) {
    std::string direction;
    if(arguments.empty()){
        std::cout<<"Go where?!\n";
        return;
    }else{
        if (arguments[0] == "n" || arguments[0] == "north") {
            direction = "north";
        } else if (arguments[0] == "s" || arguments[0] == "south") {
            direction = "south";
        } else if (arguments[0] == "e" || arguments[0] == "east") {
            direction = "east";
        } else if (arguments[0] == "w" || arguments[0] == "west") {
            direction = "west";
        } else if (arguments[0] == "u" || arguments[0] == "up") {
            direction = "up";
        } else if (arguments[0] == "d" || arguments[0] == "down") {
            direction = "down";
        } else {
            direction = arguments[0];
        }

        Room* currentRoom = player->getCurrentRoom();
        auto passage = currentRoom->getPassage(direction);
        player->setCurrentRoom(passage->getTo());
        passage->enter();
    }

}

void ZOOrkEngine::handleLookCommand(std::vector<std::string> arguments) {
    std::string description;
    if(arguments.empty()){
        auto currentRoom = player->getCurrentRoom();
        description = currentRoom->getDescription();
    } else {
        auto obj = arguments.back();
        auto objPointer = gameState->getObject(obj);
        description = objPointer->getDescription();
    }
        std::cout<< description << "\n";
}

void ZOOrkEngine::handleTakeCommand(std::vector<std::string> arguments) {
    auto currentRoom = player->getCurrentRoom();
    if (arguments.empty()) {
        std::cout << "Can you be more specific?! \n";
    } else {
        if (currentRoom->inventorySize() == 0) {
            std::cout << "There is nothing to take here. \n";
        } else {
            auto itemName = currentRoom->getItem(arguments.back());
            if (itemName == nullptr) {
                std::cout << "This item cannot be added to your inventory!\n";
            }else if(!itemName->isMovable()){
                std::cout << "You can't move this object. \n";
            }else {
                currentRoom->removeItem(itemName);
                player->addItem(itemName);
            }
        }
    }
}

void ZOOrkEngine::handleDropCommand(std::vector<std::string> arguments) {
    auto currentRoom = player->getCurrentRoom();
    if(arguments.empty()){
        std::cout << "Drop what? \n";
    } else{
        if(player->inverntorySize() == 0){
            std::cout << "You have nothing to drop. \n";
        }else{
            auto itemName = player->retrieveItem(arguments.back());
            if(itemName){
                if (player->removeItem(itemName)){
                    std::cout<<"Dropped \n";
                    currentRoom->addItem(itemName);
                }
            }else{
                std::cout << "You can't drop what you don't have. \n";
            }

        }
    }
}

void ZOOrkEngine::handleOpenCommand(std::vector<std::string> arguments) {
    if(arguments.empty()){
        std::cout << "Open what?! \n";
    }else{
        auto item = gameState->getObject(arguments[0]);
        auto openText = dynamic_cast<Item*>(item)->getOpenText();
        if (!openText.empty()) {
            std::cout << openText << "\n";
        }else {
            std::cout << "You can't open this item. \n";
        }
    }
}

void ZOOrkEngine::handleUseCommand(std::vector<std::string> arguments) {
    std::cout<< "Use command not implemented yet" << "\n";
}

void ZOOrkEngine::handleInventoryCommand() {
    player->checkInventory();
}

void ZOOrkEngine::handleQuitCommand(const std::vector<std::string>& arguments) {
    std::string input;
    std::cout << "Are you sure you want to QUIT?\n> ";
    std::cin >> input;
    std::string quitStr = makeLowercase(input);

    if (quitStr == "y" || quitStr == "yes") {
        gameOver = true;
    }
}

std::vector<std::string> ZOOrkEngine::tokenizeString(const std::string &input) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ' ')) {
        tokens.push_back(makeLowercase(token));
    }

    return tokens;
}

std::string ZOOrkEngine::makeLowercase(std::string input) {
    std::string output = std::move(input);
    std::transform(output.begin(), output.end(), output.begin(), ::tolower);

    return output;
}
