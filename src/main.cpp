#include "../include/Core/Engine.hpp"
#include "../include/Graphics/RenderSystem.hpp"
#include "../include/Graphics/SpriteObject.hpp"
#include <iostream>

int main()
{
    Engine engine(600, 400, "GAME IS LOOP!!!", 240);

    SpriteObject newSprite("/home/emo_profisional/programingCplusPlus/engine/assets/as.jpg", 0, 1);
    SpriteObject newSprite2("/home/emo_profisional/programingCplusPlus/engine/assets/sa.jpg", 100, 2);

    RenderSystem::addNewSprite(&newSprite);
    RenderSystem::addNewSprite(&newSprite2);

    while (engine.gameIsOn()){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            newSprite.move(0, -0.5 * engine.getDeltaTime());
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            newSprite.move(-0.5 * engine.getDeltaTime(), 0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            newSprite.move(0, 0.5 * engine.getDeltaTime());
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            newSprite.move(0.5 * engine.getDeltaTime(), 0);
        }
        engine.Run();
    }
    return 0;
}