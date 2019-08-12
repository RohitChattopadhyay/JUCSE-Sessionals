#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>
#include <QPair>

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

private:
    Ui::MainWindow *ui;
    QLabel *statusLabel;
};

#endif // MAINWINDOW_H
