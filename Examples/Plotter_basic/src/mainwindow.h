#pragma once

#include <QDateTime>
#include <QMainWindow>
#include <QTimer>

#include "src/plot_controller/plotter/plotter.h"
#include "plotter_controller.h"

#include "types.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    static constexpr uint8_t UPDATE_TIME_MS = 50;

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private slots:
    void connect_button_slot();
    void disconnect_button_slot();

private:
    Ui::MainWindow* _ui_form;

private:
    PlotterController* _controller;
    Plotter* _plotter;

private:
    QTimer _replot_timer;
};
