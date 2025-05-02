#pragma once
#include "PlayerController.h"


//extern int Cash;
//extern int LevelSatiety;
//extern int TyrannosaurusBones;
//extern int PterodactylBones;
//extern int MammothBones;
//extern int NeanderthalBones;
//
//extern int EndurancePickaxe;
//extern int EnduranceShovel;
//extern int EnduranceBrush;



class Inventory: public PlayerController
{
public:
	enum Hand { None, Pickaxe, Shovel, Brush };  //����� ������� � ���� � ������
	Hand PlayerHand = None;


	void AddCash()
	{
		Cash = Cash + 50;
	}
	void AddStew() {
		Stew = Stew + 1;
	}
	void AddDoshirak() 
	{
		Doshirak = Doshirak + 1;
	}

	void EatingDoshik() 
	{
		if (Doshirak > 0) 
		{
			Doshirak--;
			LevelSatiety++;
		}
		
	}

	void EatingStew()
	{
		if (Stew > 0)
		{
			Stew--;
			LevelSatiety += 5;
		}
		
	}

	void SellTyrannosaurus() 
	{
		TyrannosaurusBones--;
		Cash += 300;
	}
	void SellPterodactyl()
	{
		PterodactylBones--;
		Cash += 300;
	}
	void SellMammoth()
	{
		MammothBones--;
		Cash += 200;
	}
	void SellNeanderthal()
	{
		NeanderthalBones--;
		Cash += 250;
	}

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

	static int getTyrannosaurusBones() {
		return TyrannosaurusBones;
	}
	static int getPterodactylBones() {
		return PterodactylBones;
	}
	static int getMammothBones() {
		return MammothBones;
	}
	static int getNeanderthalBones() {
		return NeanderthalBones;
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

protected:

	int intFossils = 0;
	
	static int LevelSatiety;
	static int Cash;


	static int TyrannosaurusBones;
	static int PterodactylBones;
	static int MammothBones;
	static int NeanderthalBones;

	static int EndurancePickaxe;
	static int EnduranceShovel;
	static int EnduranceBrush;

	static int Stew;
	static int Doshirak;


};

