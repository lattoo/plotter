#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class MainGridY : public IGraphicItem
{
public:
    MainGridY();
    ~MainGridY() = default;

    void replot(QPainter* painter, const QVector<QLineF>& ticks);
};
