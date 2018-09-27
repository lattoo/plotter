#pragma once

#include "main_ticks/main_ticks.h"
#include "sub_ticks/sub_ticks.h"

class Ticks
{
public:
    Ticks();
    ~Ticks() = default;

public:
    MainTicks& main_ticks() { return _main_ticks_y; }
    SubTicks&  sub_ticks() { return _sub_ticks_x; }

private:
    MainTicks _main_ticks_y;
    SubTicks  _sub_ticks_x;
};
