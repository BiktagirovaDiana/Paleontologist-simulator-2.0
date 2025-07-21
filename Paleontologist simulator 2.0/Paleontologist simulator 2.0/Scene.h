#pragma once
#include <SFML/Graphics.hpp>

extern bool checkBase_;
extern bool checkMuseum_;
extern bool checkShop_;
extern bool checkMenu_;
extern bool checkLose_;
extern bool checkExpedition1_;
extern bool checkExpedition2_;
extern bool checkExpedition3_;
extern bool checkExpeditions_;

class Scene {
public:
    virtual ~Scene() = default;
    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) = 0;
    virtual void update(float time) = 0;
    virtual void draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) = 0;
};

