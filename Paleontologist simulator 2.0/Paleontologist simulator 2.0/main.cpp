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
#include "Museum.h"
#include "Shop.h"
#include "Menu.h"

#include "Expedition_1.h"
#include "Expedition_2.h"
#include "Expedition_3.h"
#include "Expeditions.h"

#include "Pterodactyl.h"
#include "Tyrannosaurus.h"
#include "Mammoth.h"
#include "Neanderthal.h"
#include "Game.h"


bool CheckBase = false;
bool CheckMuseum = false;
bool CheckShop = false;
bool CheckMenu = false;
bool CheckLose = false;
bool CheckExpeditions = false;
bool CheckExpedition1 = false;
bool CheckExpedition2 = false;
bool CheckExpedition3 = false;


bool isLose = false;


enum class GameState { Menu, Base, Museum , Shop, Expedition_1, Expedition_2, Expedition_3, Expeditions};


int main()
{

	std::cout << "запуск игры" << std::endl;

	sf::RenderWindow window(sf::VideoMode(1920, 1050), "Paleontologist simulator", sf::Style::Default);
	window.setFramerateLimit(30);
	//sf::View view = window.getDefaultView();
	// 
	//Defaulf - закрытие и увеличение окна, надпись и т.д.

	GameState State = GameState::Menu;
	std::unique_ptr<Scene> currentScene = std::make_unique<Menu>();

	sf::View GameView = window.getDefaultView(); //Игровой мир
	sf::View UIView = window.getDefaultView(); //Интерфейс

	sf::Event ev; //для отслеживания действий игрока

	sf::Clock Clock; //время

	Inventory In;
	Museum Mu;
	Menu Me;



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


			if (ev.type == sf::Event::KeyPressed) {

				if (ev.key.code == sf::Keyboard::F)
				{
					In.EatingDoshik();
				}
				if (ev.key.code == sf::Keyboard::G)
				{
					In.EatingStew();
				}
				if (ev.key.code == sf::Keyboard::I)
				{
					State = GameState::Expedition_3;
					currentScene = std::make_unique<Expedition_3>();
					CheckExpedition3 = false;
				}
			}
			if (CheckExpedition1) 
			{
				State = GameState::Expedition_1;
				currentScene = std::make_unique<Expedition_1>();
				CheckExpedition1 = false;
			}
			if (CheckExpedition2)
			{
				State = GameState::Expedition_2;
				currentScene = std::make_unique<Expedition_2>();
				CheckExpedition2 = false;
			}
			if (CheckExpedition3)
			{
				State = GameState::Expedition_3;
				currentScene = std::make_unique<Expedition_3>();
				CheckExpedition3 = false;
			}
			if (CheckBase)
			{
				State = GameState::Base;
				currentScene = std::make_unique<Base>();
				CheckBase = false;
			}
			if (CheckMuseum) 
			{
				State = GameState::Museum;
				currentScene = std::make_unique<Museum>();
				CheckMuseum = false;
			}
			if (CheckShop) 
			{
				State = GameState::Shop;
				currentScene = std::make_unique<Shop>();
				CheckShop = false;
			}
			if (CheckMenu)
			{
				State = GameState::Menu;
				currentScene = std::make_unique<Menu>();
				CheckMenu = false;
			}
			if (CheckLose) 
			{
				isLose = true;
				Me.lose();
				State = GameState::Menu;
				currentScene = std::make_unique<Menu>();
				CheckMenu = false;
			}
			if (CheckExpeditions)
			{
				State = GameState::Expeditions;
				currentScene = std::make_unique<Expeditions>();
				CheckExpeditions = false;
			}

			currentScene->handleEvent(ev, window);
			
		}
		
		currentScene->update(time);
		window.clear();
		currentScene->draw(window,GameView, UIView);
		window.display();
	}
}
