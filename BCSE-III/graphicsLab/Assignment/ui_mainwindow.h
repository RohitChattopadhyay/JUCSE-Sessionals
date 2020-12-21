/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QLabel *mouse_movement;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *label_5;
    QFrame *x_axis;
    QFrame *y_axis;
    QCheckBox *show_axes;
    QPushButton *Draw;
    QSpinBox *circle_radius;
    QRadioButton *draw_circle;
    QRadioButton *draw_line;
    QPushButton *set_point1;
    QPushButton *set_point2;
    QPushButton *pushButton;
    QSpinBox *gridsize;
    QLabel *label;
    QPushButton *showgrid;
    QLabel *label_2;
    QPushButton *dda;
    QPushButton *bress;
    QLabel *debugger;
    QLabel *label_4;
    QPushButton *midpt;
    QPushButton *bress_circle;
    QRadioButton *draw_ellipse;
    QSpinBox *ellipse_ry;
    QSpinBox *ellipse_rx;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *ellipse;
    QFrame *line;
    QPushButton *flood_fill;
    QPushButton *boundary_fill;
    QPushButton *scanline;
    QPushButton *set_vertex;
    QPushButton *fill_scan;
    QFrame *line_2;
    QLabel *label_8;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *label_9;
    QFrame *line_5;
    QPushButton *translate;
    QLabel *label_10;
    QSpinBox *trans_x;
    QLabel *label_11;
    QSpinBox *trans_y;
    QLabel *label_12;
    QPushButton *scale;
    QLabel *label_13;
    QSpinBox *scl_x;
    QSpinBox *scl_y;
    QPushButton *rotate;
    QLabel *label_14;
    QSpinBox *rot;
    QFrame *line_6;
    QFrame *line_7;
    QLabel *label_15;
    QPushButton *clr_bound;
    QPushButton *set_bound;
    QPushButton *clip_line;
    QLabel *label_16;
    QSpinBox *x_max;
    QSpinBox *x_min;
    QLabel *label_17;
    QLabel *label_18;
    QSpinBox *y_max;
    QLabel *label_19;
    QSpinBox *y_min;
    QPushButton *clip_poly;
    QPushButton *shear;
    QLabel *label_20;
    QLabel *label_21;
    QSpinBox *shr_y;
    QSpinBox *shr_x;
    QFrame *line_8;
    QFrame *line_9;
    QLabel *label_22;
    QPushButton *bez_init;
    QPushButton *draw_bez;
    QPushButton *bez_clear;
    QPushButton *reflect;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1303, 736);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 700, 700));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName(QStringLiteral("mouse_movement"));
        mouse_movement->setGeometry(QRect(720, 60, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(720, 40, 111, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName(QStringLiteral("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(720, 130, 111, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(730, 110, 81, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QStringLiteral("x_axis"));
        x_axis->setGeometry(QRect(0, 0, 700, 1));
        x_axis->setStyleSheet(QStringLiteral("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QStringLiteral("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 1, 700));
        y_axis->setStyleSheet(QLatin1String("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        show_axes = new QCheckBox(centralWidget);
        show_axes->setObjectName(QStringLiteral("show_axes"));
        show_axes->setGeometry(QRect(720, 0, 91, 21));
        Draw = new QPushButton(centralWidget);
        Draw->setObjectName(QStringLiteral("Draw"));
        Draw->setGeometry(QRect(710, 280, 101, 41));
        circle_radius = new QSpinBox(centralWidget);
        circle_radius->setObjectName(QStringLiteral("circle_radius"));
        circle_radius->setGeometry(QRect(790, 180, 46, 20));
        draw_circle = new QRadioButton(centralWidget);
        draw_circle->setObjectName(QStringLiteral("draw_circle"));
        draw_circle->setGeometry(QRect(710, 180, 81, 17));
        draw_line = new QRadioButton(centralWidget);
        draw_line->setObjectName(QStringLiteral("draw_line"));
        draw_line->setGeometry(QRect(710, 230, 77, 17));
        set_point1 = new QPushButton(centralWidget);
        set_point1->setObjectName(QStringLiteral("set_point1"));
        set_point1->setGeometry(QRect(790, 230, 81, 23));
        set_point2 = new QPushButton(centralWidget);
        set_point2->setObjectName(QStringLiteral("set_point2"));
        set_point2->setGeometry(QRect(880, 230, 81, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(710, 330, 101, 41));
        gridsize = new QSpinBox(centralWidget);
        gridsize->setObjectName(QStringLiteral("gridsize"));
        gridsize->setGeometry(QRect(900, 0, 61, 21));
        gridsize->setMinimum(1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(850, 0, 46, 13));
        showgrid = new QPushButton(centralWidget);
        showgrid->setObjectName(QStringLiteral("showgrid"));
        showgrid->setGeometry(QRect(890, 60, 81, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(710, 380, 121, 16));
        dda = new QPushButton(centralWidget);
        dda->setObjectName(QStringLiteral("dda"));
        dda->setGeometry(QRect(710, 410, 75, 31));
        bress = new QPushButton(centralWidget);
        bress->setObjectName(QStringLiteral("bress"));
        bress->setGeometry(QRect(800, 410, 91, 31));
        debugger = new QLabel(centralWidget);
        debugger->setObjectName(QStringLiteral("debugger"));
        debugger->setGeometry(QRect(710, 630, 171, 51));
        debugger->setFrameShape(QFrame::Panel);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(710, 450, 91, 16));
        midpt = new QPushButton(centralWidget);
        midpt->setObjectName(QStringLiteral("midpt"));
        midpt->setGeometry(QRect(710, 470, 91, 31));
        bress_circle = new QPushButton(centralWidget);
        bress_circle->setObjectName(QStringLiteral("bress_circle"));
        bress_circle->setGeometry(QRect(810, 470, 91, 31));
        draw_ellipse = new QRadioButton(centralWidget);
        draw_ellipse->setObjectName(QStringLiteral("draw_ellipse"));
        draw_ellipse->setGeometry(QRect(710, 520, 81, 17));
        ellipse_ry = new QSpinBox(centralWidget);
        ellipse_ry->setObjectName(QStringLiteral("ellipse_ry"));
        ellipse_ry->setGeometry(QRect(930, 520, 46, 20));
        ellipse_rx = new QSpinBox(centralWidget);
        ellipse_rx->setObjectName(QStringLiteral("ellipse_rx"));
        ellipse_rx->setGeometry(QRect(840, 520, 46, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(810, 520, 46, 13));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(900, 520, 46, 13));
        ellipse = new QPushButton(centralWidget);
        ellipse->setObjectName(QStringLiteral("ellipse"));
        ellipse->setGeometry(QRect(710, 550, 91, 31));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(1020, -20, 20, 691));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        flood_fill = new QPushButton(centralWidget);
        flood_fill->setObjectName(QStringLiteral("flood_fill"));
        flood_fill->setGeometry(QRect(1050, 30, 81, 41));
        boundary_fill = new QPushButton(centralWidget);
        boundary_fill->setObjectName(QStringLiteral("boundary_fill"));
        boundary_fill->setGeometry(QRect(1170, 30, 81, 41));
        scanline = new QPushButton(centralWidget);
        scanline->setObjectName(QStringLiteral("scanline"));
        scanline->setGeometry(QRect(1050, 90, 81, 41));
        set_vertex = new QPushButton(centralWidget);
        set_vertex->setObjectName(QStringLiteral("set_vertex"));
        set_vertex->setGeometry(QRect(1170, 90, 81, 41));
        fill_scan = new QPushButton(centralWidget);
        fill_scan->setObjectName(QStringLiteral("fill_scan"));
        fill_scan->setGeometry(QRect(1050, 150, 81, 41));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(1040, 10, 91, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1140, 10, 46, 13));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(1180, 20, 118, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(1040, 210, 91, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1140, 210, 71, 16));
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(1220, 210, 81, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        translate = new QPushButton(centralWidget);
        translate->setObjectName(QStringLiteral("translate"));
        translate->setGeometry(QRect(1040, 230, 75, 23));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(1220, 230, 31, 16));
        trans_x = new QSpinBox(centralWidget);
        trans_x->setObjectName(QStringLiteral("trans_x"));
        trans_x->setGeometry(QRect(1160, 230, 46, 20));
        trans_x->setMinimum(-20);
        trans_x->setMaximum(40);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1130, 230, 31, 16));
        trans_y = new QSpinBox(centralWidget);
        trans_y->setObjectName(QStringLiteral("trans_y"));
        trans_y->setGeometry(QRect(1250, 230, 46, 20));
        trans_y->setMinimum(-20);
        trans_y->setMaximum(40);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(1130, 270, 31, 16));
        scale = new QPushButton(centralWidget);
        scale->setObjectName(QStringLiteral("scale"));
        scale->setGeometry(QRect(1040, 270, 75, 23));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(1220, 270, 31, 16));
        scl_x = new QSpinBox(centralWidget);
        scl_x->setObjectName(QStringLiteral("scl_x"));
        scl_x->setGeometry(QRect(1160, 270, 46, 20));
        scl_x->setMinimum(-90);
        scl_x->setMaximum(90);
        scl_y = new QSpinBox(centralWidget);
        scl_y->setObjectName(QStringLiteral("scl_y"));
        scl_y->setGeometry(QRect(1250, 270, 46, 20));
        scl_y->setMinimum(-90);
        scl_y->setMaximum(90);
        rotate = new QPushButton(centralWidget);
        rotate->setObjectName(QStringLiteral("rotate"));
        rotate->setGeometry(QRect(1040, 310, 75, 23));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(1130, 310, 31, 16));
        rot = new QSpinBox(centralWidget);
        rot->setObjectName(QStringLiteral("rot"));
        rot->setGeometry(QRect(1170, 310, 46, 20));
        rot->setMinimum(-90);
        rot->setMaximum(90);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(1040, 430, 71, 16));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(1220, 430, 71, 16));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(1140, 430, 46, 13));
        clr_bound = new QPushButton(centralWidget);
        clr_bound->setObjectName(QStringLiteral("clr_bound"));
        clr_bound->setGeometry(QRect(1040, 520, 91, 21));
        set_bound = new QPushButton(centralWidget);
        set_bound->setObjectName(QStringLiteral("set_bound"));
        set_bound->setGeometry(QRect(1150, 520, 131, 21));
        clip_line = new QPushButton(centralWidget);
        clip_line->setObjectName(QStringLiteral("clip_line"));
        clip_line->setGeometry(QRect(1040, 550, 81, 21));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(1040, 450, 41, 20));
        x_max = new QSpinBox(centralWidget);
        x_max->setObjectName(QStringLiteral("x_max"));
        x_max->setGeometry(QRect(1080, 450, 46, 20));
        x_max->setMinimum(-20);
        x_max->setMaximum(40);
        x_min = new QSpinBox(centralWidget);
        x_min->setObjectName(QStringLiteral("x_min"));
        x_min->setGeometry(QRect(1190, 450, 46, 20));
        x_min->setMinimum(-20);
        x_min->setMaximum(40);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(1150, 450, 41, 20));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(1150, 480, 41, 20));
        y_max = new QSpinBox(centralWidget);
        y_max->setObjectName(QStringLiteral("y_max"));
        y_max->setGeometry(QRect(1080, 480, 46, 20));
        y_max->setMinimum(-20);
        y_max->setMaximum(40);
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(1040, 480, 41, 20));
        y_min = new QSpinBox(centralWidget);
        y_min->setObjectName(QStringLiteral("y_min"));
        y_min->setGeometry(QRect(1190, 480, 46, 20));
        y_min->setMinimum(-20);
        y_min->setMaximum(40);
        clip_poly = new QPushButton(centralWidget);
        clip_poly->setObjectName(QStringLiteral("clip_poly"));
        clip_poly->setGeometry(QRect(1150, 550, 81, 21));
        shear = new QPushButton(centralWidget);
        shear->setObjectName(QStringLiteral("shear"));
        shear->setGeometry(QRect(1040, 350, 75, 23));
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(1130, 350, 31, 16));
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(1220, 350, 31, 16));
        shr_y = new QSpinBox(centralWidget);
        shr_y->setObjectName(QStringLiteral("shr_y"));
        shr_y->setGeometry(QRect(1250, 350, 46, 20));
        shr_y->setMinimum(-90);
        shr_y->setMaximum(90);
        shr_x = new QSpinBox(centralWidget);
        shr_x->setObjectName(QStringLiteral("shr_x"));
        shr_x->setGeometry(QRect(1160, 350, 46, 20));
        shr_x->setMinimum(-90);
        shr_x->setMaximum(90);
        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setGeometry(QRect(1040, 600, 91, 16));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(centralWidget);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setGeometry(QRect(1220, 600, 91, 16));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(1150, 600, 61, 16));
        bez_init = new QPushButton(centralWidget);
        bez_init->setObjectName(QStringLiteral("bez_init"));
        bez_init->setGeometry(QRect(1130, 620, 81, 23));
        draw_bez = new QPushButton(centralWidget);
        draw_bez->setObjectName(QStringLiteral("draw_bez"));
        draw_bez->setGeometry(QRect(1220, 620, 81, 23));
        bez_clear = new QPushButton(centralWidget);
        bez_clear->setObjectName(QStringLiteral("bez_clear"));
        bez_clear->setGeometry(QRect(1040, 620, 81, 23));
        reflect = new QPushButton(centralWidget);
        reflect->setObjectName(QStringLiteral("reflect"));
        reflect->setGeometry(QRect(1040, 390, 181, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1303, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "    Mouse Movement", 0));
        mouse_pressed->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Mouse Pressed", 0));
        show_axes->setText(QApplication::translate("MainWindow", "Show Axes", 0));
        Draw->setText(QApplication::translate("MainWindow", "Draw", 0));
        draw_circle->setText(QApplication::translate("MainWindow", "Draw Circle", 0));
        draw_line->setText(QApplication::translate("MainWindow", "Draw Line", 0));
        set_point1->setText(QApplication::translate("MainWindow", "Set point 1", 0));
        set_point2->setText(QApplication::translate("MainWindow", "Set point 2", 0));
        pushButton->setText(QApplication::translate("MainWindow", "RESET", 0));
        label->setText(QApplication::translate("MainWindow", "Grid Size", 0));
        showgrid->setText(QApplication::translate("MainWindow", "Show Grid", 0));
        label_2->setText(QApplication::translate("MainWindow", "Line Drawing Algorithm", 0));
        dda->setText(QApplication::translate("MainWindow", "DDA", 0));
        bress->setText(QApplication::translate("MainWindow", "BRESSENHAM", 0));
        debugger->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Circle Drawing Algo", 0));
        midpt->setText(QApplication::translate("MainWindow", "Midpoint Circle", 0));
        bress_circle->setText(QApplication::translate("MainWindow", "Bressenham", 0));
        draw_ellipse->setText(QApplication::translate("MainWindow", "Draw Ellipse", 0));
        label_6->setText(QApplication::translate("MainWindow", "Rx:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Ry:", 0));
        ellipse->setText(QApplication::translate("MainWindow", "Draw Ellipse", 0));
        flood_fill->setText(QApplication::translate("MainWindow", "Flood Fill", 0));
        boundary_fill->setText(QApplication::translate("MainWindow", "Boundary fill", 0));
        scanline->setText(QApplication::translate("MainWindow", "Clear Vertices", 0));
        set_vertex->setText(QApplication::translate("MainWindow", "Set Vertex", 0));
        fill_scan->setText(QApplication::translate("MainWindow", "Scanline Fill", 0));
        label_8->setText(QApplication::translate("MainWindow", "Filling", 0));
        label_9->setText(QApplication::translate("MainWindow", "Transformation", 0));
        translate->setText(QApplication::translate("MainWindow", "Translate", 0));
        label_10->setText(QApplication::translate("MainWindow", "y:", 0));
        label_11->setText(QApplication::translate("MainWindow", "x:", 0));
        label_12->setText(QApplication::translate("MainWindow", "x:", 0));
        scale->setText(QApplication::translate("MainWindow", "Scale", 0));
        label_13->setText(QApplication::translate("MainWindow", "y:", 0));
        rotate->setText(QApplication::translate("MainWindow", "Rotate", 0));
        label_14->setText(QApplication::translate("MainWindow", "angle:", 0));
        label_15->setText(QApplication::translate("MainWindow", "Clipping", 0));
        clr_bound->setText(QApplication::translate("MainWindow", "Clear Boundary", 0));
        set_bound->setText(QApplication::translate("MainWindow", "Draw Boundary", 0));
        clip_line->setText(QApplication::translate("MainWindow", "Clip Line", 0));
        label_16->setText(QApplication::translate("MainWindow", "x_max:", 0));
        label_17->setText(QApplication::translate("MainWindow", "x_min:", 0));
        label_18->setText(QApplication::translate("MainWindow", "y_min:", 0));
        label_19->setText(QApplication::translate("MainWindow", "y_max:", 0));
        clip_poly->setText(QApplication::translate("MainWindow", "Clip Polygon", 0));
        shear->setText(QApplication::translate("MainWindow", "Shear", 0));
        label_20->setText(QApplication::translate("MainWindow", "x:", 0));
        label_21->setText(QApplication::translate("MainWindow", "y:", 0));
        label_22->setText(QApplication::translate("MainWindow", "Bezier Curve", 0));
        bez_init->setText(QApplication::translate("MainWindow", "Set 4 points", 0));
        draw_bez->setText(QApplication::translate("MainWindow", "Draw Curve", 0));
        bez_clear->setText(QApplication::translate("MainWindow", "Clear Points", 0));
        reflect->setText(QApplication::translate("MainWindow", "Reflect about last drawn line", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
