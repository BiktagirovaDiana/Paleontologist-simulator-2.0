#pragma once
#include <SFML/Graphics.hpp>

class PlayerController
{
public:
	PlayerController();

	void PlayerMovement(sf::Event& ev, float time);
	
	void Update(float time);

	void draw(sf::RenderWindow& window);
	

	sf::Vector2f getPosition() const; //��� �������� ������� � Fossils
	sf::FloatRect getGlobalBounds() const; //��� ������

	const sf::Sprite& getSprite() const 
	{
		return PlayerSprite; 
	} //��� �������� ������� � Fossils


protected:
	
private:
	
	sf::Texture TexturePlayer;
	sf::Sprite PlayerSprite;

	enum Direction { Up, Down, Left, Right };
	float speedPlayer;
	Direction currentDir;
	bool Anim;
	int frame = 0;
};

