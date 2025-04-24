#include "../../include/Core/Engine.hpp"
#include "../../include/Graphics/RenderSystem.hpp"

Engine::Engine(){_window = nullptr;}
Engine::Engine(int weight, int height, const std::string& title){
    _window = new sf::RenderWindow(sf::VideoMode(weight, height), title);
}

void Engine::Run(){
    sf::Event event;

    while (_window->pollEvent(event)){
        if (event.type == sf::Event::Closed) _window->close();
    }
    _window->clear();
    RenderSystem::RenderObject(_window);
    _window->display();
}

Engine::~Engine(){if(_window) delete _window;}