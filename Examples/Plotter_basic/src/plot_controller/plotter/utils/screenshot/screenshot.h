#pragma once

#include <QFile>
#include <QPixmap>
#include <QString>

class Screenshot
{
public:
    Screenshot();
    ~Screenshot() = default;

public:
    void run(const QString& filename, const uint8_t scale_factor);

private:

private:
};
