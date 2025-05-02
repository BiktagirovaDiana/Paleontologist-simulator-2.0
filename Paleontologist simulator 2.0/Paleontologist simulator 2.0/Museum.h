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
    void AddLevelTyrannosaurus();
    void AddLevelPterodactyl();
private:

    sf::Texture BackgroundTexture;
    sf::Sprite BackgroundSprite;
    

    //Тираннозавр
    sf::Texture TyrannosaurusTexture;
    sf::Sprite TyrannosaurusSprite;
    static int LevelTyrannosaurus;

    sf::Texture SellTyrannosaurusTexture;
    sf::Sprite SellTyrannosaurusSprite;

    //Птерадактиль
    sf::Texture PterodactylTexture;
    sf::Sprite PterodactylSprite;
    static int LevelPterodactyl;

    sf::Texture SellPterodactylTexture;
    sf::Sprite SellPterodactylSprite;

    UI Text;

 
};

