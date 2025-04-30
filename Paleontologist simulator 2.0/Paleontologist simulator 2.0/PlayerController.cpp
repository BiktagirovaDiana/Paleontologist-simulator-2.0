#include "PlayerController.h"
#include "Fossils.h"

PlayerController::PlayerController() :currentDir(Down), speedPlayer(150), frame(0), Anim(false)
{
	TexturePlayer.loadFromFile("Player1.png");
	
	PlayerSprite.setTexture(TexturePlayer);
	PlayerSprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
	PlayerSprite.setScale(0.75, 0.75);
	PlayerSprite.setPosition(1280 / 2, 720 / 2);
    

}

sf::Vector2f PlayerController::getPosition() const 
{
    return PlayerSprite.getPosition();
}

sf::FloatRect PlayerController::getGlobalBounds() const 
{
    return PlayerSprite.getGlobalBounds();
}
float speedAnim = 35;

void PlayerController::PlayerMovement(sf::Event& ev, float time)
{
    if (ev.type == sf::Event::KeyPressed) {
        
        if (ev.key.code == sf::Keyboard::W)
        {
            currentDir = Up;
            Anim = true;
        }
        if (ev.key.code == sf::Keyboard::S) 
        {
            currentDir = Down;
            Anim = true;
        }
        if (ev.key.code == sf::Keyboard::A)
        {
            currentDir = Left;
            Anim = true;
        }
        if (ev.key.code == sf::Keyboard::D) 
        {
            currentDir = Right;
            Anim = true;
        }
    }
    else if (ev.type == sf::Event::KeyReleased) {
        Anim = false;
        frame = 0;
    }
}

void PlayerController::Update(float time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        PlayerSprite.move(0, -speedPlayer * time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        PlayerSprite.move(0, speedPlayer * time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        PlayerSprite.move(-speedPlayer * time, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        PlayerSprite.move(speedPlayer * time, 0);
    }

    if (Anim) //Анимация передвижения
    {
        frame += speedAnim * time;
        if (frame > 8)
        {
            frame -= 8;
        }

        switch (currentDir) 
        {
        case Up:
            PlayerSprite.setTextureRect(sf::IntRect(frame * 256, 256 * 3, 256, 256));
            break;
        case Down:
            PlayerSprite.setTextureRect(sf::IntRect(frame * 256, 0, 256, 256));
            break;
        case Left:
            PlayerSprite.setTextureRect(sf::IntRect(frame * 256, 256 * 1, 256, 256));
            break;
        case Right:
            PlayerSprite.setTextureRect(sf::IntRect(frame * 256, 256 * 2, 256, 256));
            break;
        }
    }
    else //Статичные кадры
    {
        
        switch (currentDir) 
        {
        case Up:
            PlayerSprite.setTextureRect(sf::IntRect(0, 256 * 3, 256, 256));
            break;
        case Down:
            PlayerSprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
            break;
        case Left:
            PlayerSprite.setTextureRect(sf::IntRect(0, 256 * 1, 256, 256));
            break;
        case Right:
            PlayerSprite.setTextureRect(sf::IntRect(0, 256 * 2, 256, 256));
            break;
        }
    }
}
void PlayerController::draw(sf::RenderWindow& window)
{
	window.draw(PlayerSprite);
};
