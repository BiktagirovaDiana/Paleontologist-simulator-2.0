#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

class Menu: public Scene
{
public:
	Menu();
	void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
	void update(float time) override;
	void draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) override;

private:
	sf::Texture BackgroundTexture;
	sf::Sprite BackgroundSprite;

	sf::Texture UI;

	sf::Sprite NewGame;
	sf::Sprite ContinueGame;
	sf::Sprite ExitGame;
};

