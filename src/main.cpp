#include <SFML/Graphics.hpp>
#include "../include/Core/Engine.hpp"
#include "../include/Core/Logger.hpp"
#include <iostream>


int main()
{
    Logger log;
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    
    log.sayHello();
    log.sayHello();
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}