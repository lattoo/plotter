#include "background.h"

Background::Background()
{
    set_pen(Qt::NoPen);
}

void Background::replot(QPainter* painter, const QPointF& bottom_right)
{
//    if(_direction == GradientDirection::DISABLED)
//        return;

//    const QLineF grad_points = gradient_points(_direction, plot_area);
//    const GradientColorsPair gradient_pair = _gradient_colors.pair(_color_style);

//    set_gradient_area(0, 0, 0, bottom_right.y());
    QRectF background(0, 0, bottom_right.x(), bottom_right.y());
    set_gradient_area(QPointF(0, 0), QPointF(0, bottom_right.y()));

    painter->setPen(pen());
    painter->setBrush(brush());
    painter->drawRect(background);
}
