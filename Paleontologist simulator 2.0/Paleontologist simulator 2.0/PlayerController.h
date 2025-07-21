#pragma once
#include <SFML/Graphics.hpp>

class PlayerController
{
public:
	PlayerController();

	void PlayerMovement(sf::Event& ev);
	
	void Update(float time);

	void draw(sf::RenderWindow& window);
	

	sf::Vector2f getPosition() const; //��� �������� ������� � Fossils

	const sf::Sprite& getSprite() const 
	{
		return PlayerSprite; 
	} //��� �������� ������� � Fossils

	
private:
	
	sf::Texture TexturePlayer;
	sf::Sprite PlayerSprite;

	enum Direction { Up, Down, Left, Right };
	float speedPlayer_;
	Direction currentDir_;
	bool anim_;
	int frame_ = 0;
	bool isDead_ = false;
};

