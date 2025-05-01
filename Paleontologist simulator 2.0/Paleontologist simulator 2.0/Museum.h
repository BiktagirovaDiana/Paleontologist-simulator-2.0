#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

#include "UI.h"

class Museum : public Scene
{
public:
    Museum();
    void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
    void update(float time) override;
    void draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) override;
    void AddLevel();
private:

    sf::Texture BackgroundTexture;
    sf::Sprite BackgroundSprite;

    sf::Texture TyrannosaurusTexture;
    sf::Sprite TyrannosaurusSprite;
    static int LevelTyrannosaurus;

    sf::Texture SellTyrannosaurusTexture;
    sf::Sprite SellTyrannosaurusSprite;

    UI Text;

 
};

