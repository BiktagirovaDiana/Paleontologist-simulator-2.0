#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Inventory.h"

class UI : public Inventory
{
public:
	UI();
	void draw(sf::RenderWindow& window);

protected:

	
	
	sf::Font Touraine;

	//Сытость
	sf::Text TextSatiety;
	sf::Texture SatietyTexture;
	sf::Sprite SatietySprite;
	std::ostringstream LevelSatietyString;

	//Деньги
	sf::Text TextCash;
	sf::Texture CashTexture;
	sf::Sprite CashSprite;
	std::ostringstream CashString;


	//Тиранозавр
	sf::Text TextTyrann;
	sf::Texture IconTyrannTexture;
	sf::Sprite IconTyrannSprite;
	std::ostringstream TyrannString;

	//Птерадактель
	sf::Text TextPter;
	sf::Texture IconPterTexture;
	sf::Sprite IconPterSprite;
	std::ostringstream PterString;
	
	//Мамонт
	sf::Text TextMammoth;
	sf::Texture IconMammothTexture;
	sf::Sprite IconMammothSprite;
	std::ostringstream MammothString;

	//Неандерталец
	sf::Text TextNeand;
	sf::Texture IconNeandTexture;
	sf::Sprite IconNeandSprite;
	std::ostringstream NeandString;

	//Кирка
	sf::Text TextPickaxe;
	sf::Texture IconPickaxeTexture;
	sf::Sprite IconPickaxeSprite;
	std::ostringstream PickaxeString;

	//Лопата
	sf::Text TextShovel;
	sf::Texture IconShovelTexture;
	sf::Sprite IconShovelSprite;
	std::ostringstream ShovelString;

	//Кисть
	sf::Text TextBrush;
	sf::Texture IconBrushTexture;
	sf::Sprite IconBrushSprite;
	std::ostringstream BrushString;

	//Тушенка
	sf::Text TextStew;
	sf::Texture IconStewTexture;
	sf::Sprite IconStewSprite;
	std::ostringstream StewString;

	//Дошик
	sf::Text TextDoshirak;
	sf::Texture IconDoshirakTexture;
	sf::Sprite IconDoshirakSprite;
	std::ostringstream DoshirakString;

};


