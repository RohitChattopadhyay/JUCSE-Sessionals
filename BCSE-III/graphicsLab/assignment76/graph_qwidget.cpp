#include "graph_qwidget.h"
#include "mainwindow.h"
#include <cstdlib>

graph_qWidget::graph_qWidget(QWidget *parent) : QWidget(parent)
{
    ker = 3;
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

    painter.setPen(QPen(Qt::white, 2, Qt::SolidLine));
    painter.drawPoint(half,half);
    painter.setPen(QPen(Qt::yellow, ker, Qt::SolidLine));

    for(auto it =  points.begin(); it != points.end() ; ++it)
        painter.drawPoint(ker*it->first + width()/2,height()/2 -  ker*it->second);
    if ( ker==1 ){
        painter.setPen(QPen(Qt::green, ker, Qt::DotLine));
        painter.drawLine(half,0,half,size);
        painter.drawLine(0,half,size,half);
        return;
    }
    for(int i = -1*half; i<=half; i+=1){
        if (abs(i)%ker!=0)
            continue;
        if(i==0)
                painter.setPen(QPen(Qt::green, 1, Qt::SolidLine));
        else
                painter.setPen(QPen(Qt::green, 1, Qt::DotLine));
        painter.drawLine(i+half,0,i+half,size);
        painter.drawLine(0,i+half,size,i+half);
    }

}
