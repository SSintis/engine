#include "../../include/Utils/EventManeger.hpp"

void EventManeger::waitEvent(sf::RenderWindow* _window){
    while (_window->pollEvent(event)){
        if (event.type == sf::Event::Closed) _window->close();
    }
}