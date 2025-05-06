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

	SkeletonsTexture.loadFromFile("Skeletons2.png");
	UI3Texture.loadFromFile("UI3.png");

	//Тираннозавр
	TyrannosaurusSprite.setTexture(SkeletonsTexture);
	TyrannosaurusSprite.setScale(1, 1);
	TyrannosaurusSprite.setPosition(-50, 70);

	SellTyrannosaurusSprite.setTexture(UI3Texture);
	SellTyrannosaurusSprite.setTextureRect(sf::IntRect(0, 0, 180, 55));
	SellTyrannosaurusSprite.setPosition(570, 800);

	//Птерадактиль
	PterodactylSprite.setTexture(SkeletonsTexture);
	PterodactylSprite.setScale(1, 1);
	PterodactylSprite.setPosition(300, 200);

	SellPterodactylSprite.setTexture(UI3Texture);
	SellPterodactylSprite.setTextureRect(sf::IntRect(0, 0, 180, 55));
	SellPterodactylSprite.setPosition(810, 800);

	//Неандерталец
	NeanderthalSprite.setTexture(SkeletonsTexture);
	NeanderthalSprite.setScale(1, 1);
	NeanderthalSprite.setPosition(950, 230);

	SellNeanderthalSprite.setTexture(UI3Texture);
	SellNeanderthalSprite.setTextureRect(sf::IntRect(0, 0, 180, 55));
	SellNeanderthalSprite.setPosition(1030, 800);

	//Мамонт
	MammothSprite.setTexture(SkeletonsTexture);
	MammothSprite.setScale(1, 1);
	MammothSprite.setPosition(1130, 70);

	SellMammothSprite.setTexture(UI3Texture);
	SellMammothSprite.setTextureRect(sf::IntRect(0, 0, 180, 55));
	SellMammothSprite.setPosition(1270, 800);

	//Выход
	ExitSprite.setTexture(UI3Texture);
	ExitSprite.setTextureRect(sf::IntRect(360, 0, 180, 180));
	ExitSprite.setPosition(20, 850);

}
void Museum::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	Inventory In;
	if (event.type == sf::Event::MouseButtonPressed) 
	{
		if (event.mouseButton.button == sf::Mouse::Left) {
			//позицию клика
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			//координаты окна
			sf::Vector2f windowPos = window.mapPixelToCoords(mousePos);


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
			else if (ExitSprite.getGlobalBounds().contains(windowPos)) 
			{
				CheckBase = true;
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
	int x = 800;
	int y = 600;

	if (LevelTyrannosaurus == 0) TyrannosaurusSprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
	else if (LevelTyrannosaurus <= 5) TyrannosaurusSprite.setTextureRect(sf::IntRect((LevelTyrannosaurus - 1)* 800, 0, x, y));

	if (LevelPterodactyl == 0) PterodactylSprite.setTextureRect(sf::IntRect(0, 600, 0, 0));
	else if (LevelPterodactyl <= 5) PterodactylSprite.setTextureRect(sf::IntRect((LevelPterodactyl - 1) * 800, 600, x, y));

	if (LevelNeanderthal == 0) NeanderthalSprite.setTextureRect(sf::IntRect(0, 1800, 0, 0));
	else if (LevelNeanderthal <= 5) NeanderthalSprite.setTextureRect(sf::IntRect((LevelNeanderthal - 1) * 800, 1800, x, y));

	if (LevelMammoth == 0) MammothSprite.setTextureRect(sf::IntRect(0, 1200, 0, 0));
	else if (LevelMammoth <= 5) MammothSprite.setTextureRect(sf::IntRect((LevelMammoth - 1) * 800, 1200, x, y));


}

void Museum::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView)
{
	window.draw(BackgroundSprite);

	window.draw(TyrannosaurusSprite);
	window.draw(SellTyrannosaurusSprite);

	
	window.draw(PterodactylSprite);
	window.draw(SellPterodactylSprite);


	window.draw(MammothSprite);
	window.draw(SellMammothSprite);

	window.draw(NeanderthalSprite);
	window.draw(SellNeanderthalSprite);

	window.draw(ExitSprite);
	Text.draw(window);
}

