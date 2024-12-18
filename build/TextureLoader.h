#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class TextureLoader
{
public:
	sf::Texture landTexture;
	sf::Texture waterTexture;

	sf::Texture blockTexture;
	sf::Texture restTexture;
	sf::Texture endTexture;

	sf::Texture bigSnakeTexture;
	sf::Texture trunkTexture;

	// frog stuff
	sf::Texture frogJumpingTexture;
	sf::Texture frogStandingTexture;

	TextureLoader();
};

