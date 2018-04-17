#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class GridItem : public IGraphicItem
{
public:
    GridItem();
    ~GridItem() = default;

public:
    void replot(QPainter* painter, const QVector<QLineF>& ticks);
};
