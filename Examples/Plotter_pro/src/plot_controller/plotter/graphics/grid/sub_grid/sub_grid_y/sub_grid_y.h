#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class SubGridY : public IGraphicItem
{
public:
    SubGridY();
    ~SubGridY() = default;

    void replot(QPainter* painter, const QVector<QLineF>& ticks);
};

