#include "graph_qwidget.h"
#include "mainwindow.h"
#include <cstdlib>

graph_qWidget::graph_qWidget(QWidget *parent) : QWidget(parent)
{
    ker = 3;
    brushColorIdx = 0;
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
    switch (brushColorIdx) {
    case 0:
        painter.setPen(QPen(Qt::yellow, ker, Qt::SolidLine));
        break;
    }
    QSet<QPair<int,int> >::iterator it;
    for(it =  points.begin(); it != points.end() ; ++it)
        painter.drawPoint(ker*it->first + width()/2-ker/2,height()/2 -  ker*it->second-ker/2);

}
