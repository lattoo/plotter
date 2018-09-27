#include "label_y.h"

AxisLabelY::AxisLabelY()
{
    set_enabled(true);
}

void AxisLabelY::replot(QPainter* painter, const QVector<QPointF>& point, const QStringList& text)
{
    if(!is_shown())
    {
        set_max_text_height(0);
        set_max_text_width(0);
        return;
    }

    painter->setPen(pen());
    painter->setFont(font());

    set_max_text_width(0);

    for(uint8_t i = 0; i < text.size(); i++)
    {
        if(max_text_width() < text_width_px(font(), text.at(i)))
            set_max_text_width(text_width_px(font(), text.at(i)));
    }

    const uint16_t TEXT_HEIGHT = text_height_px(font());
    for (uint8_t i = 0; i < point.size(); i++)
        painter->drawText(point[i].x() - max_text_width() - MARGIN, point[i].y() - TEXT_HEIGHT / 2
                          , max_text_width(), TEXT_HEIGHT
                          , Qt::AlignRight | Qt::AlignVCenter
                          , text[i]);
}
