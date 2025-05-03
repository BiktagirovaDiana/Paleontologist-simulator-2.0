#pragma once
#include "Inventory.h"
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "UI.h"

class Shop : public Scene
{
public:
    Shop();
    void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
    void update(float time) override;
    void draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) override;

	
private:
    sf::Font Touraine;
    sf::Text TextPickaxe;
    sf::Text TextShovel;
    sf::Text TextBrush;
    sf::Text TextStew;
    sf::Text TextDoshirak;

    sf::Texture BackgroundTexture;
    sf::Sprite BackgroundSprite;

    sf::Texture UI_Texture;
    sf::Texture UI3Texture;

    sf::Sprite PickaxeSprite;
    sf::Sprite ShovelSprite;
    sf::Sprite BrushSprite;

    sf::Sprite StrewSprite;
    sf::Sprite DoshirakSprite;

    sf::Sprite ExitSprite;

    UI Text;
};

