#pragma once
#include <SFML/Graphics.hpp>

class Hitbox {
public:
    Hitbox(float x, float y, float width, float height);
    void setPosition(float x, float y);
    void draw(sf::RenderWindow* window) const;
    const sf::FloatRect& getBounds() const;

private:
    sf::RectangleShape shape;
    sf::FloatRect bounds;
};