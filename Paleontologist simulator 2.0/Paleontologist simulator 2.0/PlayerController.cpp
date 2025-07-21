#include "PlayerController.h"
#include "Fossils.h"



PlayerController::PlayerController() :currentDir_(Down), speedPlayer_(150), frame_(0), anim_(false)
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

float speedAnim = 35;

void PlayerController::PlayerMovement(sf::Event& ev)
{
    if (ev.type == sf::Event::KeyPressed) {
        
        if (ev.key.code == sf::Keyboard::W)
        {
            currentDir_ = Up;
            anim_ = true;
        }
        if (ev.key.code == sf::Keyboard::S) 
        {
            currentDir_ = Down;
            anim_ = true;
        }
        if (ev.key.code == sf::Keyboard::A)
        {
            currentDir_ = Left;
            anim_ = true;
        }
        if (ev.key.code == sf::Keyboard::D) 
        {
            currentDir_ = Right;
            anim_ = true;
        }
        
    }
    else if (ev.type == sf::Event::KeyReleased) 
    {
        anim_ = false;
        frame_ = 0;
    }
}
void PlayerController::Update(float time)
{
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        PlayerSprite.move(0, -speedPlayer_ * time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        PlayerSprite.move(0, speedPlayer_ * time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        PlayerSprite.move(-speedPlayer_ * time, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        PlayerSprite.move(speedPlayer_ * time, 0);
    }

    if (anim_) //Анимация передвижения
    {
        frame_ += speedAnim * time;
        if (frame_ > 8)
        {
            frame_ -= 8;
        }

        switch (currentDir_) 
        {
        case Up:
            PlayerSprite.setTextureRect(sf::IntRect(frame_ * 256, 256 * 3, 256, 256));
            break;
        case Down:
            PlayerSprite.setTextureRect(sf::IntRect(frame_ * 256, 0, 256, 256));
            break;
        case Left:
            PlayerSprite.setTextureRect(sf::IntRect(frame_ * 256, 256 * 1, 256, 256));
            break;
        case Right:
            PlayerSprite.setTextureRect(sf::IntRect(frame_ * 256, 256 * 2, 256, 256));
            break;
        }
    }
    else //Статичные кадры
    {
        
        switch (currentDir_) 
        {
        case Up:
            PlayerSprite.setTextureRect(sf::IntRect(0, 256 * 3, 256, 256));
            if (isDead_) PlayerSprite.setColor(sf::Color(255, 0, 0, 255));
            break;
        case Down:
            PlayerSprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
            if (isDead_) PlayerSprite.setColor(sf::Color(255, 0, 0, 255));
            break;
        case Left:
            PlayerSprite.setTextureRect(sf::IntRect(0, 256 * 1, 256, 256));
            if (isDead_) PlayerSprite.setColor(sf::Color(255, 0, 0, 255));
            break;
        case Right:
            PlayerSprite.setTextureRect(sf::IntRect(0, 256 * 2, 256, 256));
            if (isDead_) PlayerSprite.setColor(sf::Color(255, 0, 0, 255));
            break;
        }
    }

    

}

void PlayerController::draw(sf::RenderWindow& window)
{
	window.draw(PlayerSprite);
};
