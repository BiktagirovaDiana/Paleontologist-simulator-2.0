#pragma once
#include "PlayerController.h"


class Inventory: public PlayerController
{
public:
	enum Hand { None, Pickaxe, Shovel, Brush };  //какой предмет в руке у игрока
	Hand PlayerHand = None;


	void EatingDoshik() 
	{
		if (Doshirak > 0)
		{
			if (LevelSatiety < 10) 
			{
				Doshirak--;
				LevelSatiety++;
			}
			else Doshirak--;
		}
		
		
	}

	void EatingStew()
	{
		if (Stew > 0)
		{
			if (LevelSatiety < 6) 
			{
				Stew--;
				LevelSatiety += 5;
			}
			else Stew--;
			
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

	static int getTyrannosaurusBones() 
	{
		return TyrannosaurusBones;
	}
	static int getPterodactylBones() 
	{
		return PterodactylBones;
	}
	static int getMammothBones() 
	{
		return MammothBones;
	}
	static int getNeanderthalBones() 
	{
		return NeanderthalBones;
	}
	static int getEndurancePickaxe() {
		return EndurancePickaxe;
	}
	static int getEnduranceShovel() {
		return EnduranceShovel;
	}
	static int getEnduranceBrush() {
		return EnduranceBrush;
	}


	//Добавление инструментов
	void AddPickaxe()  
	{
		if (EndurancePickaxe <= 0 && Cash >= 250) 
		{
			EndurancePickaxe = 100;
			Cash -= 250;
		}
		else
		{
			//Кирка еще есть
		}
	}
	void AddShovel()
	{
		if (EnduranceShovel <= 0 && Cash >= 150) 
		{
			EnduranceShovel = 100;
			Cash -= 150;
		}
		else
		{
			//Лопата еще есть
		}
	}
	void AddBrush()
	{
		if (EnduranceBrush <= 0 && Cash >= 100)
		{
			EnduranceBrush = 100;
			Cash -= 100;
		}
		else
		{
			//Кисть еще есть
		}
	}
	void AddStew()
	{
		if (Cash >= 80) {
			Stew++;
			Cash -= 80;
		}
	}
	void AddDoshirak() {
		if (Cash >= 35) 
		{
			Doshirak++;
			Cash -= 35;
		}
	}

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

	//Ломание инструментов
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

