#include "plot_area.h"

PlotArea::PlotArea()
    :
//      _brush(Qt::transparent)
     _direction(GradientDirection::VERTICAL)
    , _color_style(GradientStyle::LIGHT_GRAY)
{
    pen().setColor(Qt::transparent);
//    pen().setBrush(_brush);
}

void PlotArea::replot(QPainter* painter, const QRect& plot_area)
{
//    if(_direction == GradientDirection::DISABLED)
//        return;

//    const QLineF grad_points = gradient_points(_direction, plot_area);
//    const GradientColorsPair gradient_pair = _gradient_colors.pair(_color_style);

//    QLinearGradient gradient(grad_points.x1(), grad_points.y1(), grad_points.x2(), grad_points.y2());
//    gradient.setColorAt(0, gradient_pair.color_1);
//    gradient.setColorAt(1, gradient_pair.color_2);

//    _brush = QBrush(gradient);

    if(brush().gradient())
    {
        set_gradient_area(plot_area.topLeft(), plot_area.bottomLeft());
    }
    painter->setPen(pen());
    painter->setBrush(brush());
    painter->drawRect(plot_area.adjusted(0, 0, -1, -1));
    painter->setBrush(Qt::NoBrush);
}

QLineF PlotArea::gradient_points(const GradientDirection direction, const QRect& plot_area)
{
    switch (direction)
    {
    case GradientDirection::DISABLED:
        break;
    case GradientDirection::VERTICAL:
        return QLineF(QPointF(plot_area.topLeft())
                      , QPointF(plot_area.bottomLeft()));
        break;
    case GradientDirection::HORIZONTAL:
        return QLineF(QPointF(plot_area.topLeft())
                      , QPointF(plot_area.topRight()));
        break;
    default:
        break;
    }
}
