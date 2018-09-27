#include "title_x.h"

#include <QDebug>

AxisTitleX::AxisTitleX()
{
    set_text("Time, mm:ss:ms");
    set_font_size_px(20);
    set_enabled(true);
}

void AxisTitleX::replot(QPainter* painter, const QPointF& point)
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
    const uint16_t TEXT_WIDTH = text_width_px(font(), text());

    set_max_text_height(TEXT_HEIGHT);
    set_max_text_width(TEXT_WIDTH);

    painter->drawText(point.x() - TEXT_WIDTH/2, point.y()
                      , TEXT_WIDTH, TEXT_HEIGHT
                      , Qt::AlignHCenter | Qt::AlignTop
                      , text());
}
