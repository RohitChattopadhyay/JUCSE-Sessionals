#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QHBoxLayout>
#include <QTime>
#include <iostream>
#include <utility>

using namespace std;

class Graph : public QGraphicsView
{
    Q_OBJECT    
    int pixelsize;
    int no_of_pixels;
    int mouseclickStatus;
    int brushColor;
    pair<float, float> points[2];

    class MyGraphicsScene : public QGraphicsScene
    {
        Graph *parent;

    public:
        MyGraphicsScene(Graph *p)
        {
            parent = p;            
        }

        void mousePressEvent(QGraphicsSceneMouseEvent *event)
        {
            int xCord = event->scenePos().x() / parent->pixelsize;
            int yCord = event->scenePos().y() / parent->pixelsize;
            emit parent->pointSelect(pair<int, int>(xCord , yCord ));
            parent->GraphPointPaint(xCord, yCord);
        }

        void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
        {
            emit parent->pointHover(pair<int, int>(event->scenePos().x() / parent->pixelsize, event->scenePos().y() / parent->pixelsize));
        }
    };

    MyGraphicsScene *graphscene;

    void GenerateGraph()
    {
        graphscene = new MyGraphicsScene(this);
        graphscene->setBackgroundBrush(Qt::darkRed);
        for (int i = -no_of_pixels / 2; i <= no_of_pixels / 2; i++)
        {
            for (int j = -no_of_pixels / 2; j <= no_of_pixels / 2; j++)
            {
                graphscene->addRect(i * pixelsize, j * pixelsize, pixelsize, pixelsize);
            }
        }

        for (int i = -no_of_pixels / 2; i <= no_of_pixels / 2; i++)
        {
            QGraphicsItem *item = graphscene->itemAt(i * pixelsize, 0, QTransform());
            QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(item);
            if (rect == NULL)
            {
                cout << "rect is null at " << i << " "
                     << "0" << endl;
            }
            QBrush br(Qt::SolidPattern);
            br.setColor(Qt::darkGray);
            rect->setBrush(br);
            rect->update();
        }

        for (int i = -no_of_pixels / 2; i <= no_of_pixels / 2; i++)
        {
            QGraphicsItem *item = graphscene->itemAt(0, i * pixelsize, QTransform());
            QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(item);
            if (rect == NULL)
            {
                cout << "rect is null at " << i << " "
                     << "0" << endl;
            }
            QBrush br(Qt::SolidPattern);
            br.setColor(Qt::darkGray);
            rect->setBrush(br);
            rect->update();
        }
        this->setScene(graphscene);

        mouseclickStatus = 0;
    }

public:
    Graph(int p = 5, int n = 100)
    {
        this->setMouseTracking(1);
        pixelsize = p;
        no_of_pixels = n;
        GenerateGraph();
    }

    void GraphPointPaint(int x, int y)
    {
        if (abs(x) > no_of_pixels / 2 && abs(y) > no_of_pixels / 2)
        {
            cout << "pixel coordinates: (" << x << "," << y << ") incorrect " << no_of_pixels * pixelsize / 2 << endl;
            return;
        }
        else
        {
            QGraphicsItem *item = graphscene->itemAt(x * pixelsize, y * pixelsize, QTransform());
            if (item == NULL)
            {
//                cout << " item at pixel coordinates: (" << x << "," << y << ") not found" << endl;
                return;
            }

            QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(item);

            QBrush *br = new QBrush(Qt::SolidPattern);
            switch(brushColor){
                case 0:
                    br->setColor(Qt::yellow);
                    break;
                case 1:
                    br->setColor(Qt::green);
                    break;
                case 2:
                    br->setColor(Qt::red);
                    break;
            }


            rect->setBrush(*br);
            rect->update();
        }
    }

    void GraphReset()
    {
        GenerateGraph();
    }

    void GraphReset(int p, int n)
    {
        pixelsize = p;
        no_of_pixels = n;
        GenerateGraph();
    }

public:
signals:
    void pointSelect(pair<int, int>);
    void pointHover(pair<int, int>);

public slots:
    void GraphPlotSlot(int x, int y){
        this->GraphPointPaint(x,y);
    };
    void GraphPlotColorSlot(int x){
        brushColor = x;
    };
    void GraphResetSlot(int p, int n)
    {
        pixelsize = p;
        no_of_pixels = n;
        GenerateGraph();
    }
};
