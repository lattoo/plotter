#include "sub_grid_x.h"

SubGridX::SubGridX()
{
    pen().setColor(Qt::lightGray);
    pen().setStyle(Qt::DotLine);
    pen().setWidth(1);
}

void SubGridX::replot(QPainter* painter, const QVector<QLineF>& ticks)
{
    if(!is_shown())
        return;

    painter->setPen(pen());

    for (uint8_t i = 0; i < ticks.size(); i++)
        painter->drawLine(ticks[i]);
}
