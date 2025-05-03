#include "Museum.h"
#include "Inventory.h"

int Museum::LevelTyrannosaurus = 0;
int Museum::LevelPterodactyl = 0;
int Museum::LevelNeanderthal = 0;
int Museum::LevelMammoth = 0;


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
	SellTyrannosaurusSprite.setPosition(570, 800);

	//Птерадактиль
	PterodactylTexture.loadFromFile("Skeletons.png");
	PterodactylSprite.setTexture(PterodactylTexture);
	PterodactylSprite.setScale(2, 2);
	PterodactylSprite.setPosition(300, 200);

	SellPterodactylTexture.loadFromFile("UI3.png");
	SellPterodactylSprite.setTexture(SellPterodactylTexture);
	SellPterodactylSprite.setTextureRect(sf::IntRect(0, 0, 180, 55));
	SellPterodactylSprite.setPosition(810, 800);

	//Неандерталец
	NeanderthalTexture.loadFromFile("Skeletons.png");
	NeanderthalSprite.setTexture(NeanderthalTexture);
	NeanderthalSprite.setScale(2, 2);
	NeanderthalSprite.setPosition(950, 230);

	SellNeanderthalTexture.loadFromFile("UI3.png");
	SellNeanderthalSprite.setTexture(SellNeanderthalTexture);
	SellNeanderthalSprite.setTextureRect(sf::IntRect(0, 0, 180, 55));
	SellNeanderthalSprite.setPosition(1030, 800);

	//Мамонт
	MammothTexture.loadFromFile("Skeletons.png");
	MammothSprite.setTexture(MammothTexture);
	MammothSprite.setScale(1.5, 1.5);
	MammothSprite.setPosition(1230, 170);

	SellMammothTexture.loadFromFile("UI3.png");
	SellMammothSprite.setTexture(SellMammothTexture);
	SellMammothSprite.setTextureRect(sf::IntRect(0, 0, 180, 55));
	SellMammothSprite.setPosition(1270, 800);

	

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
			sf::Vector2f windowPos = window.mapPixelToCoords(mousePos);

			// Проверяем, пересекается ли клик со спрайтом
			if (SellTyrannosaurusSprite.getGlobalBounds().contains(windowPos)) 
			{
				if (In.getTyrannosaurusBones() > 0)
				{
					In.SellTyrannosaurus();
					AddLevelTyrannosaurus();
				}
				
			}
			else if (SellPterodactylSprite.getGlobalBounds().contains(windowPos))
			{
				if (In.getPterodactylBones() > 0)
				{
					In.SellPterodactyl ();
					AddLevelPterodactyl();
				}
			}
			else if (SellMammothSprite.getGlobalBounds().contains(windowPos))
			{
				if (In.getMammothBones() > 0)
				{
					In.SellMammoth();
					AddLevelMammoth();
				}
			}
			else if (SellNeanderthalSprite.getGlobalBounds().contains(windowPos))
			{
				if (In.getNeanderthalBones() > 0)
				{
					In.SellNeanderthal();
					AddLevelNeanderthal();
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

void Museum::AddLevelMammoth()
{
	LevelMammoth++;
}

void Museum::AddLevelNeanderthal()
{
	LevelNeanderthal++;
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

	switch (LevelNeanderthal)
	{
	case 0:
		NeanderthalSprite.setTextureRect(sf::IntRect(0, 900, 0, 0));
		break;
	case 1:
		NeanderthalSprite.setTextureRect(sf::IntRect(0, 900, 400, 300));
		break;
	case 2:
		NeanderthalSprite.setTextureRect(sf::IntRect(400, 900, 400, 300));
		break;
	case 3:
		NeanderthalSprite.setTextureRect(sf::IntRect(800, 900, 400, 300));
		break;
	case 4:
		NeanderthalSprite.setTextureRect(sf::IntRect(1200, 900, 400, 300));
		break;
	case 5:
		NeanderthalSprite.setTextureRect(sf::IntRect(1600, 900, 400, 300));
		break;
	}

	switch (LevelMammoth)
	{
	case 0:
		MammothSprite.setTextureRect(sf::IntRect(0, 600, 0, 0));
		break;
	case 1:
		MammothSprite.setTextureRect(sf::IntRect(0, 600, 400, 300));
		break;
	case 2:
		MammothSprite.setTextureRect(sf::IntRect(400, 600, 400, 300));
		break;
	case 3:
		MammothSprite.setTextureRect(sf::IntRect(800, 600, 400, 300));
		break;
	case 4:
		MammothSprite.setTextureRect(sf::IntRect(1200, 600, 400, 300));
		break;
	case 5:
		MammothSprite.setTextureRect(sf::IntRect(1600, 600, 400, 300));
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


	window.draw(MammothSprite);
	window.draw(SellMammothSprite);

	window.draw(NeanderthalSprite);
	window.draw(SellNeanderthalSprite);

	

	
	window.setView(UIView);
	Text.draw(window);
}
