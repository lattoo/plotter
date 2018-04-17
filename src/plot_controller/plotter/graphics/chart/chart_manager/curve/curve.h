#pragma once

#include <vector>

#include "src/plot_controller/plotter/graphics/chart/chart_manager/chart.h"

class Curve : public IChart
{
public:
    Curve();
    Curve(const QString& chart_name);
//    Curve(const QString& chart_name, const QVector<QPointF>& data);
    ~Curve();

public:
    void replot(QPainter* painter, QPolygonF& polyline);
    void replot_filling(QPainter* painter, QPolygonF& polyline);

public:
    void add_data(const float x, const float y);
    void clear_data();

public:
    std::vector<QPointF>& data() { return _curve_data; }

private:
    std::vector<QPointF> _curve_data;
};
