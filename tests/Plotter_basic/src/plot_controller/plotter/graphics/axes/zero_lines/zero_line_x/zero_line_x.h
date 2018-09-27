#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class ZeroLineX : private IGraphicItem
{
public:
    ZeroLineX();
    ~ZeroLineX() = default;

    void replot(QPainter* painter, const QLineF& line);
};
