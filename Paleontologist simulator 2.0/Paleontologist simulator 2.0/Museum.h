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

    sf::Texture SkeletonsTexture;
    sf::Texture UI3Texture;

    //Тираннозавр
    sf::Sprite TyrannosaurusSprite;
    static int LevelTyrannosaurus;
    sf::Sprite SellTyrannosaurusSprite;

    //Птерадактиль
    sf::Sprite PterodactylSprite;
    static int LevelPterodactyl;
    sf::Sprite SellPterodactylSprite;

    //Мамонт
    sf::Sprite MammothSprite;
    static int LevelMammoth;
    sf::Sprite SellMammothSprite;

    //Неандерталец
    sf::Sprite NeanderthalSprite;
    static int LevelNeanderthal;
    sf::Sprite SellNeanderthalSprite;

    //Выход
    sf::Sprite ExitSprite;


    UI Text;
};

