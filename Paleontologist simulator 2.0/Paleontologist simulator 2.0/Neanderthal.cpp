#include "Neanderthal.h"

void Neanderthal::DrawLandLevel4() override
{
    LandSprite.setTextureRect(sf::IntRect(540, 0, 270, 203));
}

void Neanderthal::DrawLandLevel3() override
{
    LandSprite.setTextureRect(sf::IntRect(270, 0, 270, 203));
}

void Neanderthal::DrawLandLevel2() override
{
    LandSprite.setTextureRect(sf::IntRect(540, 608, 270, 203));
}
void Neanderthal::DrawLandLevel1() override
{
    LandSprite.setTextureRect(sf::IntRect(0, 608, 270, 203));
}
void Neanderthal::DrawLandLevel0(bool Right) override
{
    LandSprite.setTextureRect(sf::IntRect(810, 0, 270, 203));
    if (Right == true)
    {
        NeanderthalBones++;
    }
}