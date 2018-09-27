#pragma once

#include "label/label.h"
#include "title/title.h"

class AxesText
{
public:
    AxesText();
    ~AxesText() = default;

public:
    void replot(QPainter* painter, const QRect& plot_area);

public:
    AxesLabel& label() { return _label; }
    AxesTitle& title() { return _title; }

private:
    AxesLabel _label;
    AxesTitle _title;
};
