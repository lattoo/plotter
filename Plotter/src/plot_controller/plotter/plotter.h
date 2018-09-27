#pragma once

#include <QContextMenuEvent>
#include <QMenu>

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QMap>
#include <QKeyEvent>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QFont>
#include <cassert>

#include <QtSvg/QSvgGenerator>
#include <QFileDialog>
#include <QDebug>
#include <QGraphicsItem>
#include <QMessageBox>

#include <algorithm>
#include <iterator>

#include "src/types.h"

// charts
#include "src/plot_controller/plotter/graphics/chart/chart_manager/chart_manager.h"
#include "src/plot_controller/plotter/graphics/chart/chart_manager/curve/curve.h"

// graphics
#include "src/plot_controller/plotter/graphics/background/background.h"
#include "src/plot_controller/plotter/graphics/plot_area/plot_area.h"
#include "src/plot_controller/plotter/graphics/axes/axes.h"
#include "src/plot_controller/plotter/graphics/grid/grid.h"


// text
#include "src/plot_controller/plotter/text/title/title.h"
#include "src/plot_controller/plotter/text/axes/axes.h"
#include "src/plot_controller/plotter/text/legend/legend.h"

// utils
#include "src/plot_controller/plotter/utils/time_parser/time_parser.h"

class Plotter : public QWidget
{
    Q_OBJECT

    static constexpr uint8_t WIDGET_MARGIN = 10u;
    static constexpr uint8_t AXES_EXTENSION = 5u;

    static constexpr size_t ERASE_BLOCK_SIZE = 100u;
    static constexpr size_t ERASE_SECONDS = 2;

public:
    Plotter(QWidget* parent = 0);
    ~Plotter() = default;

public slots:
    void recalculate_static_data();

private:
    void recalculate_data();

    void replot(QPainter* painter);

public:
    void set_type(const PlotterType type);


    void set_name(const QString& name) { _name = name; }
    QString& name() { return _name; }

private:
    QString _name;


public:
    //    void add_graph(const uint8_t graph_id, const QColor color = Qt::black, const QString name = "Graph");
    void delete_graph(const uint8_t graph_id);

public:
    void replot();

public:
    void rescale_y_axis();
    void rescale_x_axis();
    void scroll_graph();
    void scroll_x(const float dx);
    void erase_invisible_data(const float current_x);

public slots:
    void screenshot();

private:
    void find_plot_borders();

private:
    void update_zoom_region();

private slots:
    void zoom_out();

private:
    void zoom_in();
    void apply_zoom(const QRectF& zoom_rect);

private:
    //    void replot_markers();
    //    void replot_static();
    void replot_realtime();
    //    void replot_histogram();

private:
    template<typename T>
    T rescale_to_x_pixels(const T x_value)
    {
        const float dx = x_value - _x_min;
        return (_plot_area_borders.left() + (dx * (_plot_area_borders.width() - 1) / x_span()));
    }

    template<typename T>
    T rescale_to_y_pixels(const T y_value)
    {
        const float dy = y_value - _y_min;
        return (_plot_area_borders.bottom() - (dy * (_plot_area_borders.height() - 1) / y_span()));
    }

    template<typename T>
    T rescale_to_x_coord(const T x_value)
    {
        const float dx = x_value - _plot_area_borders.left();
        return (_x_min + (dx * x_span() / _plot_area_borders.width()));
    }

    template<typename T>
    T rescale_to_y_coord(const T y_value)
    {
        const float dy = y_value - _plot_area_borders.top();
        return (_y_max - (dy * y_span() / _plot_area_borders.height()));
    }

private:
    void replot_markers(QPainter* painter);
    void replot_curves(QPainter* painter);
    void replot_legend(QPainter* painter);

private:
    void replot_histogram(QPainter* painter);

protected:
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent* event) override;

private:
    QPixmap _pixmap;

private:
    QRect _plot_area_borders;

private:
    QRect _zoom_rectangle;

private:
    QVector<float> _x_ticks_vector;
    QVector<float> _y_ticks_vector;

private:
    bool _is_zoom_rectangle_active;
    uint8_t _current_zoom_index;
    QVector<QRectF> _zooms;

private:
    float _x_previous;

private:
    PlotterType _plot_type;












