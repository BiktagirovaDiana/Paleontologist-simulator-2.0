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
#include "Museum.h"
#include "Shop.h"

#include "Pterodactyl.h"
#include "Tyrannosaurus.h"
#include "Mammoth.h"
#include "Neanderthal.h"


int LevelSatiety = 10;
//int Cash = 0;

//int TyrannosaurusBones = 0;
//int PterodactylBones = 0;
//int MammothBones = 0;
//int NeanderthalBones = 0;
//
//int EndurancePickaxe = 100;
//int EnduranceShovel = 100;
//int EnduranceBrush = 100; 

bool CheckBase = false;
bool CheckExpedition1 = false;
bool CheckMuseum = false;
bool CheckShop = false;


enum class GameState { Base, Expedition_1, Museum , Shop};


int main()
{

	sf::RenderWindow window(sf::VideoMode(1920, 1050), "Paleontologist simulator", sf::Style::Default);
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

	Inventory In;
	Museum Mu;



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
				/*if (ev.key.code == sf::Keyboard::P) {
					In.AddCash();
				}*/
				if (ev.key.code == sf::Keyboard::O) {
					In.AddStew();
					In.AddDoshirak();
				}
				if (ev.key.code == sf::Keyboard::I) {
					State = GameState::Shop;
					currentScene = std::make_unique<Shop>();
					CheckShop = false;
				}
				if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::F)
				{
					In.EatingDoshik();
				}
				if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::G)
				{
					In.EatingStew();
				}
			}
			if (CheckExpedition1 == true) 
			{
				State = GameState::Expedition_1;
				currentScene = std::make_unique<Expedition_1>();
				CheckExpedition1 = false;
			}
			if (CheckBase == true)
			{
				State = GameState::Base;
				currentScene = std::make_unique<Base>();
				CheckBase = false;
			}
			if (CheckMuseum == true) 
			{
				State = GameState::Museum;
				currentScene = std::make_unique<Museum>();
				CheckMuseum = false;
			}
			if (CheckShop == true) 
			{
				State = GameState::Shop;
				currentScene = std::make_unique<Shop>();
				CheckShop = false;
			}

			currentScene->handleEvent(ev, window);
			
		}
		
		currentScene->update(time);
		window.clear();
		currentScene->draw(window,GameView, UIView);
		window.display();
	}
}
