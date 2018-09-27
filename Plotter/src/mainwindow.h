#pragma once

#include <QMainWindow>

#include "src/plot_controller/plotter/plotter.h"

#include "types.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    Plotter* _plotter;
};
