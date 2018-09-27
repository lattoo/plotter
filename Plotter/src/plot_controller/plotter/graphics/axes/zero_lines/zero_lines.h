#pragma once

#include "zero_line.h"

class ZeroLines
{
public:
    ZeroLines();
    ~ZeroLines() = default;

public:
    void replot(QPainter* painter, const QLineF& x, const QLineF& y);

    ZeroLine& x() { return _zero_line_x; }
    ZeroLine& y() { return _zero_line_y; }

private:
    ZeroLine _zero_line_x;
    ZeroLine _zero_line_y;
};
