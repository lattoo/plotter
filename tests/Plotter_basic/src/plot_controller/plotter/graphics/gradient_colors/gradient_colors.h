#pragma once

#include "src/types.h"

using namespace GradientTypes;

class GradientColors
{
public:
    GradientColors();
    GradientColors(const QColor color_a, const QColor color_b);
    ~GradientColors() = default;

public:
    void set_pair(const GradientColorsPair pair);
    void set_pair(const QColor color_a, const QColor color_b);

    GradientColorsPair& pair(const GradientStyle& color_style);
    GradientColorsPair  pair() const { return _custom_pair; }

private:
    void init_pairs();

private:
    GradientColorsPair _custom_pair;

    GradientColorsPair _light_gray;
    GradientColorsPair _dark_gray;

    GradientColorsPair _light_red;
    GradientColorsPair _dark_red;

    GradientColorsPair _light_green;
    GradientColorsPair _dark_green;
};
