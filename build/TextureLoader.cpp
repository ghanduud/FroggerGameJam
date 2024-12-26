#include "TextureLoader.h"

TextureLoader::TextureLoader()
{
    if (!this->landTexture.loadFromFile("../resources/land4.png")) {
        std::cout << "Error loading land texture!" << std::endl;
    }
    landTexture.setRepeated(true);


    if (!this->waterTexture.loadFromFile("../resources/dfcvs.png")) {
        std::cout << "Error loading land texture!" << std::endl;
    }
    waterTexture.setRepeated(true);


    if (!this->blockTexture.loadFromFile("../resources/block.png")) {
        std::cout << "Error loading land texture!" << std::endl;
    }
    blockTexture.setRepeated(true);

    if (!this->restTexture.loadFromFile("../resources/grass2.png")) {
        std::cout << "Error loading land texture!" << std::endl;
    }
    restTexture.setRepeated(true);

    if (!this->endTexture.loadFromFile("../resources/line.png")) {
        std::cout << "Error loading land texture!" << std::endl;
    }
    endTexture.setRepeated(true);

    // frog stuff
    if (!this->frogJumpingTexture.loadFromFile("../resources/fire-frogger1234.png")) { 
        std::cerr << "Failed to load image.png" << std::endl;
        return;
    }


    if (!frogStandingTexture.loadFromFile("../resources/fire-frogger12.png")) {
        std::cerr << "Failed to load image.png" << std::endl;
        return;
    }

    if (!this->bigSnakeTexture.loadFromFile("../resources/snake3.png")) {
        std::cerr << "Failed to load image.png" << std::endl;
        return;
    }
    if (!this->trunkTexture.loadFromFile("../resources/wood-trunk.png")) {
        std::cerr << "Failed to load image.png" << std::endl;
        return;
    }
}