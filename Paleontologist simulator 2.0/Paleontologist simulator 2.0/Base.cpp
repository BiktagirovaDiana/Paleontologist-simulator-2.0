#include "Base.h"

Base::Base() 
{
	BackgroundTexture.loadFromFile("Background.png");
	BackgroundSprite.setTexture(BackgroundTexture);
}
void Base::handleEvent(sf::Event& event) 
{

}
void Base::update(float time)
{
}
void Base::draw(sf::RenderWindow& window, sf::View GameView)
{
	window.setView(GameView);
	window.setView(window.getDefaultView());
	window.draw(BackgroundSprite);
}
