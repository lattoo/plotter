#pragma once

#include "main_grid/main_grid.h"
#include "sub_grid/sub_grid.h"

class Grid
{
public:
    Grid();
    ~Grid() = default;

    void replot(QPainter* painter, const QVector<QLineF>& x_ticks_main, const QVector<QLineF>& x_ticks_sub, const QVector<QLineF>& y_ticks);

public:
    void replot(QPainter* painter, const QRect& plot_area);

public:
    MainGrid& main_grid() { return _main_grid; }
    SubGrid&  sub_grid()  { return _sub_grid; }

private:
    MainGrid _main_grid;
    SubGrid  _sub_grid;
};
