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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <graph_qwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    graph_qWidget *graph;
    QFrame *line;
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QComboBox *kernel;
    QLabel *label_13;
    QPushButton *clearButton;
    QComboBox *brushColor;
    QLabel *label_17;
    QLineEdit *gridBgColor;
    QLabel *label_18;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QTabWidget *controlPanel;
    QWidget *lineDrawTab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *lineDrawingTab;
    QFrame *line_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_9;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_3;
    QLineEdit *dda_start_x;
    QLineEdit *dda_end_x;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_8;
    QLineEdit *dda_start_y;
    QLineEdit *dda_end_y;
    QComboBox *lineDrawingMethodsCombo;
    QPushButton *lineDraw_button;
    QWidget *circleDrawTab;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *circleDrawingTab;
    QFrame *line_3;
    QPushButton *circleDrawButton;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QComboBox *circleDrawMethod;
    QHBoxLayout *horizontalLayout;
    QLineEdit *circleCenterX;
    QLineEdit *circleCenterY;
    QLineEdit *circleRadius;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *ellipseDrawTab;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *circleDrawingTab_2;
    QFrame *line_4;
    QPushButton *ellipseDrawButton;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QComboBox *ellipseDrawMethod;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *ellipseCenterX;
    QLineEdit *ellipseCenterY;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *ellipseMajorAxisLen;
    QLineEdit *ellipseMinorAxisLen;
    QMenuBar *menuBar;
    QMenu *menuRaster;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(850, 557);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(850, 557));
        MainWindow->setMaximumSize(QSize(850, 557));
        QIcon icon;
        icon.addFile(QStringLiteral("julogo.gif"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 501, 491));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        graph = new graph_qWidget(gridLayoutWidget);
        graph->setObjectName(QStringLiteral("graph"));
        graph->setEnabled(true);
        sizePolicy.setHeightForWidth(graph->sizePolicy().hasHeightForWidth());
        graph->setSizePolicy(sizePolicy);
        graph->setMinimumSize(QSize(0, 0));
        graph->setMaximumSize(QSize(480, 480));
        graph->setCursor(QCursor(Qt::CrossCursor));
        graph->setMouseTracking(true);
        graph->setLayoutDirection(Qt::LeftToRight);
        graph->setAutoFillBackground(false);
        graph->setStyleSheet(QStringLiteral("background-color:#173C1B"));

        gridLayout->addWidget(graph, 0, 1, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(510, 10, 320, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(615, 0, 110, 20));
        label->setAutoFillBackground(true);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(0);
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(510, 20, 321, 157));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        comboBox_2 = new QComboBox(formLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_2);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        kernel = new QComboBox(formLayoutWidget);
        kernel->setObjectName(QStringLiteral("kernel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, kernel);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_13);

        clearButton = new QPushButton(formLayoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        formLayout->setWidget(5, QFormLayout::FieldRole, clearButton);

        brushColor = new QComboBox(formLayoutWidget);
        brushColor->setObjectName(QStringLiteral("brushColor"));

        formLayout->setWidget(3, QFormLayout::FieldRole, brushColor);

        label_17 = new QLabel(formLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_17);

        gridBgColor = new QLineEdit(formLayoutWidget);
        gridBgColor->setObjectName(QStringLiteral("gridBgColor"));

        formLayout->setWidget(4, QFormLayout::FieldRole, gridBgColor);

        label_18 = new QLabel(formLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_18);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(510, 189, 321, 301));
        tabWidget->setTabPosition(QTabWidget::North);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayoutWidget_2 = new QWidget(tab);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(-1, 9, 321, 261));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        controlPanel = new QTabWidget(gridLayoutWidget_2);
        controlPanel->setObjectName(QStringLiteral("controlPanel"));
        controlPanel->setTabShape(QTabWidget::Rounded);
        controlPanel->setUsesScrollButtons(true);
        lineDrawTab = new QWidget();
        lineDrawTab->setObjectName(QStringLiteral("lineDrawTab"));
        verticalLayoutWidget = new QWidget(lineDrawTab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 321, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineDrawingTab = new QGroupBox(verticalLayoutWidget);
        lineDrawingTab->setObjectName(QStringLiteral("lineDrawingTab"));
        lineDrawingTab->setAutoFillBackground(true);
        line_2 = new QFrame(lineDrawingTab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 18, 321, 6));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget_3 = new QWidget(lineDrawingTab);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(-3, 19, 61, 121));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7);

        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_6);

        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_9);

        verticalLayoutWidget_2 = new QWidget(lineDrawingTab);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(59, 19, 251, 121));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_3);

        dda_start_x = new QLineEdit(verticalLayoutWidget_2);
        dda_start_x->setObjectName(QStringLiteral("dda_start_x"));

        verticalLayout_9->addWidget(dda_start_x);

        dda_end_x = new QLineEdit(verticalLayoutWidget_2);
        dda_end_x->setObjectName(QStringLiteral("dda_end_x"));

        verticalLayout_9->addWidget(dda_end_x);


        horizontalLayout_2->addLayout(verticalLayout_9);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_8);

        dda_start_y = new QLineEdit(verticalLayoutWidget_2);
        dda_start_y->setObjectName(QStringLiteral("dda_start_y"));

        verticalLayout_6->addWidget(dda_start_y);

        dda_end_y = new QLineEdit(verticalLayoutWidget_2);
        dda_end_y->setObjectName(QStringLiteral("dda_end_y"));

        verticalLayout_6->addWidget(dda_end_y);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_2->addLayout(horizontalLayout_2);

        lineDrawingMethodsCombo = new QComboBox(verticalLayoutWidget_2);
        lineDrawingMethodsCombo->setObjectName(QStringLiteral("lineDrawingMethodsCombo"));

        verticalLayout_2->addWidget(lineDrawingMethodsCombo);

        lineDraw_button = new QPushButton(lineDrawingTab);
        lineDraw_button->setObjectName(QStringLiteral("lineDraw_button"));
        lineDraw_button->setGeometry(QRect(10, 150, 301, 25));

        verticalLayout->addWidget(lineDrawingTab);

        controlPanel->addTab(lineDrawTab, QString());
        circleDrawTab = new QWidget();
        circleDrawTab->setObjectName(QStringLiteral("circleDrawTab"));
        verticalLayoutWidget_4 = new QWidget(circleDrawTab);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(-1, -1, 321, 271));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        circleDrawingTab = new QGroupBox(verticalLayoutWidget_4);
        circleDrawingTab->setObjectName(QStringLiteral("circleDrawingTab"));
        circleDrawingTab->setAutoFillBackground(true);
        line_3 = new QFrame(circleDrawingTab);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 18, 321, 6));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        circleDrawButton = new QPushButton(circleDrawingTab);
        circleDrawButton->setObjectName(QStringLiteral("circleDrawButton"));
        circleDrawButton->setGeometry(QRect(10, 130, 301, 25));
        formLayoutWidget_2 = new QWidget(circleDrawingTab);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(9, 30, 301, 101));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        circleDrawMethod = new QComboBox(formLayoutWidget_2);
        circleDrawMethod->setObjectName(QStringLiteral("circleDrawMethod"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, circleDrawMethod);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        circleCenterX = new QLineEdit(formLayoutWidget_2);
        circleCenterX->setObjectName(QStringLiteral("circleCenterX"));

        horizontalLayout->addWidget(circleCenterX);

        circleCenterY = new QLineEdit(formLayoutWidget_2);
        circleCenterY->setObjectName(QStringLiteral("circleCenterY"));

        horizontalLayout->addWidget(circleCenterY);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        circleRadius = new QLineEdit(formLayoutWidget_2);
        circleRadius->setObjectName(QStringLiteral("circleRadius"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, circleRadius);

        label_10 = new QLabel(formLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(formLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_11);

        label_12 = new QLabel(formLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_12);


        verticalLayout_4->addWidget(circleDrawingTab);

        controlPanel->addTab(circleDrawTab, QString());
        ellipseDrawTab = new QWidget();
        ellipseDrawTab->setObjectName(QStringLiteral("ellipseDrawTab"));
        verticalLayoutWidget_5 = new QWidget(ellipseDrawTab);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(0, -1, 321, 231));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        circleDrawingTab_2 = new QGroupBox(verticalLayoutWidget_5);
        circleDrawingTab_2->setObjectName(QStringLiteral("circleDrawingTab_2"));
        circleDrawingTab_2->setAutoFillBackground(true);
        line_4 = new QFrame(circleDrawingTab_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 18, 321, 6));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        ellipseDrawButton = new QPushButton(circleDrawingTab_2);
        ellipseDrawButton->setObjectName(QStringLiteral("ellipseDrawButton"));
        ellipseDrawButton->setGeometry(QRect(10, 130, 301, 25));
        formLayoutWidget_3 = new QWidget(circleDrawingTab_2);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(9, 30, 301, 101));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        ellipseDrawMethod = new QComboBox(formLayoutWidget_3);
        ellipseDrawMethod->setObjectName(QStringLiteral("ellipseDrawMethod"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, ellipseDrawMethod);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ellipseCenterX = new QLineEdit(formLayoutWidget_3);
        ellipseCenterX->setObjectName(QStringLiteral("ellipseCenterX"));

        horizontalLayout_3->addWidget(ellipseCenterX);

        ellipseCenterY = new QLineEdit(formLayoutWidget_3);
        ellipseCenterY->setObjectName(QStringLiteral("ellipseCenterY"));

        horizontalLayout_3->addWidget(ellipseCenterY);


        formLayout_3->setLayout(0, QFormLayout::FieldRole, horizontalLayout_3);

        label_14 = new QLabel(formLayoutWidget_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_14);

        label_15 = new QLabel(formLayoutWidget_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_15);

        label_16 = new QLabel(formLayoutWidget_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_16);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        ellipseMajorAxisLen = new QLineEdit(formLayoutWidget_3);
        ellipseMajorAxisLen->setObjectName(QStringLiteral("ellipseMajorAxisLen"));

        horizontalLayout_4->addWidget(ellipseMajorAxisLen);

        ellipseMinorAxisLen = new QLineEdit(formLayoutWidget_3);
        ellipseMinorAxisLen->setObjectName(QStringLiteral("ellipseMinorAxisLen"));

        horizontalLayout_4->addWidget(ellipseMinorAxisLen);


        formLayout_3->setLayout(1, QFormLayout::FieldRole, horizontalLayout_4);


        verticalLayout_5->addWidget(circleDrawingTab_2);

        controlPanel->addTab(ellipseDrawTab, QString());

        gridLayout_2->addWidget(controlPanel, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 850, 21));
        menuRaster = new QMenu(menuBar);
        menuRaster->setObjectName(QStringLiteral("menuRaster"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setLayoutDirection(Qt::LeftToRight);
        statusBar->setAutoFillBackground(true);
        statusBar->setStyleSheet(QStringLiteral(""));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(lineDraw_button, dda_start_x);
        QWidget::setTabOrder(dda_start_x, dda_start_y);
        QWidget::setTabOrder(dda_start_y, dda_end_x);
        QWidget::setTabOrder(dda_end_x, dda_end_y);
        QWidget::setTabOrder(dda_end_y, kernel);
        QWidget::setTabOrder(kernel, comboBox_2);
        QWidget::setTabOrder(comboBox_2, clearButton);

        menuBar->addAction(menuRaster->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        controlPanel->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "001710501076 | Priti Shaw", 0));
        label->setText(QApplication::translate("MainWindow", "<b>Graph Settings</b>", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Size</span></p></body></html>", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "480x480", 0)
         << QApplication::translate("MainWindow", "300x300", 0)
         << QApplication::translate("MainWindow", "90X90", 0)
        );
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Zoom</span></p></body></html>", 0));
        kernel->clear();
        kernel->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "3", 0)
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "7", 0)
         << QApplication::translate("MainWindow", "9", 0)
        );
        label_13->setText(QString());
        clearButton->setText(QApplication::translate("MainWindow", "Clear Graph", 0));
        brushColor->clear();
        brushColor->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Yellow", 0)
         << QApplication::translate("MainWindow", "Red", 0)
         << QApplication::translate("MainWindow", "Black", 0)
         << QApplication::translate("MainWindow", "Blue", 0)
         << QApplication::translate("MainWindow", "White", 0)
        );
        label_17->setText(QApplication::translate("MainWindow", "<b>Color</b>", 0));
        gridBgColor->setText(QApplication::translate("MainWindow", "#173C1B", 0));
        label_18->setText(QApplication::translate("MainWindow", "<b>bgColor</b>", 0));
        lineDrawingTab->setTitle(QApplication::translate("MainWindow", "  Line Drawing Algorithms", 0));
        label_7->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", " Start", 0));
        label_6->setText(QApplication::translate("MainWindow", " End", 0));
        label_9->setText(QApplication::translate("MainWindow", "Method", 0));
        label_3->setText(QApplication::translate("MainWindow", "<b>X Axis</b>", 0));
        label_8->setText(QApplication::translate("MainWindow", "<b>Y Axis</b>", 0));
        lineDrawingMethodsCombo->clear();
        lineDrawingMethodsCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Parametric Form", 0)
         << QApplication::translate("MainWindow", "Digital Differential Analyzer", 0)
         << QApplication::translate("MainWindow", "Bresenham", 0)
        );
        lineDraw_button->setText(QApplication::translate("MainWindow", "Draw Line", 0));
        controlPanel->setTabText(controlPanel->indexOf(lineDrawTab), QApplication::translate("MainWindow", "Line", 0));
        circleDrawingTab->setTitle(QApplication::translate("MainWindow", "  Circle Drawing Algorithms", 0));
        circleDrawButton->setText(QApplication::translate("MainWindow", "Draw Circle", 0));
        circleDrawMethod->clear();
        circleDrawMethod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Cartesian Form", 0)
         << QApplication::translate("MainWindow", "Polar Cordinate", 0)
         << QApplication::translate("MainWindow", "Mid Point", 0)
         << QApplication::translate("MainWindow", "Bresenham Mid Point", 0)
        );
        circleCenterX->setPlaceholderText(QApplication::translate("MainWindow", "X Axis", 0));
        circleCenterY->setPlaceholderText(QApplication::translate("MainWindow", "Y Axis", 0));
        circleRadius->setPlaceholderText(QApplication::translate("MainWindow", "In Pixels", 0));
        label_10->setText(QApplication::translate("MainWindow", "Center", 0));
        label_11->setText(QApplication::translate("MainWindow", "Radius", 0));
        label_12->setText(QApplication::translate("MainWindow", "Method", 0));
        controlPanel->setTabText(controlPanel->indexOf(circleDrawTab), QApplication::translate("MainWindow", "Circle", 0));
        circleDrawingTab_2->setTitle(QApplication::translate("MainWindow", "  Ellipse Drawing Algorithms", 0));
        ellipseDrawButton->setText(QApplication::translate("MainWindow", "Draw Ellipse", 0));
        ellipseDrawMethod->clear();
        ellipseDrawMethod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Cartesian Form", 0)
         << QApplication::translate("MainWindow", "Polar Cordinate", 0)
         << QApplication::translate("MainWindow", "Bresenham Midpoint", 0)
        );
        ellipseCenterX->setPlaceholderText(QApplication::translate("MainWindow", "X Axis", 0));
        ellipseCenterY->setPlaceholderText(QApplication::translate("MainWindow", "Y Axis", 0));
        label_14->setText(QApplication::translate("MainWindow", "Center", 0));
        label_15->setText(QApplication::translate("MainWindow", "Axis", 0));
        label_16->setText(QApplication::translate("MainWindow", "Method", 0));
        ellipseMajorAxisLen->setText(QString());
        ellipseMajorAxisLen->setPlaceholderText(QApplication::translate("MainWindow", "Major = 2a", 0));
        ellipseMinorAxisLen->setPlaceholderText(QApplication::translate("MainWindow", "Minor = 2b", 0));
        controlPanel->setTabText(controlPanel->indexOf(ellipseDrawTab), QApplication::translate("MainWindow", "Ellipse", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Primitive", 0));
        menuRaster->setTitle(QApplication::translate("MainWindow", "Raster", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
