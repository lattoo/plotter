#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , _plotter(new Plotter)
{
}

MainWindow::~MainWindow()
{
}
