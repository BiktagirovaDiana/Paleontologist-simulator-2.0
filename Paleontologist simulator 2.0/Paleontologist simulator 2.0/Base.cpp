#include "Base.h"

Base::Base() 
{
	BackgroundTexture.loadFromFile("Background_Base.png");
	BackgroundSprite.setTexture(BackgroundTexture);

	//TransitionExpedition1 = sf::FloatRect(1400, 900, 300, 200);
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
			//позицию клика
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			//координаты окна
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
		int n = In.getCash();
		n -= 150;
		if (n > 1)
		{
			In.BuyExpedition();

		}
		else {
			CheckLose = true;
		}
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

	//sf::RectangleShape expeditionRect, museumRect, shopRect;

	//// Настройка прямоугольника для Expedition1
	//expeditionRect.setSize(sf::Vector2f(TransitionExpedition1.width, TransitionExpedition1.height));
	//expeditionRect.setPosition(TransitionExpedition1.left, TransitionExpedition1.top);
	//expeditionRect.setFillColor(sf::Color(255, 0, 0, 100)); // Полупрозрачный красный

	//// Настройка прямоугольника для Museum
	//museumRect.setSize(sf::Vector2f(TransitionMuseum.width, TransitionMuseum.height));
	//museumRect.setPosition(TransitionMuseum.left, TransitionMuseum.top);
	//museumRect.setFillColor(sf::Color(0, 255, 0, 100)); // Полупрозрачный зеленый

	//// Настройка прямоугольника для Shop
	//shopRect.setSize(sf::Vector2f(TransitionShop.width, TransitionShop.height));
	//shopRect.setPosition(TransitionShop.left, TransitionShop.top);
	//shopRect.setFillColor(sf::Color(0, 0, 255, 100)); // Полупрозрачный синий

	//// Отрисовка прямоугольников
	//window.draw(expeditionRect);
	//window.draw(museumRect);
	//window.draw(shopRect);

	window.setView(UIView);
	Text.draw(window);
	window.draw(IconHomeSprite);
}
