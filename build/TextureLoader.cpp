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
}