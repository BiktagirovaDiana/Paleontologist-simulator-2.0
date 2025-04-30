#pragma once
#include "Fossils.h"
class Mammoth : public Fossils
{
public:
    Mammoth(int x, int y) : Fossils(x, y) {} 

    void DrawLandLevel4() override
    {
        LandSprite.setTextureRect(sf::IntRect(540, 0, 270, 203));
    }

    void DrawLandLevel3() override
    {
        LandSprite.setTextureRect(sf::IntRect(270, 0, 270, 203));
    }

    void DrawLandLevel2() override
    {
        LandSprite.setTextureRect(sf::IntRect(540, 812, 270, 203));
    }

    void DrawLandLevel1() override
    {
        LandSprite.setTextureRect(sf::IntRect(0, 812, 270, 203));
    }
    void DrawLandLevel0() override
    {
        LandSprite.setTextureRect(sf::IntRect(810, 0, 270, 203));
        MammothBones++;
    }
};

