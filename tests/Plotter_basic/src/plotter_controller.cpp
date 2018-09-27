#include "plotter_controller.h"

PlotterController::PlotterController(Plotter* plotter)
    : _plotter(plotter)
{
    setup_plot();
}

PlotterController::~PlotterController()
{
}

void PlotterController::update_plotter_slot()
{
    static float x = 0;
    static QDateTime time = QDateTime::currentDateTime();
    static int16_t y = 0;
    static int16_t yy = Y_MAX;
    static int16_t yyy = 0;
    static int16_t yyyy = Y_MAX;

    _plotter->chart(CHART_ONE)->add_data(x, y);
    _plotter->chart(CHART_TWO)->add_data(x, yy);
    _plotter->chart(CHART_THREE)->add_data(x, yyy);
    _plotter->rescale_y_axis();

    _plotter->erase_invisible_data(x - X_SPAN);

//    if(x < X_SPAN)
//    {
//        _plotter->x_min(0);
//        _plotter->x_max(x - X_SPAN);
//    }
//    else
//        _plotter->x_min(x - X_SPAN);
//        _plotter->x_max(x);

    _plotter->scroll_graph();
    _plotter->replot();

    if (y > Y_MAX)
        y = 0;
    if (yy < -100)
        yy = Y_MAX * 2;
    if (yyy > Y_MAX * 3)
        yyy = 0;
    if (yyyy < -200)
        yyyy = Y_MAX * 2;
    y += 1;
    yy -= 2;
    yyy+= 5;
    yyyy -= 1;

    x += (time.msecsTo(QDateTime::currentDateTime()))*1e-3;
    time = QDateTime::currentDateTime();
}

void PlotterController::setup_plot()
{
    QFont axes("Times");
    axes.setPixelSize(15);
    QFont legend("Times");
    legend.setPixelSize(12);

    _plotter->set_name("Plotter_1");
    _plotter->set_type(PlotterType::Cuvre);
    _plotter->add_chart(CHART_ONE);
    _plotter->add_chart(CHART_TWO);
    _plotter->add_chart(CHART_THREE);
    _plotter->add_chart("CHART_THREE");
    _plotter->chart(CHART_ONE)->set_pen(QPen(CH_ONE_COLOR, PEN_WIDTH, PEN_STYLE));
    _plotter->chart(CHART_TWO)->set_pen(QPen(CH_TWO_COLOR, PEN_WIDTH, PEN_STYLE));
    _plotter->chart(CHART_THREE)->set_pen(QPen(CH_THREE_COLOR, PEN_WIDTH, PEN_STYLE));

    _plotter->set_autoticks(false);
    _plotter->y_ticks(2);
    _plotter->x_ticks(2);

    _plotter->axes().ticks().main_ticks().ticks_x().set_enabled(true);
    _plotter->axes().ticks().main_ticks().ticks_x().set_tick_type((TickType)1);
    _plotter->axes().ticks().main_ticks().ticks_x().set_length(10);

    _plotter->axes().ticks().main_ticks().ticks_y().set_enabled(true);
    _plotter->axes().ticks().main_ticks().ticks_y().set_tick_type((TickType)1);
    _plotter->axes().ticks().main_ticks().ticks_y().set_length(10);

    _plotter->axes().ticks().sub_ticks().sub_ticks_x().set_enabled(true);
    _plotter->axes().ticks().sub_ticks().sub_ticks_y().set_enabled(true);

    _plotter->grid().main_grid().grid_x().set_enabled(true);
    _plotter->grid().main_grid().grid_y().set_enabled(true);
    _plotter->grid().sub_grid().grid_x().set_enabled(true);
    _plotter->grid().sub_grid().grid_y().set_enabled(true);

    _plotter->axes_text().title().title_x().set_enabled(false);
    _plotter->axes_text().title().title_y().set_enabled(false);
    _plotter->axes_text().label().axis_x().set_enabled(true);
    _plotter->axes_text().label().axis_y().set_enabled(true);

    _plotter->title().set_enabled(true);
    _plotter->title().set_text("PlotterTest");
//    _plotter->title().set_font_size_px(22);

    _plotter->x_max(X_SPAN);
}
