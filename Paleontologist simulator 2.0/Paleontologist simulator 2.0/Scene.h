#pragma once
#include <SFML/Graphics.hpp>

extern bool CheckBase;
extern bool CheckMuseum;
extern bool CheckShop;
extern bool CheckMenu;
extern bool CheckLose;
extern bool CheckExpedition1;
extern bool CheckExpedition2;
extern bool CheckExpedition3;
extern bool CheckExpeditions;

class Scene {
public:
    virtual ~Scene() = default;
    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) = 0;
    virtual void update(float time) = 0;
    virtual void draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) = 0;
};

