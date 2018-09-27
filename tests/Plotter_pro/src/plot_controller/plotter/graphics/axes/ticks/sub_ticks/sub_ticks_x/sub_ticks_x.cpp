#include "sub_ticks_x.h"

SubTicksX::SubTicksX()
//    : _size(DEFAULT_SUB_TICK_SIZE)
//    , _type(DEFAULT_SUB_TICK_TYPE)
{
    pen().setColor(Qt::black);
}

void SubTicksX::replot(QPainter* painter, const QVector<QLineF>& lines_x)
{
    if(!is_shown())
        return;

    painter->setPen(pen());

    for (uint8_t i = 0; i < lines_x.size(); i++)
        painter->drawLine(lines_x[i]);
}

void SubTicksX::replot(QPainter* painter, const QVector<QPointF>& points)
{
    if(!is_shown())
        return;

    if(points.size() == 0)
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

void SubTicksX::replot_internal_single_sided(QPainter* painter, const QVector<QPointF>& points)
{
    for (uint8_t i = 0; i < points.size(); i++)
        painter->drawLine(QLineF(QPointF(points[i].x(), points[i].y())
                                 , QPointF(points[i].x(), points[i].y() - length())));
}

void SubTicksX::replot_single_sided(QPainter *painter, const QVector<QPointF> &points)
{
    for (uint8_t i = 0; i < points.size(); i++)
        painter->drawLine(QLineF(QPointF(points[i].x(), points[i].y())
                                 , QPointF(points[i].x(), points[i].y() + length())));
}

void SubTicksX::replot_double_sided(QPainter *painter, const QVector<QPointF>& points)
{
    for (uint8_t i = 0; i < points.size(); i++)
        painter->drawLine(QLineF(QPointF(points[i].x(), points[i].y() - length())
                                 , QPointF(points[i].x(), points[i].y() + length())));
}

