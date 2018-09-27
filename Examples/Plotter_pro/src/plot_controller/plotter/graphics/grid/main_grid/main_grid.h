#pragma once

#include "main_grid_x/main_grid_x.h"
#include "main_grid_y/main_grid_y.h"

class MainGrid
{
public:
    MainGrid();
    ~MainGrid() = default;

    void replot(QPainter* painter, const QVector<QLineF>& x_ticks, const QVector<QLineF>& y_ticks);

public:
    MainGridX& grid_x() { return _grid_x; }
    MainGridY& grid_y() { return _grid_y; }

    void    set_pen(const QPen& pen);
    QPen&   get_pen();

    void    set_pen_width_px(const uint8_t width_px);
    uint8_t get_pen_width_px() const;

    void    set_pen_color(const QColor& color);
    QColor& get_pen_color() const;

private:
    QPen _pen;

    MainGridX _grid_x;
    MainGridY _grid_y;
};
