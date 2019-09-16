#include <QApplication>
#include "sources/graph.h"
#include "sources/controlpanel.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window->setWindowTitle("JU BCSEIII 001710501073");
    window->showMaximized();
    window->activateWindow();
    window->raise();
    Graph *graph = new Graph();
    ControlPanel *controlpanel = new ControlPanel();
    QLayout *parentlayout = new QHBoxLayout;
    parentlayout->addWidget(graph);
    parentlayout->addWidget(controlpanel);

    QObject::connect(controlpanel,SIGNAL(GraphResetSignal(int,int)),controlpanel,SLOT(ResetUI()));
    QObject::connect(controlpanel,SIGNAL(GraphResetSignal(int,int)),graph,SLOT(GraphResetSlot(int,int)));
    QObject::connect(controlpanel,SIGNAL(GraphPlotSignal(int,int)),graph,SLOT(GraphPlotSlot(int,int)));
    QObject::connect(controlpanel,SIGNAL(GraphPlotColorSignal(int)),graph,SLOT(GraphPlotColorSlot(int)));
    QObject::connect(controlpanel,SIGNAL(GraphCheckPixelColor(int,int)),graph,SLOT(GraphCheckPixel(int,int)));
    QObject::connect(graph,SIGNAL(pointSelect(pair<int,int>)),controlpanel,SLOT(getPointSelect(pair<int,int>)));
    QObject::connect(graph,SIGNAL(pointHover(pair<int,int>)),controlpanel,SLOT(getPointHover(pair<int,int>)));

    window->setLayout(parentlayout);
    window->show();
    return app.exec();
}
