#include "Expedition_1.h"

Expedition_1::Expedition_1(): Neanderthal(250, 540), Tyrannosaurus(1450, 280), Fossil(1410, 680)
{
	BackgroundTexture.loadFromFile("Background_ExpeditionPlain.png");
	BackgroundSprite.setTexture(BackgroundTexture);

	TransitionBase = sf::FloatRect(0, 0, 2000, 20);
	
}
void Expedition_1::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	Player.PlayerMovement(event);

	Neanderthal.ToolsControl(event);
	Tyrannosaurus.ToolsControl(event);
	Fossil.ToolsControl(event);
}
void Expedition_1::update(float time) 
{
	Player.Update(time);

	Neanderthal.Update(time);
	Neanderthal.UpdateTrigger(Player.getSprite());

	Tyrannosaurus.Update(time);
	Tyrannosaurus.UpdateTrigger(Player.getSprite());

	Fossil.Update(time);
	Fossil.UpdateTrigger(Player.getSprite());

	if (TransitionBase.contains(Player.getPosition()))
	{
		CheckBase = true;
	}
}
void Expedition_1::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView)
{
	window.setView(GameView);
	window.draw(BackgroundSprite);

	Neanderthal.draw(window);
	Tyrannosaurus.draw(window);
	Fossil.draw(window);

	Player.draw(window);

	window.setView(UIView);
	Text.draw(window);

}