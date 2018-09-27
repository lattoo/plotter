#include "plotter.h"

Plotter::Plotter(QWidget* parent)
    : QWidget(parent)
    , _is_zoom_rectangle_active(false)
    , _current_zoom_index(0)
    , _x_previous(0)
    , _plot_type(PlotterType::Cuvre)
    , _x_min(0.0)
    , _x_max(20.0)
    , _x_ticks_num(5)
    , _y_min(0.0)
    , _y_max(10.0)
    , _y_ticks_num(4)
    , _autoticks(true)
    , _is_show_legend(true)
    , _background_color(Qt::white)
    , _widget_margin(WIDGET_MARGIN)
    , _main_title_margin(0)
    , _legend_margin(0)
    , _labels_x_margin(0)
    , _labels_y_margin(0)
    , _title_x_margin(0)
    , _title_y_margin(0)
{
    //    _grid_pen.setStyle(Qt::DotLine);
    //    _axes_pen.setStyle(Qt::SolidLine);
    setBackgroundRole(QPalette::Light);
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFocusPolicy(Qt::StrongFocus);


    // track the cursor by default
    setMouseTracking(true);


    _manager.create_chart<Curve>();


    _act_screenshot = new QAction(tr("Save screenshot"), this);
    // doesn't work because not in mainwindow (I think so)
    //    _act_screenshot->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    _act_screenshot->setStatusTip(tr("Make a screenshot "));
    connect(_act_screenshot, SIGNAL(triggered(bool)), this, SLOT(screenshot()));

    _act_open = new QAction(tr("Open"), this);
    //    _act_open->setShortcuts(QKeySequence::Open);
    _act_open->setStatusTip(tr("Open an existing file"));
    connect(_act_open, SIGNAL(triggered(bool)), this, SLOT(screenshot()));

    _act_zoom_out = new QAction(tr("Zoom out"), this);
    _act_zoom_out->setStatusTip(tr("Zoom out"));
    connect(_act_zoom_out, SIGNAL(triggered(bool)), this, SLOT(zoom_out()));

    _context_menu.addAction(_act_screenshot);
    _context_menu.addAction(_act_open);
    _context_menu.addAction(_act_zoom_out);
}

void Plotter::recalculate_data()
{
    //    update_borders_data();

    //    update_margins_data();





    //    update_background_data();

    //    update_grid_x_data();
    //    update_subgrid_x_data();

    //    update_grid_y_data();
    //    update_subgrid_y_data();

    //    update_zero_lines_data();

    //    update_axes_main_ticks_data();
    //    update_axes_sub_ticks_data();

    //    update_x_axis_labels_data();
    //    update_y_axis_labels_data();

    //    update_x_axis_title_data();
    //    update_y_axis_title_data();



    update_margins_data();

    update_borders_data();

    update_background_data();

    update_grid_x_data();
    update_subgrid_x_data();

    update_grid_y_data();
    update_subgrid_y_data();

    update_zero_lines_data();

    update_axes_main_ticks_data();
    update_axes_sub_ticks_data();

    update_arrows_data();

    update_x_axis_labels_data();
    update_y_axis_labels_data();

    update_x_axis_title_data();
    update_y_axis_title_data();
}

void Plotter::replot(QPainter* painter)
{
    recalculate_data();

    _background.replot(painter, QPointF(width(), height()));

    _borders.replot(painter, _plot_area_borders);

    _grid.main_grid().grid_x().replot(painter, _x_ticks_main_grid);
    _grid.main_grid().grid_y().replot(painter, _y_ticks_main_grid);

    _grid.sub_grid().grid_x().replot(painter, _x_ticks_sub_grid);
    _grid.sub_grid().grid_y().replot(painter, _y_ticks_sub_grid);

    QPointF top_left(_plot_area_borders.left(), _plot_area_borders.top() - AXES_EXTENSION);
    QPointF bottom_right(_plot_area_borders.right() + AXES_EXTENSION, _plot_area_borders.bottom());
    _axes.terminators().terminator_x().replot(painter, bottom_right);
    _axes.terminators().terminator_y().replot(painter, top_left);

    _axes.ticks().main_ticks().ticks_x().replot(painter, _x_ticks_pf);
    _axes.ticks().main_ticks().ticks_y().replot(painter, _y_ticks_pf);
    _axes.ticks().sub_ticks().sub_ticks_x().replot(painter, _x_subticks_pf);
    _axes.ticks().sub_ticks().sub_ticks_y().replot(painter, _y_subticks_pf);

    _axes.zero_lines().line_x().replot(painter, _x_zero_line);
    _axes.zero_lines().line_y().replot(painter, _y_zero_line);

    //    // main title
    QPointF p(width()/2, _widget_margin / 2);
    _title.replot(painter, p);

    // axes text
    // labels
    _axes_text.label().axis_x().replot(painter, _x_axis_labels_points, _x_axis_labels);
    _axes_text.label().axis_y().replot(painter, _y_axis_labels_points, _y_axis_labels);
    // titles
    _axes_text.title().title_x().replot(painter, _x_axis_title_point);
    _axes_text.title().title_y().replot(painter, _y_axis_title_point);

    replot_legend(painter);

    replot_markers(painter);
    replot_curves(painter);
    update();
}

