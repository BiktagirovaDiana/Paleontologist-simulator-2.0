#include "Game.h"
#include "Inventory.h"
#include <fstream>
#include <iostream>


void Game::NewGame()
{
	std::ofstream Data("Game.txt");
	if (Data.is_open())
	{
		Inventory::Cash = 500;
		Inventory::LevelSatiety = 10;

		Inventory::TyrannosaurusBones = 0;
		Inventory::PterodactylBones = 0;
		Inventory::MammothBones = 0;
		Inventory::NeanderthalBones = 0;

		Inventory::EndurancePickaxe = 0;
		Inventory::EnduranceShovel = 0;
		Inventory::EnduranceBrush = 0;

		Inventory::Stew = 0 ;
		Inventory::Doshirak = 0;
		Data.close();
	}

}
void Game::SaveGame()
{
	std::ofstream Data("Game.txt");
	if (Data.is_open())
	{
		Data << Inventory::Cash << "\n";
		Data << Inventory::LevelSatiety << "\n";

		Data << Inventory::TyrannosaurusBones << "\n";
		Data << Inventory::PterodactylBones << "\n";
		Data << Inventory::MammothBones << "\n";
		Data << Inventory::NeanderthalBones << "\n";

		Data << Inventory::EndurancePickaxe << "\n";
		Data << Inventory::EnduranceShovel << "\n";
		Data << Inventory::EnduranceBrush << "\n";

		Data << Inventory::Stew << "\n";
		Data << Inventory::Doshirak << "\n";
		Data.close();
	}


}
void Game::LoadGame()
{
	std::ifstream Data("Game.txt");
	if (Data.is_open())
	{
		Data >> Inventory::Cash;
		Data >> Inventory::LevelSatiety;

		Data >> Inventory::TyrannosaurusBones;
		Data >> Inventory::PterodactylBones;
		Data >> Inventory::MammothBones;
		Data >> Inventory::NeanderthalBones;

		Data >> Inventory::EndurancePickaxe;
		Data >> Inventory::EnduranceShovel;
		Data >> Inventory::EnduranceBrush;

		Data >> Inventory::Stew;
		Data >> Inventory::Doshirak;
		Data.close();
	}
}