#pragma once

#include "zero_line_x/zero_line_x.h"
#include "zero_line_y/zero_line_y.h"

class ZeroLines
{
public:
    ZeroLines();
    ~ZeroLines() = default;

public:
    void replot(QPainter* painter, const QLineF& line_x, const QLineF& line_y);

    ZeroLineX& line_x() { return _zero_line_x; }
    ZeroLineY& line_y() { return _zero_line_y; }

private:
    ZeroLineX _zero_line_x;
    ZeroLineY _zero_line_y;
};
