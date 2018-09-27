#pragma once

#include "src/plot_controller/plotter/text/text_item.h"

class ITitleItem : public ITextItem
{
public:
    ITitleItem()
        : _text("Default Name")
    {}
    ~ITitleItem() = default;

public:
    void set_text(const QString& text) { _text = text; }
    QString& text() { return _text; }

private:
    QString _text;
};
