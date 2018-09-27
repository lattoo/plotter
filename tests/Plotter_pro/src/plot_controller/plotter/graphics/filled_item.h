#pragma once

#include <QDebug>

#include "src/plot_controller/plotter/graphics/graphic_item.h"
#include "src/plot_controller/plotter/graphics/gradient_colors/gradient_colors.h"

class IFilledItem : public IGraphicItem
{
public:
    IFilledItem();
    ~IFilledItem() = default;

public:
    void set_brush(const QBrush& brush) { _brush = brush; }
    QBrush& brush() { return _brush; }

    void set_brush_color(const QColor& color);
    QColor brush_color() const { return _brush.color(); }

    void set_color_b(const QColor& color);
    QColor color_b() const { return _color_b; }

    void set_gradient_area(const QPointF& p1, const QPointF& p2);

    void set_brush_style(const Qt::BrushStyle style);
    Qt::BrushStyle brush_style() { return _brush.style(); }

private:
    float x1;
    float y1;
    float x2;
    float y2;

    QBrush _brush;
    Qt::BrushStyle _brush_style;

    QColor _color_a;
    QColor _color_b;

    QLinearGradient _gradient;
};
