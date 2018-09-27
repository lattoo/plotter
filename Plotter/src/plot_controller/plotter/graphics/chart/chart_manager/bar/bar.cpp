#include "bar.h"

Bar::Bar()
{

}

void Bar::replot(QPainter* painter, QPolygonF& polyline)
{

}

void Bar::add_data(const float x, const float y)
{
    _bar_data.push_back(QPointF(x, y));
}

void Bar::clear_data()
{
    _bar_data.clear();
}
