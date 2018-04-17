#include "line_terminator_y.h"

LineTerminatorY::LineTerminatorY()
    : _size(DEFAULT_SIZE)
    , _radius(DEFAULT_RADIUS)
    , _ending_type(LineTerminatorType::ARROW)
{
    pen().setStyle(Qt::SolidLine);
}

void LineTerminatorY::replot(QPainter* painter, const QPolygonF& arrow_x, const QPolygonF& arrow_y)
{
    painter->setPen(pen());
    painter->setBrush(painter->pen().color());
    painter->drawPolygon(arrow_x);
    painter->drawPolygon(arrow_y);
    painter->setBrush(Qt::NoBrush);
}

void LineTerminatorY::replot(QPainter* painter, const QPointF& point)
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

void LineTerminatorY::replot_thin_arrow(QPainter* painter, const QPointF& top_left)
{
    QLineF arrow_y_left;
    QLineF arrow_y_right;

    arrow_y_left = QLineF(QPointF(top_left.x() - _size/4, top_left.y() + _size),
                          QPointF(top_left.x()          , top_left.y()));

    arrow_y_right = QLineF(QPointF(top_left.x() + _size/4, top_left.y() + _size),
                           QPointF(top_left.x()          , top_left.y()));

    painter->drawLine(arrow_y_left);
    painter->drawLine(arrow_y_right);
}

void LineTerminatorY::replot_arrow(QPainter* painter, const QPointF& top_left)
{
    QPolygonF arrow_y;

    painter->setBrush(Qt::NoBrush);

    arrow_y << QPointF(top_left.x() - _size/4, top_left.y())
            << QPointF(top_left.x()          , top_left.y() - _size)
            << QPointF(top_left.x() + _size/4, top_left.y());

    painter->drawPolygon(arrow_y);
}

void LineTerminatorY::replot_filled_arrow(QPainter *painter, const QPointF &top_left)
{
    QPolygonF arrow_y;

    painter->setBrush(painter->pen().color());

    arrow_y << QPointF(top_left.x() + _size/4, top_left.y() + _size)
            << QPointF(top_left.x()          , top_left.y())
            << QPointF(top_left.x() - _size/4, top_left.y() + _size);

    painter->drawPolygon(arrow_y);
}

void LineTerminatorY::replot_arrow2(QPainter* painter, const QPointF& top_left)
{
    QPolygonF arrow_y;

    painter->setBrush(painter->pen().color());

    arrow_y << QPointF(top_left.x()                       , top_left.y())
            << QPointF(top_left.x() - ARROW2_COEFF * _size, top_left.y() + _size)
            << QPointF(top_left.x()                       , top_left.y() + (1 - ARROW2_COEFF) * _size)
            << QPointF(top_left.x() + ARROW2_COEFF * _size, top_left.y() + _size);

//    arrow_x << QPointF(p2.x() - _size / 2, p2.y() - ARROW2_COEFF * _size)
//            << QPointF(p2.x() - _size / 4, p2.y())
//            << QPointF(p2.x() - _size / 2, p2.y() + ARROW2_COEFF * _size)
//            << QPointF(p2.x() + _size / 2, p2.y());

//    arrow_y << QPointF(p1.x()                       , p1.y() - _size/2)
//            << QPointF(p1.x() + ARROW2_COEFF * _size, p1.y() + _size/2)
//            << QPointF(p1.x()                       , p1.y() + _size / 4)
//            << QPointF(p1.x() - ARROW2_COEFF * _size, p1.y() + _size/2);

    painter->drawPolygon(arrow_y);

    painter->setBrush(Qt::NoBrush);
}

void LineTerminatorY::replot_filled_arrow2(QPainter *painter, const QPointF &top_left)
{
    QPolygonF arrow_y;

    painter->setBrush(Qt::NoBrush);

    arrow_y << QPointF(top_left.x()                       , top_left.y())
            << QPointF(top_left.x() - ARROW2_COEFF * _size, top_left.y() + _size)
            << QPointF(top_left.x()                       , top_left.y() + (1 - ARROW2_COEFF) * _size)
            << QPointF(top_left.x() + ARROW2_COEFF * _size, top_left.y() + _size);

    painter->drawPolygon(arrow_y);
}

// todo
void LineTerminatorY::replot_delta_arrow(QPainter* painter, const QPointF& top_left)
{
    QPolygonF arrow_y;

    painter->setBrush(painter->pen().color());

    arrow_y << QPointF(top_left.x()                            , top_left.y())
            << QPointF(top_left.x() + DELTA_ARROW_COEFF * _size, top_left.y() + _size)
            << QPointF(top_left.x() - DELTA_ARROW_COEFF * _size, top_left.y() + _size);

    painter->drawPolygon(arrow_y);

    arrow_y << QPointF(top_left.x()                            , top_left.y() - _size/4)
            << QPointF(top_left.x() + DELTA_ARROW_COEFF * _size, top_left.y() + _size/2)
            << QPointF(top_left.x() - DELTA_ARROW_COEFF * _size, top_left.y() + _size/2);

    painter->drawPolygon(arrow_y);
}

void LineTerminatorY::replot_filled_delta_arrow(QPainter *painter, const QPointF &top_left)
{

}

void LineTerminatorY::replot_circle(QPainter *painter, const QPointF &top_left)
{
    painter->setBrush(Qt::NoBrush);
    painter->drawEllipse(QPointF(top_left.x(), top_left.y() - _radius)
                         , _radius, _radius);
}

void LineTerminatorY::replot_filled_circle(QPainter *painter, const QPointF &top_left)
{
    painter->setBrush(painter->pen().color());
    painter->drawEllipse(QPointF(top_left.x(), top_left.y() - _radius)
                         , _radius, _radius);
}

void LineTerminatorY::replot_square(QPainter* painter, const QPointF& top_left)
{
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(top_left.x() - _size/2, top_left.y() - _size
                      , _size, _size);
}

void LineTerminatorY::replot_filled_square(QPainter *painter, const QPointF &top_left)
{
    painter->setBrush(painter->pen().color());
    painter->drawRect(top_left.x() - _size/2, top_left.y() - _size
                      , _size, _size);
}

void LineTerminatorY::replot_diamond(QPainter *painter, const QPointF &top_left)
{

}

void LineTerminatorY::replot_filled_diamond(QPainter *painter, const QPointF &top_left)
{

}

void LineTerminatorY::replot_star(QPainter *painter, const QPointF &top_left)
{

}

void LineTerminatorY::replot_filled_star(QPainter *painter, const QPointF &top_left)
{

}
