#include "marker.h"

Marker::Marker()
{

}

void Marker::replot(QPainter* painter
                            , const MarkerType type
                            , const uint8_t marker_size
                            , const float x
                            , const float y)
{
    const uint8_t w = marker_size / 2.0;
    switch (type)
    {
    case MarkerType::CROSS:
    {
        painter->drawLine(QLineF(x-w, y-w, x+w, y+w));
        painter->drawLine(QLineF(x-w, y+w, x+w, y-w));
        break;
    }
    case MarkerType::PLUS:
    {
        painter->drawLine(QLineF(x-w,   y, x+w,   y));
        painter->drawLine(QLineF(  x, y+w,   x, y-w));
        break;
    }
    case MarkerType::CIRCLE:
    {
        painter->setBrush(Qt::transparent);
        painter->drawEllipse(QPointF(x , y), w, w);
        break;
    }
    case MarkerType::FILLED_CIRCLE:
    {
        QBrush b = painter->brush();
        painter->setBrush(painter->pen().color());
        painter->drawEllipse(QPointF(x , y), w, w);
        painter->setBrush(b);
        break;
    }
    case MarkerType::DIAMOND:
    {
        painter->drawLine(QLineF(x-w,   y,   x, y-w));
        painter->drawLine(QLineF(  x, y-w, x+w,   y));
        painter->drawLine(QLineF(x+w,   y,   x, y+w));
        painter->drawLine(QLineF(  x, y+w, x-w,   y));
        break;
    }
    case MarkerType::FILLED_DIAMOND:
    {
        QPolygonF polygon;
        painter->setBrush(painter->pen().color());
        polygon << QPointF(x-w,   y)
                << QPointF(x, y-w)
                << QPointF(x, y-w)
                << QPointF(x+w,   y)
                << QPointF(x+w,   y)
                << QPointF(x, y+w)
                << QPointF(x, y+w)
                << QPointF(x-w,   y);
        painter->drawPolygon(polygon);
        break;
    }
    case MarkerType::SQUARE:
    {
        painter->setBrush(Qt::transparent);
        painter->drawRect(QRectF(x-w, y-w, marker_size, marker_size));
        break;
    }
    case MarkerType::FILLED_SQUARE:
    {
        QBrush b = painter->brush();
        painter->setBrush(painter->pen().color());
        painter->drawRect(QRectF(x-w, y-w, marker_size, marker_size));
        painter->setBrush(b);
        break;
    }
    case MarkerType::STAR:
    {
        painter->drawLine(QLineF(x-w,   y, x+w,   y));
        painter->drawLine(QLineF(  x, y+w,   x, y-w));
        painter->drawLine(QLineF(x-w*0.707, y-w*0.707, x+w*0.707, y+w*0.707));
        painter->drawLine(QLineF(x-w*0.707, y+w*0.707, x+w*0.707, y-w*0.707));
        break;
    }
    case MarkerType::TRIANGLE:
    {
        painter->drawLine(QLineF(x-w, y+0.755*w, x+w, y+0.755*w));
        painter->drawLine(QLineF(x+w, y+0.755*w,   x, y-0.977*w));
        painter->drawLine(QLineF(  x, y-0.977*w, x-w, y+0.755*w));
        break;
    }
    case MarkerType::FILLED_TRIANGLE:
    {
        QPolygonF polygon;
        painter->setBrush(painter->pen().color());
        polygon << QPointF(x-w, y+0.755*w)
                << QPointF(x+w, y+0.755*w)
                << QPointF(x+w, y+0.755*w)
                << QPointF(x, y-0.977*w)
                << QPointF(x, y-0.977*w)
                << QPointF(x-w, y+0.755*w);
        painter->drawPolygon(polygon);
        break;
    }
    case MarkerType::TRIANGLE2:
    {
        painter->drawLine(QLineF(x-w, y-0.755*w, x+w, y-0.755*w));
        painter->drawLine(QLineF(x+w, y-0.755*w,   x, y+0.977*w));
        painter->drawLine(QLineF(  x, y+0.977*w, x-w, y-0.755*w));
        break;
    }
    case MarkerType::FILLED_TRIANGLE2:
    {
        QPolygonF polygon;
        painter->setBrush(painter->pen().color());
        polygon << QPointF(x-w, y-0.755*w)
                << QPointF(x+w, y-0.755*w)
                << QPointF(x+w, y-0.755*w)
                << QPointF(x, y+0.977*w)
                << QPointF(x, y+0.977*w)
                << QPointF(x-w, y-0.755*w);
        painter->drawPolygon(polygon);
        break;
    }
    default:
        break;
    }
}
