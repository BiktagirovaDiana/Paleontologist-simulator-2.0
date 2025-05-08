#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Inventory.h"

class Expeditions : public Scene
{
public:
    Expeditions();
    void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) override;
private:

    sf::Texture BackgroundTexture;
    sf::Sprite BackgroundSprite;

    sf::Texture UI;

    sf::Font Touraine;

    sf::Sprite PlainSprite;
    sf::Sprite SteppeSprite;
    sf::Sprite TundraSprite;

    sf::Text PlainText;
    sf::Text SteppeText;
    sf::Text TundraText;
    Inventory In;

};
