#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QString>
#include <string>
#include <utility>
#include <iostream>
#include <QtCore/qmath.h>
#include <QTime>

using namespace std;

class ControlPanel : public QWidget
{
    Q_OBJECT

    //members of graph setting-----------------------------
    int pixelsize;
    int no_of_pixels;
    QLabel *pixelsizeLabel;
    QSpinBox *pixelsizeSpinBox;
    QLabel *noOfPixelsLabel;
    QLabel *timeTaken;
    QSpinBox *noOfPixelsSpinBox;
    QPushButton *setGraphButton;
    QComboBox *setBrushColor;
    //members of drawing------------------------------------
    QComboBox *lineDrawingAlgoComboBox;
    QComboBox *circleDrawingAlgoComboBox;
    QComboBox *ellipseDrawingAlgoComboBox;
    QLabel *clickCoordinate;
    QLabel *mouseCoordinate;

    //members of line drawing
    QLineEdit *lineDrawStartX;
    QLineEdit *lineDrawEndX;
    QLineEdit *lineDrawStartY;
    QLineEdit *lineDrawEndY;

    //members of circle drawing
    QLineEdit *circleDrawCenterX;
    QLineEdit *circleDrawCenterY;
    QLineEdit *circleDrawRadius;

    //members of ellipse drawing
    QLineEdit *ellipseDrawCenterX;
    QLineEdit *ellipseDrawCenterY;
    QLineEdit *ellipseDrawMajor;
    QLineEdit *ellipseDrawMinor;

public:
    ControlPanel()
    {
        pixelsize = 5;
        no_of_pixels = 100;

        //Contents of graph setting----------------------------------------------------
        QGroupBox *setGraphGroup = new QGroupBox("Graph Setting");
        QLayout *setGraphLayout = new QVBoxLayout();

        pixelsizeLabel = new QLabel("Enter the pixel size");
        pixelsizeSpinBox = new QSpinBox();
        pixelsizeSpinBox->setRange(1, 10);
        pixelsizeSpinBox->setValue(5);
        pixelsizeLabel->setBuddy(pixelsizeSpinBox);

        noOfPixelsLabel = new QLabel("Enter the no of pixels");
        noOfPixelsSpinBox = new QSpinBox();
        noOfPixelsSpinBox->setRange(10, 200);
        noOfPixelsSpinBox->setValue(100);
        noOfPixelsLabel->setBuddy(noOfPixelsSpinBox);

        setGraphButton = new QPushButton("Set Graph");

        timeTaken = new QLabel("<b>Time Taken :</b>");
        clickCoordinate = new QLabel("<b>Clicked on :</b>");
        mouseCoordinate = new QLabel("<b>Mouse at :</b>");
        setBrushColor = new QComboBox();
        setBrushColor->addItem("Yellow");
        setBrushColor->addItem("Green");
        setBrushColor->addItem("Red");

        QObject::connect(setGraphButton, SIGNAL(clicked()), this, SLOT(handleButton()));

        setGraphLayout->addWidget(pixelsizeLabel);
        setGraphLayout->addWidget(pixelsizeSpinBox);

        setGraphLayout->addWidget(noOfPixelsLabel);
        setGraphLayout->addWidget(noOfPixelsSpinBox);
        setGraphLayout->addWidget(setGraphButton);
        setGraphLayout->addWidget(new QLabel("Set Brush Color"));
        setGraphLayout->addWidget(setBrushColor);
        QHBoxLayout * mouseInfo = new QHBoxLayout();
        mouseInfo->addWidget(mouseCoordinate);
        mouseInfo->addWidget(clickCoordinate);
        mouseInfo->addWidget(timeTaken);
        QWidget * mouseInfoWidget = new QWidget();
        mouseInfoWidget->setLayout(mouseInfo);
        setGraphLayout->addWidget(mouseInfoWidget);
        setGraphGroup->setLayout(setGraphLayout);

        QTabWidget *allAssignments = new QTabWidget();
        QTabWidget * primitiveDrawing = new QTabWidget();

        //Contents of Line drawing----------------------------------------------------------
        QGroupBox *lineDrawingGroup = new QGroupBox("Line Drawing Algorithms");
        QLayout *lineDrawingLayout = new QVBoxLayout();
        QLabel *lineDrawStartLabel = new QLabel("Start Point");
        lineDrawStartX = new QLineEdit();
        lineDrawStartX->setPlaceholderText("X Coordinate");
        lineDrawEndX = new QLineEdit();
        lineDrawEndX->setPlaceholderText("X Coordinate");
        lineDrawStartY = new QLineEdit();
        lineDrawStartY->setPlaceholderText("Y Coordinate");
        lineDrawEndY = new QLineEdit();
        lineDrawEndY->setPlaceholderText("Y Coordinate");
        QLabel *lineDrawEndLabel = new QLabel("End Point");
        QPushButton *lineButton = new QPushButton("Draw Line");
        QObject::connect(lineButton, SIGNAL(clicked()), this, SLOT(drawLineHandler()));

        lineDrawingAlgoComboBox = new QComboBox();
        lineDrawingAlgoComboBox->addItem("DDA line drawing");
        lineDrawingAlgoComboBox->addItem("Bresenham's line drawing");
        lineDrawingAlgoComboBox->addItem("Parametric line drawing");

        lineDrawingLayout->addWidget(lineDrawingAlgoComboBox);
        QHBoxLayout * lineStartPoint = new QHBoxLayout();
        lineStartPoint->addWidget(lineDrawStartLabel);
        lineStartPoint->addWidget(lineDrawStartX);
        lineStartPoint->addWidget(lineDrawStartY);
        QWidget * lineStartPointWidget = new QWidget();
        lineStartPointWidget->setLayout(lineStartPoint);
        lineDrawingLayout->addWidget(lineStartPointWidget);

        QHBoxLayout * lineEndPoint = new QHBoxLayout();
        lineEndPoint->addWidget(lineDrawEndLabel);
        lineEndPoint->addWidget(lineDrawEndX);
        lineEndPoint->addWidget(lineDrawEndY);
        QWidget * lineEndPointWidget = new QWidget();
        lineEndPointWidget->setLayout(lineEndPoint);
        lineDrawingLayout->addWidget(lineEndPointWidget);

        lineDrawingLayout->addWidget(lineButton);

        lineDrawingGroup->setLayout(lineDrawingLayout);
        QVBoxLayout *layoutLine = new QVBoxLayout();
        layoutLine->addWidget(lineDrawingGroup);
        QWidget * lineDrawing = new QWidget();
        lineDrawing->setLayout(layoutLine);


// Circle Drawing
        QGroupBox *circleDrawingGroup = new QGroupBox("Circle Drawing Algorithms");
        QLayout *circleDrawingLayout = new QVBoxLayout();

        circleDrawingAlgoComboBox = new QComboBox();
        circleDrawingAlgoComboBox->addItem("Cartesian form");
        circleDrawingAlgoComboBox->addItem("Polar form");
        circleDrawingAlgoComboBox->addItem("Bresenham Mid Point form");
        circleDrawingLayout->addWidget(circleDrawingAlgoComboBox);

        QLabel * circleCenterLabel = new QLabel("Center");
        QLabel * circleRadiusLabel = new QLabel("Radius");
        circleDrawCenterX =  new QLineEdit();
        circleDrawCenterX->setPlaceholderText("X Coordinate");
        circleDrawCenterY =  new QLineEdit();
        circleDrawCenterY->setPlaceholderText("Y Coordinate");
        circleDrawRadius =  new QLineEdit();
        circleDrawRadius->setPlaceholderText("In pixels");

        QPushButton *circleButton = new QPushButton("Draw Circle");
        QObject::connect(circleButton, SIGNAL(clicked()), this, SLOT(drawCircleHandler()));

        circleDrawingLayout->addWidget(circleCenterLabel);
        circleDrawingLayout->addWidget(circleDrawCenterX);
        circleDrawingLayout->addWidget(circleDrawCenterY);
        circleDrawingLayout->addWidget(circleRadiusLabel);
        circleDrawingLayout->addWidget(circleDrawRadius);
        circleDrawingLayout->addWidget(circleButton);

        circleDrawingGroup->setLayout(circleDrawingLayout);

        QVBoxLayout *layoutCircle = new QVBoxLayout();
        layoutCircle->addWidget(circleDrawingGroup);
        QWidget * circleDrawing = new QWidget();
        circleDrawing->setLayout(layoutCircle);

// Ellipse Drawing
        QGroupBox *ellipseDrawingGroup = new QGroupBox("Ellipse Drawing Algorithms");
        QLayout *ellipseDrawingLayout = new QVBoxLayout();

        ellipseDrawingAlgoComboBox = new QComboBox();
        ellipseDrawingAlgoComboBox->addItem("Cartesian form");
        ellipseDrawingAlgoComboBox->addItem("Polar form");
        ellipseDrawingAlgoComboBox->addItem("Bresenham Mid Point form");
        ellipseDrawingLayout->addWidget(ellipseDrawingAlgoComboBox);

        ellipseDrawCenterX =  new QLineEdit();
        ellipseDrawCenterX->setPlaceholderText("X Coordinate");
        ellipseDrawCenterY =  new QLineEdit();
        ellipseDrawCenterY->setPlaceholderText("Y Coordinate");
        ellipseDrawMajor =  new QLineEdit();
        ellipseDrawMajor->setPlaceholderText("Major Axis (2a)");
        ellipseDrawMinor =  new QLineEdit();
        ellipseDrawMinor->setPlaceholderText("Minor Axis (2b)");

        QPushButton *ellipseButton = new QPushButton("Draw Ellipse");
        QObject::connect(ellipseButton, SIGNAL(clicked()), this, SLOT(drawLineHandler()));

        QHBoxLayout * ellipseLayoutTemp = new QHBoxLayout();
        ellipseLayoutTemp->addWidget(ellipseDrawCenterX);
        ellipseLayoutTemp->addWidget(ellipseDrawCenterY);
        QWidget * ellipseWidgetTemp = new QWidget();
        ellipseWidgetTemp->setLayout(ellipseLayoutTemp);
        ellipseDrawingLayout->addWidget(new QLabel("Center"));
        ellipseDrawingLayout->addWidget(ellipseWidgetTemp);

        ellipseLayoutTemp = new QHBoxLayout();
        ellipseLayoutTemp->addWidget(ellipseDrawMajor);
        ellipseLayoutTemp->addWidget(ellipseDrawMinor);
        ellipseWidgetTemp = new QWidget();
        ellipseWidgetTemp->setLayout(ellipseLayoutTemp);
        ellipseDrawingLayout->addWidget(new QLabel("Axis"));
        ellipseDrawingLayout->addWidget(ellipseWidgetTemp);

        ellipseDrawingLayout->addWidget(ellipseButton);

        ellipseDrawingGroup->setLayout(ellipseDrawingLayout);

        QVBoxLayout *layoutEllipse = new QVBoxLayout();
        layoutEllipse->addWidget(ellipseDrawingGroup);
        QWidget * ellipseDrawing = new QWidget();
        ellipseDrawing->setLayout(layoutEllipse);

        // tab
        primitiveDrawing->addTab(lineDrawing,"Line");
        primitiveDrawing->addTab(circleDrawing,"Circle");
        primitiveDrawing->addTab(ellipseDrawing,"Ellipse");

        //Parent layout-----------------------------------------------------------------
        QVBoxLayout *layout = new QVBoxLayout();
        allAssignments->addTab(primitiveDrawing,"Primitive");
        layout->addWidget(setGraphGroup);
        layout->addWidget(allAssignments);
        this->setLayout(layout);
    }
    float abs(float a){
        return a>0?a:(-1*a);
    }
    void lineDrawParametric(){
        float  x0, y0, x1, y1;
        x0 = (lineDrawStartX->text()).toInt();
        y0 = -1*(lineDrawStartY->text()).toInt();
        x1 = (lineDrawEndX->text()).toInt();
        y1 = -1*(lineDrawEndY->text()).toInt();
        if(x0>x1){
            int temp = x0;
            x0 = x1;
            x1 = temp;
            temp = y0;
            y0 = y1;
            y1 = temp;
        }
        if(x0==x1){
            for(int iy = y0;iy<=y1; ++iy){
                emit GraphPlotSignal(x0, iy);
            }
        }
        else {
            float c = float(x0*y1-x1*y0)/float(x0-x1);
            float m = float(y1-y0)/float(x1-x0);
            if (abs(m)<1.0){
                for(int ix = x0;ix<=x1; ++ix){
                    float fy = m*ix + c ; // y = mx + c
                    int iy = (int)(fy+0.5);
                    emit GraphPlotSignal(ix, iy);
                }
            }
            else {
                for(int iy = y0;iy<=y1; ++iy){
                    float fx = (iy - c)/m ; // x = (y - c) /m
                    int ix = (int)(fx+0.5);
                    emit GraphPlotSignal(ix, iy);
                }
            }
        }
    }

