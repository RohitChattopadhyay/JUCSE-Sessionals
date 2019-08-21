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

private slots:
        void Mouse_current_pos();
        void Mouse_Pressed();
        void Mouse_left();

        void on_comboBox_2_currentIndexChanged(int index);

        void on_kernel_currentIndexChanged(const QString &arg1);

        void on_pushButton_clicked();

        void on_clearButton_clicked();

        void on_lineDraw_button_clicked();

        // Line Drawing Algorithms
        void drawLineParametric(int,int,int,int);
        void drawLineDDA(float,float,float,float);
        void drawLineBresenham(float,float,float,float);
        void bresenhamPlotLineLow(int,int,int,int);
        void bresenhamPlotLineHigh(int,int,int,int);

        // Circle Drawing Algorithm
        void drawCircleCartesian(int,int,float);
        void drawCirclePolar(int,int,float);

        void on_circleDrawButton_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *statusLabel;
};

#endif // MAINWINDOW_H
