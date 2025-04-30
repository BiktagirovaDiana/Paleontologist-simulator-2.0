#include "Base.h"

Base::Base() 
{
	BackgroundTexture.loadFromFile("Background_Base.png");
	BackgroundSprite.setTexture(BackgroundTexture);

	TransitionExpedition1 = sf::FloatRect(1400, 900, 300, 200);
}
void Base::handleEvent(sf::Event& event) 
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
}
void Base::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView)
{
	window.setView(GameView);
	//window.setView(window.getDefaultView());
	window.draw(BackgroundSprite);
	Player.draw(window);

	window.setView(UIView);
	Text.draw(window);
	Text.draw(window);
}
