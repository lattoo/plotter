#pragma once

#include "ticks_item_x.h"
#include "ticks_item_y.h"

class Ticks
{
public:
    Ticks() = default;
    ~Ticks() = default;

public:
    TicksItemX& x() { return _ticks_x; }
    TicksItemY& y() { return _ticks_y; }
    TicksItemX& sub_x() { return _sub_ticks_x; }
    TicksItemY& sub_y() { return _sub_ticks_y; }

private:
    TicksItemX _ticks_x;
    TicksItemY _ticks_y;
    TicksItemX _sub_ticks_x;
    TicksItemY _sub_ticks_y;
};
