#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class SubTicksY : public IGraphicItem
{
public:
    SubTicksY();
    ~SubTicksY() = default;

    void replot(QPainter* painter, const QVector<QLineF>& lines_y);

    void replot(QPainter* painter, const QVector<QPointF>& points);

private:
    void replot_internal_single_sided(QPainter* painter, const QVector<QPointF>& points);
    void replot_single_sided(QPainter* painter, const QVector<QPointF>& points);
    void replot_double_sided(QPainter* painter, const QVector<QPointF>& points);

private:
//    QPen _pen;

//    uint8_t  _size;
//    TickType _type;
};
