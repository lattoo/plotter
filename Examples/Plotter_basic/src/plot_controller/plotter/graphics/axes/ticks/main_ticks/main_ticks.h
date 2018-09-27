#pragma once

#include "main_ticks_x/main_ticks_x.h"
#include "main_ticks_y/main_ticks_y.h"

class MainTicks
{
public:
    MainTicks();
    ~MainTicks() = default;


public:
    MainTicksX& ticks_x() { return _ticks_x; }
    MainTicksY& ticks_y() { return _ticks_y; }

private:
    MainTicksX _ticks_x;
    MainTicksY _ticks_y;

    QPen _pen;
};
