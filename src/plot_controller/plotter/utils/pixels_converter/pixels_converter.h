#pragma once

class PixelsConverter
{
public:
    PixelsConverter();
    ~PixelsConverter() = default;

public:
    // template<typename T>
    // T rescale_to_x_pixels(const T x_value)
    // {
    //     const float dx = x_value - _x_min;
    //     return (_plot_area_borders.left() + (dx * (_plot_area_borders.width() - 1) / x_span()));
    // }

    // template<typename T>
    // T rescale_to_y_pixels(const T y_value)
    // {
    //     const float dy = y_value - _y_min;
    //     return (_plot_area_borders.bottom() - (dy * (_plot_area_borders.height() - 1) / y_span()));
    // }

    // template<typename T>
    // T rescale_to_x_coord(const T x_value)
    // {
    //     const float dx = x_value - _plot_area_borders.left();
    //     return (_x_min + (dx * x_span() / _plot_area_borders.width()));
    // }

    // template<typename T>
    // T rescale_to_y_coord(const T y_value)
    // {
    //     const float dy = y_value - _plot_area_borders.top();
    //     return (_y_max - (dy * y_span() / _plot_area_borders.height()));
    // }
private:

private:
};