void Plotter::set_type(const PlotterType type)
{
    _plot_type = type;
}

void Plotter::delete_graph(const uint8_t graph_id)
{
    _curves.remove(graph_id);
    replot();
}

void Plotter::scroll(const float dx, const float dy)
{
    const float x_step = x_span() / _x_ticks_num;
    _x_min = _x_min + dx * x_step;
    _x_max = _x_max + dx * x_step;

    const float y_step = y_span() / _y_ticks_num;
    _y_min = _y_min + dy * y_step;
    _y_max = _y_max + dy * y_step;
}

void Plotter::recalculate_static_data()
{
    update_background_data();

    update_grid_x_data();
    update_subgrid_x_data();

    update_grid_y_data();
    update_subgrid_y_data();

    update_zero_lines_data();

    update_axes_main_ticks_data();
    update_axes_sub_ticks_data();

    update_x_axis_labels_data();
    update_y_axis_labels_data();

    update_x_axis_title_data();
    update_y_axis_title_data();
}

void Plotter::update_borders_data()
{
    _plot_area_borders = QRect(3 * _widget_margin + _title_y_margin + _labels_y_margin
                               , _widget_margin + _main_title_margin + _legend_margin + _widget_margin/2
                               , width() - 2 * (3 * _widget_margin + _title_y_margin) - _labels_y_margin
                               , height() - 2 * _widget_margin - _main_title_margin - _title_x_margin - _legend_margin - _labels_x_margin - _widget_margin/2);
}

void Plotter::update_margins_data()
{
    _main_title_margin = _title.max_text_height();

    _legend_margin   = _legend_text.max_text_height();

    _labels_x_margin = _axes_text.label().axis_x().max_text_height();
    _labels_y_margin = _axes_text.label().axis_y().max_text_width();

    _title_x_margin  = _axes_text.title().title_x().max_text_height();
    _title_y_margin  = _axes_text.title().title_y().max_text_height();
}

void Plotter::update_background_data()
{
    _background_bottom_right = QPointF(height(), width());
}

void Plotter::scroll_graph()
{
    if(!_curves.size())
        return;

    const size_t size = _curves.at(0)->data().size();
    const float x_current = _curves.at(0)->data().at(size - 1).x();
    const float dx = x_current - _x_previous;

    // scroll graph
    if(_x_max <= x_current)
        scroll_x(dx);

    _x_previous = x_current;
}

void Plotter::scroll_x(const float dx)
{
    _x_min += dx;
    _x_max += dx;
}

void Plotter::replot()
{
    _pixmap = QPixmap(size());
    _pixmap.fill(Qt::transparent);
    QPainter painter(&_pixmap);
    replot(&painter);

    //    if(_plot_type == TYPE::MARKERS)
    //        replot_markers();
    //    if(_plot_type == TYPE::STATIC)
    //        replot_static();
    //    if(_plot_type == PlotterType::Cuvre)
    //        replot_realtime();
    //    if(_plot_type == TYPE::HISTOGRAM)
    //        replot_histogram();
}

void Plotter::update_zoom_region()
{
    QRect rect = _zoom_rectangle.normalized();
    update(rect.left(), rect.top(), rect.width(), 1);
    update(rect.left(), rect.top(), 1, rect.height());
    update(rect.left(), rect.bottom(), rect.width(), 1);
    update(rect.right(), rect.top(), 1, rect.height());
}

void Plotter::zoom_in()
{
    if (_current_zoom_index < _zooms.count() - 1)
    {
        _current_zoom_index++;
        apply_zoom(_zooms[_current_zoom_index]);
        replot();
    }
}

void Plotter::zoom_out()
{
    if (_current_zoom_index > 0)
    {
        _current_zoom_index--;
        if (_current_zoom_index > 0)
            apply_zoom(_zooms[_current_zoom_index]);
        replot();
    }
    if(_current_zoom_index == 0)
    {
        find_plot_borders();
        replot();
    }
}

