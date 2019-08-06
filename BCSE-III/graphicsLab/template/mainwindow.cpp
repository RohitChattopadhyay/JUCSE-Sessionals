#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::point(int x,int y,int r)
{
    int a,b;
    QImage img=QImage(450,450,QImage::Format_RGB888);
    r=0;
    for(a=-r;a<=r;a++){
        for(b=-r;b<=r;b++){
                img.setPixelColor(x+a,y+b,qRgb(255,0,0));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::showMousePosition(QPoint &pos)
{
    ui->mouse_movement->setText(" X : "+QString::number(pos.x())+", Y : "+QString::number(pos.y()));
}
void MainWindow::Mouse_Pressed()
{
    ui->mouse_pressed->setText(" X : "+QString::number(ui->frame->x)+", Y : "+QString::number(ui->frame->y));
    point(ui->frame->x,ui->frame->y,3);
    ui->x_axis->move(0,ui->frame->y);
    ui->y_axis->move(ui->frame->x,0);
}

void MainWindow::on_show_axes_clicked()
{
    if(ui->show_axes->isChecked())
    {
        ui->x_axis->show();
        ui->y_axis->show();
    }
    else{
        ui->x_axis->hide();
        ui->y_axis->hide();
    }
}
void MainWindow::on_set_point1_clicked()
{
    if(ui->draw_line->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
    }
}

void MainWindow::on_set_point2_clicked()
{
    if(ui->draw_line->isChecked()){
        p2.setX(ui->frame->x);
        p2.setY(ui->frame->y);
    }
}

void MainWindow::on_Draw_clicked()
{
    int r0=ui->circle_radius->value();
    QPixmap *pix=new QPixmap(450,450);
    QPainter *paint=new QPainter();
    if(ui->draw_circle->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
        /*int a,b;
        QImage img=QImage(450,450,QImage::Format_RGB888);
        for(a=-r0;a<=r0;a++){
            for(b=-r0;b<=r0;b++){
                if((a*a)+(b*b)<=(r0*r0)){
                    img.setPixelColor(p1.x()+a,p1.y()+b,qRgb(255,255,255));
                }
            }
        }*/
        paint->begin(pix);
        paint->setPen(Qt::lightGray);
        paint->drawEllipse(p1,r0,r0);
        ui->frame->setPixmap(*pix);
        paint->end();
        //ui->frame->setPixmap(QPixmap::fromImage(img));
    }
    if(ui->draw_line->isChecked()){
        paint->begin(pix);
        paint->setPen(Qt::white);
        paint->drawLine(p1,p2);
        ui->frame->setPixmap(*pix);
        paint->end();
    }
}
