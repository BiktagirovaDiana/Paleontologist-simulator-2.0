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
	virtual void DrawLandLevel0() = 0;
	void UpdateTrigger(const sf::Sprite& playerSprite);
	

	bool isVisiblePickaxe = false;
	bool isVisibleShovel = false;
	bool isVisibleBrush = false;

	

protected:

	int ImmersionLevel = 4; //������� ����������� (0-4)
	//3 - � ������, ����� � ���� 
	//2 - � ����� � ����
	//1 - � ����
	//0 - ���������

	int Broken = false; //������� �� �������� (������� ����� ������ ��� �����)

	sf::Texture TextureLand;
	sf::Sprite LandSprite;
	sf::Clock landChangeTimer; //������ ��� ������������

	float speedTools = 60.0f; //�������� ��� ���� ������������
	 
	sf::Clock toolDelayTimer;  //������ �������� ������� ������
	bool isToolDelayActive = false;  //���� ���������� ��������

	bool Trigger = false;

	UI Text;

	//�����
	sf::Texture TexturePickaxe;
	sf::Sprite PickaxeSprite;
	int FramePickaxe = 0;
	bool AnimPickaxe = false;
	bool DirectPickaxe = true;
	bool shouldChangeLandPickaxe = false; //���� ��� ����� �������

	//������
	sf::Texture TextureShovel;
	sf::Sprite ShovelSprite;
	int FrameShovel = 0;
	bool AnimShovel = false;
	bool DirectShovel = true;
	bool shouldChangeLandShovel = false;

	//�����
	sf::Texture TextureBrush;
	sf::Sprite BrushSprite;
	int FrameBrush = 0;
	bool AnimBrush = false;
	bool DirectBrush = true;
	bool shouldChangeLandBrush = false;

	bool shouldChangeLandHand = false;

	UI Satiety;
	
	int currentAnimationCycle;

	

	//����� ������ ������ ���� �������������
	//��������� (������ ������, ���������� � ���������)
	//������������ �����������

	//����� ��������
	// - ����� ��������
	// - ������� ������������
	// - ����� � ��������� ��������� �����������
	// - ����� � ������������ ��������
	// - ������� ��������

	//�������� ��� ������� �� ������ R
	void Excavation()
	{
		if (LevelSatiety > 0) 
		{
			if (ImmersionLevel == 4) //��������� �������
			{
				//��������� ������ ���������� � ����
				if (PlayerHand == Pickaxe) UsingPickaxe(true);
				else if (PlayerHand == Shovel)
				{
					if (EnduranceShovel != 0)
					{
						BrokeShovel();
						//������ ��������
						//������ �� �������� � ������� �� ��������
					}
					else
					{
						//������ �������
					}
				}
				else if (PlayerHand == Brush) UsingBrush(false);
			}
			else if (ImmersionLevel == 3)
			{
				//��������� ������ ���������� � ����
				if (PlayerHand == Pickaxe) UsingPickaxe(false);
				else if (PlayerHand == Shovel) UsingShovel(true);
				else if (PlayerHand == Brush) UsingPickaxe(false);
			}
			else if (ImmersionLevel == 2)
			{
				if (Broken == false) 
				{
					if (PlayerHand == Pickaxe) UsingPickaxe(false);
					else if (PlayerHand == Shovel) UsingShovel(false);
					if (PlayerHand == Brush) UsingBrush(true);
				}
				else {
					//�������� �������

				}
				
			}
			else if (ImmersionLevel == 1)
			{
				AddFossil();
				DrawLandLevel0();
				//������ ��������
			}
			LevelSatiety--;
		}
		else 
		{
			LevelSatiety = 0;
			//��������
		}
		
	};
	void UsingPickaxe(bool RightTool) 
	{
		if (RightTool == true)
		{
			if (EndurancePickaxe != 0)
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

				//������� ������
			}
			else
			{
				//����� �������
			}
		}
		else
		{
			if (EndurancePickaxe != 0)
			{
				DamagePickaxe(25);
				DrawLandLevel4();
				Broken = true;
				//�������� ��������
			}
			else
			{
				//����� �������
			}
		}
		Hand PlayerHand = None; 
	}
	void UsingShovel(bool RightTool)
	{
		if (RightTool == true) 
		{
			if (EnduranceShovel != 0)
			{

				isVisibleShovel = true; 
				AnimShovel = true;      
				FrameShovel = 0;       
				DirectShovel = false;  
				currentAnimationCycle = 0; 

				landChangeTimer.restart();
				shouldChangeLandShovel= true;
				DamageShovel(20);
				ImmersionLevel = 2;
			}
			else {
				//������ �������
			}
		}
		else 
		{
			if (EnduranceShovel != 0)
			{
				DamageShovel(30);
				//������ �� �������� � ������� �� ��������
				Broken = true;
				//�������� ��������
			}
			else
			{
				//������ �������
			}
		}
	}
	void UsingBrush(bool RightTool) 
	{
		if (RightTool == true) 
		{
			if (EnduranceBrush != 0)
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
			else 
			{
				//����� �������
			}
		}
		else 
		{
			if (EnduranceBrush != 0)
			{
				DamageBrush(50);
				//������ �� �������� � ������� �� ��������
			}
			else {
				//����� �������
			}
		}
	}
	void TakeBones() 
	{
		shouldChangeLandHand = true;
		ImmersionLevel = 0;
	}
	virtual void AddFossil()
	{
		//intFossils++;
	}
};

