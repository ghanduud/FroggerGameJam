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


    if (!this->blockTexture.loadFromFile("../resources/block.png")) {
        std::cout << "Error loading land texture!" << std::endl;
    }
    blockTexture.setRepeated(true);

    // frog stuff
    if (!this->frogJumpingTexture.loadFromFile("../resources/fire-frogger123.png")) { 
        std::cerr << "Failed to load image.png from ghandy" << std::endl;
        return;
    }

    if (!frogStandingTexture.loadFromFile("../resources/fire-frogger12.png")) {
        std::cerr << "Failed to load image.png" << std::endl;
        return;
    }
}