#include "Inventory.h"

int Inventory::Cash = 500;
int Inventory::LevelSatiety = 10;

int Inventory::TyrannosaurusBones = 0;
int Inventory::PterodactylBones = 0;
int Inventory::MammothBones = 0;
int Inventory::NeanderthalBones = 0;

int Inventory::EndurancePickaxe = 100;
int Inventory::EnduranceShovel = 100;
int Inventory::EnduranceBrush = 100;

int Inventory::Stew = 0;
int Inventory::Doshirak = 0;


void Inventory::EatingDoshik()
{
	if (Doshirak > 0) {
		if (LevelSatiety < 10) {
			Doshirak--;
			LevelSatiety++;
		}
		else Doshirak--;
	}
}

void Inventory::EatingStew()
{
	if (Stew > 0) {
		if (LevelSatiety < 6) {
			Stew--;
			LevelSatiety += 5;
		}
		else Stew--;

	}
}

void Inventory::SellTyrannosaurus()
{
	TyrannosaurusBones--;
	Cash += 300;
}
void Inventory::SellPterodactyl()
{
	PterodactylBones--;
	Cash += 300;
}
void Inventory::SellMammoth()
{
	MammothBones--;
	Cash += 200;
}
void Inventory::SellNeanderthal()
{
	NeanderthalBones--;
	Cash += 250;
}
void Inventory::AddBonesTyrannosaurus()
{
	TyrannosaurusBones++;
}
void Inventory::AddBonesPterodacty()
{
	PterodactylBones++;
}
void Inventory::AddBonesMammoth()
{
	MammothBones++;
}
void Inventory::AddBonesNeanderthal()
{
	NeanderthalBones++;
}

int Inventory::getTyrannosaurusBones()
{
	return TyrannosaurusBones;
}
int Inventory::getPterodactylBones()
{
	return PterodactylBones;
}
int Inventory::getMammothBones()
{
	return MammothBones;
}
int Inventory::getNeanderthalBones()
{
	return NeanderthalBones;
}

int Inventory::getEndurancePickaxe() {
	return EndurancePickaxe;
}
int Inventory::getEnduranceShovel() {
	return EnduranceShovel;
}
int Inventory::getEnduranceBrush() {
	return EnduranceBrush;
}

int Inventory::getLevelSatiety()
{
	return LevelSatiety;
}
int Inventory::getCash() {
	return Cash;
}
void Inventory::BuyExpedition()
{
	Cash -= 150;
}

//Добавление инструментов
void Inventory::AddPickaxe()
{
	if (Cash >= 250) {
		EndurancePickaxe += 100;
		Cash -= 250;
	}
	else {
		//Кирка еще есть
	}
}
void Inventory::AddShovel()
{
	if (Cash >= 150) {
		EnduranceShovel = 100;
		Cash -= 150;
	}
}
void Inventory::AddBrush()
{
	if (Cash >= 100) {
		EnduranceBrush = 100;
		Cash -= 100;
	}
}
void Inventory::AddStew()
{
	if (Cash >= 80) {
		Stew++;
		Cash -= 80;
	}
}
void Inventory::AddDoshirak() {
	if (Cash >= 35) {
		Doshirak++;
		Cash -= 35;
	}
}

void Inventory::DamagePickaxe(int n)
{
	//15
	EndurancePickaxe -= n; if (EndurancePickaxe <= 0)
	{
		BrokePickaxe();
	}
}
void Inventory::DamageShovel(int n) {
	//20
	EnduranceShovel -= n;
	if (EnduranceShovel <= 0) {
		BrokeShovel();
	}
}
void Inventory::DamageBrush(int n) {
	//35
	EnduranceBrush -= n;
	if (EnduranceBrush <= 0) {
		BrokeBrush();
	}
}

//Ломание инструментов
void Inventory::BrokePickaxe()
{
	EndurancePickaxe = 0;
}
void Inventory::BrokeShovel()
{
	EnduranceShovel = 0;
}
void Inventory::BrokeBrush()
{
	EnduranceBrush = 0;
}

void Inventory::DeadPlayer()
{
	if (LevelSatiety < 1) {
		checkLose_ = true;
	}
	if (Cash < 1) {
		checkLose_ = true;
	}
}
