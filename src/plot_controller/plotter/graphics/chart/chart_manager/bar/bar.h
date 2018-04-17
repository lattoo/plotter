#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class Bar : public IGraphicItem
{
public:
    Bar();
    Bar(const QString& chart_name);
    ~Bar() = default;

public:
    void replot(QPainter* painter, QPolygonF& polyline);
//    void replot_filling(QPainter* painter, QPolygonF& polyline);

public:
    void add_data(const float x, const float y);
    void clear_data();

public:
    std::vector<QPointF>& data() { return _bar_data; }

private:
    std::vector<QPointF> _bar_data;
};
