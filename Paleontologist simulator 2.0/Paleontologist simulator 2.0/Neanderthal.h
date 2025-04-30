#pragma once
#include "Fossils.h"
class Neanderthal : public Fossils
{
public:
    Neanderthal(int x, int y) : Fossils(x, y) {} 

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
        LandSprite.setTextureRect(sf::IntRect(540, 608, 270, 203));
    }
    void DrawLandLevel1() override
    {
        LandSprite.setTextureRect(sf::IntRect(0, 608, 270, 203));
    }
    void DrawLandLevel0() override
    {
        LandSprite.setTextureRect(sf::IntRect(810, 0, 270, 203));
        NeanderthalBones++;
    }
};

