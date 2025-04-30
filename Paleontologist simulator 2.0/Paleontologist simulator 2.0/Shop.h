#pragma once
#include "Inventory.h"
class Shop : public Inventory
{
	//Что добавить
	//Текст недостаточно денег
	void BuyPickaxe() 
	{
		if (Cash >= 300) AddPickaxe();
		else 
		{
			//Недостаточно денег
		}
	}
	void BuyShovel()
	{
		if (Cash >= 200) AddShovel();
		else
		{
			//Недостаточно денег
		}
		
	}
	void BuyBrush()
	{
		if (Cash >= 100) AddBrush();
		else
		{
			//Недостаточно денег
		}

	}
};

