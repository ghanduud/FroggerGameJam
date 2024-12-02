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

//pofo was here

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle Collision", sf::Style::Default);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    sf::Clock clock;
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);

    Renderer r;
    Game pw;

    // THIS IS NANOOO!!!!!

    
    Direction direction;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.key.code == sf::Keyboard::Up)
            {
                
            }
            if (event.key.code == sf::Keyboard::Down)
            {

            }
            if (event.key.code == sf::Keyboard::Left)
            {

            }
            if (event.key.code == sf::Keyboard::Right)
            {

            }
        }


        pw.Update(0.2);

 
        r.Render(window);
    }

    return 0;
}
