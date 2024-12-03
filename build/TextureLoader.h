#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class TextureLoader
{
public:
	sf::Texture landTexture;
	sf::Texture waterTexture;

	sf::Texture blockTexture;

	// frog stuff
	sf::Texture frogJumpingTexture;
	sf::Texture frogStandingTexture;

	TextureLoader();
};

