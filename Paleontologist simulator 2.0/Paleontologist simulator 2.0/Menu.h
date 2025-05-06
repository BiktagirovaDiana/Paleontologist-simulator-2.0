#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Game.h"

class Menu: public Scene
{
public:
	Menu();
	void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
	void update(float time) override;
	void draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) override;
	void lose();

private:
	sf::Texture BackgroundTexture;
	sf::Sprite BackgroundSprite;

	sf::Texture UI;

	sf::Sprite NewGameIcon;
	sf::Sprite ContinueGameIcon;
	sf::Sprite ExitGameIcon;

	sf::Font Touraine;

	sf::Text NewGameText;
	sf::Text ContinueGameText;
	sf::Text ExitGameText;

	sf::Text LoseText;
	Game Game;

	//bool isLose = false;
};


