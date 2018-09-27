#include "line_terminator_x.h"

LineTerminatorX::LineTerminatorX()
    : _size(DEFAULT_SIZE)
    , _radius(DEFAULT_RADIUS)
    , _ending_type(LineTerminatorType::ARROW)
{
    pen().setStyle(Qt::SolidLine);
}

void LineTerminatorX::replot(QPainter* painter, const QPolygonF& arrow_x, const QPolygonF& arrow_y)
{
    painter->setPen(pen());
    painter->setBrush(painter->pen().color());
    painter->drawPolygon(arrow_x);
    painter->drawPolygon(arrow_y);
    painter->setBrush(Qt::NoBrush);
}

void LineTerminatorX::replot(QPainter* painter, const QPointF& point)
{
    painter->setPen(pen());

    switch(_ending_type)
    {
    case LineTerminatorType::THIN_ARROW:
        replot_thin_arrow(painter, point);
        break;
    case LineTerminatorType::ARROW:
        replot_arrow(painter, point);
        break;
    case LineTerminatorType::FILLED_ARROW:
        replot_filled_arrow(painter, point);
        break;
    case LineTerminatorType::ARROW2:
        replot_arrow2(painter, point);
        break;
    case LineTerminatorType::FILLED_ARROW2:
        replot_filled_arrow(painter, point);
        break;
    case LineTerminatorType::DELTA_ARROW:
        replot_delta_arrow(painter, point);
        break;
    case LineTerminatorType::FILLED_DELTA_ARROW:
        replot_filled_delta_arrow(painter, point);
        break;
    case LineTerminatorType::CIRCLE:
        replot_circle(painter, point);
        break;
    case LineTerminatorType::FILLED_CIRCLE:
        replot_filled_circle(painter, point);
        break;
    case LineTerminatorType::SQUARE:
        replot_square(painter, point);
        break;
    case LineTerminatorType::FILLED_SQUARE:
        replot_filled_square(painter, point);
        break;
    case LineTerminatorType::DIAMOND:
        replot_diamond(painter, point);
        break;
    case LineTerminatorType::FILLED_DIAMOND:
        replot_filled_diamond(painter, point);
        break;
    case LineTerminatorType::STAR:
        replot_star(painter, point);
        break;
    case LineTerminatorType::FILLED_STAR:
        replot_filled_star(painter, point);
        break;
    }
}

void LineTerminatorX::replot_thin_arrow(QPainter* painter, const QPointF& bottom_right)
{
    QLineF arrow_x_up;
    QLineF arrow_x_down;

    arrow_x_up = QLineF(QPointF(bottom_right.x() - _size, bottom_right.y() - _size/4),
                        QPointF(bottom_right.x()        , bottom_right.y()));

    arrow_x_down = QLineF(QPointF(bottom_right.x() - _size, bottom_right.y() + _size/4),
                          QPointF(bottom_right.x()            , bottom_right.y()));

    painter->drawLine(arrow_x_up);
    painter->drawLine(arrow_x_down);
}

void LineTerminatorX::replot_arrow(QPainter* painter, const QPointF& bottom_right)
{
    QPolygonF arrow_x;

    painter->setBrush(Qt::NoBrush);

    arrow_x << QPointF(bottom_right.x()        , bottom_right.y() - _size/4)
            << QPointF(bottom_right.x()        , bottom_right.y() + _size/4)
            << QPointF(bottom_right.x() + _size, bottom_right.y());

    painter->drawPolygon(arrow_x);
}

void LineTerminatorX::replot_filled_arrow(QPainter *painter, const QPointF &bottom_right)
{
    QPolygonF arrow_x;

    painter->setBrush(painter->pen().color());

    arrow_x << QPointF(bottom_right.x() - _size, bottom_right.y() - _size/4)
            << QPointF(bottom_right.x()        , bottom_right.y())
            << QPointF(bottom_right.x() - _size, bottom_right.y() + _size/4);

    painter->drawPolygon(arrow_x);
}

