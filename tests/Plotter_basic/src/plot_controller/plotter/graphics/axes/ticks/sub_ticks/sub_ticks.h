#pragma once

#include "sub_ticks_x/sub_ticks_x.h"
#include "sub_ticks_y/sub_ticks_y.h"

class SubTicks
{
public:
    SubTicks();
    ~SubTicks() = default;

    SubTicksX& sub_ticks_x() { return _sub_ticks_x; }
    SubTicksY& sub_ticks_y() { return _sub_ticks_y; }

private:
    SubTicksX _sub_ticks_x;
    SubTicksY _sub_ticks_y;
};
