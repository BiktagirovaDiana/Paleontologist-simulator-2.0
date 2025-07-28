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


bool checkBase_ = false;
bool checkMuseum_ = false;
bool checkShop_ = false;
bool checkMenu_ = false;
bool checkLose_ = false;
bool checkExpeditions_ = false;
bool checkExpedition1_ = false;
bool checkExpedition2_ = false;
bool checkExpedition3_ = false;


bool isLose = false;


enum class GameState { Menu, Base, Museum , Shop, Expedition_1, Expedition_2, Expedition_3, Expeditions};


int main()
{

	std::cout << "запуск игры" << std::endl;

	sf::RenderWindow window(sf::VideoMode(1920, 1050), "Paleontologist simulator", sf::Style::Default);
	window.setFramerateLimit(30);

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

				if (ev.key.code == sf::Keyboard::F) {
					In.EatingDoshik();
				}
				if (ev.key.code == sf::Keyboard::G) {
					In.EatingStew();
				}
			}
			if (checkExpedition1_) {
				State = GameState::Expedition_1;
				currentScene = std::make_unique<Expedition_1>();
				checkExpedition1_ = false;
			}
			if (checkExpedition2_) {
				State = GameState::Expedition_2;
				currentScene = std::make_unique<Expedition_2>();
				checkExpedition2_ = false;
			}
			if (checkExpedition3_) {
				State = GameState::Expedition_3;
				currentScene = std::make_unique<Expedition_3>();
				checkExpedition3_ = false;
			}
			if (checkBase_) {
				State = GameState::Base;
				currentScene = std::make_unique<Base>();
				checkBase_ = false;
			}
			if (checkMuseum_)  {
				State = GameState::Museum;
				currentScene = std::make_unique<Museum>();
				checkMuseum_ = false;
			}
			if (checkShop_) {
				State = GameState::Shop;
				currentScene = std::make_unique<Shop>();
				checkShop_ = false;
			}
			if (checkMenu_) {
				State = GameState::Menu;
				currentScene = std::make_unique<Menu>();
				checkMenu_ = false;
			}
			if (checkLose_) {
				isLose = true;
				Me.lose();
				State = GameState::Menu;
				currentScene = std::make_unique<Menu>();
				checkMenu_ = false;
			}
			if (checkExpeditions_) {
				State = GameState::Expeditions;
				currentScene = std::make_unique<Expeditions>();
				checkExpeditions_ = false;
			}
			currentScene->handleEvent(ev, window);
		}
		currentScene->update(time);
		window.clear();
		currentScene->draw(window,GameView, UIView);
		window.display();
	}
}
