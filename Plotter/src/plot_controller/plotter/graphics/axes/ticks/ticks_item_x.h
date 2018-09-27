#pragma once

#include "src/plot_controller/plotter/graphics/axes/ticks/tick_items.h"

class TicksItemX : public ITickItems
{
public:
    TicksItemX();
    ~TicksItemX() = default;

public:
    void replot(QPainter* painter, const QVector<QPointF>& points);

private:
    void replot_internal_single_sided(QPainter* painter, const QVector<QPointF>& points) override;
    void replot_single_sided(QPainter* painter, const QVector<QPointF>& points) override;
    void replot_double_sided(QPainter* painter, const QVector<QPointF>& points) override;
};
