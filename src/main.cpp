#include "../include/Core/Engine.hpp"
#include "../include/Graphics/RenderSystem.hpp"
#include "../include/Graphics/SpriteObject.hpp"
#include <iostream>

#define WIDTH 600
#define HEIGHT 400

int main()
{
    Engine engine(WIDTH, HEIGHT, "GAME IS LOOP!!!", 240);

    SpriteObject newSprite("/home/emo_profisional/programingCplusPlus/engine/assets/as.jpg", 0, 50, 0.1);
    SpriteObject newSprite2("/home/emo_profisional/programingCplusPlus/engine/assets/sa.jpg", WIDTH / 2, HEIGHT / 2, 0.1);
    SpriteObject player("/home/emo_profisional/programingCplusPlus/engine/assets/BODY_skeleton.png", 0, 1, 1);

    sf::FloatRect nsb = newSprite2.returnSpriteObject().getGlobalBounds();

    player.initAnimation(64, 64);
    //player.setHitbox(0, 0, 64, 64);
    player.setCollider(0, 0, 64, 64);

    //newSprite2.setHitbox(0, 0, nsb.width, nsb.height);
    newSprite2.setCollider();

    RenderSystem::addNewSprite(&newSprite2);
    RenderSystem::addNewSprite(&newSprite);
    RenderSystem::addNewSprite(&player);
    RenderSystem::editSettings(Setting::DRAW_COLLIDER);

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
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            RenderSystem::editSettings(Setting::DRAW_COLLIDER);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            RenderSystem::editSettings(Setting::NOT_DRAW_COLLIDER);
        }
        player.getCollider()->update();
        newSprite2.getCollider()->update();

        if(player.getCollider()->checkCollision(*newSprite2.getCollider())){
            player.getCollider()->resolveCollision(*newSprite2.getCollider());
        }

        engine.Run();
    }
    return 0;
}