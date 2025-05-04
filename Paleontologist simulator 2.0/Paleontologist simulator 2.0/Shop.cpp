#include "Shop.h"

Shop::Shop()
{
	BackgroundTexture.loadFromFile("Background_Shop.png");
	BackgroundSprite.setTexture(BackgroundTexture);

	UI_Texture.loadFromFile("UI_Items.png");

	PickaxeSprite.setTexture(UI_Texture);
	PickaxeSprite.setTextureRect(sf::IntRect(360, 0, 180, 180));
	PickaxeSprite.setPosition(690, 480);

	ShovelSprite.setTexture(UI_Texture);
	ShovelSprite.setTextureRect(sf::IntRect(540, 0, 180, 180));
	ShovelSprite.setPosition(890, 480);

	BrushSprite.setTexture(UI_Texture);
	BrushSprite.setTextureRect(sf::IntRect(720, 0, 180, 180));
	BrushSprite.setPosition(1090, 480);

	StrewSprite.setTexture(UI_Texture);
	StrewSprite.setTextureRect(sf::IntRect(0, 0, 180, 180));
	StrewSprite.setPosition(790, 320);

	DoshirakSprite.setTexture(UI_Texture);
	DoshirakSprite.setTextureRect(sf::IntRect(180, 0, 180, 180));
	DoshirakSprite.setPosition(990, 320);

	UI3Texture.loadFromFile("UI3.png");
	ExitSprite.setTexture(UI3Texture);
	ExitSprite.setTextureRect(sf::IntRect(360, 0, 180, 180));
	ExitSprite.setPosition(20, 850);

	Touraine.loadFromFile("Touraine.ttf");

	TextPickaxe.setFont(Touraine);
	TextPickaxe.setString("250");
	TextPickaxe.setCharacterSize(50);
	TextPickaxe.setFillColor(sf::Color::Black);
	TextPickaxe.setPosition(595, 680);

	TextBrush.setFont(Touraine);
	TextBrush.setString("100");
	TextBrush.setCharacterSize(50);
	TextBrush.setFillColor(sf::Color::Black);
	TextBrush.setPosition(760, 680);

	TextStew.setFont(Touraine);
	TextStew.setString("80");
	TextStew.setCharacterSize(50);
	TextStew.setFillColor(sf::Color::Black);
	TextStew.setPosition(950, 680);

	TextDoshirak.setFont(Touraine);
	TextDoshirak.setString("35");
	TextDoshirak.setCharacterSize(50);
	TextDoshirak.setFillColor(sf::Color::Black);
	TextDoshirak.setPosition(1125, 680);

	TextShovel.setFont(Touraine);
	TextShovel.setString("150");
	TextShovel.setCharacterSize(50);
	TextShovel.setFillColor(sf::Color::Black);
	TextShovel.setPosition(1280, 680);

}
void Shop::handleEvent(sf::Event& event, sf::RenderWindow& window) 
{
	window.setKeyRepeatEnabled(false);
	Inventory In;
	if (event.type == sf::Event::MouseButtonPressed) 
	{
		if (event.mouseButton.button == sf::Mouse::Left) {
			//позицию клика
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			//координаты окна
			sf::Vector2f windowPos = window.mapPixelToCoords(mousePos);


			if (PickaxeSprite.getGlobalBounds().contains(windowPos))
			{
				if (In.getEndurancePickaxe() == 0)
				{
					In.AddPickaxe();
				}
			}
			else if (ShovelSprite.getGlobalBounds().contains(windowPos))
			{
				if (In.getEnduranceShovel() == 0)
				{
					In.AddShovel();
				}
			}
			else if (BrushSprite.getGlobalBounds().contains(windowPos))
			{
				if (In.getEnduranceBrush() == 0)
				{
					In.AddBrush();
				}
			}
			else if (StrewSprite.getGlobalBounds().contains(windowPos))
			{
				In.AddStew();
			}
			else if (DoshirakSprite.getGlobalBounds().contains(windowPos))
			{
				In.AddDoshirak();
			}

			else if (ExitSprite.getGlobalBounds().contains(windowPos))
			{
				CheckBase = true;
			}
		}
	}
	
}

void Shop::update(float time) 
{

}

void Shop::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView)
{
	window.draw(BackgroundSprite);

	window.draw(PickaxeSprite);
	window.draw(ShovelSprite);
	window.draw(BrushSprite);
	window.draw(StrewSprite);
	window.draw(DoshirakSprite);

	window.draw(ExitSprite);
	Text.draw(window);
	window.draw(TextPickaxe);
	window.draw(TextShovel);
	window.draw(TextBrush);
	window.draw(TextStew);
	window.draw(TextDoshirak);
}