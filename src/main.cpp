#include "../include/Core/Engine.hpp"
#include "../include/Graphics/RenderSystem.hpp"
#include "../include/Graphics/SpriteObject.hpp"
#include <iostream>

int main()
{
    Engine engine(200, 200, "SFML worls!");
    SpriteObject newSprite("/home/emo_profisional/programingCplusPlus/engine/assets/as.jpg", 0, 0);
    SpriteObject newSprite2("/home/emo_profisional/programingCplusPlus/engine/assets/sa.jpg", 100, 0);
    RenderSystem::addNewSprite(newSprite);
    RenderSystem::addNewSprite(newSprite2);
    engine.Run();
    return 0;
}