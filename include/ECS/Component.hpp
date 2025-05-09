#include <SFML/Graphics.hpp>

class Component
{
public:
    virtual ~Component() = default;
};

struct Sprite : public Component{
    sf::Texture texture;
    sf::Sprite sprite;
};

struct Movement : public Component{
    float x;
    float y;
};
