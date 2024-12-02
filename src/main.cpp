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

//pofo was here

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Circle Collision", sf::Style::Default);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    sf::Clock clock;
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);

    //Renderer r;
    // 
    // 
    // 
    // 
    //Game pw;



    Level level1;

    


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        //pw.Update(0.2);
        window.clear();
        level1.renderMap(10,window);
        window.display();
        //r.Render(window);
    }

    return 0;
}
