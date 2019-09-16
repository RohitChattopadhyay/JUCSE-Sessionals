#include "graph_qwidget.h"
#include "mainwindow.h"
#include <cstdlib>

graph_qWidget::graph_qWidget(QWidget *parent) : QWidget(parent)
{
    ker = 3;
    brushColorIdx = 0;
}
int graph_qWidget::linearSearch(int x,int y){    
    for(int i=points.size()-1;i>-1;i--){
        QPair<QPair<int,int>, int>  it = points[i];
        if(it.first.first == x && it.first.second == y)
            return it.second;
    }
    return -1;
}

void graph_qWidget::mouseMoveEvent(QMouseEvent *ev){
    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Pos();
}

void graph_qWidget::mousePressEvent(QMouseEvent *ev){
    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Pressed();
}

void graph_qWidget::leaveEvent(QEvent *){
    emit Mouse_Left();
}
void graph_qWidget::paintEvent(QPaintEvent *pe) {
    QStyleOption styleOption;
    styleOption.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &styleOption, &painter, this);
    int size = this->width();
    int half = size/2;

    if ( ker==1 ){
        painter.setPen(QPen(Qt::green, ker, Qt::DotLine));
        painter.drawLine(half,0,half,size);
        painter.drawLine(0,half,size,half);
    }
    else {
        for(int i = -1*half; i<=half; i+=1){
            if (abs(i)%ker!=0)
                continue;
            painter.setPen(QPen(Qt::darkGreen, 1, Qt::SolidLine));
            painter.drawLine(i+half,0,i+half,size);
            painter.drawLine(0,i+half,size,i+half);
        }
        for(int i=-ker;i<=0;i++){
            painter.setPen(QPen(Qt::green, 1, Qt::SolidLine));
            painter.drawLine(i+half,0,i+half,size);
            painter.drawLine(0,i+half,size,i+half);
            continue;
        }
    }

    painter.setPen(QPen(Qt::white, ker, Qt::SolidLine));
    painter.drawPoint(half-ker/2,half-ker/2);
    QVector<QPair<QPair<int,int>, int> >::iterator it;
    QColor brushColor;
    for(it =  points.begin(); it != points.end() ; ++it){
        switch (it->second) {
        case 0:
            brushColor = Qt::yellow;
            break;
        case 1:
            brushColor = Qt::red;
            break;
        case 2:
            brushColor = Qt::black;
            break;
        case 3:
            brushColor = Qt::blue;
            break;
        case 4:
            brushColor = Qt::white;
            break;
        }
        painter.setPen(QPen(brushColor, ker, Qt::SolidLine));
        painter.drawPoint(ker*it->first.first + width()/2-ker/2,height()/2 -  ker*it->first.second-ker/2);
    }
}
