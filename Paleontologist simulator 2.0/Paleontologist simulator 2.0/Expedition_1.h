#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "PlayerController.h"
#include "UI.h"

#include "Fossils.h"
#include "Pterodactyl.h"
#include "Tyrannosaurus.h"
#include "Mammoth.h"
#include "Neanderthal.h"
#include "EmptyFossil.h"

class Expedition_1 : public Scene {
public:
    Expedition_1();
    void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) override;

private:
    sf::Texture BackgroundTexture;
    sf::Sprite BackgroundSprite;

    PlayerController Player;
    UI Text;
 
    Pterodactyl Pterodactyl;
    Tyrannosaurus Tyrannosaurus;
    Mammoth Mammoth;
    Neanderthal Neanderthal;
    EmptyFossil Fossil;

    sf::FloatRect TransitionBase;
};
