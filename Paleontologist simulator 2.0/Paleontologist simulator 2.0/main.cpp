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

#include "Base.h"
#include "Expedition_1.h"

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

enum class GameState { Base, Expedition_1 };


int main()
{

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Paleontologist simulator", sf::Style::Default);
	window.setFramerateLimit(30);
	//sf::View view = window.getDefaultView();
	// 
	//Defaulf - закрытие и увеличение окна, надпись и т.д.

	GameState State = GameState::Base;
	std::unique_ptr<Scene> currentScene = std::make_unique<Base>();

	sf::View GameView = window.getDefaultView(); //Игровой мир
	sf::View UIView = window.getDefaultView(); //Интерфейс

	


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

			/*Fossil1.ToolsControl(ev, time) ;
			Fossil2.ToolsControl(ev, time);
			Fossil3.ToolsControl(ev, time);
			Fossil4.ToolsControl(ev, time);*/

			if (ev.type == sf::Event::KeyPressed) {
				if (ev.key.code == sf::Keyboard::P) {
					State = GameState::Base;
					currentScene = std::make_unique<Base>();
				}
				else if (ev.key.code == sf::Keyboard::L) {
					State = GameState::Expedition_1;
					currentScene = std::make_unique<Expedition_1>();
				}
			}

			currentScene->handleEvent(ev);
			
		}
		
		currentScene->update(time);
		window.clear();
		currentScene->draw(window,GameView);
		window.display();

		//Player.Update(time);

		//window.clear();
		//window.setView(GameView);


		//window.draw(BackgroundSprite);

		//Fossil1.Update(time);
		//Fossil1.UpdateTrigger(Player.getSprite());

		//Fossil2.Update(time);
		//Fossil2.UpdateTrigger(Player.getSprite());

		//Fossil3.Update(time);
		//Fossil3.UpdateTrigger(Player.getSprite());

		//Fossil4.Update(time);
		//Fossil4.UpdateTrigger(Player.getSprite());

		//

		//Fossil1.draw(window);
		//Fossil2.draw(window);
		//Fossil3.draw(window);
		//Fossil4.draw(window);

		//Player.draw(window);

		////Отрисовка интерфейса
		//window.setView(UIView);
		//Text.draw(window);
		//Text.draw(window);
		//
		//
		//window.display();

	}
}
