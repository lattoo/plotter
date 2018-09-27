#include "screenshot.h"

Screenshot::Screenshot()
{
}

void Screenshot::run(const QString& filename, const uint8_t scale_factor)
{
    QPixmap screenshot_pixmap;
    QFile screenshot(filename);

//    const uint16_t prev_width = width();
//    const uint16_t prev_height = height();

//    resize(prev_width * scale_factor, prev_height * scale_factor);
//    screenshot_pixmap = _pixmap;
//    screenshot.open(QIODevice::WriteOnly);
//    screenshot_pixmap.save(&screenshot, "PNG", -1);
//    resize(prev_width, prev_height);
}
