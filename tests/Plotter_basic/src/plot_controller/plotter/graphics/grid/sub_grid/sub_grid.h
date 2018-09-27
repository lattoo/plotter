#pragma once

#include "sub_grid_x/sub_grid_x.h"
#include "sub_grid_y/sub_grid_y.h"

class SubGrid
{
public:
    SubGrid();
    ~SubGrid() = default;

    void replot(QPainter* painter, const QVector<QLineF>& x_ticks, const QVector<QLineF>& y_ticks);

public:
    SubGridX& grid_x() { return _grid_x; }
    SubGridY& grid_y() { return _grid_y; }

    void replot(QPainter* painter, const QRect& plot_area);

    void    set_pen(const QPen& pen);
    QPen&   get_pen();

    void    set_pen_width_px(const uint8_t width_px);
    uint8_t get_pen_width_px() const;

    void    set_pen_color(const QColor& color);
    QColor& get_pen_color() const;

private:
    QPen _pen;

    SubGridX _grid_x;
    SubGridY _grid_y;
};

