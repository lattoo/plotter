#pragma once

#include <QFont>
#include <QColor>
#include <QPainter>
#include <QPen>
#include <QFontMetrics>

class ITextItem
{
public:
    ITextItem()
        : _size(12)
        , _font("Times", _size)
        , _color(Qt::black)
        , _font_metrics(_font)
        , _max_width(0)
        , _max_height(0)
    {
        _font.setPixelSize(_size);
        _pen.setColor(_color);
        _font_metrics = QFontMetrics(_font);
    }

    ~ITextItem() = default;

public:
    void set_font(const QFont& font)
    {
        _font = font;
        _font_metrics = QFontMetrics(_font);
    }
    ////////////////////////////////////
    ////////////////////////////////////
    ////////////////////////////////////
    QFont& font() { return _font; }
    ////////////////////////////////////
    // VS. QFont font() const { return _font; }
    ////////////////////////////////////
    void set_font_size_px(const float size)
    {
        _size = size;
        _font.setPixelSize(_size);
        _font_metrics = QFontMetrics(_font);
    }
    uint8_t font_size_px() const { return _size; }

    void set_text_color(const QColor& color)
    {
        _color = color;
        _pen.setColor(color);
    }
    QColor text_color() const { return _color; }

    void set_pen(const QPen& pen) { _pen = pen; }
    QPen& pen() { return _pen; }

public:
    uint16_t text_height_px(const QFont& font)
    {
        if(_font.pixelSize() != font.pixelSize()
                || _font.family() != font.family())

            _font_metrics = QFontMetrics(font);

        return _font_metrics.height();
    }
    uint16_t text_width_px(const QFont& font, const QString& text)
    {
        if(_font.pixelSize() != font.pixelSize()
                || _font.family() != font.family())

            _font_metrics = QFontMetrics(font);

        return _font_metrics.width(text);
    }

    void set_max_text_width(const uint16_t width) { _max_width = width; }
    uint16_t max_text_width() const { return _max_width; }

    void set_max_text_height(const uint16_t height) { _max_height = height; }
    uint16_t max_text_height() const { return _max_height; }

    void set_enabled(const bool enable = true)
    {
        _is_shown = enable;
    }
    bool is_shown() const { return _is_shown; }

private:
    QPen    _pen;
    uint8_t _size;
    QFont   _font;
    QColor  _color;

    QFontMetrics _font_metrics;
    uint16_t _max_width;
    uint16_t _max_height;

    bool _is_shown;
};
