#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Inventory.h"

class UI : public Inventory
{
public:
	UI();
	void draw(sf::RenderWindow& window);
	void handleEvent(sf::Event& event, sf::RenderWindow& window);

protected:

	sf::Font Touraine;

	//�������
	sf::Text TextSatiety;
	sf::Texture SatietyTexture;
	sf::Sprite SatietySprite;
	std::ostringstream LevelSatietyString;

	//������
	sf::Text TextCash;
	sf::Texture CashTexture;
	sf::Sprite CashSprite;
	std::ostringstream CashString;


	//����������
	sf::Text TextTyrann;
	sf::Texture IconTyrannTexture;
	sf::Sprite IconTyrannSprite;
	std::ostringstream TyrannString;

	//������������
	sf::Text TextPter;
	sf::Texture IconPterTexture;
	sf::Sprite IconPterSprite;
	std::ostringstream PterString;
	
	//������
	sf::Text TextMammoth;
	sf::Texture IconMammothTexture;
	sf::Sprite IconMammothSprite;
	std::ostringstream MammothString;

	//������������
	sf::Text TextNeand;
	sf::Texture IconNeandTexture;
	sf::Sprite IconNeandSprite;
	std::ostringstream NeandString;

	//�����
	sf::Text TextPickaxe;
	sf::Texture IconPickaxeTexture;
	sf::Sprite IconPickaxeSprite;
	std::ostringstream PickaxeString;

	//������
	sf::Text TextShovel;
	sf::Texture IconShovelTexture;
	sf::Sprite IconShovelSprite;
	std::ostringstream ShovelString;

	//�����
	sf::Text TextBrush;
	sf::Texture IconBrushTexture;
	sf::Sprite IconBrushSprite;
	std::ostringstream BrushString;

	//�������
	sf::Text TextStew;
	sf::Texture IconStewTexture;
	sf::Sprite IconStewSprite;
	std::ostringstream StewString;

	//�����
	sf::Text TextDoshirak;
	sf::Texture IconDoshirakTexture;
	sf::Sprite IconDoshirakSprite;
	std::ostringstream DoshirakString;
};


