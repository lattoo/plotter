#include "legend.h"

LegendText::LegendText()
{
    set_enabled(true);
}

void LegendText::replot(QPainter* painter, const QVector<QPointF>& points, const QStringList& text_list)
{
    if(!is_shown())
    {
        set_max_text_height(0);
        set_max_text_width(0);
        return;
    }

    painter->setPen(pen());
    painter->setFont(font());

    const uint16_t TEXT_HEIGHT = text_height_px(font());

    set_max_text_height(TEXT_HEIGHT);

    for (uint8_t i = 0; i < points.size(); i++)
    {
        const uint16_t TEXT_WIDTH = text_width_px(font(), text_list.at(i));
        painter->drawText(points[i].x() + 5, points[i].y()
                          , TEXT_WIDTH, TEXT_HEIGHT
                          , Qt::AlignHCenter | Qt::AlignBottom
                          , text_list[i]);
    }
}

void LegendText::replot(QPainter* painter, const QPointF& point, const QString& text, const QColor& fill_color)
{
//    painter->fillRect(fill_color);

    if(!is_shown())
        return;

    painter->setPen(pen());
    painter->setFont(font());

    const uint16_t TEXT_HEIGHT = text_height_px(font());

    set_max_text_height(TEXT_HEIGHT);

    const uint16_t TEXT_WIDTH = text_width_px(font(), text);
    painter->drawText(point.x() + 5, point.y()
                      , TEXT_WIDTH, TEXT_HEIGHT
                      , Qt::AlignHCenter | Qt::AlignBottom
                      , text);
}
