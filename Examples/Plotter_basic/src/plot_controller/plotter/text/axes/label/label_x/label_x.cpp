#include "label_x.h"

AxisLabelX::AxisLabelX()
{
    set_enabled(true);
    set_font_size_px(12);
    font().setFamily("Arial Narrow");
}

void AxisLabelX::replot(QPainter* painter, const QVector<QPointF>& point, const QStringList& text)
{
    if(!is_shown())
    {
        set_max_text_height(0);
        set_max_text_width(0);
        return;
    }

    painter->setPen(pen());
    painter->setFont(font());

    set_max_text_height(0);

    const uint16_t TEXT_HEIGHT = text_height_px(font());
    set_max_text_height(TEXT_HEIGHT);
    for(uint8_t i = 0; i < text.size(); i++)
    {
        if(max_text_width() < text_width_px(font(), text.at(i)))
            set_max_text_width(text_width_px(font(), text.at(i)));
    }
    const uint16_t TEXT_WIDTH = max_text_width();
    for (uint8_t i = 0; i < point.size(); i++)
    {
        painter->drawText(point[i].x() - TEXT_WIDTH/2, point[i].y() + MARGIN
                          , TEXT_WIDTH, TEXT_HEIGHT
                          , Qt::AlignHCenter | Qt::AlignTop
                          , text[i]);
    }
}
