#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class SubTicksX : public IGraphicItem
{
public:
    SubTicksX();
    ~SubTicksX() = default;

    void replot(QPainter* painter, const QVector<QLineF>& lines_x);

    void replot(QPainter* painter, const QVector<QPointF>& points);

private:
    void replot_internal_single_sided(QPainter* painter, const QVector<QPointF>& points);
    void replot_single_sided(QPainter* painter, const QVector<QPointF>& points);
    void replot_double_sided(QPainter* painter, const QVector<QPointF>& points);

private:
    uint8_t  _size;
    TickType _type;
};
