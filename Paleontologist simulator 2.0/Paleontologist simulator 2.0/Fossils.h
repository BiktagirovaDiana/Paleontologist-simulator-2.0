#pragma once
#include "Inventory.h"
#include "PlayerController.h"
#include "UI.h"



class Fossils : public Inventory
{
public:

	Fossils(int x, int y);

	void ToolsControl(sf::Event& ev);
	void Update(float time);
	void draw(sf::RenderWindow& window);
	virtual void DrawLandLevel4() = 0;
	virtual void DrawLandLevel3() = 0;
	virtual void DrawLandLevel2() = 0;
	virtual void DrawLandLevel1() = 0;
	virtual void DrawLandLevel0(bool Right) = 0;
	void UpdateTrigger(const sf::Sprite& playerSprite);

	void Excavation();
	void UsingPickaxe(bool RightTool);
	void UsingShovel(bool RightTool);
	void UsingBrush(bool RightTool);
	void TakeBones();
	

	bool isVisiblePickaxe = false;
	bool isVisibleShovel = false;
	bool isVisibleBrush = false;

	

protected:

	int immersionLevel_ = 4; //уровень закопаности (0-4)
	//3 - в камнях, земли и пыли 
	//2 - в земли и пыли
	//1 - в пыли
	//0 - раскопано

	int broken_ = false; //Сломана ли раскопка (сломать может только сам игрок)

	sf::Texture TextureLand;
	sf::Sprite LandSprite;
	sf::Clock landChangeTimer; //таймер для инструментов

	float speedTools = 60.0f; //скорость для всех инструментов
	 
	sf::Clock toolDelayTimer;  //таймер задержки нажатие клавиш
	bool isToolDelayActive = false;  //флаг активности задержки

	bool trigger_ = false;

	UI Text;


	sf::Texture TextureTools;

	//Кирка
	sf::Sprite PickaxeSprite;
	int framePickaxe_ = 0;
	bool animPickaxe_ = false;
	bool directPickaxe_ = true;
	bool shouldChangeLandPickaxe_ = false; //флаг для смены спрайта

	//Лопата
	sf::Sprite ShovelSprite;
	int frameShovel_ = 0;
	bool animShovel_ = false;
	bool directShovel_ = true;
	bool shouldChangeLandShovel_ = false;

	//Кисть
	sf::Sprite BrushSprite;
	int frameBrush_ = 0;
	bool animBrush_ = false;
	bool directBrush_ = true;
	bool shouldChangeLandBrush_ = false;

	bool shouldChangeLandHand_ = false;

	UI Satiety;
	
	int currentAnimationCycle_;

	virtual void AddFossil() {};
};

