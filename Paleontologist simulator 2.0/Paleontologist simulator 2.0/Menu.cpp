#include "Menu.h"
#include "Game.h"

extern bool isLose;

Menu::Menu() 
{
	Touraine.loadFromFile("Touraine.ttf");

	BackgroundTexture.loadFromFile("Background_Menu.png");
	BackgroundSprite.setTexture(BackgroundTexture);

	UI.loadFromFile("UI4.png");

	//Новая игра
	NewGameIcon.setTexture(UI);
	NewGameIcon.setTextureRect(sf::IntRect(0, 0, 600, 200));
	NewGameIcon.setPosition(690, 360);
	
	NewGameText.setFont(Touraine);
	NewGameText.setString(L"Новая игра");
	NewGameText.setCharacterSize(60);
	NewGameText.setFillColor(sf::Color::Black);
	NewGameText.setPosition(850, 425);

	//Продолжить игру
	ContinueGameIcon.setTexture(UI);
	ContinueGameIcon.setTextureRect(sf::IntRect(0, 0, 600, 200));
	ContinueGameIcon.setPosition(690, 515);

	ContinueGameText.setFont(Touraine);
	ContinueGameText.setString(L"Продолжить игру");
	ContinueGameText.setCharacterSize(60);
	ContinueGameText.setFillColor(sf::Color::Black);
	ContinueGameText.setPosition(770, 575);

	//Выйти из игры
	ExitGameIcon.setTexture(UI);
	ExitGameIcon.setTextureRect(sf::IntRect(0, 0, 600, 200));
	ExitGameIcon.setPosition(690, 670);

	ExitGameText.setFont(Touraine);
	ExitGameText.setString(L"Выход");
	ExitGameText.setCharacterSize(60);
	ExitGameText.setFillColor(sf::Color::Black);
	ExitGameText.setPosition(900, 725);

	LoseText.setFont(Touraine);
	LoseText.setString(L"ВЫ ПРОИГРАЛИ");
	LoseText.setCharacterSize(60);
	LoseText.setFillColor(sf::Color::Red);
	LoseText.setPosition(750, 225);


}
void Menu::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left) 
		{
			//позицию клика
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			//координаты окна
			sf::Vector2f windowPos = window.mapPixelToCoords(mousePos);


			if (NewGameIcon.getGlobalBounds().contains(windowPos))
			{
				Game.NewGame();
				checkBase_ = true;
				isLose = false;
			}
			else if (ContinueGameIcon.getGlobalBounds().contains(windowPos))
			{
				Game.LoadGame();
				checkBase_ = true;
			}
			else if (ExitGameIcon.getGlobalBounds().contains(windowPos))
			{
				window.close();
			}
		}
	}
}
void Menu::update(float time) 
{

}
void Menu::lose() 
{
	Game.NewGame();
	
}
void Menu::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) 
{
	window.draw(BackgroundSprite);

	window.draw(NewGameIcon);
	window.draw(NewGameText);

	window.draw(ContinueGameIcon);
	window.draw(ContinueGameText);

	window.draw(ExitGameIcon);
	window.draw(ExitGameText);
	if (isLose) 
	{
		window.draw(LoseText);
	}
	
}