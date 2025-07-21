#include "EmptyFossil.h"

void EmptyFossil::DrawLandLevel4() 
{
    LandSprite.setTextureRect(sf::IntRect(540, 0, 270, 203));
}


void EmptyFossil::DrawLandLevel3()
{
    LandSprite.setTextureRect(sf::IntRect(270, 0, 270, 203));
}

void EmptyFossil::DrawLandLevel2()
{
    LandSprite.setTextureRect(sf::IntRect(810, 0, 270, 203));
}

void EmptyFossil::DrawLandLevel1()
{
    LandSprite.setTextureRect(sf::IntRect(810, 0, 270, 203));
}
void EmptyFossil::DrawLandLevel0(bool Right)
{

    LandSprite.setTextureRect(sf::IntRect(810, 0, 270, 203));
}