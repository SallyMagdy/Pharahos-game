#include "RoomDefaultEnterCommand.h"
#include "Passage.h"
#include "Player.h"
#include "Room.h"
#include "ZOOrkEngine.h"
#include "GameObjectFactory.h"
#include "WorldBuilder.h"


int main() {
    std::unique_ptr<WorldBuilder> builder = std::make_unique<WorldBuilder>();
    builder->createRoom("start-room",
                           "You are standing in an open field west of a white house, with a boarded front door.\n");
    builder->createRoom("south-of-house",
                                    "You are facing the south side of a white house.  There is no door here, and all the windows are barred.\n");

    builder->createRoom("behind-house",
                                  "You are behind the white house. A path leads into the forest to the east. In one corner of the house there is a small window which is slightly ajar.\n");

    builder->createItem("Sword", "This is the sword description", "start-room");

    builder->createPassage("start-room","behind-house","east", true);
    builder->createPassage("behind-house","south-of-house","south", true);
    builder->createPassage("south-of-house","start-room","west", true);
//    builder->createPassage("south_of_house","behind_house","east", true);
    builder->setStartRoom("start-room");
    ZOOrkEngine zoork(std::move(builder->build()));
    zoork.run();

    return 0;
}
