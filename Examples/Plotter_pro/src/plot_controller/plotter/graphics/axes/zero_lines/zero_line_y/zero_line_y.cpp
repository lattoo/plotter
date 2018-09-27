#include "zero_line_y.h"

ZeroLineY::ZeroLineY()
{

}

void ZeroLineY::replot(QPainter* painter, const QLineF& line)
{
    if(line.isNull())
        return;

    painter->setPen(pen());
    painter->drawLine(line);
}
