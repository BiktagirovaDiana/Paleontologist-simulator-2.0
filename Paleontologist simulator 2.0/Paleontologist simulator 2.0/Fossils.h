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

	int immersionLevel_ = 4; //������� ����������� (0-4)
	//3 - � ������, ����� � ���� 
	//2 - � ����� � ����
	//1 - � ����
	//0 - ���������

	int broken_ = false; //������� �� �������� (������� ����� ������ ��� �����)

	sf::Texture TextureLand;
	sf::Sprite LandSprite;
	sf::Clock landChangeTimer; //������ ��� ������������

	float speedTools = 60.0f; //�������� ��� ���� ������������
	 
	sf::Clock toolDelayTimer;  //������ �������� ������� ������
	bool isToolDelayActive = false;  //���� ���������� ��������

	bool trigger_ = false;

	UI Text;


	sf::Texture TextureTools;

	//�����
	sf::Sprite PickaxeSprite;
	int framePickaxe_ = 0;
	bool animPickaxe_ = false;
	bool directPickaxe_ = true;
	bool shouldChangeLandPickaxe_ = false; //���� ��� ����� �������

	//������
	sf::Sprite ShovelSprite;
	int frameShovel_ = 0;
	bool animShovel_ = false;
	bool directShovel_ = true;
	bool shouldChangeLandShovel_ = false;

	//�����
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

