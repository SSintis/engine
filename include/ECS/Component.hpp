#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>

class Component
{
public:
    virtual ~Component() = default;
};

struct Sprite : public Component{
  std::string path;

  sf::Texture texture;
  sf::Sprite sprite;

  Sprite(const std::string pathToSprite) : path(pathToSprite){
    if(!texture.loadFromFile(path)){
      std::runtime_error("You cant to load a sprite!!!\n");
    }
  }
};

