#include "Expedition_2.h"

Expedition_2::Expedition_2() : Pterodactyl(320, 630), Tyrannosaurus(1450, 280), Fossil(570, 120)
{
	BackgroundTexture.loadFromFile("Background_ExpeditionSteppe.png");
	BackgroundSprite.setTexture(BackgroundTexture);

	TransitionBase = sf::FloatRect(0, 1000, 2000, 100);


}
void Expedition_2::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	Player.PlayerMovement(event);

	Pterodactyl.ToolsControl(event);
	Tyrannosaurus.ToolsControl(event);
	Fossil.ToolsControl(event);
}
void Expedition_2::update(float time)
{
	Player.Update(time);

	Pterodactyl.Update(time);
	Pterodactyl.UpdateTrigger(Player.getSprite());

	Tyrannosaurus.Update(time);
	Tyrannosaurus.UpdateTrigger(Player.getSprite());

	Fossil.Update(time);
	Fossil.UpdateTrigger(Player.getSprite());

	if (TransitionBase.contains(Player.getPosition()))
	{
		checkBase_ = true;
	}
}
void Expedition_2::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView)
{
	window.setView(GameView);
	window.draw(BackgroundSprite);

	Pterodactyl.draw(window);
	Tyrannosaurus.draw(window);
	Fossil.draw(window);

	Player.draw(window);

	window.setView(UIView);
	Text.draw(window);

}