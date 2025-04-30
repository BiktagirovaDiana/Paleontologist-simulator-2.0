#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

#include "PlayerController.h"
#include "UI.h"

class Base : public Scene 
{

public:
    Base();
    void handleEvent(sf::Event& event) override;
    void update(float time) override;
    void draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) override;

private:
    PlayerController Player;
    UI Text;

    sf::Texture BackgroundTexture;
    sf::Sprite BackgroundSprite;

    sf::FloatRect TransitionExpedition1;
    
};
