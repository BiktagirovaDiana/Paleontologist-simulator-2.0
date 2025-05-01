#include "Museum.h"
#include "Inventory.h"

int Museum::LevelTyrannosaurus = 0;

Museum::Museum()
{
	BackgroundTexture.loadFromFile("Background_Museum.png");
	BackgroundSprite.setTexture(BackgroundTexture);

	TyrannosaurusTexture.loadFromFile("Tyrannosaurus.png");
	TyrannosaurusSprite.setTexture(TyrannosaurusTexture);
	TyrannosaurusSprite.setScale(2, 2);
	TyrannosaurusSprite.setPosition(50, 150);

	SellTyrannosaurusTexture.loadFromFile("UI3.png");
	SellTyrannosaurusSprite.setTexture(SellTyrannosaurusTexture);
	SellTyrannosaurusSprite.setTextureRect(sf::IntRect(0, 0, 180, 55));
	SellTyrannosaurusSprite.setPosition(580, 800);

}
void Museum::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	Inventory In;
	if (event.type == sf::Event::MouseButtonPressed) 
	{
		if (event.mouseButton.button == sf::Mouse::Left) {
			// Получаем позицию клика
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			// Преобразуем в координаты окна (если нужно)
			sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

			// Проверяем, пересекается ли клик со спрайтом
			if (SellTyrannosaurusSprite.getGlobalBounds().contains(worldPos)) 
			{
				In.SellTyrannosaurus(); 
				
			}
		}
	}
}

void Museum::AddLevel() 
{
	LevelTyrannosaurus++;
}
void Museum::update(float time)
{
	switch (LevelTyrannosaurus)
	{
	case 0:
		TyrannosaurusSprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
		break;
	case 1:
		TyrannosaurusSprite.setTextureRect(sf::IntRect(0, 0, 400, 300));
		break;
	case 2:
		TyrannosaurusSprite.setTextureRect(sf::IntRect(400, 0, 800, 300));
		break;
	case 3:
		TyrannosaurusSprite.setTextureRect(sf::IntRect(800, 0, 1200, 300));
		break;
	case 4:
		TyrannosaurusSprite.setTextureRect(sf::IntRect(1200, 0, 1600, 300));
		break;
	case 5:
		TyrannosaurusSprite.setTextureRect(sf::IntRect(1600, 0, 2000, 300));
		break;
	default:
		break;
	}
}

void Museum::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView)
{
	window.setView(GameView);
	window.draw(BackgroundSprite);
	window.draw(TyrannosaurusSprite);
	window.draw(SellTyrannosaurusSprite);

	window.setView(UIView);
	Text.draw(window);
}
