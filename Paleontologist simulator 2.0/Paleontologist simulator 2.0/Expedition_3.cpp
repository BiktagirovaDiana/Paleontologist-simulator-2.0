#include "Expedition_3.h"

Expedition_3::Expedition_3() : Mammoth(90, 550), Neanderthal(1410, 820), Fossil(470, 840)
{ 
	BackgroundTexture.loadFromFile("Background_ExpeditionTundra.png");
	BackgroundSprite.setTexture(BackgroundTexture);

}
void Expedition_3::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	Player.PlayerMovement(event);

	Mammoth.ToolsControl(event);
	Neanderthal.ToolsControl(event);
	Fossil.ToolsControl(event);
}
void Expedition_3::update(float time)
{
	Player.Update(time);

	Mammoth.Update(time);
	Mammoth.UpdateTrigger(Player.getSprite());

	Neanderthal.Update(time);
	Neanderthal.UpdateTrigger(Player.getSprite());

	Fossil.Update(time);
	Fossil.UpdateTrigger(Player.getSprite());

	if (TransitionBase.contains(Player.getPosition()))
	{
		CheckBase = true;
	}
}
void Expedition_3::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView)
{
	window.setView(GameView);
	window.draw(BackgroundSprite);

	Mammoth.draw(window);
	Neanderthal.draw(window);
	Fossil.draw(window);


	Player.draw(window);

	window.setView(UIView);
	Text.draw(window);

}