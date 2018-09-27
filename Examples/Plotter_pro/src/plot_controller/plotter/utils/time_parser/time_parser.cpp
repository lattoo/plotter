#include "time_parser.h"

void TimeParser::parse_time(float time)
{
    time = floor(time * 10.0) / 10.0;

    const uint8_t hours = static_cast<uint8_t>(time / 3600);
    const uint8_t minutes = (static_cast<uint16_t>(time) % 3600) / 60;
    const uint8_t seconds = static_cast<uint16_t>(time) % 60;
    const uint8_t milliseconds = static_cast<uint8_t>(std::fmod((time * 10), 10));

    if(hours > 0)
    {
        if(number_of_digits(hours) == 1 || number_of_digits(hours) == 0)
            _time.hours = "0" + QString::number(hours);
        else
            _time.hours = QString::number(hours);
    }

    if(number_of_digits(minutes) == 1 || number_of_digits(minutes) == 0)
        _time.minutes = "0" + QString::number(minutes);
    else
        _time.minutes = QString::number(minutes);

    if(number_of_digits(seconds) == 1)
        _time.seconds = "0" + QString::number(seconds);
    else
        _time.seconds = QString::number(seconds);

    _time.milliseconds = QString::number(milliseconds);
}

uint8_t TimeParser::number_of_digits(const uint8_t number)
{
    return (number > 0 ? static_cast<uint8_t>(log10(number) + 1) : 0);
}
