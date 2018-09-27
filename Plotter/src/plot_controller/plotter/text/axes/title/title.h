#pragma once

#include "title_x/title_x.h"
#include "title_y/title_y.h"

class AxesTitle
{
public:
    AxesTitle();
    ~AxesTitle() = default;

public:
    void replot(QPainter* painter, const QRect& plot_area);

public:
    AxisTitleX& title_x() {return _title_x; }
    AxisTitleY& title_y() {return _title_y; }

private:
    AxisTitleX _title_x;
    AxisTitleY _title_y;
};
