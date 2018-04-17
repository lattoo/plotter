#include "curve.h"

Curve::Curve()
    : _curve_data(0)
{
    enable_markers(false);
//    set_fill_type(DEFAULT_FILLING_TYPE);
    set_name("Chart");
}

Curve::Curve(const QString& chart_name)
    : _curve_data(0)
{
    enable_markers(false);
//    set_fill_type(DEFAULT_FILLING_TYPE);
    set_name(chart_name);
}

//Curve::Curve(const QString& chart_name, const QVector<QPointF>& curve_data)
//    : _curve_data(curve_data)
//{
//    enable_markers(false);
//    set_fill_type(DEFAULT_FILLING_TYPE);
//    set_name(chart_name);
//}

Curve::~Curve()
{
}

void Curve::replot(QPainter* painter, QPolygonF& polyline)
{
    replot_filling(painter, polyline);

    polyline.remove(0, 1);
    polyline.remove(polyline.size() - 1, 1);
    QPainterPath line_path;
    line_path.addPolygon(polyline);
    painter->drawPath(line_path);
    painter->setBrush(brush());
}

void Curve::replot_filling(QPainter* painter, QPolygonF& polyline)
{
    QPainterPath fill_path;

    set_gradient_area(QPointF(0, 0), QPointF(0, 500));

    fill_path.addPolygon(polyline);
    painter->setPen(pen());
    painter->setBrush(brush());
    painter->fillPath(fill_path, brush());
    painter->setBrush(Qt::NoBrush);
}

void Curve::add_data(const float x, const float y)
{
    _curve_data.push_back(QPointF(x, y));
}

void Curve::clear_data()
{
    _curve_data.clear();
}
