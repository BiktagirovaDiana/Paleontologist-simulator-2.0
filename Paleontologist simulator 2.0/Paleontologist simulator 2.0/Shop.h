#pragma once
#include "Inventory.h"
class Shop : public Inventory
{
	//��� ��������
	//����� ������������ �����
	void BuyPickaxe() 
	{
		if (Cash >= 300) AddPickaxe();
		else 
		{
			//������������ �����
		}
	}
	void BuyShovel()
	{
		if (Cash >= 200) AddShovel();
		else
		{
			//������������ �����
		}
		
	}
	void BuyBrush()
	{
		if (Cash >= 100) AddBrush();
		else
		{
			//������������ �����
		}

	}
};

