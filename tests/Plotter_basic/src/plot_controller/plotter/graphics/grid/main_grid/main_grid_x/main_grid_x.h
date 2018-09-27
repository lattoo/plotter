#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class MainGridX : public IGraphicItem
{
public:
    MainGridX();
    ~MainGridX() = default;

    void replot(QPainter* painter, const QVector<QLineF>& ticks);
};
