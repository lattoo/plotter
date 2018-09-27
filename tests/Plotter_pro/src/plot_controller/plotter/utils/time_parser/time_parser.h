#pragma once

#include <QString>

#include <cmath>

class TimeParser
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
    TimeParser() = default;
    ~TimeParser() = default;

public:
    void parse_time(float data);
    x_time& data() { return _time; }

private:
    uint8_t number_of_digits(const uint8_t number);

private:
    x_time _time;
};
