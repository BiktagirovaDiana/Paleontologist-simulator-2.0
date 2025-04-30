#include <iostream>
#include <sstream>


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "PlayerController.h"
#include "Fossils.h"
#include "UI.h"
#include "Inventory.h"


#include "Pterodactyl.h"
#include "Tyrannosaurus.h"
#include "Mammoth.h"
#include "Neanderthal.h"


int LevelSatiety = 10;

int TyrannosaurusBones = 0;
int PterodactylBones = 0;
int MammothBones = 0;
int NeanderthalBones = 0;

int EndurancePickaxe = 100;
int EnduranceShovel = 100;
int EnduranceBrush = 100; 

//enum class GameState { Base, Expedition_1 };


int main()
{

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Paleontologist simulator", sf::Style::Default);
	window.setFramerateLimit(30);
	//sf::View view = window.getDefaultView();
	// 
	//Defaulf - закрытие и увеличение окна, надпись и т.д.

	sf::View GameView = window.getDefaultView(); //Игровой мир
	sf::View UIView = window.getDefaultView(); //Интерфейс

	sf::Texture BackgroundTexture;
	BackgroundTexture.loadFromFile("Background_Base.png");
	sf::Sprite BackgroundSprite(BackgroundTexture);


	sf::Event ev; //для отслеживания действий игрока


	sf::Clock Clock; //время

	
	PlayerController Player;

	UI Text;
	Pterodactyl Fossil1(95, 550);
	Tyrannosaurus Fossil2(1610, 270);
	Mammoth Fossil3(1405, 820);
	Neanderthal Fossil4(470, 855);

	Inventory PlayerInventory;


	while (window.isOpen())
	{
		float time = Clock.restart().asSeconds();

		GameView.setCenter(Player.getPosition());

		sf::FloatRect backgroundBounds(0, 0,
			BackgroundTexture.getSize().x,
			BackgroundTexture.getSize().y);
		sf::Vector2f cameraCenter = GameView.getCenter();
		sf::Vector2f cameraSize = GameView.getSize();

		if (cameraCenter.x - cameraSize.x / 2 < backgroundBounds.left)
			cameraCenter.x = backgroundBounds.left + cameraSize.x / 2;
		if (cameraCenter.y - cameraSize.y / 2 < backgroundBounds.top)
			cameraCenter.y = backgroundBounds.top + cameraSize.y / 2;
		if (cameraCenter.x + cameraSize.x / 2 > backgroundBounds.left + backgroundBounds.width)
			cameraCenter.x = backgroundBounds.left + backgroundBounds.width - cameraSize.x / 2;
		if (cameraCenter.y + cameraSize.y / 2 > backgroundBounds.top + backgroundBounds.height)
			cameraCenter.y = backgroundBounds.top + backgroundBounds.height - cameraSize.y / 2;

		GameView.setCenter(cameraCenter);




		while (window.pollEvent(ev))
		{

			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				//закрытие окна
				break;
			}
			Player.PlayerMovement(ev, time);

			Fossil1.ToolsControl(ev, time) ;
			Fossil2.ToolsControl(ev, time);
			Fossil3.ToolsControl(ev, time);
			Fossil4.ToolsControl(ev, time);
			
		}



		Player.Update(time);

		window.clear();
		window.setView(GameView);

		window.draw(BackgroundSprite);

		Fossil1.Update(time);
		Fossil1.UpdateTrigger(Player.getSprite());

		Fossil2.Update(time);
		Fossil2.UpdateTrigger(Player.getSprite());

		Fossil3.Update(time);
		Fossil3.UpdateTrigger(Player.getSprite());

		Fossil4.Update(time);
		Fossil4.UpdateTrigger(Player.getSprite());

		

		Fossil1.draw(window);
		Fossil2.draw(window);
		Fossil3.draw(window);
		Fossil4.draw(window);

		Player.draw(window);

		//Отрисовка интерфейса
		window.setView(UIView);
		Text.draw(window);
		Text.draw(window);
		
		
		window.display();


	}
}
