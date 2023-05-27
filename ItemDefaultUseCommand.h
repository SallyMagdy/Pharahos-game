//
// Created by Sally on 27/05/2023.
//

#ifndef ZOORK_ITEMDEFAULTUSECOMMAND_H
#define ZOORK_ITEMDEFAULTUSECOMMAND_H


#include "Command.h"

#include <utility>

class ItemDefaultUseCommand : public Command {
public:
    explicit ItemDefaultUseCommand(GameObject* g) : Command(g) {}

    void execute() override;
};

#endif //ZOORK_ITEMDEFAULTUSECOMMAND_H