void Plotter::apply_zoom(const QRectF& zoom_rect)
{
    _x_min = zoom_rect.topLeft().x();
    _y_min = zoom_rect.topLeft().y();
    _x_max = zoom_rect.bottomRight().x();
    _y_max = zoom_rect.bottomRight().y();
}

void Plotter::replot_realtime()
{
    _pixmap = QPixmap(size());
    _pixmap.fill(Qt::transparent);
    QPainter painter(&_pixmap);
    replot(&painter);
}

void Plotter::find_plot_borders()
{
    //    Q_ASSERT(_curve_map.size() > 0);

    _x_max = std::numeric_limits<int16_t>::min();
    _x_min = std::numeric_limits<int16_t>::max();
    _y_max = std::numeric_limits<int16_t>::min();
    _y_min = std::numeric_limits<int16_t>::max();

    const size_t size = _curves.size();

    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < _curves.at(i)->data().size(); j++)
        {
            if(_y_max < _curves.at(i)->data().at(j).y())
                _y_max = _curves.at(i)->data().at(j).y();
            if(_y_min > _curves.at(i)->data().at(j).y())
                _y_min = _curves.at(i)->data().at(j).y();

            if(_x_max < _curves.at(i)->data().at(j).x())
                _x_max = _curves.at(i)->data().at(j).x();
            if(_x_min > _curves.at(i)->data().at(j).x())
                _x_min = _curves.at(i)->data().at(j).x();
        }
    }
}

//void Plotter::erase_invisible_data(const float current_x)
//{
//    for (uint8_t i = 0; i < _curves.size(); i++)
//    {
//        // ??? magic numbers ???
//        if(_curves.at(i)->data().size() < 3)
//            continue;

//        const auto before = _curves.at(i)->data().size();

//        const auto end = _curves.at(i)->data().end();
//        for(uint8_t j = 0; j < _curves.at(i)->data().size(); j++)
//        {
//            auto it = _curves.at(i)->data().begin();
//            const auto dx = _curves.at(i)->data().at(2).x() - _curves.at(i)->data().at(0).x();
////            qDebug() << dx;
//// todo
////            if(dx > ERASE_BLOCK_SIZE)
//            {
//                while ((it != end) && (it->x() < (current_x - dx)))
//                    it = _curves.at(i)->data().erase(it);

//                const auto after = _curves.at(i)->data().size();
//                qDebug() << before << after;
//            }
//        }
//    }
//}


void Plotter::erase_invisible_data(const float current_x)
{
    // todo
    // 1) if data size > MAX_SIZE (should be calculated)
    // 2) get x_min value
    // 3) find x_min value in the vector (it is a little bit complicated bcz vector is two-dimensional (QPointF))
    // 4) Erase everithing from x0 to x_min (vector.begin() to x_min_index)

    for (uint8_t i = 0; i < _curves.size(); i++)
    {
        const auto current_data_size = _curves.at(i)->data().size();

        // ??? magic numbers ???
        if(current_data_size < 3)
            continue;

        const float SECS_TO_ERASE = 0.1;
        if(current_x > 0 && ((current_x - _curves.at(i)->data().at(0).x()) > SECS_TO_ERASE))
        {
            for(auto j = 0; j < current_data_size; j++)
            {
                // used to find index
                if(fabs(_curves.at(i)->data().at(j).x() - current_x) < 0.05)
                {
                    const uint16_t index = j;

                    _curves.at(i)->data().erase(_curves.at(i)->data().begin(), _curves.at(i)->data().begin() + index);

                    return;
                }
            }
        }
    }
}

void Plotter::rescale_y_axis()
{
    _y_max = std::numeric_limits<int16_t>::min();
    _y_min = std::numeric_limits<int16_t>::max();

    const size_t size = _curves.size();

    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < _curves.at(i)->data().size(); j++)
        {
            if(_y_max < _curves.at(i)->data().at(j).y())
                _y_max = _curves.at(i)->data().at(j).y();
            if(_y_min > _curves.at(i)->data().at(j).y())
                _y_min = _curves.at(i)->data().at(j).y();
        }
    }
    //    _y_max += 5;
    //    _y_min -= 5;
}

void Plotter::rescale_x_axis()
{
    _x_max = std::numeric_limits<int16_t>::min();
    _x_min = std::numeric_limits<int16_t>::max();

    const size_t size = _curves.size();

    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < _curves.at(i)->data().size(); j++)
        {
            if(_x_max < _curves.at(i)->data().at(j).x())
                _x_max = _curves.at(i)->data().at(j).x();
            if(_x_min > _curves.at(i)->data().at(j).x())
                _x_min = _curves.at(i)->data().at(j).x();
        }
    }
}

