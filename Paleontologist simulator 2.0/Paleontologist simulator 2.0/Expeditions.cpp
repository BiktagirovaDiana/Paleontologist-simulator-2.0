#include "Expeditions.h"


Expeditions::Expeditions() 
{
	BackgroundTexture.loadFromFile("Background_Bus.png");
	BackgroundSprite.setTexture(BackgroundTexture);

	Touraine.loadFromFile("Touraine.ttf");
	UI.loadFromFile("UI4.png");

	PlainText.setFont(Touraine);
	PlainText.setString(L"Равнины");
	PlainText.setCharacterSize(80);
	PlainText.setFillColor(sf::Color::Black);
	PlainText.setPosition(250, 750);
	
	PlainSprite.setTexture(UI);
	PlainSprite.setTextureRect(sf::IntRect(0, 0, 600, 200));
	PlainSprite.setPosition(100, 700);

	SteppeText.setFont(Touraine);
	SteppeText.setString(L"Степи");
	SteppeText.setCharacterSize(80);
	SteppeText.setFillColor(sf::Color::Black);
	SteppeText.setPosition(850, 750);

	SteppeSprite.setTexture(UI);
	SteppeSprite.setTextureRect(sf::IntRect(0, 0, 600, 200));
	SteppeSprite.setPosition(650, 700);

	TundraText.setFont(Touraine);
	TundraText.setString(L"Тундра");
	TundraText.setCharacterSize(80);
	TundraText.setFillColor(sf::Color::Black);
	TundraText.setPosition(1370, 750);

	TundraSprite.setTexture(UI);
	TundraSprite.setTextureRect(sf::IntRect(0, 0, 600, 200));
	TundraSprite.setPosition(1200, 700);
}

void Expeditions::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left) {
			//позицию клика
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			//координаты окна
			sf::Vector2f windowPos = window.mapPixelToCoords(mousePos);


			if (PlainSprite.getGlobalBounds().contains(windowPos))
			{
				CheckExpedition1 = true;
			}
			if (SteppeSprite.getGlobalBounds().contains(windowPos))
			{
				CheckExpedition2 = true;
			}
			if (TundraSprite.getGlobalBounds().contains(windowPos))
			{
				CheckExpedition3 = true;
			}
		}
	}
}

void Expeditions::update(float deltaTime) 
{

}
void Expeditions::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) 
{
	window.draw(BackgroundSprite);
	window.draw(PlainSprite);
	window.draw(PlainText);
	window.draw(SteppeSprite);
	window.draw(SteppeText);
	window.draw(TundraSprite);
	window.draw(TundraText);
}
