#include "Base.h"

Base::Base() 
{
	BackgroundTexture.loadFromFile("Background_Base.png");
	BackgroundSprite.setTexture(BackgroundTexture);

	TransitionExpedition1 = sf::FloatRect(1400, 900, 300, 200);
	TransitionMuseum = sf::FloatRect(1400, 0, 300, 10);
}
void Base::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	Player.PlayerMovement(event);
}
void Base::update(float time)
{
	Player.Update(time);

	if (TransitionExpedition1.contains(Player.getPosition()))
	{
		CheckExpedition1 = true;
	}
	if (TransitionMuseum.contains(Player.getPosition()))
	{
		CheckMuseum = true;
	}
}
void Base::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView)
{
	window.setView(GameView);
	window.draw(BackgroundSprite);
	Player.draw(window);

	window.setView(UIView);
	Text.draw(window);
}
