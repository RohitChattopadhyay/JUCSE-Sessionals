#ifndef GRAPH_QWIDGET_H
#define GRAPH_QWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <QStyle>
#include <QPainter>
#include <QStyleOption>

class graph_qWidget : public QWidget
{
    Q_OBJECT
public:
    explicit graph_qWidget(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *);
    void paintEvent(QPaintEvent *);
    QSet<QPair<int,int>> points = {};
    int ker;
    int x,y;

signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();
public slots:
};

#endif // GRAPH_QWIDGET_H
