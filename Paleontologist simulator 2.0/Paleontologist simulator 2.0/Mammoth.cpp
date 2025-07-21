#include "Mammoth.h"


void Mammoth::DrawLandLevel4() 
{
    LandSprite.setTextureRect(sf::IntRect(540, 0, 270, 203));
}

void Mammoth::DrawLandLevel3()
{
    LandSprite.setTextureRect(sf::IntRect(270, 0, 270, 203));
}

void Mammoth::DrawLandLevel2()
{
    LandSprite.setTextureRect(sf::IntRect(540, 812, 270, 203));
}

void Mammoth::DrawLandLevel1()
{
    LandSprite.setTextureRect(sf::IntRect(0, 812, 270, 203));
}
void Mammoth:: DrawLandLevel0(bool Right)
{
    LandSprite.setTextureRect(sf::IntRect(810, 0, 270, 203));
    if (Right == true)
    {
        MammothBones++;
    }
}