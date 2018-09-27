#include "gradient_colors.h"

GradientColors::GradientColors()
{
    init_pairs();
}

GradientColors::GradientColors(const QColor color_a, const QColor color_b)
{
    init_pairs();

    _custom_pair.color_1 = color_a;
    _custom_pair.color_2 = color_b;
}

void GradientColors::set_pair(const GradientColorsPair pair)
{
    _custom_pair = pair;
}

void GradientColors::set_pair(const QColor color_a, const QColor color_b)
{
    _custom_pair.color_1 = color_a;
    _custom_pair.color_2 = color_b;
}

GradientColorsPair& GradientColors::pair(const GradientStyle& color_style)
{
    switch (color_style)
    {
    case GradientStyle::LIGHT_GRAY:
        _custom_pair = _light_gray;
        break;
    case GradientStyle::DARK_GRAY:
        _custom_pair = _dark_gray;
        break;

    default:
        return _custom_pair;
        break;
    }

    return _custom_pair;
}

void GradientColors::init_pairs()
{
    _light_gray = GradientColorsPair(Qt::white, QColor(220, 220, 220));
    _dark_gray = GradientColorsPair(QColor(240, 240, 240), QColor(180, 180, 180));

//    _light_red = ;
//    _dark_red;

//    _light_green;
//    _dark_green;
}
