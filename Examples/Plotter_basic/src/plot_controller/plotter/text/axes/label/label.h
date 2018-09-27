#pragma once

#include "label_x/label_x.h"
#include "label_y/label_y.h"

class AxesLabel
{
public:
    AxesLabel();
    ~AxesLabel() = default;

public:
    void replot(QPainter* painter, const QRect& plot_area);
    void replot(QPainter* painter, const QVector<QPointF>& point, const QStringList& text);

public:
    AxisLabelX& axis_x() { return _axis_x; }
    AxisLabelY& axis_y() { return _axis_y; }

    void set_font(const QFont& font);
    QFont get_font() { return _font; }

    void set_font_size(const uint8_t size);
    uint8_t get_font_size() const { return _font.pixelSize(); }

private:
    void update_fonts();

private:
    AxisLabelX _axis_x;
    AxisLabelY _axis_y;

    QFont _font;
};
