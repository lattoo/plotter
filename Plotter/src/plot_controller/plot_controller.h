#pragma once

#include "plotter/plotter.h"

class PlotController
{
public:
    PlotController();
    ~PlotController() = default;

private:
    Plotter _plotter1;
    Plotter _plotter2;
    Plotter _plotter3;
};
