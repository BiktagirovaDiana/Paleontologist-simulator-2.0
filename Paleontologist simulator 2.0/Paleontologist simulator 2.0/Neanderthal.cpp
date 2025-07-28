#include "Neanderthal.h"

void Neanderthal::DrawLandLevel4()
{
    LandSprite.setTextureRect(sf::IntRect(540, 0, 270, 203));
}

void Neanderthal::DrawLandLevel3()
{
    LandSprite.setTextureRect(sf::IntRect(270, 0, 270, 203));
}

void Neanderthal::DrawLandLevel2() 
{
    LandSprite.setTextureRect(sf::IntRect(540, 608, 270, 203));
}
void Neanderthal::DrawLandLevel1()
{
    LandSprite.setTextureRect(sf::IntRect(0, 608, 270, 203));
}
void Neanderthal::DrawLandLevel0(bool Right)
{
    LandSprite.setTextureRect(sf::IntRect(810, 0, 270, 203));
    if (Right == true)
    {
        NeanderthalBones++;
    }
}