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

    //�����������
    sf::Sprite TyrannosaurusSprite;
    static int LevelTyrannosaurus;
    sf::Sprite SellTyrannosaurusSprite;

    //������������
    sf::Sprite PterodactylSprite;
    static int LevelPterodactyl;
    sf::Sprite SellPterodactylSprite;

    //������
    sf::Sprite MammothSprite;
    static int LevelMammoth;
    sf::Sprite SellMammothSprite;

    //������������
    sf::Sprite NeanderthalSprite;
    static int LevelNeanderthal;
    sf::Sprite SellNeanderthalSprite;

    //�����
    sf::Sprite ExitSprite;


    UI Text;
};

