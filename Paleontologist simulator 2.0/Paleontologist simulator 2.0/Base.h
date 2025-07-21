#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Inventory.h"

#include "PlayerController.h"
#include "UI.h"
#include "Game.h"

class Base : public Scene
{

public:
    Base();
    void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
    void update(float time) override;
    void draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) override;
    void UpdateTrigger(const sf::Sprite& playerSprite);

private:
    PlayerController player_;
    UI text_;

    sf::Texture BackgroundTexture;
    sf::Sprite BackgroundSprite;

    sf::FloatRect TransitionMuseum;
    sf::FloatRect TransitionShop;

    sf::Texture UI;
    sf::Sprite IconHomeSprite;

    sf::Texture BusTexture;
    sf::Sprite BusSprite;

    bool trigger_ = false;
    Inventory In;
    Game Game;
};