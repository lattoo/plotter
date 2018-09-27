#include "ticks_item_y.h"

TicksItemY::TicksItemY()
{

}

void TicksItemY::replot(QPainter* painter, const QVector<QPointF>& points)
{
    if(!is_shown())
        return;

    painter->setPen(pen());

    switch (tick_type())
    {
    case TickType::INTERNAL_SINGLE_SIDED:
        replot_internal_single_sided(painter, points);
        break;
    case TickType::SINGLE_SIDED:
        replot_single_sided(painter, points);
        break;
    case TickType::DOUBLE_SIDED:
        replot_double_sided(painter, points);
        break;
    default:
        break;
    }
}

void TicksItemY::replot_internal_single_sided(QPainter* painter, const QVector<QPointF>& points)
{
    for (uint8_t i = 0; i < points.size(); i++)
        painter->drawLine(QLineF(QPointF(points[i].x() + length(), points[i].y())
                                 , QPointF(points[i].x(), points[i].y())));
}

void TicksItemY::replot_single_sided(QPainter*painter, const QVector<QPointF>& points)
{
    for (uint8_t i = 0; i < points.size(); i++)
        painter->drawLine(QLineF(QPointF(points[i].x() - length(), points[i].y())
                                 , QPointF(points[i].x(), points[i].y())));
}

void TicksItemY::replot_double_sided(QPainter* painter, const QVector<QPointF>& points)
{
    for (uint8_t i = 0; i < points.size(); i++)
        painter->drawLine(QLineF(QPointF(points[i].x() - length(), points[i].y())
                                 , QPointF(points[i].x() + length(), points[i].y())));
}
