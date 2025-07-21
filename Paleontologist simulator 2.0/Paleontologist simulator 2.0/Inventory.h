#pragma once
#include "PlayerController.h"
#include "Scene.h"

class Inventory: public PlayerController
{
public:
	enum Hand { None, Pickaxe, Shovel, Brush };  //какой предмет в руке у игрока
	Hand PlayerHand = None;

	void EatingDoshik();
	void EatingStew();
	void SellTyrannosaurus();
	void SellPterodactyl();
	void SellMammoth();
	void SellNeanderthal();
	void AddBonesTyrannosaurus();
	void AddBonesPterodacty();
	void AddBonesMammoth();
	void AddBonesNeanderthal();

	static int getTyrannosaurusBones();
	static int getPterodactylBones();
	static int getMammothBones();
	static int getNeanderthalBones();
	static int getEndurancePickaxe();
	static int getEnduranceShovel();
	static int getEnduranceBrush();
	static int getLevelSatiety();
	static int getCash();

	void BuyExpedition();
	void AddPickaxe();
	void AddShovel();
	void AddBrush();
	void AddStew();
	void AddDoshirak();

	void DamagePickaxe(int n);
	void DamageShovel(int n);
	void DamageBrush(int n);
	void BrokePickaxe();
	void BrokeShovel();
	void BrokeBrush();
	void DeadPlayer();

protected:

	int intFossils_ = 0;
	
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

