#pragma once

#include <cstdint>
#include <QColor>

enum class PlotterType : uint8_t
{
    Cuvre,
    Bar,
    Pie
};

enum class ChartType : uint8_t
{
    Cuvre,
    Bar,
    Pie
};

enum MarkerType : uint8_t
{
    DISABLED,
    CROSS,
    PLUS,
    CIRCLE,
    FILLED_CIRCLE,
    DIAMOND,
    FILLED_DIAMOND,
    SQUARE,
    FILLED_SQUARE,
    STAR,
    TRIANGLE,
    FILLED_TRIANGLE,
    TRIANGLE2,
    FILLED_TRIANGLE2
};

namespace LineTerminatorTypes
{
    enum class LineTerminatorType : uint8_t
    {
        DISABLED,

        THIN_ARROW,

        ARROW,
        FILLED_ARROW,
        ARROW2,
        FILLED_ARROW2,
        DELTA_ARROW,
        FILLED_DELTA_ARROW,

        CIRCLE,
        FILLED_CIRCLE,
        SQUARE,
        FILLED_SQUARE,

        DIAMOND,
        FILLED_DIAMOND,
        STAR,
        FILLED_STAR
    };
}

namespace TickTypes
{
    enum class TickType : uint8_t
    {
        DISABLED,
        INTERNAL_SINGLE_SIDED,
        SINGLE_SIDED,
        DOUBLE_SIDED
    };

    static constexpr TickType DEFAULT_TICK_TYPE = TickType::SINGLE_SIDED;
    static constexpr TickType DEFAULT_SUB_TICK_TYPE = TickType::SINGLE_SIDED;

    static constexpr uint8_t DEFAULT_TICK_SIZE = 6;
    static constexpr uint8_t DEFAULT_SUB_TICK_SIZE = 3;
}

namespace GradientTypes
{
    // delete me
    struct GradientColorsPair
    {
        QColor color_1;
        QColor color_2;

        GradientColorsPair() = default;

        GradientColorsPair(const QColor color_a, const QColor color_b)
            : color_1(color_a)
            , color_2(color_b)
        {}
    };

    enum class GradientDirection : uint8_t
    {
        DISABLED,
        VERTICAL,
        HORIZONTAL
    };

    // delete me
    enum class GradientStyle : uint8_t
    {
        LIGHT_GRAY,
        DARK_GRAY,

        LIGHT_RED,
        DARK_RED,

        LIGHT_GREEN,
        DARK_GREEN
    };
}

// fix bug with smaller UPDATE_TIME
static constexpr uint8_t UPDATE_TIME_MS = 50;
