#include "../../include/Core/Engine.hpp"

Engine::Engine(){_window = nullptr;}
Engine::Engine(int weight, int height, const std::string& title, int maxFrameratePerSecond){
  _window = new sf::RenderWindow(sf::VideoMode(weight, height), title);
  _window->setFramerateLimit(maxFrameratePerSecond);
  //RenderSystem::editSettings(Setting::NOT_DRAW_COLLIDER);
}

void Engine::Run(EntityManeger& entityManeger){
  sf::Time deltaTimeTimer = clock.restart();
  deltaTime = deltaTimeTimer.asMilliseconds();
  
  eventManeger.waitEvent(_window);

  _window->clear();
  renderer.SearchAndRender(entityManeger, _window); 
  _window->display();
}

Engine::~Engine(){if(_window) delete _window;}
