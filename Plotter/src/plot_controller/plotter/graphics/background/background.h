#pragma once

#include "src/plot_controller/plotter/graphics/filled_item.h"

class Background : public IFilledItem
{
public:
    Background();
    ~Background() = default;

public:
    void replot(QPainter* painter, const QPointF& bottom_right);
};
