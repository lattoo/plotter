/*
 * erase_invisible_data(const float x);
find_plot_borders
set_zoom_region
parse_time
*/

#pragma once

#include <QString>

#include <cmath>

class Utils
{

    struct x_time
    {
        QString hours;
        QString minutes;
        QString seconds;
        QString milliseconds;

        x_time()
            : hours("")
            , minutes("")
            , seconds("")
            , milliseconds("")
        {}
    };

public:
    Utils();
    ~Utils() = default;

public:
    void parse_time(float time);
    x_time& time() { return _time; }

private:
    uint8_t number_of_digits(const uint8_t number);

private:
    x_time _time;
};
