#include "Expedition_1.h"

Expedition_1::Expedition_1() 
{
	BackgroundTexture.loadFromFile("Background_Base.png");
	BackgroundSprite.setTexture(BackgroundTexture);
}
void Expedition_1::handleEvent(sf::Event& event) 
{

}
void Expedition_1::update(float time) 
{

}
void Expedition_1::draw(sf::RenderWindow& window, sf::View GameView)
{
	window.setView(GameView);
	window.setView(window.getDefaultView());
	window.draw(BackgroundSprite);
}