void Plotter::update_grid_data()
{
    if (!_plot_area_borders.isValid())
        return;

    _x_ticks_main_grid.clear();
    _y_ticks_main_grid.clear();
    _x_ticks_sub_grid.clear();
    _y_ticks_sub_grid.clear();

    if(_autoticks)
    {
        _x_ticks_num = width() * 0.005;
        _y_ticks_num = height() * 0.015;
    }

    // x-axis
    const size_t size_x_ticks = _x_ticks_num;

    for (uint8_t i = 0; i <= size_x_ticks; i++)
    {
        const uint16_t single_step = (_plot_area_borders.width() - 1) / _x_ticks_num;
        const float x = _plot_area_borders.left() + (i * _plot_area_borders.width() - 1) / _x_ticks_num;
        const float x_secondary = _plot_area_borders.left() + (0.5f + i) * single_step;

        _x_ticks_main_grid.push_back(QLineF(x, _plot_area_borders.top(),
                                            x, _plot_area_borders.bottom()));

        if(i == size_x_ticks)
            continue;
        _x_ticks_sub_grid.push_back(QLineF(x_secondary, _plot_area_borders.top(),
                                           x_secondary, _plot_area_borders.bottom()));
    }

    // y-axis
    const size_t size_y_ticks = _y_ticks_num;

    for (uint8_t i = 0; i <= size_y_ticks; i++)
    {
        const uint16_t single_step = (_plot_area_borders.height() - 1) / _y_ticks_num;
        const float y = _plot_area_borders.bottom() - (i * (_plot_area_borders.height() - 1) / _y_ticks_num);
        const float y_secondary = _plot_area_borders.bottom() - (0.5f + i) * single_step;

        _y_ticks_main_grid.push_back(QLineF(_plot_area_borders.left(), y,
                                            _plot_area_borders.right(), y));

        if(i == size_y_ticks)
            continue;
        _y_ticks_sub_grid.push_back(QLineF(_plot_area_borders.left(), y_secondary,
                                           _plot_area_borders.right(), y_secondary));
    }
}

void Plotter::update_grid_x_data()
{
    if (!_plot_area_borders.isValid())
        return;

    _x_ticks_main_grid.clear();

    if(_autoticks)
        _x_ticks_num = width() * 0.005;

    const size_t size_x_ticks = _x_ticks_num;

    for (uint8_t i = 0; i <= size_x_ticks; i++)
    {
        const float x = _plot_area_borders.left() + (i * _plot_area_borders.width() - 1) / _x_ticks_num;
        _x_ticks_main_grid.push_back(QLineF(x, _plot_area_borders.top(),
                                            x, _plot_area_borders.bottom()));
    }
}

void Plotter::update_grid_y_data()
{
    if (!_plot_area_borders.isValid())
        return;

    _y_ticks_main_grid.clear();

    if(_autoticks)
        _y_ticks_num = height() * 0.02;

    const size_t size_y_ticks = _y_ticks_num;

    for (uint8_t i = 0; i <= size_y_ticks; i++)
    {
        const float y = _plot_area_borders.bottom() - (i * (_plot_area_borders.height() - 1) / _y_ticks_num);
        _y_ticks_main_grid.push_back(QLineF(_plot_area_borders.left(), y,
                                            _plot_area_borders.right(), y));
    }
}

void Plotter::update_subgrid_x_data()
{
    _x_ticks_sub_grid.clear();

    const size_t size_x_ticks = _x_ticks_num;

    for (uint8_t i = 0; i <= size_x_ticks; i++)
    {
        const float x_sub = _plot_area_borders.left() + (0.5f + i) * (_plot_area_borders.width() - 1) / _x_ticks_num;

        if(i == size_x_ticks)
            continue;
        _x_ticks_sub_grid.push_back(QLineF(x_sub, _plot_area_borders.top(),
                                           x_sub, _plot_area_borders.bottom()));
    }
}

void Plotter::update_subgrid_y_data()
{
    _y_ticks_sub_grid.clear();

    const size_t size_y_ticks = _y_ticks_num;

    for (uint8_t i = 0; i <= size_y_ticks; i++)
    {
        const float y_sub = _plot_area_borders.bottom() - (0.5f + i) * (_plot_area_borders.height() - 1) / _y_ticks_num;

        if(i == size_y_ticks)
            continue;
        _y_ticks_sub_grid.push_back(QLineF(_plot_area_borders.left(), y_sub,
                                           _plot_area_borders.right(), y_sub));
    }
}

void Plotter::update_arrows_data()
{
}

