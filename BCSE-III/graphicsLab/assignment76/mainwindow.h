#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>
#include <QPair>
#include <QtCore/qmath.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //Clipping
    int clipWinX,clipWinY;

private slots:
        void Mouse_current_pos();
        void Mouse_Pressed();
        void Mouse_left();

        void on_comboBox_2_currentIndexChanged(int index);

        void on_kernel_currentIndexChanged(const QString &arg1);

        void on_clearButton_clicked();

        // Line Drawing Algorithms
        void drawLineParametric(int,int,int,int);
        void drawLineDDA(float,float,float,float);
        void drawLineBresenham(float,float,float,float,bool);
        void bresenhamPlotLineLow(int,int,int,int,bool);
        void bresenhamPlotLineHigh(int,int,int,int,bool);
        void on_lineDraw_button_clicked();

        // Circle Drawing Algorithm
        void drawCircleCartesian(int,int,float);
        void drawCirclePolar(int,int,float);
        void drawCircleMidPoint(int,int,float);
        void drawCircleBresenhamMidPoint(int,int,float);
        void on_circleDrawButton_clicked();

        // Ellipse Drawing Algorithm
        void drawEllipseCartesian(int,int,float,float);
        void drawEllipsePolar(int,int,float,float);
        void drawEllipseBresenham(int, int, float, float);
        void on_ellipseDrawButton_clicked();

        void on_brushColor_currentIndexChanged(int index);

        void on_gridBgColor_textEdited(const QString &arg1);

        //Filling
        void on_fillingButton_clicked();
        void fillingScanLine(int, int, int, int, bool, int, int);
        void boundaryFill(int, int, bool, int, int);
        void floodFill(int, int, bool, int, int);

        //Clipping
        void linearClip();
        void polygonClip();
        void on_clipWindowButton_clicked();
        void on_clipButton_clicked();

        //Transformation
        void on_transShearBtn_clicked();
        void on_transScaleBtn_clicked();
        void on_transTranslateBtn_clicked();
        void on_transRotBtn_clicked();
        void reflectAboutLine();
        void on_transRefBtn_clicked();

        void on_bezierBtn_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *statusLabel;
};

#endif // MAINWINDOW_H
