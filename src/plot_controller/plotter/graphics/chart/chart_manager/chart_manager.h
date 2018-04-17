#pragma once

#include "src/plot_controller/plotter/graphics/chart/chart_manager/bar/bar.h"
#include "src/plot_controller/plotter/graphics/chart/chart_manager/curve/curve.h"
#include "src/plot_controller/plotter/graphics/chart/chart_manager/pie/pie.h"

class ChartManager
{
public:
    ChartManager();
    ~ChartManager();

    template <class T>
    void create_chart()
    {
        static_assert(std::is_base_of<IChart, T>::value, "Should be based only on IChart");
        if (_chart == nullptr)
            _chart = new T;
    }

    // will be used in destructor
    void delete_chart()
    {
        if (_chart)
        {
            delete _chart;
            _chart = nullptr;
        }
    }

//    void set_chart_type(const ChartType type)
//    {
//        switch (type)
//        {
//        case ChartType::Cuvre:
//            create_chart<Curve>();
//            break;
//        case ChartType::Bar:
//            create_chart<Bar>();
//            break;
//        case ChartType::Pie:
//            create_chart<Pie>();
//            break;
//        default:
//            break;
//        }
//    }

    IChart* chart() { return _chart; }

private:
    IChart* _chart = nullptr;

//public:
//    Bar   bar() const { return _bar; }
//    Curve curve() const { return _curve; }
//    Pie   pie() const { return _pie; }

//private:
//    Bar     _bar;
//    Curve   _curve;
//    Pie     _pie;
};
