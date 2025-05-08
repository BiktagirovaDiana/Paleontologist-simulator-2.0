#include "Base.h"

Base::Base()
{
	BackgroundTexture.loadFromFile("Background_Base.png");
	BackgroundSprite.setTexture(BackgroundTexture);

	TransitionMuseum = sf::FloatRect(1400, 0, 300, 10);
	TransitionShop = sf::FloatRect(220, 0, 300, 10);

	UI4.loadFromFile("UI4.png");
	IconHomeSprite.setTexture(UI4);
	IconHomeSprite.setTextureRect(sf::IntRect(590, 0, 200, 200));
	IconHomeSprite.setScale(0.75, 0.75);
	IconHomeSprite.setPosition(1750, 20);

	BusTexture.loadFromFile("Bus.png");
	BusSprite.setTexture(BusTexture);
	BusSprite.setScale(0.75, 0.75);
	BusSprite.setPosition(700, 700);
}
void Base::handleEvent(sf::Event& event, sf::RenderWindow& window)
{

	Player.PlayerMovement(event);
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left) {
			//ïîçèöèþ êëèêà
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			//êîîðäèíàòû îêíà
			sf::Vector2f windowPos = window.mapPixelToCoords(mousePos);
			{
				if (IconHomeSprite.getGlobalBounds().contains(windowPos))
				{
					CheckMenu = true;
					Game.SaveGame();


				}
			}
		}
	}
}
void Base::update(float time)
{
	Player.Update(time);
	Base::UpdateTrigger(Player.getSprite());

	if (TransitionMuseum.contains(Player.getPosition()))
	{
		CheckMuseum = true;
	}
	if (TransitionShop.contains(Player.getPosition()))
	{
		CheckShop = true;
	}
	if (!Trigger) return;

	else
	{
		CheckExpeditions = true;
		
	}

}
void Base::UpdateTrigger(const sf::Sprite& playerSprite)
{
	Trigger = BusSprite.getGlobalBounds().intersects(playerSprite.getGlobalBounds());
}
void Base::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView)
{
	window.setView(GameView);
	window.draw(BackgroundSprite);
	Player.draw(window);
	window.draw(BusSprite);



	window.setView(UIView);
	Text.draw(window);
	window.draw(IconHomeSprite);
}