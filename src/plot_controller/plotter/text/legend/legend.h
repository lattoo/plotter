#pragma once

#include "src/plot_controller/plotter/text/title_item.h"

class LegendText : public ITitleItem
{
public:
    LegendText();
    ~LegendText() = default;

    void replot(QPainter* painter, const QVector<QPointF>& points, const QStringList& text_list);
    void replot(QPainter* painter, const QPointF& point, const QString& text, const QColor& fill_color);

private:
    void replot_borders();
    void replot_text();
};
