#pragma once
#include "Fossils.h"
class Pterodactyl : public Fossils
{
public:
    Pterodactyl(int x, int y) : Fossils(x, y) {}
    
    void DrawLandLevel4();
    void DrawLandLevel3();
    void DrawLandLevel2();
    void DrawLandLevel1();
    void DrawLandLevel0(bool Right);
    
};

