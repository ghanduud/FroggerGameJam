#include "TextureLoader.h"

TextureLoader::TextureLoader()
{
    if (!this->landTexture.loadFromFile("../resources/land.png")) {
        std::cout << "Error loading land texture!" << std::endl;
    }
    landTexture.setRepeated(true);


    if (!this->waterTexture.loadFromFile("../resources/frogger-Recovered.png")) {
        std::cout << "Error loading land texture!" << std::endl;
    }
    waterTexture.setRepeated(true);


    // frog stuff
    if (!this->frogJumpingTexture.loadFromFile("C:/Users/Admin/Documents/GitHub/FroggerGameJam/resources/frog.png")) { //--------------------change image here
        std::cerr << "Failed to load image.png from ghandy" << std::endl;
        return;
    }

    if (!frogStandingTexture.loadFromFile("C:/Users/Admin/Documents/GitHub/FroggerGameJam/resources/frog.png")) { //-----------------------change image here too
        std::cerr << "Failed to load image.png" << std::endl;
        return;
    }
}