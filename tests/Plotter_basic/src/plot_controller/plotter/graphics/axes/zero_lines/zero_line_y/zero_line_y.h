#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class ZeroLineY : private IGraphicItem
{
public:
    ZeroLineY();
    ~ZeroLineY() = default;

    void replot(QPainter* painter, const QLineF& line);
};
