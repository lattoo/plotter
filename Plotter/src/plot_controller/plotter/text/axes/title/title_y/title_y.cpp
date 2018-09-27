#include "title_y.h"
#include <QDebug>


AxisTitleY::AxisTitleY()
{
    set_text("Voltage, mV");
    set_font_size_px(20);
    set_enabled(true);
}

void AxisTitleY::replot(QPainter* painter, const QPointF& point)
{
    if(!is_shown())
    {
        set_max_text_height(0);
        set_max_text_width(0);
        return;
    }

    painter->setPen(pen());
    painter->setFont(font());

    painter->save();

    const uint16_t TEXT_HEIGHT = text_height_px(font());
    const uint16_t TEXT_WIDTH = text_width_px(font(), text());

    set_max_text_height(TEXT_HEIGHT);
    set_max_text_width(TEXT_WIDTH);

    painter->rotate(-90);

    painter->drawText(-point.y() - TEXT_WIDTH/2, point.x()
                      , TEXT_WIDTH, TEXT_HEIGHT
                      , Qt::AlignHCenter | Qt::AlignVCenter
                      , text());

    //    painter->drawText(point.x() - TEXT_WIDTH/2, point.y()
    //                      , TEXT_WIDTH, TEXT_HEIGHT
    //                      , Qt::AlignHCenter | Qt::AlignTop
    //                      , text());
    painter->rotate(90);
    painter->restore();
}
