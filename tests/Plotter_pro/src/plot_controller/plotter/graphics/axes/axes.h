#pragma once

#include "line_terminators/line_terminators.h"
#include "ticks/ticks.h"
#include "zero_lines/zero_lines.h"

class Axes
{
public:
    Axes();
    ~Axes() = default;

public:
    LineTerminators& terminators() { return _terminators; }
    Ticks&           ticks() { return _ticks; }
    ZeroLines&       zero_lines()   { return _zero_lines; }

private:
    LineTerminators _terminators;
    Ticks           _ticks;
    ZeroLines       _zero_lines;
};
