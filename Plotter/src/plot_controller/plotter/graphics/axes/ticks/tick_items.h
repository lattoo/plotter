#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class ITickItems : public IGraphicItem
{
public:
    ITickItems()
        : _tick_type(TickType::INTERNAL_SINGLE_SIDED)
    {}
    ~ITickItems() = default;

public:
    void update_internal(QPainter* painter)
    {
        if(!is_shown())
            return;

        painter->setPen(pen());
    }

public:
    void set_tick_type(const TickType type) { _tick_type = type; }
    TickType tick_type() const { return _tick_type; }

private:
    virtual void replot_internal_single_sided(QPainter* painter, const QVector<QPointF>& points) = 0;
    virtual void replot_single_sided(QPainter* painter, const QVector<QPointF>& points) = 0;
    virtual void replot_double_sided(QPainter* painter, const QVector<QPointF>& points) = 0;

private:
    TickType _tick_type;
};
