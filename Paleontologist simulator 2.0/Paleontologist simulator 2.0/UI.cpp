#include "UI.h"
#include "Inventory.h"

UI::UI()
{
	//Шрифт
	Touraine.loadFromFile("Touraine.ttf");
	
	//Тиранозавр
	TextTyrann.setFont(Touraine);
	TextTyrann.setCharacterSize(50);
	TextTyrann.setFillColor(sf::Color::Black);
	TextTyrann.setPosition(170, 70);

	IconTyrannTexture.loadFromFile("UI2.png");
	IconTyrannSprite.setTexture(IconTyrannTexture);
	IconTyrannSprite.setTextureRect(sf::IntRect(0, 360, 360, 360));
	IconTyrannSprite.setScale(0.5, 0.5);
	IconTyrannSprite.setPosition(5, 5);


	//Птерадактель
	TextPter.setFont(Touraine);
	TextPter.setCharacterSize(50);
	TextPter.setFillColor(sf::Color::Black);
	TextPter.setPosition(410, 70);

	IconPterTexture.loadFromFile("UI2.png");
	IconPterSprite.setTexture(IconPterTexture);
	IconPterSprite.setTextureRect(sf::IntRect(360, 360, 360, 360));
	IconPterSprite.setScale(0.5, 0.5);
	IconPterSprite.setPosition(240, 5);

	//Неандерталец
	TextNeand.setFont(Touraine);
	TextNeand.setCharacterSize(50);
	TextNeand.setFillColor(sf::Color::Black);
	TextNeand.setPosition(620, 70);


	IconNeandTexture.loadFromFile("UI1.png");
	IconNeandSprite.setTexture(IconNeandTexture);
	IconNeandSprite.setTextureRect(sf::IntRect(720, 360, 360, 360));
	IconNeandSprite.setScale(0.5, 0.5);
	IconNeandSprite.setPosition(480, 5);

	//Мамонт
	TextMammoth.setFont(Touraine);
	TextMammoth.setCharacterSize(50);
	TextMammoth.setFillColor(sf::Color::Black);
	TextMammoth.setPosition(910, 70);

	IconMammothTexture.loadFromFile("UI2.png");
	IconMammothSprite.setTexture(IconMammothTexture);
	IconMammothSprite.setTextureRect(sf::IntRect(1080, 360, 360, 360));
	IconMammothSprite.setScale(0.5, 0.5);
	IconMammothSprite.setPosition(730, 5);



	//Сытость
	TextSatiety.setFont(Touraine);
	TextSatiety.setCharacterSize(50);
	TextSatiety.setFillColor(sf::Color::Black);
	TextSatiety.setPosition(170, 170);

	SatietyTexture.loadFromFile("UI2.png");
	SatietySprite.setTexture(SatietyTexture);
	SatietySprite.setTextureRect(sf::IntRect(720, 0, 360, 360));
	SatietySprite.setScale(0.5, 0.5);
	SatietySprite.setPosition(5, 120);

	//Деньги
	TextCash.setFont(Touraine);
	TextCash.setCharacterSize(50);
	TextCash.setFillColor(sf::Color::Black);
	TextCash.setPosition(170, 270);

	CashTexture.loadFromFile("UI2.png");
	CashSprite.setTexture(CashTexture);
	CashSprite.setTextureRect(sf::IntRect(1080, 0, 360, 360));
	CashSprite.setScale(0.5, 0.5);
	CashSprite.setPosition(5, 220);

	
	//Кирка
	TextPickaxe.setFont(Touraine);
	TextPickaxe.setCharacterSize(50);
	TextPickaxe.setFillColor(sf::Color::Black);
	TextPickaxe.setPosition(170, 370);

	IconPickaxeTexture.loadFromFile("UI2.png");
	IconPickaxeSprite.setTexture(IconPickaxeTexture);
	IconPickaxeSprite.setTextureRect(sf::IntRect(0, 720, 360, 360));
	IconPickaxeSprite.setScale(0.35, 0.35);
	IconPickaxeSprite.setPosition(15, 350);

	//Лопата
	TextShovel.setFont(Touraine);
	TextShovel.setCharacterSize(50);
	TextShovel.setFillColor(sf::Color::Black);
	TextShovel.setPosition(170, 470);

	IconShovelTexture.loadFromFile("UI2.png");
	IconShovelSprite.setTexture(IconShovelTexture);
	IconShovelSprite.setTextureRect(sf::IntRect(360, 720, 360, 360));
	IconShovelSprite.setScale(0.35, 0.35);
	IconShovelSprite.setPosition(15, 450);

	//Кисть
	TextBrush.setFont(Touraine);
	TextBrush.setCharacterSize(50);
	TextBrush.setFillColor(sf::Color::Black);
	TextBrush.setPosition(170, 560);

	IconBrushTexture.loadFromFile("UI2.png");
	IconBrushSprite.setTexture(IconBrushTexture);
	IconBrushSprite.setTextureRect(sf::IntRect(720, 720, 360, 360));
	IconBrushSprite.setScale(0.35, 0.35);
	IconBrushSprite.setPosition(15, 540);

	//Тушенка
	TextStew.setFont(Touraine);
	TextStew.setCharacterSize(50);
	TextStew.setFillColor(sf::Color::Black);
	TextStew.setPosition(170, 660);

	IconStewTexture.loadFromFile("UI2.png");
	IconStewSprite.setTexture(IconStewTexture);
	IconStewSprite.setTextureRect(sf::IntRect(0, 0, 360, 360));
	IconStewSprite.setScale(0.35, 0.35);
	IconStewSprite.setPosition(15, 640);

	//Дошик
	TextDoshirak.setFont(Touraine);
	TextDoshirak.setCharacterSize(50);
	TextDoshirak.setFillColor(sf::Color::Black);
	TextDoshirak.setPosition(170, 760);

	IconDoshirakTexture.loadFromFile("UI2.png");
	IconDoshirakSprite.setTexture(IconDoshirakTexture);
	IconDoshirakSprite.setTextureRect(sf::IntRect(360, 0, 360, 360));
	IconDoshirakSprite.setScale(0.35, 0.35);
	IconDoshirakSprite.setPosition(15, 740);

	/*UI4.loadFromFile("UI4.png");
	IconHomeSprite.setTexture(UI4);
	IconHomeSprite.setTextureRect(sf::IntRect(590, 0, 200, 200));
	IconHomeSprite.setScale(0.75, 0.75);
	IconHomeSprite.setPosition(1750, 20);*/


}
void UI::handleEvent(sf::Event& event, sf::RenderWindow& window)
{

	//if (event.type == sf::Event::MouseButtonPressed)
	//{
	//	if (event.mouseButton.button == sf::Mouse::Left) {
	//		//позицию клика
	//		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	//		//координаты окна
	//		sf::Vector2f windowPos = window.mapPixelToCoords(mousePos);
	//		{
	//			if (IconHomeSprite.getGlobalBounds().contains(windowPos)) {
	//				CheckMenu = true;
	//			}
	//		}
	//	}
	//}
}

void UI::draw(sf::RenderWindow& window)
{
	LevelSatietyString.str("");
	LevelSatietyString << LevelSatiety;
	TextSatiety.setString(": " + LevelSatietyString.str());

	CashString.str("");
	CashString << Cash;
	TextCash.setString(": " + CashString.str());

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

	StewString.str("");
	StewString << Stew;
	TextStew.setString(": " + StewString.str());

	DoshirakString.str("");
	DoshirakString << Doshirak;
	TextDoshirak.setString(": " + DoshirakString.str());

	window.draw(TextSatiety);
	window.draw(SatietySprite);

	window.draw(TextCash);
	window.draw(CashSprite);

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

	window.draw(IconStewSprite);
	window.draw(TextStew);

	window.draw(IconDoshirakSprite);
	window.draw(TextDoshirak);

	//window.draw(IconHomeSprite);
}