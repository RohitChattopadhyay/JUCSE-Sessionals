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
    ui->pushButton->hide(); // undo button
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
    ui->graph->points.insert(QPair< int , int >(xCord,yCord));
    if(ui->graph->recent.size()<2)
        ui->graph->recent.push_back(QPair< QString , QString >(QString::number(xCord),QString::number(yCord)));
    else{
        ui->graph->recent.pop_back();
        ui->graph->recent.push_front(QPair< QString , QString >(QString::number(xCord),QString::number(yCord)));
    }
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
//    ui->graph->points.pop_back();
    ui->graph->repaint();
}

void MainWindow::on_clearButton_clicked()
{
    ui->graph->points.clear();
    ui->graph->recent.clear();
    ui->graph->repaint();
}

// Line Drawing Algorithms
//Parametric
void MainWindow::drawLineParametric(int x0, int y0, int x1, int y1){
    if(x0==x1){
        for(int iy = y0;iy<=y1; ++iy){
            ui->graph->points.insert(QPair< int , int >(x0,iy));
            ui->graph->repaint();
        }
    }
    else{
        if(x0>x1){
            int temp = x0;
            x0 = x1;
            x1 = temp;
            temp = y0;
            y0 = y1;
            y1 = temp;
        }
        float m = float(y1-y0)/float(x1-x0);
        float c = float(x0*y1-x1*y0)/float(x0-x1);
        if(abs(m)>1){

        }
        else{
            for(int ix = x0;ix<=x1; ++ix){
                float fy = m*ix + c ; // y = mx + c
                int iy = (int)(fy+0.5);
                ui->graph->points.insert(QPair< int , int >(ix,iy));
                ui->graph->repaint();
            }
        }
    }
}

