#pragma once
#include <SFML/Graphics.hpp>

class Scene {
public:
    virtual ~Scene() = default;
    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float time) = 0;
    virtual void draw(sf::RenderWindow& window, sf::View GameView) = 0;
};

