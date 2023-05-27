//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_ITEM_H
#define ZOORK_ITEM_H

#include <memory>
#include "Command.h"
#include "GameObject.h"
#include "NullCommand.h"

class Item : public GameObject {
public:
    Item(const std::string &, const std::string &, bool );

    //item has useText and openText
    Item(const std::string &, const std::string &, const std::string &, const std::string &,bool );

    virtual void use();
    virtual void open();

    void setUseCommand(std::shared_ptr<Command>);
    void setOpenCommand(std::shared_ptr<Command>);
    std::string getUseText();
    bool isMovable();
    std::string getOpenText();
protected:
    std::shared_ptr<Command> useCommand;   //Command for item use
    std::shared_ptr<Command> openCommand;  // Command for item open

private:
    std::string useText;   // Text specific to item use
    std::string openText;  // Text specific to item open
    bool movable = true;


};

#endif //ZOORK_ITEM_H
