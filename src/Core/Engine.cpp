#include "../../include/Core/Engine.hpp"
#include "../../include/Graphics/RenderSystem.hpp"
#include "../../include/Utils/EventManeger.hpp"

Engine::Engine(){_window = nullptr;}
Engine::Engine(int weight, int height, const std::string& title){
    _window = new sf::RenderWindow(sf::VideoMode(weight, height), title);
}

void Engine::Run(){
    EventManeger em;
    em.waitEvent(_window);
    _window->clear();
    RenderSystem::RenderObject(_window);
    _window->display();
}

Engine::~Engine(){if(_window) delete _window;}