#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class EventManeger{
private:
    sf::Event event;
public:
    void waitEvent(sf::RenderWindow* _window);
};