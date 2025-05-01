#pragma once
#include <SFML/Graphics.hpp>

extern bool CheckBase;
extern bool CheckExpedition1;
extern bool CheckMuseum;

class Scene {
public:
    virtual ~Scene() = default;
    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) = 0;
    virtual void update(float time) = 0;
    virtual void draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) = 0;
};

