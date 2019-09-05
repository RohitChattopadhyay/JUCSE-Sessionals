#ifndef GRAPH_QWIDGET_H
#define GRAPH_QWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <QStyle>
#include <QPainter>
#include <QStyleOption>
#include <QTime>

class graph_qWidget : public QWidget
{
    Q_OBJECT
public:
    explicit graph_qWidget(QWidget *parent = NULL);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *);
    void paintEvent(QPaintEvent *);
    QVector<QPair<QPair<int,int> , int > > points = {};
    QVector<QPair<QString,QString> > recent = {};
    int ker;
    int x,y;
    int brushColorIdx;
    int linearSearch(int x,int y);

signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();
public slots:
};

#endif // GRAPH_QWIDGET_H
