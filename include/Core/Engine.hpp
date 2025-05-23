#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

class Engine{
public:
    Engine();
    Engine(int weight, int height, const std::string& title, int maxFrameratePerSecond);
   
    void Run();

    bool gameIsOn() { return _window->isOpen(); }
    float getDeltaTime() { return deltaTime; }

    ~Engine();
private:
    sf::RenderWindow* _window;
    sf::Clock clock;
    float deltaTime;
};