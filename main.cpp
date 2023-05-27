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
    builder->createRoom("outside-world","You are an adventurer seeking fame and fortune,\nand you've come to explore the Lost Tomb of the Pharaohs deep in the Egyptian desert.\n"
                                        "As you approach the entrance, you see that the tomb is surrounded by sand dunes and guarded by a fierce sandstorm.\n");

    builder->createRoom("tomb-entrance","The tomb entrance is shut seal behind you, there is no going back and the only way out is through the tomb.\nThe air is thick with the scent of ancient spices, and you can hear the sound of rats scurrying in the distance.\nThe hallway is lined with hieroglyphics and torches that flicker in the wind.\n"
                                        "You notice a room to your left and a staircase leading down to your right.\n");

    builder->createRoom("antechamber",
                                  "You go inside and find a small chamber filled with various artifacts and treasures.\nYou notice a golden ankh on a pedestal.\n");

    builder->createRoom("burial-chamber",
                        "You enter a large chamber adorned with elaborate carvings and paintings.The walls are decorated with scenes depicting ancient rituals and offerings. In the center of the chamber, there is a massive stone sarcophagus.\n");

    builder->createRoom("treasure-vault",
                        "You enter a chamber shrouded in darkness, illuminated only by the faint flicker of torchlight. The air is thick with an aura of mystery, as if centuries of secrets are embedded within its stone walls. \n");

    builder->createRoom("secret-crypt",
                        "You enter a room filled with hieroglyphics covering every inch of the walls.The air is thick with dust, and you can barely make out the symbols in the dim light.\n"
                        "In the center of the room, there's a large stone tablet covered in more hieroglyphics.\n"
                        "It seems like you'll need to decipher the symbols in order to proceed.\n");

    builder->createRoom("hall-of-echoes","As you step into the hall, your footsteps echo loudly,filling the space with a haunting sound.The walls are adorned with ancient tapestries, their vibrant colors faded with time.\n");

    builder->createRoom("chamber-of-serpents","Upon entering, you find yourself surrounded by statues and carvings of snakes. The room seems to come alive with a sense of slithering movement, making you tread carefully.\n");
    builder->createRoom("riddle-chamber","You enter a chamber adorned with ancient symbols and hieroglyphics. The walls seem to whisper secrets, and the room is dominated by a large stone pedestal, atop which sits the enigmatic Sphinx, ready to challenge you with its riddles.\n");
    builder->createRoom("tomb-exit","Congratulations! You found the exit and return to the surface, triumphant and enriched by your adventure.\n"
                                    "You realize that the Lost Tomb of the Pharaohs was just the beginning of your adventures, and you look forward to exploring more ancient tombs and uncovering even greater treasures.\n");

    //    Items in Rooms
    builder->createItem("ankh", "The Ankh shines with a golden radiance, symbolizing life and immortality. Its intricate engravings hint at ancient wisdom, beckoning you to unravel its mysteries.\n"
                                "A subtle energy emanates from its surface, evoking a sense of reverence and curiosity.", "antechamber", true);

//    builder->createItem("tablet", "The symbols look mysterious and complex, and you realize that deciphering them will be no easy task.\n"
//                                  "However, you notice a small leaflet lying on top.", "secret-crypt", false);
//
//    builder->createItem("leaflet", "This leaflet has the same symbols and you can see these are symbols on the wall \n20 21 20 1 14 11 8 1 13 21 14\nCode to Decipher the Symbols:\nSymbol 1 = A\nSymbol 2 = B\nSymbol 3 = C\nSymbol 4 = D\nSymbol 5 = E\nSymbol 6 = F\nSymbol 7 = G\nSymbol 8 = H\nSymbol 9 = I\nSymbol 10 = J\nSymbol 11 = K\nSymbol 12 = L\nSymbol 13 = M\nSymbol 14 = N\nSymbol 15 = O\nSymbol 16 = P\nSymbol 17 = Q\nSymbol 18 = R\nSymbol 19 = S\nSymbol 20 = T\nSymbol 21 = U\nSymbol 22 = V\nSymbol 23 = W\nSymbol 24 = X\nSymbol 25 = Y\nSymbol 26 = Z\nSymbol 27 = space", "secret-crypt", true);

    builder->createItem("sarcophagus",
                        "The sarcophagus is an imposing black granite structure, standing about seven feet tall.\nIntricate carvings of hieroglyphics and symbols adorn its surface, while a sealed lid features gilded motifs and a stoic pharaoh's face.",
                        "",
                        "As you open the heavy stone lid of the sarcophagus, a cloud of dust billows out, momentarily obscuring your vision. As it settles, you see the remains of an ancient Pharaoh resting in peaceful repose.\nAdorned with golden jewelry and wrapped in intricately woven linen bandages, the Pharaoh's mummified body lies on a bed of fragrant herbs and flowers.\nIn their hands, they hold a small, weathered scroll.",
                        "burial-chamber",
                        false);
    builder->createItem("scroll",
                        "The scroll, weathered and adorned with elegant hieroglyphics, holds the secrets and guidance of the pharaohs, offering a glimpse into the past.",
                        "",
                        "The Scroll reads 'Fear not the hiss, for the ancient symbol grants you protection against their deadly strikes.'\n",
                        "burial-chamber",
                        true);


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
