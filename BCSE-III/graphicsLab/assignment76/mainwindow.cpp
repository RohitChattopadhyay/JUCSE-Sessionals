#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "graph_qwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusLabel = new QLabel("");
    statusLabel->setMinimumWidth(75);
    statusBar()->addPermanentWidget(new QLabel("Coordinates: "));
    statusBar()->addPermanentWidget(statusLabel);
    connect(ui->graph, SIGNAL(Mouse_Pos()),this,SLOT(Mouse_current_pos()));
    connect(ui->graph, SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
    connect(ui->graph, SIGNAL(Mouse_Left()),this,SLOT(Mouse_left()));
    ui->graph->resize(480,480);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Mouse_current_pos()
{
    int ker = ui->graph->ker;
    int xCord = (ui->graph->x - ui->graph->width()/2)/ker;
    int yCord = (ui->graph->height()/2 - ui->graph->y)/ker;
    QString msg;
    msg.sprintf("%4d, %4d",xCord,yCord);
    MainWindow::statusLabel->setText(msg);

}

void MainWindow::Mouse_Pressed()
{
    int ker = ui->graph->ker;
    int xCord = (ui->graph->x - ui->graph->width()/2)/ker;
    int yCord = (ui->graph->height()/2 - ui->graph->y)/ker;
    ui->graph->points.push_back(QPair< int , int >(xCord,yCord));
    statusBar()->showMessage("Plotted: " + QString::number(xCord) + "," + QString::number(yCord),2000);
    ui->graph->repaint();

}

void MainWindow::Mouse_left()
{
    MainWindow::statusLabel->setText("");
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    int size[3] = {480,300,90};
//    ui->graph->points.clear();
    ui->graph->resize(size[index],size[index]);
    ui->graph->repaint();
    MainWindow::statusLabel->setText("");

}

void MainWindow::on_kernel_currentIndexChanged(const QString &arg1)
{
    ui->graph->ker = arg1.toInt();
    ui->graph->repaint();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->graph->points.size()==0)
           return;
    ui->graph->points.pop_back();
    ui->graph->repaint();

}

void MainWindow::on_clearButton_clicked()
{
    ui->graph->points.clear();
    ui->graph->repaint();
}
