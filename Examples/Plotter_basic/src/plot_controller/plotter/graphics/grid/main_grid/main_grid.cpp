#include "main_grid.h"

MainGrid::MainGrid()
    : _pen(QPen(Qt::black))
{
    _pen.setStyle(Qt::DotLine);
}

void MainGrid::replot(QPainter* painter, const QVector<QLineF>& x_ticks, const QVector<QLineF>& y_ticks)
{
    _grid_x.replot(painter, x_ticks);
    _grid_y.replot(painter, y_ticks);
}

void MainGrid::set_pen(const QPen &pen)
{
    _grid_x.set_pen(pen);
    _grid_y.set_pen(pen);
}

void MainGrid::set_pen_width_px(const uint8_t width_px)
{
    _grid_x.set_pen_width_px(width_px);
    _grid_y.set_pen_width_px(width_px);
}

uint8_t MainGrid::get_pen_width_px() const
{
    // temporary
    return _grid_x.pen_width_px();
}