void Plotter::update_axes_ticks_data()
{
    if(!_x_ticks_main_grid.size()
            || !_y_ticks_main_grid.size()
            || !_x_ticks_sub_grid.size()
            || !_y_ticks_sub_grid.size())
        return;

    _x_ticks_pf.clear();
    _y_ticks_pf.clear();

    _x_subticks_pf.clear();
    _y_subticks_pf.clear();

    for (uint8_t i = 0; i < _x_ticks_main_grid.size(); i++)
        _x_ticks_pf.push_back(QPointF(_x_ticks_main_grid.at(i).x1(), _plot_area_borders.bottom()));

    for (uint8_t i = 0; i < _y_ticks_main_grid.size(); i++)
        _y_ticks_pf.push_back(QPointF(_plot_area_borders.left(), _y_ticks_main_grid.at(i).y1()));

    for(uint8_t i = 0; i < _x_ticks_sub_grid.size(); i++)
        _x_subticks_pf.push_back(QPointF(_x_ticks_sub_grid.at(i).x1(), _plot_area_borders.bottom()));

    for(uint8_t i = 0; i < _y_ticks_sub_grid.size(); i++)
        _y_subticks_pf.push_back(QPointF(_plot_area_borders.left(), _y_ticks_sub_grid.at(i).y1()));
}

void Plotter::update_axes_main_ticks_data()
{
    if(_x_ticks_main_grid.size() == 0 || _y_ticks_main_grid.size() == 0)
        return;

    _x_ticks_pf.clear();
    _y_ticks_pf.clear();

    for (uint8_t i = 0; i < _x_ticks_main_grid.size(); i++)
        _x_ticks_pf.push_back(QPointF(_x_ticks_main_grid.at(i).x1(), _plot_area_borders.bottom()));

    for (uint8_t i = 0; i < _y_ticks_main_grid.size(); i++)
        _y_ticks_pf.push_back(QPointF(_plot_area_borders.left(), _y_ticks_main_grid.at(i).y1()));
}

void Plotter::update_axes_sub_ticks_data()
{
    if(_x_ticks_sub_grid.size() == 0 || _y_ticks_sub_grid.size() == 0)
        return;

    _x_subticks_pf.clear();
    _y_subticks_pf.clear();

    for(uint8_t i = 0; i < _x_ticks_sub_grid.size(); i++)
        _x_subticks_pf.push_back(QPointF(_x_ticks_sub_grid.at(i).x1(), _plot_area_borders.bottom()));

    for(uint8_t i = 0; i < _y_ticks_sub_grid.size(); i++)
        _y_subticks_pf.push_back(QPointF(_plot_area_borders.left(), _y_ticks_sub_grid.at(i).y1()));
}

void Plotter::update_zero_lines_data()
{
    _x_zero_line = QLineF(_plot_area_borders.left(), _plot_area_borders.bottom(),
                          _plot_area_borders.right() + AXES_EXTENSION, _plot_area_borders.bottom());
    _y_zero_line = QLineF(_plot_area_borders.left(), _plot_area_borders.top() - AXES_EXTENSION,
                          _plot_area_borders.left(), _plot_area_borders.bottom());
}

void Plotter::update_x_axis_labels_data()
{
    if(_x_ticks_main_grid.size() == 0)
        return;

    _x_axis_labels.clear();
    _x_axis_labels_points.clear();

    for (uint8_t i = 0; i < _x_ticks_main_grid.size(); i++)
    {
        QString label_to_print;
        float label = _x_min + (i * x_span() / _x_ticks_num);

        if(_is_time_on_x_axis)
        {
            _time_parser.parse_time(label);
            if(_time_parser.data().hours > 0)
                label_to_print = _time_parser.data().hours
                        + ":"
                        + _time_parser.data().minutes
                        + ":"
                        + _time_parser.data().seconds
                        + "."
                        + _time_parser.data().milliseconds;
            else
                label_to_print = _time_parser.data().minutes
                        + ":"
                        + _time_parser.data().seconds
                        + "."
                        + _time_parser.data().milliseconds;
        }
        else
            label_to_print = QString::number(label);

        _x_axis_labels_points.push_back(QPointF(_x_ticks_main_grid.at(i).x1(), _plot_area_borders.bottom()));
        _x_axis_labels.push_back(label_to_print);
    }
}

void Plotter::update_y_axis_labels_data()
{
    if(_y_ticks_main_grid.size() == 0)
        return;

    _y_axis_labels.clear();
    _y_axis_labels_points.clear();

    for (uint8_t i = 0; i < _y_ticks_main_grid.size(); i++)
    {
        float label_to_print = _y_min + (i * y_span() / _y_ticks_num);
        label_to_print = floor(label_to_print * 10.0) / 10.0;

        _y_axis_labels_points.push_back(QPointF(_plot_area_borders.left(), _y_ticks_main_grid.at(i).y1()));
        _y_axis_labels.push_back(QString::number(label_to_print));
    }
}

