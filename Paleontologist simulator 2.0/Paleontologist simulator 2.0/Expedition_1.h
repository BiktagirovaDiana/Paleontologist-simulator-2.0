#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "PlayerController.h"
#include "UI.h"

class Expedition_1 : public Scene {
public:
    Expedition_1();
    void handleEvent(sf::Event& event) override;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window, sf::View GameView) override;

private:
    PlayerController Player;
    UI Text;
    sf::Texture BackgroundTexture;
    sf::Sprite BackgroundSprite;
};
