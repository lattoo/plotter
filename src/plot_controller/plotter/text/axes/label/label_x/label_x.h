#pragma once

#include "src/plot_controller/plotter/text/text_item.h"

class AxisLabelX : public ITextItem
{
    static constexpr uint8_t MARGIN = 5;

public:
    AxisLabelX();
    ~AxisLabelX() = default;

    void replot(QPainter* painter, const QVector<QPointF>& point, const QStringList& text);
};
