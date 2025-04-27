#include "../../include/Graphics/Hitbox.hpp"

Hitbox::Hitbox(float x, float y, float width, float height) 
    : bounds(x, y, width, height) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(1.f);
}

void Hitbox::setPosition(float x, float y) {
    bounds.left = x;
    bounds.top = y;
    shape.setPosition(x, y);
}

void Hitbox::draw(sf::RenderWindow* window) const {
    if (window) {
        window->draw(shape);
    }
}

const sf::FloatRect& Hitbox::getBounds() const {
    return bounds;
}