//DDA
void MainWindow::drawLineDDA(float x0, float y0, float x1, float y1){
    float dx,dy,step,x,y;
    int i,graphX,graphY;
    dx = (x1-x0);
    dy = (y1-y0);
    if (abs(dx) >= abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
    dx = dx/step;
    dy = dy/step;
    x = x0;
    y = y0;
    i = 1;
    while(i<=step){
        graphX = x;
        graphY = y;
        ui->graph->points.insert(QPair< int , int >(graphX,graphY));
        x += dx;
        y += dy;
        i++;
        ui->graph->repaint();
    }
}

// Bresenham
void MainWindow::bresenhamPlotLineLow(int x0,int y0,int x1, int y1){
    int dx = x1-x0;
    int dy = y1-y0;
    int yi = 1;
    if (dy<0){
        yi = -1;
        dy *= -1;
    }
    int D = 2*dy - dx;
    int y = y0;
    for(int x = x0; x<=x1;x++){
        ui->graph->points.insert(QPair< int , int >(x,y));
        ui->graph->repaint();
        if(D>0){
            y += yi;
            D -= 2*dx;
        }
        D += 2*dy;
    }
}
void MainWindow::bresenhamPlotLineHigh(int x0,int y0,int x1, int y1){
    int dx = x1-x0;
    int dy = y1-y0;
    int xi = 1;
    if (dx<0){
        xi = -1;
        dx *= -1;
    }
    int D = 2*dx - dy;
    int x = x0;
    for(int y = y0; y<=y1;y++){
        ui->graph->points.insert(QPair< int , int >(x,y));
        ui->graph->repaint();
        if(D>0){
            x += xi;
            D -= 2*dy;
        }
        D += 2*dx;
    }
}
void MainWindow::drawLineBresenham(float x0, float y0, float x1, float y1){
    if (abs(y1-y0) < abs(x1-x0)) {
        if (x0 > x1)
            bresenhamPlotLineLow(x1,y1,x0,y0);
        else
            bresenhamPlotLineLow(x0,y0,x1,y1);
    }
    else {
        if (y0 > y1)
            bresenhamPlotLineHigh(x1,y1,x0,y0);
        else
            bresenhamPlotLineHigh(x0,y0,x1,y1);
    }
}


void MainWindow::on_lineDraw_button_clicked()
{
    if(
            ui->dda_start_x->text() == "" ||
            ui->dda_start_y->text() == "" ||
            ui->dda_end_x->text() == "" ||
            ui->dda_end_y->text() == ""
       )
    {
        if(ui->graph->recent.size()==2){
            ui->dda_start_x->setText(ui->graph->recent[1].first);
            ui->dda_start_y->setText(ui->graph->recent[1].second);
            ui->dda_end_x->setText(ui->graph->recent[0].first);
            ui->dda_end_y->setText(ui->graph->recent[0].second);
        }
        else{
            statusBar()->showMessage("Coordinates not sufficient",2000);
            return;
        }
    }
    float x0 = (ui->dda_start_x->text()).toFloat();
    float y0 = (ui->dda_start_y->text()).toFloat();
    float x1 = (ui->dda_end_x->text()).toFloat();
    float y1 = (ui->dda_end_y->text()).toFloat();
    QTime timer;
    timer.start();
    switch(ui->lineDrawingMethodsCombo->currentIndex()){
        case 0:
            drawLineParametric(x0,y0,x1,y1);
            break;
        case 1:
            drawLineDDA(x0,y0,x1,y1);
            break;
        case 2:
            drawLineBresenham(x0,y0,x1,y1);
            break;
    }
    statusBar()->showMessage("Time taken: "+QString::number(timer.elapsed()) + "ms",2000);
}

// Circle Drawing algorithm

// Cartesian form
void MainWindow::drawCircleCartesian(int cx, int cy, float r){
    ui->graph->points.insert(QPair< int , int >(cx,cy));
    ui->graph->repaint();
    int ixR = cx;
    int ixL = cx-1;
    int iy = cy;
    float diff;
    do{
        diff = sqrt(r*r-(ixR-cx)*(ixR-cx));
        ui->graph->points.insert(QPair< int , int >(ixR,iy+diff));
        ui->graph->points.insert(QPair< int , int >(ixR,iy-diff));
        ui->graph->points.insert(QPair< int , int >(ixL,iy+diff));
        ui->graph->points.insert(QPair< int , int >(ixL,iy-diff));
        ui->graph->repaint();
        ixR++;
        ixL--;
    }
    while (ixR<=(int)(1.42*(cx+r))); // root2 is 1.414 so took 1.42

    int iyU = cy;
    int iyD = cy-1;
    int ix = cx;
    do{
        diff = sqrt(r*r-(iyU-cy)*(iyU-cy));
        ui->graph->points.insert(QPair< int , int >(ix+diff,iyU));
        ui->graph->points.insert(QPair< int , int >(ix-diff,iyU));
        ui->graph->points.insert(QPair< int , int >(ix+diff,iyD));
        ui->graph->points.insert(QPair< int , int >(ix-diff,iyD));
        ui->graph->repaint();
        iyU++;
        iyD--;
    }
    while (iyU<=(int)(1.42*(cy+r))); // root2 is 1.414 so took 1.42
}

// Polar Form
void MainWindow::drawCirclePolar(int cx, int cy, float r){
    ui->graph->points.insert(QPair< int , int >(cx,cy));
    ui->graph->repaint();
    int ix = cx;
    int iy = cy;
    float delTheta = 1/r;
    float theta = 0;
    do{
        float cosTheta = r*cos(theta);
        float sinTheta = r*sin(theta);
        ui->graph->points.insert(QPair< int , int >(ix+cosTheta,iy+sinTheta));
        ui->graph->points.insert(QPair< int , int >(ix+cosTheta,iy-sinTheta));
        ui->graph->points.insert(QPair< int , int >(ix-cosTheta,iy+sinTheta));
        ui->graph->points.insert(QPair< int , int >(ix-cosTheta,iy-sinTheta));
        ui->graph->repaint();
        theta += delTheta;
    }
    while (theta<=1.571); // pi = 3.141 => pi/2 = 1.570795
}
void MainWindow::on_circleDrawButton_clicked()
{
    if( ui->circleCenterX->text() == "" || ui->circleCenterY->text() == "" )
    {
        if(ui->graph->recent.size()>0){
            ui->circleCenterX->setText(ui->graph->recent[0].first);
            ui->circleCenterY->setText(ui->graph->recent[0].second);
        }
        else{
            statusBar()->showMessage("Center not specified",2000);
            return;
        }
    }
    if( ui->circleRadius->text() == "")
    {
        if(ui->graph->recent.size()>1){
            int x1 = (ui->graph->recent[0].first).toInt();
            int y1 = (ui->graph->recent[0].second).toInt();
            int x2 = (ui->graph->recent[1].first).toInt();
            int y2 = (ui->graph->recent[1].second).toInt();
            ui->circleRadius->setText(QString::number((sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)))));
        }
        else{
            statusBar()->showMessage("Radiusr not specified",2000);
            return;
        }
    }
    int cx = (ui->circleCenterX->text()).toInt();
    int cy = (ui->circleCenterY->text()).toInt();
    float r = (ui->circleRadius->text()).toFloat();
    QTime timer;
    timer.start();
    switch(ui->circleDrawMethod->currentIndex()){
        case 0:
            drawCircleCartesian(cx,cy,r);
            break;
        case 1:
            drawCirclePolar(cx,cy,r);
            break;
        case 2:
            // drawCircleBresenham(cx,cy,r);
            break;
    }
    statusBar()->showMessage("Time taken: "+QString::number(timer.elapsed()) + "ms",2000);

}
