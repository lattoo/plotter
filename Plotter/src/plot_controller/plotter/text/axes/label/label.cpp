#include "label.h"

AxesLabel::AxesLabel()
{

}

void AxesLabel::replot(QPainter* painter, const QRect& plot_area)
{
}

void AxesLabel::replot(QPainter *painter, const QVector<QPointF> &point, const QStringList &text)
{
}

void AxesLabel::set_font(const QFont& font)
{
    _font = font;
    update_fonts();
}

void AxesLabel::set_font_size(const uint8_t size)
{
    _font.setPixelSize(size);
    update_fonts();
}

void AxesLabel::update_fonts()
{
    _axis_x.set_font(_font);
    _axis_y.set_font(_font);
}