void LineTerminatorX::replot_arrow2(QPainter* painter, const QPointF& bottom_right)
{
    QPolygonF arrow_x;

    painter->setBrush(painter->pen().color());

    arrow_x << QPointF(bottom_right.x()                             , bottom_right.y())
            << QPointF(bottom_right.x() - _size                     , bottom_right.y() - ARROW2_COEFF * _size)
            << QPointF(bottom_right.x() - (1 - ARROW2_COEFF) * _size, bottom_right.y())
            << QPointF(bottom_right.x() - _size                     , bottom_right.y() + ARROW2_COEFF * _size);

    //    arrow_x << QPointF(p2.x() - _size / 2, p2.y() - ARROW2_COEFF * _size)
    //            << QPointF(p2.x() - _size / 4, p2.y())
    //            << QPointF(p2.x() - _size / 2, p2.y() + ARROW2_COEFF * _size)
    //            << QPointF(p2.x() + _size / 2, p2.y());

    //    arrow_y << QPointF(p1.x()                       , p1.y() - _size/2)
    //            << QPointF(p1.x() + ARROW2_COEFF * _size, p1.y() + _size/2)
    //            << QPointF(p1.x()                       , p1.y() + _size / 4)
    //            << QPointF(p1.x() - ARROW2_COEFF * _size, p1.y() + _size/2);

    painter->drawPolygon(arrow_x);
}

void LineTerminatorX::replot_filled_arrow2(QPainter *painter, const QPointF &bottom_right)
{
    QPolygonF arrow_x;

    painter->setBrush(Qt::NoBrush);

    arrow_x << QPointF(bottom_right.x()                             , bottom_right.y())
            << QPointF(bottom_right.x() - _size                     , bottom_right.y() - ARROW2_COEFF * _size)
            << QPointF(bottom_right.x() - (1 - ARROW2_COEFF) * _size, bottom_right.y())
            << QPointF(bottom_right.x() - _size                     , bottom_right.y() + ARROW2_COEFF * _size);

    painter->drawPolygon(arrow_x);
}

// todo
void LineTerminatorX::replot_delta_arrow(QPainter* painter, const QPointF& bottom_right)
{
    QPolygonF arrow_x;

    painter->setBrush(painter->pen().color());

    arrow_x << QPointF(bottom_right.x() - _size, bottom_right.y() - DELTA_ARROW_COEFF * _size)
            << QPointF(bottom_right.x() - _size, bottom_right.y() + DELTA_ARROW_COEFF * _size)
            << QPointF(bottom_right.x()        , bottom_right.y());

    painter->drawPolygon(arrow_x);

    arrow_x << QPointF(bottom_right.x() - _size /2, bottom_right.y() - DELTA_ARROW_COEFF * _size)
            << QPointF(bottom_right.x() - _size /2, bottom_right.y() + DELTA_ARROW_COEFF * _size)
            << QPointF(bottom_right.x() + _size /2, bottom_right.y());

    painter->drawPolygon(arrow_x);
}

void LineTerminatorX::replot_filled_delta_arrow(QPainter *painter, const QPointF &bottom_right)
{

}

void LineTerminatorX::replot_circle(QPainter *painter, const QPointF &bottom_right)
{
    painter->setBrush(Qt::NoBrush);
    painter->drawEllipse(QPointF(bottom_right.x() + _radius, bottom_right.y())
                         , _radius, _radius);
}

void LineTerminatorX::replot_filled_circle(QPainter *painter, const QPointF &bottom_right)
{
    painter->setBrush(painter->pen().color());
    painter->drawEllipse(QPointF(bottom_right.x() + _radius, bottom_right.y())
                         , _radius, _radius);
}

void LineTerminatorX::replot_square(QPainter* painter, const QPointF& bottom_right)
{
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(bottom_right.x(), bottom_right.y() - _size/2
                      , _size, _size);
}

void LineTerminatorX::replot_filled_square(QPainter *painter, const QPointF &bottom_right)
{
    painter->setBrush(painter->pen().color());
    painter->drawRect(bottom_right.x(), bottom_right.y() - _size/2
                      , _size, _size);
}

void LineTerminatorX::replot_diamond(QPainter *painter, const QPointF &bottom_right)
{

}

void LineTerminatorX::replot_filled_diamond(QPainter *painter, const QPointF &bottom_right)
{

}

void LineTerminatorX::replot_star(QPainter *painter, const QPointF &bottom_right)
{

}

void LineTerminatorX::replot_filled_star(QPainter *painter, const QPointF &bottom_right)
{

}
