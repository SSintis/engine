#pragma once
#include <SFML/Graphics.hpp>

class EventManeger{
private:
    sf::Event event;
public:
    void waitEvent(sf::RenderWindow* _window);
};
