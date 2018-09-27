#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class SubGridX : public IGraphicItem
{
public:
    SubGridX();
    ~SubGridX() = default;

    void replot(QPainter* painter, const QVector<QLineF>& ticks);
};

