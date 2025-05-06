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
	

	bool isVisiblePickaxe = false;
	bool isVisibleShovel = false;
	bool isVisibleBrush = false;

	

protected:

	int ImmersionLevel = 4; //уровень закопаности (0-4)
	//3 - в камнях, земли и пыли 
	//2 - в земли и пыли
	//1 - в пыли
	//0 - раскопано

	int Broken = false; //Сломана ли раскопка (сломать может только сам игрок)

	sf::Texture TextureLand;
	sf::Sprite LandSprite;
	sf::Clock landChangeTimer; //таймер для инструментов

	float speedTools = 60.0f; //скорость для всех инструментов
	 
	sf::Clock toolDelayTimer;  //таймер задержки нажатие клавиш
	bool isToolDelayActive = false;  //флаг активности задержки

	bool Trigger = false;

	UI Text;


	sf::Texture TextureTools;

	//Кирка
	//sf::Texture TexturePickaxe;
	sf::Sprite PickaxeSprite;
	int FramePickaxe = 0;
	bool AnimPickaxe = false;
	bool DirectPickaxe = true;
	bool shouldChangeLandPickaxe = false; //флаг для смены спрайта

	//Лопата
	//sf::Texture TextureShovel;
	sf::Sprite ShovelSprite;
	int FrameShovel = 0;
	bool AnimShovel = false;
	bool DirectShovel = true;
	bool shouldChangeLandShovel = false;

	//Кисть
	//sf::Texture TextureBrush;
	sf::Sprite BrushSprite;
	int FrameBrush = 0;
	bool AnimBrush = false;
	bool DirectBrush = true;
	bool shouldChangeLandBrush = false;

	bool shouldChangeLandHand = false;

	UI Satiety;
	
	int currentAnimationCycle;

	void Excavation()
	{
		if (LevelSatiety > 0) 
		{
			if (ImmersionLevel == 4)
			{
				if (PlayerHand == Pickaxe) UsingPickaxe(true);
				else if (PlayerHand == Shovel && EnduranceShovel > 0) UsingShovel(false);
				else if (PlayerHand == Brush && EnduranceBrush > 0) UsingBrush(false);

			}
			else if (ImmersionLevel == 3)
			{
				if (PlayerHand == Pickaxe && EndurancePickaxe > 0) UsingPickaxe(false);
				else if (PlayerHand == Shovel && EnduranceShovel > 0) UsingShovel(true);
				else if (PlayerHand == Brush && EnduranceBrush > 0) UsingPickaxe(false);
			}
			else if (ImmersionLevel == 2)
			{
				if (PlayerHand == Pickaxe) UsingPickaxe(false);
				else if (PlayerHand == Shovel) UsingShovel(false);
				if (PlayerHand == Brush) UsingBrush(true);
				
			}
			else if (ImmersionLevel == 1)
			{
				if (PlayerHand == Pickaxe) UsingPickaxe(false);
				else if (PlayerHand == Shovel) UsingShovel(false);
				if (PlayerHand == None) {
					AddFossil();
					DrawLandLevel0(true);
					ImmersionLevel = 0;
				}
				
				//Подбор раскопки
			}
			LevelSatiety--;
			DeadPlayer();
		}
		else 
		{
			DeadPlayer();
		}
		
	};
	void UsingPickaxe(bool RightTool) 
	{
		if (RightTool == true && EndurancePickaxe > 0)
		{
			isVisiblePickaxe = true;
			AnimPickaxe = true;
			FramePickaxe = 0;
			DirectPickaxe = false;
			currentAnimationCycle = 0;

			landChangeTimer.restart();
			shouldChangeLandPickaxe = true;
			DamagePickaxe(15);
			ImmersionLevel = 3;
		}
		else if (RightTool == false && EndurancePickaxe > 0)
		{
			if (ImmersionLevel == 3) 
			{
				isVisiblePickaxe = true;
				AnimPickaxe = true;
				FramePickaxe = 0;
				DirectPickaxe = false;
				currentAnimationCycle = 0;

				DamagePickaxe(25);
				DrawLandLevel4();
				//Broken = true;
			}
			else if (ImmersionLevel < 3)
			{
				isVisiblePickaxe = true;
				AnimPickaxe = true;
				FramePickaxe = 0;
				DirectPickaxe = false;
				currentAnimationCycle = 0;

				DamagePickaxe(25);
				DrawLandLevel0(false);
			}
			
		}
		Hand PlayerHand = None; 
	}
	void UsingShovel(bool RightTool)
	{
		if (RightTool == true && EnduranceShovel > 0)
		{
			isVisibleShovel = true;
			AnimShovel = true;
			FrameShovel = 0;
			DirectShovel = false;
			currentAnimationCycle = 0;

			landChangeTimer.restart();
			shouldChangeLandShovel = true;
			DamageShovel(20);
			ImmersionLevel = 2;
		}
		else if (RightTool == false && EnduranceShovel > 0)
		{
			if (ImmersionLevel < 3) 
			{
				isVisibleShovel = true;
				AnimShovel = true;
				FrameShovel = 0;
				DirectShovel = false;
				currentAnimationCycle = 0;

				DamageShovel(30);
				DrawLandLevel0(false);
				//Broken = true;
			}
			
		}
	}
	void UsingBrush(bool RightTool) 
	{
		if (RightTool == true && EnduranceBrush > 0)
		{
			isVisibleBrush = true;
			AnimBrush = true;
			FrameBrush = 0;
			DirectBrush = false;
			currentAnimationCycle = 0;

			landChangeTimer.restart();
			shouldChangeLandBrush = true;
			DamageBrush(30);
			ImmersionLevel = 1;
		}
		else if(RightTool == false && EnduranceBrush != 0)
		{
			isVisibleBrush = true;
			AnimBrush = true;
			FrameBrush = 0;
			DirectBrush = false;
			currentAnimationCycle = 0;

			DamageBrush(50);
		}
	}
	void TakeBones() 
	{
		shouldChangeLandHand = true;
		ImmersionLevel = 0;
	}
	virtual void AddFossil() {};
};

