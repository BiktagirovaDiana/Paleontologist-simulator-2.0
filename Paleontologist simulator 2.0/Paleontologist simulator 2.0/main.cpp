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

bool CheckBase = false;
bool CheckExpedition1 = false;


enum class GameState { Base, Expedition_1 };


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
				if (ev.key.code == sf::Keyboard::P) {
					State = GameState::Base;
					currentScene = std::make_unique<Base>();
				}
				else if (ev.key.code == sf::Keyboard::L) {
					State = GameState::Expedition_1;
					currentScene = std::make_unique<Expedition_1>();
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

			currentScene->handleEvent(ev);
			
		}
		
		currentScene->update(time);
		window.clear();
		currentScene->draw(window,GameView, UIView);
		window.display();
	}
}
