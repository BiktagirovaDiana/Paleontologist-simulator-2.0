#include "Pterodactyl.h"

void Pterodactyl::DrawLandLevel4() override
{
    LandSprite.setTextureRect(sf::IntRect(540, 0, 270, 203));
}
void Pterodactyl::DrawLandLevel3() override
{
    LandSprite.setTextureRect(sf::IntRect(270, 0, 270, 203));
}

void Pterodactyl::DrawLandLevel2() override
{
    LandSprite.setTextureRect(sf::IntRect(540, 406, 270, 203));
}

void Pterodactyl::DrawLandLevel1() override
{
    LandSprite.setTextureRect(sf::IntRect(0, 406, 270, 203));

}
void Pterodactyl::DrawLandLevel0(bool Right) override
{
    LandSprite.setTextureRect(sf::IntRect(810, 0, 270, 203));
    if (Right == true)
    {
        PterodactylBones++;
    }
}