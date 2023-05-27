//
// Created by Sally on 27/05/2023.
//

#include "ItemDefaultUseCommand.h"
#include "Item.h"

void ItemDefaultUseCommand::execute() {
    dynamic_cast<Item*>(gameObject)->getUseText();
}