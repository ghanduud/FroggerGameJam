#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../build/MovingPlatform.h"
#include "../build/Renderer.h"
#include "../build/Game.h"
#include "../build/Level.h"
#include "../build/TextureLoader.h"

//pofo was here

int main() {
    srand(static_cast<unsigned int>(time(0)));
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Circle Collision", sf::Style::Default);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    sf::Clock clock;
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);


    sf::SoundBuffer buffer;
        
    if (!buffer.loadFromFile("../resources/backgroundmusic.ogg")) {
        std::cerr << "Failed to load audio file!" << std::endl;
        return -1;
    }

        sf::Sound sound;
        sound.setBuffer(buffer);


        sound.setLoop(true);
		sound.setVolume(50);

        sound.play();
    
    TextureLoader textureLoader;
    Level level1(textureLoader);

    
    Direction direction;


    while (window.isOpen()) {
        sf::Event event;
        direction = NONE;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up)
                {
                    direction = UP;
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    direction = DOWN;
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    direction = LEFT;
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    direction = RIGHT;
                }
            }
            
        }
        if (level1.isGameOver) window.close();
        level1.update(timePerFrame.asSeconds(), direction, textureLoader);

        //pw.Update(0.2);
        window.clear();
        level1.renderMap(10,window);
        window.display();
        //r.Render(window);
    }

    return 0;
}
