#pragma once

#include "../Component.hpp"
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>

struct Sprite : public Component{
  std::string path;

  sf::Texture texture;
  sf::Sprite sprite;

  Sprite(const std::string pathToSprite) : path(pathToSprite){
    if(!texture.loadFromFile(path)){
      std::runtime_error("You cant to load this sprite!!!\n");
    }
  }
};
