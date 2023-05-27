//
// Created by Sally on 27/05/2023.
//

#include "ItemOpenCommand.h"

#include "Item.h"

void ItemOpenCommand::execute() {
    dynamic_cast<Item*>(gameObject)->getOpenText();
}