#include "../../include/Graphics/SpriteObject.hpp"

SpriteObject::SpriteObject(const std::string& title, float axisX, float axisY){
    if(!texture.loadFromFile(title)){
        std::cout << "Error with load texture!!!"<<std::endl;
    }else { std::cout<<"Texture was loaded"<<std::endl; }

    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.1, 0.1));
    sprite.setPosition(axisX, axisY);
}