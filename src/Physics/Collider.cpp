#include "../../include/Physics/Collider.hpp"

Collider::Collider(sf::Sprite& sprite, float offsetX, float offsetY, float width, float height) : sprite(sprite), offset(offsetX, offsetY){
    if(width <= 0 || height <= 0){
        sf::FloatRect spriteBounds = sprite.getGlobalBounds();
        size = sf::Vector2f(spriteBounds.width, spriteBounds.height);
    }else{
        size = sf::Vector2f(width, height);
    }

    update();
}

void Collider::update(){
    sf::Vector2f spritePos = sprite.getPosition();

    bounds.left = spritePos.x + offset.x;
    bounds.top = spritePos.y + offset.y;
    bounds.width = size.x;
    bounds.height = size.y;
}

bool Collider::checkCollision(const Collider& other){
    return bounds.intersects(other.bounds);
}

void Collider::resolveCollision(Collider& other){
    sf::FloatRect otherBounds = other.getBounds();

    float overlapX = std::min(
        bounds.left + bounds.width - otherBounds.left,
        otherBounds.left + otherBounds.width - bounds.left
    );
    float overlapY = std::min(
        bounds.top + bounds.height - otherBounds.top,
        otherBounds.top + otherBounds.height - bounds.top
    );

    if(overlapX < overlapY){
        if(bounds.left < otherBounds.left) sprite.move(-overlapX, 0);
        else sprite.move(overlapX, 0);
    }
    else{
        if(bounds.top < otherBounds.top) sprite.move(0, -overlapY);
        else sprite.move(0, overlapY);
    }

    update();
    other.update();
}

const sf::FloatRect& Collider::getBounds() const { return bounds; }
sf::Vector2f Collider::getPosition() const { return sf::Vector2f(bounds.left, bounds.top); }

void Collider::setOffset(float offsetX, float offsetY) { offset = sf::Vector2f(offsetX, offsetY); update(); }
void Collider::setSize(float width, float height) { size = sf::Vector2f(width, height); update(); }
