#pragma once

#include "src/plot_controller/plotter/text/title_item.h"

class AxisTitleY : public ITitleItem
{
public:
    AxisTitleY();
    ~AxisTitleY() = default;

    void replot(QPainter* painter, const QPointF& point);

public:
};
