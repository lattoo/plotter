#pragma once

#include "src/plot_controller/plotter/text/text_item.h"

class AxisLabelY : public ITextItem
{
    static constexpr uint8_t MARGIN = 10;

public:
    AxisLabelY();
    ~AxisLabelY() = default;

    void replot(QPainter* painter, const QVector<QPointF>& point, const QStringList& text);
};
