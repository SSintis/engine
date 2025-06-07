#include "../include/Core/Engine.hpp"
#include "../include/Graphics/RenderSystem.hpp"
#include "../include/Graphics/SpriteObject.hpp"
#include <iostream>
#include <sstream>

#define WIDTH 600
#define HEIGHT 400

int main() {
  int count = 0;

  Engine engine(WIDTH, HEIGHT, "GAME IS LOOP!!!", 240);

  SpriteObject newSprite(
      "/home/emo_profisional/programingCplusPlus/engine/assets/as.jpg", 0, 150,
      0.1);
  SpriteObject newSprite2(
      "/home/emo_profisional/programingCplusPlus/engine/assets/sa.jpg",
      WIDTH / 2, HEIGHT / 2, 0.1);
  SpriteObject player("/home/emo_profisional/programingCplusPlus/engine/assets/BODY_skeleton.png", 1, 1, 1);

  sf::FloatRect nsbt= newSprite2.returnSpriteObject().getGlobalBounds();

  sf::Font font; // шрифт
  if (!font.loadFromFile("/home/emo_profisional/programingCplusPlus/engine/assets/Roboto-Black.ttf")) {
    std::cerr << "Failed to load font!" << std::endl;
  }

  sf::Text text(
      "", font,
      20); // создаем объект текст. закидываем в объект текст строку, шрифт,
           // размер шрифта(в пикселях);//сам объект текст (не строка)
  text.setStyle(sf::Text::Bold | sf::Text::Underlined); // жир
  text.setFillColor(sf::Color::White);

  player.initAnimation(64, 64);
  // player.setHitbox(0, 0, 64, 64);
  player.setCollider(0, 0, 64, 64);
  // newSprite2.setHitbox(0, 0, nsb.width, nsb.height);
  newSprite2.setCollider();
  newSprite.setCollider();

  RenderSystem::addNewSprite(&newSprite2);
  RenderSystem::addNewSprite(&newSprite);
  RenderSystem::addNewSprite(&player);

  RenderSystem::addNewText(&text);

  RenderSystem::editSettings(Setting::DRAW_COLLIDER);

  while (engine.gameIsOn()) {
    float delta = engine.getDeltaTime();
    float speed = 0.5f * delta;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      player.move(0, -speed);
      player.updateAnimation(Rotation::UP);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      player.move(-speed, 0);
      player.updateAnimation(Rotation::LEFT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      player.move(0, speed);
      player.updateAnimation(Rotation::DOWN);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      player.move(speed, 0);
      player.updateAnimation(Rotation::RIGHT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
      RenderSystem::editSettings(Setting::DRAW_COLLIDER);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
      RenderSystem::editSettings(Setting::NOT_DRAW_COLLIDER);
    }
    player.getCollider()->update();
    newSprite2.getCollider()->update();

    if (player.getCollider()->checkCollision(*newSprite2.getCollider())) {
      player.getCollider()->resolveCollision(*newSprite2.getCollider());
    }
    if (player.getCollider()->checkCollision(*newSprite.getCollider())) {
      std::cout << "Collider!!!\n";
      RenderSystem::deleteSprite(&newSprite);
      count++;
    }

    std::ostringstream playerScoreString;
    playerScoreString << count;

    text.setString("fesfefse: " +
                   playerScoreString.str()); // задает строку тексту
    text.setPosition(50, 50); // задаем позицию текста, центр камеры

    engine.Run();
  }
  return 0;
}
