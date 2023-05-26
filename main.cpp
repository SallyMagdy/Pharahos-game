#include "RoomDefaultEnterCommand.h"
#include "Passage.h"
#include "Player.h"
#include "Room.h"
#include "ZOOrkEngine.h"
#include "GameObjectFactory.h"
#include "WorldBuilder.h"


int main() {
    std::unique_ptr<WorldBuilder> builder = std::make_unique<WorldBuilder>();
//    Rooms Details
    builder->createRoom("outside-world","You are an adventurer seeking fame and fortune, and you've come to explore the Lost Tomb of the Pharaohs deep in the Egyptian desert.As you approach the entrance, you see that the tomb is surrounded by sand dunes and guarded by a fierce sandstorm.\n");
    builder->createRoom("tomb-entrance","The tomb entrance is shut seal behind you, there is no going back and the only way out is through the tomb. The air is thick with the scent of ancient spices, and you can hear the sound of rats scurrying in the distance.\n The hallway is lined with hieroglyphics and torches that flicker in the wind.\n"
                                        "You notice a room to your left and a staircase leading down to your right.\n");

    builder->createRoom("antechamber",
                                  "You go inside and find a small chamber filled with various artifacts and treasures. \nYou notice a golden ankh on a pedestal.\n");

    builder->createRoom("burial-chamber",
                        "You enter a large chamber adorned with elaborate carvings and paintings. The walls are decorated with scenes depicting ancient rituals and offerings. In the center of the chamber, there is a massive stone sarcophagus.\n");

    builder->createRoom("treasure-vault",
                        " You stumble upon a hidden vault filled with glittering treasures and precious gems. The room is stacked with golden statues, jeweled artifacts, and chests overflowing with riches. The air is heavy with anticipation and the temptation to take it all.\n");

    builder->createRoom("secret-crypt",
                        "You enter a room filled with hieroglyphics covering every inch of the walls. The air is thick with dust, and you can barely make out the symbols in the dim light. In the center of the room, there's a large stone tablet covered in more hieroglyphics. It seems like you'll need to decipher the symbols in order to proceed.\n");

    builder->createRoom("hall-of-echoes","As you step into the hall, your footsteps echo loudly, filling the space with a haunting sound. The walls are adorned with ancient tapestries, their vibrant colors faded with time.\n");

    builder->createRoom("chamber-of-serpents","Upon entering, you find yourself surrounded by statues and carvings of snakes. The room seems to come alive with a sense of slithering movement, making you tread carefully.\n");
    builder->createRoom("riddle-chamber","You enter a chamber adorned with ancient symbols and hieroglyphics. The walls seem to whisper secrets, and the room is dominated by a large stone pedestal, atop which sits the enigmatic Sphinx, ready to challenge you with its riddles.\n");
    builder->createRoom("tomb-exit","You exit the tomb and return to the surface, triumphant and enriched by your adventure. You realize that the Lost Tomb of the Pharaohs was just the beginning of your adventures, and you look forward to exploring more ancient tombs and uncovering even greater treasures.\n");

    //    Items in Rooms
    builder->createItem("ankh", "The Ankh shines with a golden radiance, symbolizing life and immortality. Its intricate engravings hint at ancient wisdom, beckoning you to unravel its mysteries. A subtle energy emanates from its surface, evoking a sense of reverence and curiosity.", "antechamber");



//    Passages Details
    builder->createPassage("outside-world","tomb-entrance","north", false);
    builder->createPassage("tomb-entrance","antechamber","west", true);
    builder->createPassage("tomb-entrance","burial-chamber","down", true);
    builder->createPassage("burial-chamber","treasure-vault","east", true);
    builder->createPassage("treasure-vault","secret-crypt","north", true);
    builder->createPassage("secret-crypt","hall-of-echoes","west", true);
    builder->createPassage("hall-of-echoes","chamber-of-serpents","south", true);
    builder->createPassage("chamber-of-serpents","riddle-chamber","west", true);
    builder->createPassage("riddle-chamber","tomb-exit","north", true);
    builder->setStartRoom("outside-world");
    ZOOrkEngine zoork(std::move(builder->build()));
    zoork.run();

    return 0;
}
