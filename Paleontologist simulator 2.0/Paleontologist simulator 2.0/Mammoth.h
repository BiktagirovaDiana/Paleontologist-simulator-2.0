#pragma once
#include "Fossils.h"
class Mammoth : public Fossils
{
public:
    Mammoth(int x, int y) : Fossils(x, y) {}

    void DrawLandLevel4() override;
    void DrawLandLevel3() override;
    void DrawLandLevel2() override;
    void DrawLandLevel1() override;
    void DrawLandLevel0(bool Right);
};

