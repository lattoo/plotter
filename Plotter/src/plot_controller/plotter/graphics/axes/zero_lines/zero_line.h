#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class ZeroLine : private IGraphicItem
{
public:
    ZeroLine();
    ~ZeroLine() = default;

    void replot(QPainter* painter, const QLineF& line);
};
