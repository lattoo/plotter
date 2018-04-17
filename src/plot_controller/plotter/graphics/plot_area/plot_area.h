#pragma once

#include "src/plot_controller/plotter/graphics/filled_item.h"

class PlotArea: public IFilledItem
{
public:
    PlotArea();
    ~PlotArea() = default;

public:
    void replot(QPainter* painter, const QRect& plot_area);

    void set_gradient_direction(const GradientDirection& direction) { _direction = direction; }
    GradientDirection get_gradient_direction() const { return _direction; }

    void set_gradient_style(const GradientStyle& style) { _color_style = style; }
    GradientStyle set_gradient_style() const { return _color_style; }

private:
    QLineF gradient_points(const GradientDirection direction, const QRect& plot_area);

private:
//    QBrush _brush;

    GradientDirection _direction;
    GradientStyle     _color_style;

//    GradientColors _gradient_colors;
};
