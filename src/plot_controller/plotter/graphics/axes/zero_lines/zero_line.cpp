#include "zero_line.h"

ZeroLine::ZeroLine()
{
    set_enabled(true);
}

void ZeroLine::replot(QPainter* painter, const QLineF& line)
{
    if(!is_shown())
        return;

    if(line.isNull())
        return;

    painter->setPen(pen());
    painter->drawLine(line);
}
