#include "grid.h"

Grid::Grid()
{

}

void Grid::replot(QPainter* painter, const QRect& plot_area)
{

}

void Grid::replot(QPainter* painter, const QVector<QLineF>& x_ticks_main, const QVector<QLineF>& x_ticks_sub, const QVector<QLineF>& y_ticks)
{
    _main_grid.replot(painter, x_ticks_main, y_ticks);
    _sub_grid.replot(painter, x_ticks_sub, y_ticks);
}
