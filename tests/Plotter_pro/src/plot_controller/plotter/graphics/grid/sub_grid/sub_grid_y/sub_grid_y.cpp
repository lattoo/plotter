#include "sub_grid_y.h"

SubGridY::SubGridY()
{
    pen().setColor(Qt::lightGray);
    pen().setStyle(Qt::DotLine);
}

void SubGridY::replot(QPainter* painter, const QVector<QLineF>& ticks)
{
    if(!is_shown())
        return;

    painter->setPen(pen());

    for (uint8_t i = 0; i < ticks.size(); i++)
        painter->drawLine(ticks[i]);
}

