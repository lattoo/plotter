#pragma once

#include <QColor>
#include <QPainter>
#include <QPen>

#include "src/types.h"

using namespace LineTerminatorTypes;
using namespace TickTypes;
using namespace GradientTypes;

class IGraphicItem
{
public:
    IGraphicItem() = default;
    ~IGraphicItem() = default;

public:
    void set_pen(const QPen& pen) { _pen = pen; }
    QPen& pen() { return _pen; }

    void set_pen_width_px(const uint8_t width_px) { _pen.setWidth(width_px); }
    uint8_t pen_width_px() const { return _pen.width(); }

    void         set_pen_style(const Qt::PenStyle style) { _pen.setStyle(style); }
    Qt::PenStyle pen_style() const { return _pen.style(); }

    void set_pen_color(const QColor& color) { _pen.setColor(color); }
    QColor pen_color() const { return _pen.color(); }

    void set_enabled(const bool enable = true)
    {
        _is_shown = enable;
    }
    bool is_shown() const { return _is_shown; }



    void set_length(const uint8_t length) { _length = length; }
    uint8_t length() const { return _length; }

    void set_tick_type(const TickType type) { _tick_type = type; }
    TickType tick_type() const { return _tick_type; }

private:
    QPen _pen;
    uint8_t _length;
    TickType _tick_type;
    bool _is_shown;
};
