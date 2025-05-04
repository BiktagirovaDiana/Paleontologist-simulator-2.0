#include "Game.h"
#include "Inventory.h"
#include <fstream>
#include <iostream>


void Game::NewGame()
{
}
void Game::SaveGame()
{
	std::ofstream Data("Game.txt");
	if (Data.is_open())
	{
		Data << Cash << "\n";
		Data << LevelSatiety << "\n";

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