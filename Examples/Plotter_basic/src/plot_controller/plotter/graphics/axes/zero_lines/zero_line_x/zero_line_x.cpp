#include "zero_line_x.h"

ZeroLineX::ZeroLineX()
{

}

void ZeroLineX::replot(QPainter* painter, const QLineF& line)
{
    if(line.isNull())
        return;

    painter->setPen(pen());
    painter->drawLine(line);
}
