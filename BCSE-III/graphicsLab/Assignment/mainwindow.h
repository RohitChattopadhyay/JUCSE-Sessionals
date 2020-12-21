#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <vector>
#include <algorithm>
#define maxVer 50
#define maxHt 1000
#define maxWd 800

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);

private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    int x_max,x_min,y_max,y_min;

    typedef struct edgebucket
    {
        int ymax;   //max y-coordinate of edge
        float xofymin;  //x-coordinate of lowest edge point updated only in aet
        float slopeinverse;
    }EdgeBucket;

    typedef struct edgetabletup
    {
        // the array will give the scanline number
        // The edge table (ET) with edges entries sorted
        // in increasing y and x of the lower end

        int countEdgeBucket;    //no. of edgebuckets
        EdgeBucket buckets[maxVer];
    }EdgeTableTuple;

    EdgeTableTuple EdgeTable[maxHt], ActiveEdgeTuple;

    std::vector<std::pair<int,int> > EdgeList;
    std::vector<std::pair<int,int> > BezList;

    void point(int x,int y,int r=255,int g=255,int b=0);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_show_axes_clicked();

    void on_Draw_clicked();

    void on_set_point1_clicked();

    void on_set_point2_clicked();

    void on_pushButton_clicked();

    int changeX(int x);

    int changeY(int y);

    void on_showgrid_clicked();

    void on_dda_clicked();

    void on_bress_clicked();

    void on_midpt_clicked();

    void drawCircle(QPoint p1,int r0);

    void on_bress_circle_clicked();

    void drawCircleBress(QPoint p1,int r0);

    void on_ellipse_clicked();

    void drawEllipse(QPoint p1,int rx,int ry);

    void on_flood_fill_clicked();

    void flood_fill_util(int x1,int y1,int k,QRgb q1,int r,int g,int b);

    void on_boundary_fill_clicked();

    void boundary_fill_util(int x1,int y1,int k,QRgb edgecolor,int r,int g,int b);

    void on_scanline_clicked();

    void on_set_vertex_clicked();

    void on_fill_scan_clicked();

    void storeEdgeInTable (int x1,int y1, int x2, int y2);

    void storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv);

    void initEdgeTable();

    void insertionSort(EdgeTableTuple *ett);

    void removeEdgeByYmax(EdgeTableTuple *Tup,int yy);

    void updatexbyslopeinv(EdgeTableTuple *Tup);

    void drawPoly();

    int* matMul3x3(double mat[3][3],int coord[3]);

    void translate(int tx,int ty);

    void on_translate_clicked();
    void on_scale_clicked();
    void rotate(int angle,int piv_x,int piv_y);
    void on_rotate_clicked();
    void on_clr_bound_clicked();
    void reflect_x();
    void on_set_bound_clicked();

    void drawBound();
    void cohenSutherlandClip(int x1, int y1,int x2, int y2);
    int computeCode(int x, int y);

    void on_clip_line_clicked();

    int x_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4);
    int y_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4);
    void clip(int x1, int y1, int x2, int y2);
    void suthHodgClip();
    void on_clip_poly_clicked();
    void on_shear_clicked();
    void on_bez_init_clicked();
    void on_bez_clear_clicked();
    void on_draw_bez_clicked();

    void bezierCurve();
    void on_reflect_clicked();
};

#endif // MAINWINDOW_H
