#pragma once
#include "Inventory.h"
#include "Museum.h"
#include <fstream>
#include <iostream>


class Game : public Inventory
{
public:
	void NewGame();
	void SaveGame();
	void LoadGame();

};

