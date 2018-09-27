#pragma once

#include "src/plot_controller/plotter/graphics/grid/grid_item.h"

class Grid
{
public:
    Grid();
    ~Grid() = default;

public:
    GridItem& x() { return _grid_x; }
    GridItem& y() { return _grid_y; }
    GridItem& sub_x() { return _subgrid_x; }
    GridItem& sub_y() { return _subgrid_y; }

private:
    GridItem _grid_x;
    GridItem _grid_y;
    GridItem _subgrid_x;
    GridItem _subgrid_y;
};
