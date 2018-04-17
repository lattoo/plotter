#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , _ui_form(new Ui::MainWindow)
    , _plotter(new Plotter)
{
    _ui_form->setupUi(this);
    _ui_form->gridLayout->addWidget(_plotter);

    _controller = new PlotterController(_plotter);

    connect(_ui_form->close_bt, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(_ui_form->dsc_btn, SIGNAL(clicked(bool)), this, SLOT(disconnect_button_slot()));
    connect(_ui_form->connect_btn, SIGNAL(clicked(bool)), this, SLOT(connect_button_slot()));
}

MainWindow::~MainWindow()
{
    delete _ui_form;
}

void MainWindow::connect_button_slot()
{
    _replot_timer.start(UPDATE_TIME_MS);
    connect(&_replot_timer, SIGNAL(timeout()), _controller, SLOT(update_plotter_slot()));
}

void MainWindow::disconnect_button_slot()
{
    _replot_timer.stop();
    disconnect(&_replot_timer, SIGNAL(timeout()), _controller, SLOT(update_plotter_slot()));
}

