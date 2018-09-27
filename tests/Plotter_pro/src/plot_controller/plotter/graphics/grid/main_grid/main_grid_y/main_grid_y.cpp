#include "main_grid_y.h"

MainGridY::MainGridY()
{
    pen().setColor(Qt::black);
    pen().setStyle(Qt::DotLine);
}

void MainGridY::replot(QPainter* painter, const QVector<QLineF>& ticks)
{
    if(!is_shown())
        return;

    painter->setPen(pen());

    for (uint8_t i = 0; i < ticks.size(); i++)
        painter->drawLine(ticks[i]);
}
