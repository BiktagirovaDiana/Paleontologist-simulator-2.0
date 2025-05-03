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
    void AddLevelMammoth();
    void AddLevelNeanderthal();
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

    //Мамонт
    sf::Texture MammothTexture;
    sf::Sprite MammothSprite;
    static int LevelMammoth;

    sf::Texture SellMammothTexture;
    sf::Sprite SellMammothSprite;

    //Неандерталец
    sf::Texture NeanderthalTexture;
    sf::Sprite NeanderthalSprite;
    static int LevelNeanderthal;

    sf::Texture SellNeanderthalTexture;
    sf::Sprite SellNeanderthalSprite;

    UI Text;

 
};

