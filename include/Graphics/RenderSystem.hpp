#pragma once

#include <SFML/Graphics.hpp>
#include "../Utils/EntityManeger.hpp"

class RenderSystem{
public:
  void SearchAndRender(EntityManeger& em, sf::RenderWindow* _window);
};
