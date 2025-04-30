#include "Expedition_1.h"



Expedition_1::Expedition_1(): Pterodactyl(95, 550), Tyrannosaurus(1610, 270), Mammoth(1405, 820), Neanderthal(470, 855)
{
	BackgroundTexture.loadFromFile("Background_Expedition_1.png");
	BackgroundSprite.setTexture(BackgroundTexture);

	
}
void Expedition_1::handleEvent(sf::Event& event) 
{
	Player.PlayerMovement(event);

	Pterodactyl.ToolsControl(event);
	Tyrannosaurus.ToolsControl(event);
	Mammoth.ToolsControl(event);
	Neanderthal.ToolsControl(event);
}
void Expedition_1::update(float time) 
{
	Player.Update(time);

	Pterodactyl.Update(time);
	Pterodactyl.UpdateTrigger(Player.getSprite());

	Tyrannosaurus.Update(time);
	Tyrannosaurus.UpdateTrigger(Player.getSprite());

	Mammoth.Update(time);
	Mammoth.UpdateTrigger(Player.getSprite());

	Neanderthal.Update(time);
	Neanderthal.UpdateTrigger(Player.getSprite());
}
void Expedition_1::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView)
{
	window.setView(GameView);
	//window.setView(window.getDefaultView());
	window.draw(BackgroundSprite);

	Pterodactyl.draw(window);
	Tyrannosaurus.draw(window);
	Mammoth.draw(window);
	Neanderthal.draw(window);

	Player.draw(window);

	window.setView(UIView);
	Text.draw(window);
	Text.draw(window);

}