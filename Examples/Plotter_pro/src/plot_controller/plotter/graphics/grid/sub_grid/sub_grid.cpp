#include "sub_grid.h"

SubGrid::SubGrid()
    : _pen(Qt::red)
{

}

void SubGrid::replot(QPainter* painter, const QVector<QLineF>& x_ticks, const QVector<QLineF>& y_ticks)
{
    painter->setPen(_pen);

    _grid_x.replot(painter, x_ticks);
    _grid_y.replot(painter, y_ticks);
}

void SubGrid::replot(QPainter* painter, const QRect& plot_area)
{

}

void SubGrid::set_pen(const QPen& pen)
{
    _grid_x.set_pen(pen);
    _grid_y.set_pen(pen);
}

QPen& SubGrid::get_pen()
{

}

void SubGrid::set_pen_width_px(const uint8_t width_px)
{
    _grid_x.set_pen_width_px(width_px);
    _grid_y.set_pen_width_px(width_px);
}

uint8_t SubGrid::get_pen_width_px() const
{
    // temporary
    return _grid_x.pen_width_px();
}

void SubGrid::set_pen_color(const QColor& color)
{

}

QColor& SubGrid::get_pen_color() const
{

}
