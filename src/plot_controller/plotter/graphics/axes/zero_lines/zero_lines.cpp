#include "zero_lines.h"

ZeroLines::ZeroLines()
{

}

void ZeroLines::replot(QPainter *painter, const QLineF &line_x, const QLineF &line_y)
{
    _zero_line_x.replot(painter, line_x);
    _zero_line_y.replot(painter, line_y);
}

