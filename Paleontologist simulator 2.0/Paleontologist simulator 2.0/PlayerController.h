#pragma once
#include <SFML/Graphics.hpp>

class PlayerController
{
public:
	PlayerController();

	void PlayerMovement(sf::Event& ev);
	
	void Update(float time);

	void draw(sf::RenderWindow& window);
	

	sf::Vector2f getPosition() const; //Для передачи спрайта в Fossils

	const sf::Sprite& getSprite() const 
	{
		return PlayerSprite; 
	} //Для передачи спрайта в Fossils


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