    void lineDrawDDA(){
        float x, y, x1, y1, x2, y2, dx, dy, step;
        int i;
        x1 = (lineDrawStartX->text()).toInt();
        y1 = -1*(lineDrawStartY->text()).toInt();
        x2 = (lineDrawEndX->text()).toInt();
        y2 = -1*(lineDrawEndY->text()).toInt();
        dx = (x2 - x1);
        dy = (y2 - y1);
        if(abs(dx) >= abs(dy))
          step = abs(dx);
        else
          step = abs(dy);
        dx = dx / step;
        dy = dy / step;
        x = x1;
        y = y1;
        i = 1;
        while(i <= step) {
          emit GraphPlotSignal(x, y);
          x = x + dx;
          y = y + dy;
          i = i + 1;
        }
    }
    void bresenhamPlotLineLow(int x0,int y0,int x1, int y1){
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
            emit GraphPlotSignal(x, y);
            if(D>0){
                y += yi;
                D -= 2*dx;
            }
            D += 2*dy;
        }
    }
    void bresenhamPlotLineHigh(int x0,int y0,int x1, int y1){
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
            emit GraphPlotSignal(x, y);
            if(D>0){
                x += xi;
                D -= 2*dy;
            }
            D += 2*dx;
        }
    }
    void lineDrawBresenham(){
        float x0, y0, x1, y1;
        x0 = (lineDrawStartX->text()).toInt();
        y0 = -1 * (lineDrawStartY->text()).toInt();
        x1 = (lineDrawEndX->text()).toInt();
        y1 = -1 * (lineDrawEndY->text()).toInt();
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

    // Circle drawing
    void circleDrawCartesian(int cx, int cy, float r){
        emit GraphPlotSignal(cx, cy);
        int ixR = cx;
        int ixL = cx-1;
        int iy = cy;
        float diff;
        do{
            diff = sqrt(r*r-(ixR-cx)*(ixR-cx));
            emit GraphPlotSignal(ixR,iy+diff);
            emit GraphPlotSignal(ixR,iy-diff);
            emit GraphPlotSignal(ixL,iy+diff);
            emit GraphPlotSignal(ixL,iy-diff);
            ixR++;
            ixL--;
        }
        while (ixR<=ceil((cx+r/1.4)));

        int iyU = cy;
        int iyD = cy-1;
        int ix = cx;
        do{
            diff = sqrt(r*r-(iyU-cy)*(iyU-cy));
            emit GraphPlotSignal(ix+diff,iyU);
            emit GraphPlotSignal(ix-diff,iyU);
            emit GraphPlotSignal(ix+diff,iyD);
            emit GraphPlotSignal(ix-diff,iyD);
            iyU++;
            iyD--;
        }
        while (iyU<=ceil((cy+r/1.4))); // root2 is 1.414 so took 1.4
    }
    void circleDrawPolar(int cx, int cy, float r){
        emit GraphPlotSignal(cx,cy);
        int ix = cx;
        int iy = cy;
        float delTheta = 1/r;
        float theta = 0;
        do{
            float cosTheta = r*cos(theta);
            float sinTheta = r*sin(theta);
            emit GraphPlotSignal(ix+cosTheta,iy+sinTheta);
            emit GraphPlotSignal(ix+cosTheta,iy-sinTheta);
            emit GraphPlotSignal(ix-cosTheta,iy+sinTheta);
            emit GraphPlotSignal(ix-cosTheta,iy-sinTheta);
            theta += delTheta;
        }
        while (theta<=1.571); // pi = 3.141 => pi/2 = 1.570795
    }
    void circleDrawMidPoint(int cx, int cy, float r){
        int x = r, y = 0;
        emit GraphPlotSignal(cx,cy);
        emit GraphPlotSignal(cx + r,cy);
        emit GraphPlotSignal(cx - r,cy);
        emit GraphPlotSignal(cx,cy + r);
        emit GraphPlotSignal(cx,cy - r);

        if (r > 0)
        {
            emit GraphPlotSignal( x + cx, -y + cy);
            emit GraphPlotSignal( y + cx, x + cy);
            emit GraphPlotSignal( -y + cx, x + cy);
        }

        int P = 1 - r;
        while (x > y)
        {
            y++;
            if (P <= 0)
                P = P + 2*y + 1;
            else
            {
                x--;
                P = P + 2*y - 2*x + 1;
            }

            if (x < y)
                break;

            emit GraphPlotSignal( x + cx, y + cy);
            emit GraphPlotSignal( -x + cx, y + cy);
            emit GraphPlotSignal( x + cx, -y + cy);
            emit GraphPlotSignal( -x + cx, -y + cy);

            if (x != y)
            {
                emit GraphPlotSignal( y + cx, x + cy);
                emit GraphPlotSignal( -y + cx, x + cy);
                emit GraphPlotSignal( y + cx, -x + cy);
                emit GraphPlotSignal( -y + cx, -x + cy);
            }
        }
    }

    // Ellipse drawing
    void ellipseDrawCartesian(){

    }
    void ellipseDrawPolar(){

    }
    void ellipseDrawMidPoint(){

    }
signals:
    void GraphResetSignal(int, int);
    void GraphPlotSignal(int,int);
    void GraphPlotColorSignal(int);

public slots:
    void handleButton()
    {
        pixelsize = pixelsizeSpinBox->value();
        no_of_pixels = noOfPixelsSpinBox->value();
        emit GraphResetSignal(pixelsize, no_of_pixels);
    }
    void drawLineHandler(){
        emit GraphPlotColorSignal(setBrushColor->currentIndex());
        QTime clock;
        clock.start();
        switch(lineDrawingAlgoComboBox->currentIndex()){
            case 0:
                this->lineDrawDDA();
                break;
            case 1:
                this->lineDrawBresenham();
                break;
            case 2:
                this->lineDrawParametric();
                break;
        }
        timeTaken->setText("<b>Time Taken: </b>"+QString::number(clock.elapsed())+"ms");
    }

    void drawCircleHandler(){
        emit GraphPlotColorSignal(setBrushColor->currentIndex());
        int cx,cy;
        float r;
        cx = circleDrawCenterX->text().toInt();
        cy = -1 * (circleDrawCenterY->text().toInt());
        r  = abs(circleDrawRadius->text().toFloat());
        QTime clock;
        clock.start();
        switch(circleDrawingAlgoComboBox->currentIndex()){
            case 0:
                this->circleDrawCartesian(cx,cy,r);
                break;
            case 1:
                this->circleDrawPolar(cx,cy,r);
                break;
            case 2:
                this->circleDrawMidPoint(cx,cy,r);
                break;
        }
        timeTaken->setText("<b>Time Taken: </b>"+QString::number(clock.elapsed())+"ms");
    }

    void getPointHover(pair<int, int> point)
    {
        QString QShowPoint = "<b>Mouse at:</b> " + QString::number(point.first) + " " + QString::number(-1*point.second);
        mouseCoordinate->setText(QShowPoint);
    }

    void getPointSelect(pair<int, int> point)
    {
        emit GraphPlotColorSignal(setBrushColor->currentIndex());
        QString QShowPoint = "<b>Clicked on :</b> " + QString::number(point.first) + " " + QString::number(-1*point.second);
        clickCoordinate->setText(QShowPoint);
    }
};
