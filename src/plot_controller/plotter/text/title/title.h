#pragma once

#include "src/plot_controller/plotter/text/title_item.h"

class Title : public ITitleItem
{
public:
    Title();
    ~Title() = default;

public:
    void replot(QPainter* painter, const QPointF& point);
};
