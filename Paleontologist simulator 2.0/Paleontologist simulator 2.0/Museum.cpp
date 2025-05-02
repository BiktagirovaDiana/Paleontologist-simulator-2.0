#include "Museum.h"
#include "Inventory.h"

int Museum::LevelTyrannosaurus = 0;
int Museum::LevelPterodactyl = 0;

Museum::Museum()
{
	BackgroundTexture.loadFromFile("Background_Museum.png");
	BackgroundSprite.setTexture(BackgroundTexture);

	//Тираннозавр
	TyrannosaurusTexture.loadFromFile("Skeletons.png");
	TyrannosaurusSprite.setTexture(TyrannosaurusTexture);
	TyrannosaurusSprite.setScale(2, 2);
	TyrannosaurusSprite.setPosition(-50, 70);

	SellTyrannosaurusTexture.loadFromFile("UI3.png");
	SellTyrannosaurusSprite.setTexture(SellTyrannosaurusTexture);
	SellTyrannosaurusSprite.setTextureRect(sf::IntRect(0, 0, 180, 55));
	SellTyrannosaurusSprite.setPosition(580, 800);

	//Птерадактиль
	PterodactylTexture.loadFromFile("Skeletons.png");
	PterodactylSprite.setTexture(PterodactylTexture);
	PterodactylSprite.setScale(2, 2);
	PterodactylSprite.setPosition(300, 200);

	SellPterodactylTexture.loadFromFile("UI3.png");
	SellPterodactylSprite.setTexture(SellPterodactylTexture);
	SellPterodactylSprite.setTextureRect(sf::IntRect(0, 0, 180, 55));
	SellPterodactylSprite.setPosition(810, 800);


	

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
				if (In.getTyrannosaurusBones() > 0)
				{
					In.SellTyrannosaurus();
					AddLevelTyrannosaurus();
				}
				
			}
			else if (SellPterodactylSprite.getGlobalBounds().contains(worldPos))
			{
				if (In.getPterodactylBones() > 0)
				{
					In.SellPterodactyl ();
					AddLevelPterodactyl();
				}

			}
		}
	}
}

void Museum::AddLevelTyrannosaurus()
{
	LevelTyrannosaurus++;
}
void Museum::AddLevelPterodactyl() 
{
	LevelPterodactyl++;
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
		TyrannosaurusSprite.setTextureRect(sf::IntRect(400, 0, 400, 300));
		break;
	case 3:
		TyrannosaurusSprite.setTextureRect(sf::IntRect(800, 0, 400, 300));
		break;
	case 4:
		TyrannosaurusSprite.setTextureRect(sf::IntRect(1200, 0, 400, 300));
		break;
	case 5:
		TyrannosaurusSprite.setTextureRect(sf::IntRect(1600, 0, 400, 300));
		break;
	}

	switch (LevelPterodactyl)
	{
	case 0:
		PterodactylSprite.setTextureRect(sf::IntRect(0, 300, 0, 0));
		break;
	case 1:
		PterodactylSprite.setTextureRect(sf::IntRect(0, 300, 400, 300));
		break;
	case 2:
		PterodactylSprite.setTextureRect(sf::IntRect(400, 300, 400, 300));
		break;
	case 3:
		PterodactylSprite.setTextureRect(sf::IntRect(800, 300, 400, 300));
		break;
	case 4:
		PterodactylSprite.setTextureRect(sf::IntRect(1200, 300, 400, 300));
		break;
	case 5:
		PterodactylSprite.setTextureRect(sf::IntRect(1600, 300, 400, 300));
		break;
	}

}

void Museum::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView)
{
	window.setView(GameView);
	window.draw(BackgroundSprite);
	window.draw(TyrannosaurusSprite);
	window.draw(SellTyrannosaurusSprite);
	window.draw(PterodactylSprite);
	window.draw(SellPterodactylSprite);

	window.setView(UIView);
	Text.draw(window);
}
