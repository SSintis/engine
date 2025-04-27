#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
private:
    sf::Sprite& sprite;

public:
    Collider();
    ~Collider();
};