void Plotter::update_x_axis_title_data()
{
    _x_axis_title_point = QPointF(_widget_margin + _title_y_margin + _labels_y_margin + (_plot_area_borders.topRight().x() - _plot_area_borders.topLeft().x()) / 2
                                  , _plot_area_borders.bottom() + _labels_x_margin + _widget_margin);
}

void Plotter::update_y_axis_title_data()
{
    _y_axis_title_point = QPointF(_widget_margin/2
                                  , _widget_margin + _main_title_margin + _legend_margin
                                  + (_plot_area_borders.bottomLeft().y() - _plot_area_borders.topLeft().y()) / 2);
}

void Plotter::contextMenuEvent(QContextMenuEvent *event)
{
    _context_menu.exec(event->globalPos());
}

void Plotter::replot_markers(QPainter* painter)
{        
    if (!_plot_area_borders.isValid())
        return;

    painter->setClipRect(_plot_area_borders.adjusted(+1, +1, -1, -1));

    for(const auto& curves: _curves)
    {
        if(curves->data().empty())
            return;

        const auto data = curves->data();
        const auto number_of_data_points = curves->data().size();
        MarkerType marker_type = curves->marker_type();
        uint8_t marker_size = curves->marker_size();

        painter->setPen(curves->pen());
        // rescale data values to pixels
        for (uint16_t i = 0; i < number_of_data_points; i++)
        {
            const float x = rescale_to_x_pixels(data[i].x());
            const float y = rescale_to_y_pixels(data[i].y());
            _marker.replot(painter, marker_type, marker_size, x, y);
        }
    }
}

void Plotter::replot_curves(QPainter* painter)
{
    if (!_plot_area_borders.isValid())
        return;

    painter->setClipRect(_plot_area_borders.adjusted(+1, +1, -1, -1));

    for(const auto& curve: _curves)
    {
        if(curve->data().empty() || curve->data().size() < 2)
            return;


        const auto data = curve->data();
        QPolygonF polyline(data.size() + 1);

        // start points for QPainterPath
        polyline[0] = QPointF(rescale_to_x_pixels(data[0].x())
                , rescale_to_y_pixels(0.0f));
        polyline[1] = QPointF(rescale_to_x_pixels(data[0].x())
                , rescale_to_y_pixels(data[1].y()));

        // rescale data values to pixels
        for (uint16_t i = 2; i < data.size(); i++)
        {
            const float x = rescale_to_x_pixels(data[i].x());
            const float y = rescale_to_y_pixels(data[i].y());

            polyline[i] = QPointF(x, y);
        }

        // end point for QPainterPath
        polyline[data.size()] = QPointF(rescale_to_x_pixels(data[data.size()-1].x())
                , rescale_to_y_pixels(0.0));

        curve->replot(painter, polyline);
    }
}

void Plotter::replot_legend(QPainter* painter)
{
    if(!_is_show_legend)
        return;

    const uint16_t legend_step = (_plot_area_borders.topRight().x() - _plot_area_borders.topLeft().x()) / (_curves.size());
    const uint8_t size = _legend_text.max_text_height()/2;
    const uint8_t x_margin = _widget_margin + _title_y_margin + _labels_y_margin;

    for(const auto& charts: _curves)
    {
        if(charts->data().empty())
            return;

        // start with index = 1
        const uint8_t current_index = &charts - _curves.begin() + 1;

        // legend rect
        const QRect legend_borders = QRect(x_margin + current_index * legend_step
                                           , _widget_margin + _main_title_margin
                                           , size * 2
                                           , size * 2);

        painter->fillRect(legend_borders, charts->pen().color());

        _legend_text.replot(painter
                            , QPointF(legend_borders.right(), legend_borders.top())
                            , charts->name()
                            , charts->pen().color());
    }
}

