#pragma once

#include <QColor>
#include <QPainter>
#include <QPen>
#include <QPointF>
#include <QVector>

#include "src/types.h"

#include "src/plot_controller/plotter/graphics/filled_item.h"
#include "src/plot_controller/plotter/graphics/chart/chart_manager/marker/marker.h"

class IChart : public IFilledItem
{
    static constexpr uint8_t MARKER_SIZE = 8u;
    static constexpr MarkerType DEFAULT_MARKER_TYPE = MarkerType::DISABLED;

public:
    IChart()
    {
        _marker_type = DEFAULT_MARKER_TYPE;
        _marker_size = MARKER_SIZE;
    }
    ~IChart() = default;

public:
    void add_data(const float x, const float y);
    void clear_data();

    void set_name(const QString& name) { _name = name; }
    QString name() const { return _name; }

public:
    void set_marker_type(const MarkerType type) { _marker_type = type; }
    void set_marker_size(const uint8_t size) { _marker_size = size; }

public:
    void enable_markers(const bool enable) { _enable_markers = enable; }

public:
    MarkerType marker_type() const { return _marker_type; }
    uint8_t marker_size() const { return _marker_size; }

    Marker marker() { return _marker; }

public:
    bool are_markers_enabled() const { return _enable_markers; }

private:
    QPen _pen;
    QString _name;

    Marker _marker;
    MarkerType _marker_type;
    uint8_t _marker_size;
    bool _enable_markers;
};
