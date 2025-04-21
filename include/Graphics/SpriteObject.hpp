#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class SpriteObject
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    SpriteObject(const std::string& title);
};
