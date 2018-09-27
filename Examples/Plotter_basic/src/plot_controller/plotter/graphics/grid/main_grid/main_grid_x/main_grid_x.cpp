#include "main_grid_x.h"

MainGridX::MainGridX()
{
    pen().setColor(Qt::black);
    pen().setStyle(Qt::DotLine);
    pen().setWidth(1);
}

void MainGridX::replot(QPainter* painter, const QVector<QLineF>& ticks)
{
    if(!is_shown())
        return;

    painter->setPen(pen());

    for (uint8_t i = 0; i < ticks.size(); i++)
        painter->drawLine(ticks[i]);
}