public:
    Curve* chart(const uint8_t index) const;
    Curve* chart(const QString name) const;
    void add_chart();
    void add_chart(const QString& name);
    bool remove_chart(const uint8_t index);
    void clear_charts();
    uint8_t charts_count() const { return _curves.size(); }
    QVector<Curve*> _curves;



public:
    void x_min(const float x_min) { _x_min = x_min; }
    void x_max(const float x_max) { _x_max = x_max; }
    void x_ticks(const uint8_t x_ticks) { _x_ticks_num = x_ticks; }

public:
    void y_min(const float y_min) { _y_min = y_min; }
    void y_max(const float y_max) { _y_max = y_max; }
    void y_ticks(const uint8_t y_ticks) { _y_ticks_num = y_ticks; }

public:
    float   x_min() const { return _x_min; }
    float   x_max() const { return _x_max; }
    uint8_t x_ticks() const { return _x_ticks_num; }

public:
    float y_min() const { return _y_min; }
    float y_max() const { return _y_max; }
    uint8_t y_ticks() const { return _y_ticks_num; }

public:
    float x_span() const { return _x_max - _x_min; }
    float y_span() const { return _y_max - _y_min; }

private:
    float _x_min;
    float _x_max;
    uint8_t _x_ticks_num;

private:
    float _y_min;
    float _y_max;
    uint8_t _y_ticks_num;

public:
    QColor& background_color() { return _background_color; }

private:
    QColor _background_color;


    void scroll(const float dx, const float dy);

public:
    bool autoticks() const { return _autoticks; }
    void set_autoticks(const bool enabled = true) { _autoticks = enabled; }

private:
    bool _autoticks;
    bool _is_time_on_x_axis;
    bool _is_show_legend;

private:
    void update_borders_data();
    void update_margins_data();
    void update_background_data();
    void update_grid_data();

    void update_grid_x_data();
    void update_grid_y_data();
    void update_subgrid_x_data();
    void update_subgrid_y_data();

    void update_arrows_data();
    void update_axes_ticks_data();
    void update_axes_main_ticks_data();
    void update_axes_sub_ticks_data();
    
    void update_axis_y_data();
    void update_zero_lines_data();

    void update_x_axis_labels_data();
    void update_y_axis_labels_data();

    void update_x_axis_title_data();
    void update_y_axis_title_data();

public:
    Axes&       axes() { return _axes; }
    AxesText&   axes_text() { return _axes_text; }
    Grid&       grid() { return _grid; }
    LegendText& legend_text() { return _legend_text; }
    Title&      title() { return _title; }
    PlotArea&   plot_area() { return _borders; }
    Background& background() { return _background; }

private:
    Title    _title;
    Axes     _axes;
    Grid     _grid;
    Marker   _marker;
    PlotArea _borders;
    Background _background;

    AxesText   _axes_text;
    LegendText _legend_text;

private:
    QLineF _x_zero_line;
    QLineF _y_zero_line;

    QStringList      _x_axis_labels;
    QStringList      _y_axis_labels;
    QVector<QPointF> _x_axis_labels_points;
    QVector<QPointF> _y_axis_labels_points;

    QPointF _x_axis_title_point;
    QPointF _y_axis_title_point;

    QVector<QLineF> _x_ticks_main_grid;
    QVector<QLineF> _y_ticks_main_grid;
    QVector<QLineF> _x_ticks_sub_grid;
    QVector<QLineF> _y_ticks_sub_grid;
    QVector<QPointF> _x_ticks_pf;
    QVector<QPointF> _y_ticks_pf;
    QVector<QPointF> _x_subticks_pf;
    QVector<QPointF> _y_subticks_pf;

    QPointF _background_bottom_right;

public:
    ChartManager& chart_manager() { return _manager; }

private:
    ChartManager _manager;

    TimeParser _time_parser;

////////////////////////////////
// contextMenu
////////////////////////////////
private:
    void contextMenuEvent(QContextMenuEvent *event);
    QMenu    _context_menu;
    QAction* _act_zoom_out;
    QAction* _act_screenshot;
    QAction* _act_save;
    QAction* _act_open;


// margins
private:
    uint8_t _widget_margin;
    uint8_t _main_title_margin;
    uint8_t _legend_margin;
    uint8_t _labels_x_margin;
    uint8_t _labels_y_margin;
    uint8_t _title_x_margin;
    uint8_t _title_y_margin;
};
