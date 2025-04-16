#include "../../include/Core/Engine.hpp"

Engine::Engine(){_window = nullptr;}

Engine::Engine(int weight, int height, const std::string& title){
    _window = new sf::RenderWindow(sf::VideoMode(weight, height), title);
}

void Engine::Run(){
    while(_window->isOpen()){
        sf::Event event;

        while (_window->pollEvent(event)){
            if (event.type == sf::Event::Closed) _window->close();
        }
        _window->clear();

        _window->display();
    }
}

Engine::~Engine(){if(_window) delete _window;}