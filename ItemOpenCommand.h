//
// Created by Sally on 27/05/2023.
//

#ifndef ZOORK_ITEMOPENCOMMAND_H
#define ZOORK_ITEMOPENCOMMAND_H

#include "Command.h"

#include <utility>

class ItemOpenCommand : public Command {
    public:
        explicit ItemOpenCommand(GameObject* g) : Command(g) {}

        void execute() override;
    };


#endif //ZOORK_ITEMOPENCOMMAND_H
