#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteObject.hpp"
#include <vector>

enum class Setting { DRAW_COLLIDER, NOT_DRAW_COLLIDER };

class RenderSystem{
private:
    static inline std::vector<SpriteObject*> bufferForRender;
    static inline std::vector<sf::Text*> bufferForRenderText;
    static inline bool showCollider;
public:
    static void RenderObject(sf::RenderWindow* _window);
    static void addNewSprite(SpriteObject* newObject);
    static void deleteSprite(SpriteObject* Object);
    static void addNewText(sf::Text* newText);
    static void editSettings(Setting argument);
    ~RenderSystem();
};
