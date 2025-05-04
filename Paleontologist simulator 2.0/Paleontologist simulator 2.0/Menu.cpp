#include "Menu.h"
Menu::Menu() {
	BackgroundTexture.loadFromFile("Background_Menu.png");
	BackgroundSprite.setTexture(BackgroundTexture);

}

void Menu::handleEvent(sf::Event& event, sf::RenderWindow& window) {
}
void Menu::update(float time) {

}
void Menu::draw(sf::RenderWindow& window, sf::View GameView, sf::View UIView) 
{
	window.draw(BackgroundSprite);
}