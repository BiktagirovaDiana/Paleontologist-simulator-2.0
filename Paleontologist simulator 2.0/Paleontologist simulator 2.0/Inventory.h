#pragma once
#include "PlayerController.h"

extern int LevelSatiety;

extern int TyrannosaurusBones;
extern int PterodactylBones;
extern int MammothBones;
extern int NeanderthalBones;

extern int EndurancePickaxe;
extern int EnduranceShovel;
extern int EnduranceBrush;

class Inventory: public PlayerController
{
public:
	enum Hand { None, Pickaxe, Shovel, Brush };  //����� ������� � ���� � ������
	Hand PlayerHand = None;

protected:

	int intFossils = 0;
	

	int Cash = 1000;

	//static int TyrannosaurusBones;
	//static int PterodactylBones;
	//static int MammothBones;
	//static int NeanderthalBones;

	//static int EndurancePickaxe;
	//static int EnduranceShovel;
	//static int EnduranceBrush;

	//static int LevelSatiety;


	void AddBonesTyrannosaurus() 
	{
		TyrannosaurusBones++;
	}
	void AddBonesPterodacty()
	{
		PterodactylBones++;
	}
	void AddBonesMammoth()
	{
		MammothBones++;
	}
	void AddBonesNeanderthal()
	{
		NeanderthalBones++;
	}

	
	//���������� ������������
	void AddPickaxe()  //���������� �����, ��� ������
	{
		if (EndurancePickaxe <= 0) EndurancePickaxe = 100;
		else
		{
			//����� ��� ����
		}
	}
	void AddShovel() 
	{
		if (EnduranceShovel <= 0) EnduranceShovel = 100;
		else 
		{
			//������ ��� ����
		}
		
	}
	void AddBrush() 
	{
		if (EnduranceBrush <= 0) EnduranceBrush = 100;
		else 
		{
			//����� ��� ����
		}
	}
	//��������� ��������� ������������

	void DamagePickaxe(int n) 
	{
		//15
		EndurancePickaxe -= n;
		if (EndurancePickaxe <= 0) 
		{
			BrokePickaxe();
		}
	}
	void DamageShovel(int n) {
		//20
		EnduranceShovel -= n;
		if (EnduranceShovel <= 0) {
			BrokeShovel();
		}
	}
	void DamageBrush(int n) {
		//35
		EnduranceBrush -= n;
		if (EnduranceBrush <= 0) {
			BrokeBrush();
		}
	}

	//������� ������������
	void BrokePickaxe() 
	{
		EndurancePickaxe = 0;
	}
	void BrokeShovel()
	{
		EnduranceShovel = 0;
	}
	void BrokeBrush()
	{
		EnduranceBrush = 0;
	}

};