void Plotter::replot_histogram(QPainter* painter)
{
    if (!_plot_area_borders.isValid())
        return;

    float x_left = 0;
    float x_right = 0;

    const float y_bottom = 0;
    float y_top = 0;

    float y_top_max = 0;
    const uint16_t y_top_span = y_span() / 10;

    for(const auto& charts: _curves)
    {
        if(charts->data().empty())
            return;

        const auto data = charts->data();

        uint16_t y_max_f = std::numeric_limits<uint16_t>::min();

        for(auto i = 0; i < data.size(); i++)
        {
            if(y_max_f < data[i].y())
                y_max_f = data[i].y();
        }
        y_top_max = y_max_f + y_top_span;

        // FIXME
        const float STEP = 1;
        //        const float STEP = data[2].x() - data[1].x();

        for(int i = 0; i < data.size(); i++)
        {
            x_left = data[i].x();
            x_right = data[i].x() + STEP;
            y_top = data[i].y();

            float label = x_left;
            const QString label_to_print = QString::number(label);

            const float x_left_scaled = rescale_to_x_pixels(x_left);
            const float x_right_scaled = rescale_to_x_pixels(x_right);

            const float y_bottom_scaled = rescale_to_y_pixels(y_bottom);
            const float y_top_scaled = rescale_to_y_pixels(y_top);

            QRect histogram_rectangle;
            histogram_rectangle.setBottomLeft(QPoint(x_left_scaled, y_bottom_scaled));
            histogram_rectangle.setTopRight(QPoint(x_right_scaled, y_top_scaled));
            painter->setPen(Qt::black);
            painter->fillRect(histogram_rectangle, charts->pen().color());
            painter->drawRect(histogram_rectangle.adjusted(0, 0, -1, -1));
            // replot_histogram_labels
            painter->drawText(QPointF(rescale_to_x_pixels(x_left + 0.4), rescale_to_y_pixels(y_bottom) + 20.0), label_to_print);
        }
        _x_max  = x_right;
        _y_min  = y_bottom;
        _y_max  = y_top_max;
    }
}

QSize Plotter::minimumSizeHint() const
{
    return QSize(20 * _widget_margin, 14 * _widget_margin);
}

QSize Plotter::sizeHint() const
{
    return QSize(40 * _widget_margin, 28 * _widget_margin);
}

void Plotter::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, _pixmap);

    if (_is_zoom_rectangle_active)
    {
        QPen pen;
        QBrush brush;
        pen.setColor(Qt::darkGray);
        pen.setStyle(Qt::DashDotLine);
        //        brush.setStyle(Qt::Dense1Pattern);
        brush.setColor(QColor::fromRgb(230, 230, 230, 150));
        //        painter.setBrush(brush);
        painter.setPen(pen);
        painter.drawRect(_zoom_rectangle.normalized().adjusted(0, 0, -1, -1));
    }
}

void Plotter::resizeEvent(QResizeEvent * /* event */)
{
    recalculate_static_data();
    replot();
}

void Plotter::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (_plot_area_borders.contains(event->pos()))
        {
            _is_zoom_rectangle_active = true;
            _zoom_rectangle.setTopLeft(event->pos());
            _zoom_rectangle.setBottomRight(event->pos());
            update_zoom_region();
            setCursor(Qt::CrossCursor);
        }
    }
    else if(event->button() == Qt::RightButton)
    {
        //        zoom_out();
    }
}

void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    //    if(event->pos().x() <= _plot_area_borders.bottomRight().x()
    //            && event->pos().x() >= _plot_area_borders.bottomLeft().x()

    //            && event->pos().y() <= _plot_area_borders.bottomLeft().y()
    //            && event->pos().y() >= _plot_area_borders.topLeft().y())
    //    {
    //        const float x = event->pos().x();
    //        const float y = event->pos().y();
    //        qDebug() << rescale_to_x_coord(x)
    //                 << rescale_to_y_coord(y);
    //    }

    static constexpr uint16_t MAX_COORDINATE = 5000;
    if (_is_zoom_rectangle_active)
    {
        const uint16_t x_min = _plot_area_borders.left();
        const uint16_t x_max = _plot_area_borders.right();
        const uint16_t y_min = _plot_area_borders.top();
        const uint16_t y_max = _plot_area_borders.bottom();

        /////// ternary operator
        uint16_t x, y;
        x = event->pos().x();
        y = event->pos().y();
        if(x >= MAX_COORDINATE)
            x = x_min;
        if(y >= MAX_COORDINATE)
            y = y_min;
        if(x < x_min)
            x = x_min;
        if(x > x_max)
            x = x_max;
        if(y < y_min)
            y = y_min;
        if(y > y_max)
            y = y_max;
        _zoom_rectangle.setBottomRight(QPoint(x, y));
        update_zoom_region();
        replot();
    }
}

void Plotter::mouseReleaseEvent(QMouseEvent* event)
{
    if ((event->button() == Qt::LeftButton) && _is_zoom_rectangle_active)
    {
        _is_zoom_rectangle_active = false;
        update_zoom_region();
        unsetCursor();
        QRect rect = _zoom_rectangle.normalized();
        if (rect.width() < 4 || rect.height() < 4)
            return;
        rect.translate(-_widget_margin, -_widget_margin);

        const float dx = x_span() / (width() - 2 * _widget_margin);
        const float dy = y_span() / (height() - 2 * _widget_margin);
        const float x_min_f = _x_min + dx * rect.left();
        const float x_max_f = _x_min + dx * rect.right();
        const float y_min_f = _y_max - dy * rect.bottom();
        const float y_max_f = _y_max - dy * rect.top();

        _zooms.resize(_current_zoom_index + 1);
        _zooms.push_back(QRectF(QPointF(x_min_f, y_min_f), QPointF(x_max_f, y_max_f)));
        zoom_in();
    }
}

