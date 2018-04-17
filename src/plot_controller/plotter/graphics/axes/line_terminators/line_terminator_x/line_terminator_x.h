#pragma once

#include "src/plot_controller/plotter/graphics/graphic_item.h"

class LineTerminatorX: private IGraphicItem
{
    static constexpr uint8_t DEFAULT_SIZE = 15;
    static constexpr uint8_t DEFAULT_RADIUS = 5;
    static constexpr float ARROW2_COEFF = 0.3;
    static constexpr float DELTA_ARROW_COEFF = 0.5;

public:
    LineTerminatorX();
    ~LineTerminatorX() = default;

    void replot(QPainter* painter, const QPolygonF& arrow_x, const QPolygonF& arrow_y);
    void replot(QPainter* painter, const QPointF& point);

    void set_ending_type(const LineTerminatorType type) { _ending_type = type; }
    LineTerminatorType get_ending_type() const { return _ending_type; }

    void set_ending_size(const uint8_t size) { _size = size; }
    uint8_t get_ending_size() const { return _size; }

private:
    void replot_thin_arrow(QPainter* painter, const QPointF& bottom_right);

    void replot_arrow(QPainter* painter, const QPointF& bottom_right);
    void replot_filled_arrow(QPainter* painter, const QPointF& bottom_right);

    void replot_arrow2(QPainter* painter, const QPointF& bottom_right);
    void replot_filled_arrow2(QPainter* painter, const QPointF& bottom_right);

    void replot_delta_arrow(QPainter* painter, const QPointF& bottom_right);
    void replot_filled_delta_arrow(QPainter* painter, const QPointF& bottom_right);




    void replot_circle(QPainter* painter, const QPointF& bottom_right);
    void replot_filled_circle(QPainter* painter, const QPointF& bottom_right);

    void replot_square(QPainter* painter, const QPointF& bottom_right);
    void replot_filled_square(QPainter* painter, const QPointF& bottom_right);

    void replot_diamond(QPainter* painter, const QPointF& bottom_right);
    void replot_filled_diamond(QPainter* painter, const QPointF& bottom_right);

    void replot_star(QPainter* painter, const QPointF& bottom_right);
    void replot_filled_star(QPainter* painter, const QPointF& bottom_right);


private:
    uint8_t            _size;
    uint8_t            _radius;
    LineTerminatorType _ending_type;
};

