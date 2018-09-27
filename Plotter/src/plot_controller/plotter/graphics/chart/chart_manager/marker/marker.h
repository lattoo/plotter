#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class Marker : private IGraphicItem
{
public:
    Marker();
    ~Marker() = default;

public:
    void replot(QPainter* painter, const MarkerType type, const uint8_t marker_size, const float x, const float y);
};