void Plotter::keyPressEvent(QKeyEvent *event)
{
    //    screenshot("screenshot.png", 5);

    switch (event->key())
    {
    case Qt::Key_Left:
        scroll(-1, 0);
        replot();
        break;
    case Qt::Key_Right:
        scroll(+1, 0);
        replot();
        break;
    case Qt::Key_Down:
        scroll(0, -1);
        replot();
        break;
    case Qt::Key_Up:
        scroll(0, +1);
        replot();
        break;
    case Qt::Key_Enter:
        screenshot();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void Plotter::screenshot()
{
    if(!_curves.size())
        return;

    QString path;
    QString newPath = QFileDialog::getSaveFileName(this
                                                   , trUtf8("Export SVG")
                                                   , path
                                                   , tr("SVG files (*.svg)"));
    if (newPath.isEmpty())
        return;

    path = newPath;

    QSvgGenerator generator;
    generator.setFileName(path);
    generator.setSize(QSize(width(), height()));
    generator.setViewBox(QRect(0, 0, width(), height()));
    generator.setTitle(tr("SVG Exporter"));

    QPainter painter;
    painter.begin(&generator);

    //    find_plot_borders();
    replot(&painter);
    painter.end();


    //    QPixmap screenshot_pixmap;
    //    QFile screenshot(filename);


    //    // save current settings
    //    const uint16_t prev_width = width();
    //    const uint16_t prev_height = height();

    //    QVector<uint8_t> prev_curve_pen_width;
    //    prev_curve_pen_width.clear();

    //    uint8_t prev_main_grid_pen_width = _grid.main_grid().get_pen_width_px();
    //    uint8_t prev_sub_grid_pen_width  = _grid.sub_grid().get_pen_width_px();


    //    // apply new settings
    //    for(uint8_t i = 0; i < _curves.size(); i++)
    //    {
    //        prev_curve_pen_width.push_back(_curves.at(i)->get_pen_width_px());
    //        _curves.at(i)->set_pen_width_px(prev_curve_pen_width[i] * scale_factor);
    //    }

    //    _grid.main_grid().set_pen_width_px(scale_factor/2);
    //    _grid.sub_grid().set_pen_width_px(scale_factor/2);

    //    _axes_text.label().set_font_size(60);

    //    _autoticks = false;

    //    _margin_x = MARGIN_X * 3;
    //    _margin_y = MARGIN_Y * 3;

    //    resize(prev_width * scale_factor, prev_height * scale_factor);

    //    screenshot_pixmap = _pixmap;
    //    screenshot.open(QIODevice::WriteOnly);
    //    screenshot_pixmap.save(&screenshot, "PNG", -1);


    //    // restore settings
    //    resize(prev_width, prev_height);

    //    for(uint8_t i = 0; i < _curves.size(); i++)
    //        _curves.at(i)->set_pen_width_px(prev_curve_pen_width[i]);

    //    _grid.main_grid().set_pen_width_px(prev_main_grid_pen_width);
    //    _grid.sub_grid().set_pen_width_px(prev_sub_grid_pen_width);

    //    _axes_text.label().axis_x().set_font_size(12);
    //    _axes_text.label().axis_y().set_font_size(12);

    //    _autoticks = true;

    //    _margin_x = MARGIN_X;
    //    _margin_y = MARGIN_Y;
}

Curve* Plotter::chart(const uint8_t index) const
{
    if (index >= 0 && index < _curves.size())
    {
        return _curves.at(index);
    }
    else
    {
        qDebug() << Q_FUNC_INFO << "index out of bounds:" << index;
        return 0;
    }
}

Curve* Plotter::chart(const QString name) const
{
    const uint8_t chart_count = _curves.size();
    uint8_t index = 0;
    for(index = 0; index < chart_count; index++)
    {
        if(_curves.at(index)->name() == name)
            return _curves.at(index);
    }

    index++;
    if(index > chart_count)
    {
        qDebug() << Q_FUNC_INFO << "Unavailable chart. Check the name";
        return 0;
    }
}

void Plotter::add_chart()
{
    Curve* chart = new Curve("Chart " + QString::number(_curves.size() + 1));
    _curves.push_back(chart);
}

void Plotter::add_chart(const QString& name)
{
    Curve* chart = new Curve(name);
    _curves.push_back(chart);
}
