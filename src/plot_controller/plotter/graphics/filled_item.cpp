#include "filled_item.h"

IFilledItem::IFilledItem()
    : _brush_style(Qt::BrushStyle::NoBrush)
    , _color_a(Qt::transparent)
    , _color_b(Qt::transparent)
{
    _gradient = QLinearGradient(0, 0, 0, 500);
    _gradient.setColorAt(0, _color_a);
    _gradient.setColorAt(1, _color_b);
}

void IFilledItem::set_brush_color(const QColor& color)
{
    _color_a = color;
    _brush.setColor(_color_a);
}

void IFilledItem::set_color_b(const QColor &color)
{
    _color_b = color;
}

void IFilledItem::set_gradient_area(const QPointF& p1, const QPointF& p2)
{
    x1 = p1.x();
    y1 = p1.y();
    x2 = p2.x();
    y2 = p2.y();
    _gradient.setStart(p1);
    _gradient.setFinalStop(p2);
    _gradient.setColorAt(0, _color_a);
    _gradient.setColorAt(1, _color_b);
    _brush = QBrush(_gradient);
}

void IFilledItem::set_brush_style(const Qt::BrushStyle style)
{
    if(style == Qt::BrushStyle::LinearGradientPattern)
    {
        _brush = QBrush(_gradient);
    }
    else
        _brush.setStyle(style);
}
