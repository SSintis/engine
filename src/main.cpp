#include "../include/Core/Engine.hpp"
#include "../include/Graphics/RenderSystem.hpp"
#include "../include/Graphics/SpriteObject.hpp"
#include <iostream>

#define WIDTH 600
#define HEIGHT 400

int main()
{
    Engine engine(WIDTH, HEIGHT, "GAME IS LOOP!!!", 240);

    SpriteObject newSprite("/home/emo_profisional/programingCplusPlus/engine/assets/as.jpg", 0, 1, 0.1);
    SpriteObject newSprite2("/home/emo_profisional/programingCplusPlus/engine/assets/sa.jpg", WIDTH / 2, HEIGHT / 2, 0.1);
    SpriteObject player("/home/emo_profisional/programingCplusPlus/engine/assets/BODY_skeleton.png", 0, 1, 1);

    player.initAnimation(64, 64);
    player.setHitbox(0, 0, 64, 64);

    RenderSystem::addNewSprite(&newSprite2);
    RenderSystem::addNewSprite(&newSprite);
    RenderSystem::addNewSprite(&player);

    while (engine.gameIsOn()){
        float delta = engine.getDeltaTime();
        float speed = 0.5f * delta;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            player.move(0, -speed);
            player.updateAnimation(Rotation::UP);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            player.move(-speed, 0);
            player.updateAnimation(Rotation::LEFT);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            player.move(0, speed);
            player.updateAnimation(Rotation::DOWN);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            player.move(speed, 0);
            player.updateAnimation(Rotation::RIGHT);
        }
        engine.Run();

        // if(player.returnSpriteObject().getGlobalBounds().intersects(newSprite2.returnSpriteObject().getGlobalBounds())){
        //     std::cout<<"1"<<std::endl;
        // }
    }
    return 0;
}