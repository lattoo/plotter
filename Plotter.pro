#-------------------------------------------------
#
# Project created by QtCreator 2017-07-24T21:08:14
#
#-------------------------------------------------

QT       += core gui svg
CONFIG   += c++11

# this is used to availability to build projects with the same
# filenames whish are located in the different sources
# https://wiki.qt.io/Undocumented_QMake
CONFIG += object_parallel_to_source

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

#QMAKE_CXXFLAGS += -Ofast

TARGET = Plotter
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0





FORMS += \
    gui/forms/mainwindow.ui

HEADERS += \
    src/plot_controller/plotter/graphics/axes/line_terminators/line_terminator_x/line_terminator_x.h \
    src/plot_controller/plotter/graphics/axes/line_terminators/line_terminator_y/line_terminator_y.h \
    src/plot_controller/plotter/graphics/axes/line_terminators/line_terminators.h \
    src/plot_controller/plotter/graphics/axes/ticks/tick_items.h \
    src/plot_controller/plotter/graphics/axes/ticks/ticks.h \
    src/plot_controller/plotter/graphics/axes/ticks/ticks_item_x.h \
    src/plot_controller/plotter/graphics/axes/ticks/ticks_item_y.h \
    src/plot_controller/plotter/graphics/axes/zero_lines/zero_line.h \
    src/plot_controller/plotter/graphics/axes/zero_lines/zero_lines.h \
    src/plot_controller/plotter/graphics/axes/axes.h \
    src/plot_controller/plotter/graphics/background/background.h \
    src/plot_controller/plotter/graphics/chart/chart_manager/bar/horizontal/bar_horizontal.h \
    src/plot_controller/plotter/graphics/chart/chart_manager/bar/vertical/bar_vertical.h \
    src/plot_controller/plotter/graphics/chart/chart_manager/bar/bar.h \
    src/plot_controller/plotter/graphics/chart/chart_manager/curve/curve.h \
    src/plot_controller/plotter/graphics/chart/chart_manager/marker/marker.h \
    src/plot_controller/plotter/graphics/chart/chart_manager/pie/pie.h \
    src/plot_controller/plotter/graphics/chart/chart_manager/chart.h \
    src/plot_controller/plotter/graphics/chart/chart_manager/chart_manager.h \
    src/plot_controller/plotter/graphics/grid/grid.h \
    src/plot_controller/plotter/graphics/grid/grid_item.h \
    src/plot_controller/plotter/graphics/legend/legend.h \
    src/plot_controller/plotter/graphics/plot_area/plot_area.h \
    src/plot_controller/plotter/graphics/filled_item.h \
    src/plot_controller/plotter/graphics/graphic_item.h \
    src/plot_controller/plotter/text/axes/label/label_x/label_x.h \
    src/plot_controller/plotter/text/axes/label/label_y/label_y.h \
    src/plot_controller/plotter/text/axes/label/label.h \
    src/plot_controller/plotter/text/axes/title/title_x/title_x.h \
    src/plot_controller/plotter/text/axes/title/title_y/title_y.h \
    src/plot_controller/plotter/text/axes/title/title.h \
    src/plot_controller/plotter/text/axes/axes.h \
    src/plot_controller/plotter/text/legend/legend.h \
    src/plot_controller/plotter/text/title/title.h \
    src/plot_controller/plotter/text/text_item.h \
    src/plot_controller/plotter/text/title_item.h \
    src/plot_controller/plotter/utils/buffer/buffer.h \
    src/plot_controller/plotter/utils/pixels_converter/pixels_converter.h \
    src/plot_controller/plotter/utils/screenshot/screenshot.h \
    src/plot_controller/plotter/utils/scroll/scroll.h \
    src/plot_controller/plotter/utils/time_parser/time_parser.h \
    src/plot_controller/plotter/utils/timer/timer.h \
    src/plot_controller/plotter/utils/zoom/zoom.h \
    src/plot_controller/plotter/utils/utils.h \
    src/plot_controller/plotter/plotter.h \
    src/plot_controller/plot_controller.h \
    src/mainwindow.h \
    src/plotter_controller.h \
    src/types.h

SOURCES += \
    src/plot_controller/plotter/graphics/axes/line_terminators/line_terminator_x/line_terminator_x.cpp \
    src/plot_controller/plotter/graphics/axes/line_terminators/line_terminator_y/line_terminator_y.cpp \
    src/plot_controller/plotter/graphics/axes/line_terminators/line_terminators.cpp \
    src/plot_controller/plotter/graphics/axes/ticks/ticks_item_x.cpp \
    src/plot_controller/plotter/graphics/axes/ticks/ticks_item_y.cpp \
    src/plot_controller/plotter/graphics/axes/zero_lines/zero_line.cpp \
    src/plot_controller/plotter/graphics/axes/zero_lines/zero_lines.cpp \
    src/plot_controller/plotter/graphics/background/background.cpp \
    src/plot_controller/plotter/graphics/chart/chart_manager/bar/horizontal/bar_horizontal.cpp \
    src/plot_controller/plotter/graphics/chart/chart_manager/bar/vertical/bar_vertical.cpp \
    src/plot_controller/plotter/graphics/chart/chart_manager/bar/bar.cpp \
    src/plot_controller/plotter/graphics/chart/chart_manager/curve/curve.cpp \
    src/plot_controller/plotter/graphics/chart/chart_manager/marker/marker.cpp \
    src/plot_controller/plotter/graphics/chart/chart_manager/pie/pie.cpp \
    src/plot_controller/plotter/graphics/chart/chart_manager/chart_manager.cpp \
    src/plot_controller/plotter/graphics/grid/grid.cpp \
    src/plot_controller/plotter/graphics/grid/grid_item.cpp \
    src/plot_controller/plotter/graphics/legend/legend.cpp \
    src/plot_controller/plotter/graphics/plot_area/plot_area.cpp \
    src/plot_controller/plotter/graphics/filled_item.cpp \
    src/plot_controller/plotter/graphics/graphic_item.cpp \
    src/plot_controller/plotter/text/axes/label/label_x/label_x.cpp \
    src/plot_controller/plotter/text/axes/label/label_y/label_y.cpp \
    src/plot_controller/plotter/text/axes/label/label.cpp \
    src/plot_controller/plotter/text/axes/title/title_x/title_x.cpp \
    src/plot_controller/plotter/text/axes/title/title_y/title_y.cpp \
    src/plot_controller/plotter/text/axes/title/title.cpp \
    src/plot_controller/plotter/text/axes/axes.cpp \
    src/plot_controller/plotter/text/legend/legend.cpp \
    src/plot_controller/plotter/text/title/title.cpp \
    src/plot_controller/plotter/utils/buffer/buffer.cpp \
    src/plot_controller/plotter/utils/pixels_converter/pixels_converter.cpp \
    src/plot_controller/plotter/utils/screenshot/screenshot.cpp \
    src/plot_controller/plotter/utils/scroll/scroll.cpp \
    src/plot_controller/plotter/utils/time_parser/time_parser.cpp \
    src/plot_controller/plotter/utils/timer/timer.cpp \
    src/plot_controller/plotter/utils/zoom/zoom.cpp \
    src/plot_controller/plotter/utils/utils.cpp \
    src/plot_controller/plotter/plotter.cpp \
    src/plot_controller/plot_controller.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/plotter_controller.cpp

