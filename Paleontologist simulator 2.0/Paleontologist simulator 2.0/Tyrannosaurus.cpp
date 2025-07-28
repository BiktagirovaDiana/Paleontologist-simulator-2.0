#include "Tyrannosaurus.h"

void Tyrannosaurus::DrawLandLevel4()
{
    LandSprite.setTextureRect(sf::IntRect(540, 0, 270, 203));
}


void Tyrannosaurus::DrawLandLevel3()
{
    LandSprite.setTextureRect(sf::IntRect(270, 0, 270, 203));
}

void Tyrannosaurus::DrawLandLevel2()
{
    LandSprite.setTextureRect(sf::IntRect(540, 206, 270, 203));
}

void Tyrannosaurus::DrawLandLevel1()
{
    LandSprite.setTextureRect(sf::IntRect(0, 206, 270, 203));
}
void Tyrannosaurus::DrawLandLevel0(bool Right)
{
    LandSprite.setTextureRect(sf::IntRect(810, 0, 270, 203));
    if (Right == true)
    {
        TyrannosaurusBones++;
    }
}