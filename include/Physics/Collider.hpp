#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
private:
    sf::Sprite& sprite;
    sf::FloatRect bounds;
    sf::Vector2f offset;
    sf::Vector2f size;

public:
    Collider(sf::Sprite& sprite, float offsetX = 0, float offsetY = 0, float width = 0, float height = 0);

    void update();
    bool checkCollision(const Collider& other);
    void resolveCollision(Collider& other);

    const sf::FloatRect& getBounds() const;
    sf::Vector2f getPosition() const;

    void setOffset(float offsetX, float offsetY);
    void setSize(float width, float height);
};
