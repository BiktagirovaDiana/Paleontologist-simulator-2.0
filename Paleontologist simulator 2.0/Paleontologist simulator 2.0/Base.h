#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

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

private:
    PlayerController Player;
    UI Text;

    sf::Texture BackgroundTexture;
    sf::Sprite BackgroundSprite;

    sf::FloatRect TransitionExpedition1;
    sf::FloatRect TransitionMuseum;
    sf::FloatRect TransitionShop;

    sf::Texture UI4;
    sf::Sprite IconHomeSprite;
    Game Game;
};
