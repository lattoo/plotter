#pragma once

#include "src/plot_controller/plotter/text/title_item.h"

class AxisTitleX : public ITitleItem
{
public:
    AxisTitleX();
    ~AxisTitleX() = default;

    void replot(QPainter* painter, const QPointF& point);
};
