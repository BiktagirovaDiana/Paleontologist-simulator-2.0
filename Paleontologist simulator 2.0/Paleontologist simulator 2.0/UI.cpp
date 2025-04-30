#include "UI.h"
#include "Inventory.h"


UI::UI()
{
	//Шрифт
	Touraine.loadFromFile("Touraine.ttf");
	
	//Сытость
	TextSatiety.setFont(Touraine);
	TextSatiety.setCharacterSize(50);
	TextSatiety.setFillColor(sf::Color::White);
	TextSatiety.setPosition(170, 170);

	SatietyTexture.loadFromFile("UI2.png");
	SatietySprite.setTexture(SatietyTexture);
	SatietySprite.setTextureRect(sf::IntRect(720, 0, 360, 360));
	SatietySprite.setScale(0.5, 0.5);
	SatietySprite.setPosition(5, 120);

	//Тиранозавр
	TextTyrann.setFont(Touraine);
	TextTyrann.setCharacterSize(50);
	TextTyrann.setFillColor(sf::Color::White);
	TextTyrann.setPosition(170, 70);

	IconTyrannTexture.loadFromFile("UI2.png");
	IconTyrannSprite.setTexture(IconTyrannTexture);
	IconTyrannSprite.setTextureRect(sf::IntRect(0, 360, 360, 360));
	IconTyrannSprite.setScale(0.5, 0.5);
	IconTyrannSprite.setPosition(5, 5);


	//Птерадактель
	TextPter.setFont(Touraine);
	TextPter.setCharacterSize(50);
	TextPter.setFillColor(sf::Color::White);
	TextPter.setPosition(410, 70);

	IconPterTexture.loadFromFile("UI2.png");
	IconPterSprite.setTexture(IconPterTexture);
	IconPterSprite.setTextureRect(sf::IntRect(360, 360, 360, 360));
	IconPterSprite.setScale(0.5, 0.5);
	IconPterSprite.setPosition(240, 5);

	//Неандерталец
	TextNeand.setFont(Touraine);
	TextNeand.setCharacterSize(50);
	TextNeand.setFillColor(sf::Color::White);
	TextNeand.setPosition(900, 70);

	IconNeandTexture.loadFromFile("UI1.png");
	IconNeandSprite.setTexture(IconNeandTexture);
	IconNeandSprite.setTextureRect(sf::IntRect(720, 360, 360, 360));
	IconNeandSprite.setScale(0.5, 0.5);
	IconNeandSprite.setPosition(750, 5);

	//Мамонт
	TextMammoth.setFont(Touraine);
	TextMammoth.setCharacterSize(50);
	TextMammoth.setFillColor(sf::Color::White);
	TextMammoth.setPosition(700, 70);

	IconMammothTexture.loadFromFile("UI2.png");
	IconMammothSprite.setTexture(IconMammothTexture);
	IconMammothSprite.setTextureRect(sf::IntRect(1080, 360, 360, 360));
	IconMammothSprite.setScale(0.5, 0.5);
	IconMammothSprite.setPosition(500, 5);

	//Кирка
	TextPickaxe.setFont(Touraine);
	TextPickaxe.setCharacterSize(50);
	TextPickaxe.setFillColor(sf::Color::White);
	TextPickaxe.setPosition(170, 270);

	IconPickaxeTexture.loadFromFile("UI2.png");
	IconPickaxeSprite.setTexture(IconPickaxeTexture);
	IconPickaxeSprite.setTextureRect(sf::IntRect(0, 720, 360, 360));
	IconPickaxeSprite.setScale(0.35, 0.35);
	IconPickaxeSprite.setPosition(15, 250);

	//Лопата
	TextShovel.setFont(Touraine);
	TextShovel.setCharacterSize(50);
	TextShovel.setFillColor(sf::Color::White);
	TextShovel.setPosition(170, 370);

	IconShovelTexture.loadFromFile("UI2.png");
	IconShovelSprite.setTexture(IconShovelTexture);
	IconShovelSprite.setTextureRect(sf::IntRect(360, 720, 360, 360));
	IconShovelSprite.setScale(0.35, 0.35);
	IconShovelSprite.setPosition(15, 350);

	//Кисть
	TextBrush.setFont(Touraine);
	TextBrush.setCharacterSize(50);
	TextBrush.setFillColor(sf::Color::White);
	TextBrush.setPosition(170, 460);

	IconBrushTexture.loadFromFile("UI2.png");
	IconBrushSprite.setTexture(IconBrushTexture);
	IconBrushSprite.setTextureRect(sf::IntRect(720, 720, 360, 360));
	IconBrushSprite.setScale(0.35, 0.35);
	IconBrushSprite.setPosition(15, 440);

}


void UI::draw(sf::RenderWindow& window)
{
	LevelSatietyString.str("");
	LevelSatietyString << LevelSatiety;
	TextSatiety.setString(": " + LevelSatietyString.str());

	TyrannString.str("");
	TyrannString << TyrannosaurusBones;
	TextTyrann.setString(": " + TyrannString.str());

	PterString.str("");
	PterString << PterodactylBones;
	TextPter.setString(": " + PterString.str());

	NeandString.str("");
	NeandString << NeanderthalBones;
	TextNeand.setString(": " + NeandString.str());
	
	MammothString.str("");
	MammothString << MammothBones;
	TextMammoth.setString(": " + MammothString.str());

	PickaxeString.str("");
	PickaxeString << EndurancePickaxe;
	TextPickaxe.setString(": " + PickaxeString.str());

	ShovelString.str("");
	ShovelString << EnduranceShovel;
	TextShovel.setString(": " + ShovelString.str());

	BrushString.str("");
	BrushString << EnduranceBrush;
	TextBrush.setString(": " + BrushString.str());

	window.draw(TextSatiety);
	window.draw(SatietySprite);

	window.draw(IconTyrannSprite);
	window.draw(TextTyrann);

	window.draw(IconPterSprite);
	window.draw(TextPter);


	window.draw(IconMammothSprite);
	window.draw(TextMammoth);

	window.draw(IconNeandSprite);
	window.draw(TextNeand);

	window.draw(IconPickaxeSprite);
	window.draw(TextPickaxe);

	window.draw(IconShovelSprite);
	window.draw(TextShovel);

	window.draw(IconBrushSprite);
	window.draw(TextBrush);
}