#pragma once

#include <QDateTime>
#include <QObject>
#include <QTimer>

#include "src/plot_controller/plotter/plotter.h"

#include "types.h"

class PlotterController : public QObject
{
    Q_OBJECT

    static constexpr uint8_t Y_MAX = 100u;

    static constexpr uint8_t X_SPAN_S = 10u;
    static constexpr uint8_t X_SPAN_S_2 = 5u;

    static constexpr uint8_t X_SPAN = X_SPAN_S_2;

    const QString CHART_ONE = "Chart 1";
    const QString CHART_TWO = "Chart 2";
    const QString CHART_THREE = "Chart 3";

    const QColor CH_ONE_COLOR = QColor::fromRgb(220,170,0);
    const QColor CH_TWO_COLOR = QColor::fromRgb(170,0,170);
    const QColor CH_THREE_COLOR = QColor::fromRgb(0,170,170);

    const uint8_t PEN_WIDTH = 1;
    const Qt::PenStyle PEN_STYLE = Qt::SolidLine;

public:
    PlotterController(Plotter* plotter);
    ~PlotterController();

public slots:
    void update_plotter_slot();

private:
    void setup_plot();

private:
    Plotter* _plotter;
};
