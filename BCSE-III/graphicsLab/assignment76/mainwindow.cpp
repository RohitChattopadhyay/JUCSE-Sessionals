#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph_qwidget.h"
#define insertPoint(x,y) ui->graph->points.push_back(QPair<QPair<int , int>,int >(QPair< int , int >(x,y),ui->graph->brushColorIdx))

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusLabel = new QLabel("");
    statusLabel->setMinimumWidth(75);
    statusBar()->addPermanentWidget(new QLabel(QString::fromUtf8("\u0995\u09CB")));
    statusBar()->addPermanentWidget(statusLabel);
    connect(ui->graph, SIGNAL(Mouse_Pos()),this,SLOT(Mouse_current_pos()));
    connect(ui->graph, SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
    connect(ui->graph, SIGNAL(Mouse_Left()),this,SLOT(Mouse_left()));
    ui->graph->resize(480,480);
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
    insertPoint(xCord,yCord);
    ui->graph->recent.push_front(QPair< QString , QString >(QString::number(xCord),QString::number(yCord)));
    statusBar()->showMessage("Plotted: " + QString::number(xCord) + "," + QString::number(yCord),2000);
    ui->graph->repaint();
    if(ui->algoTab->currentIndex()==1)
        ui->fillingPointsCount->setText(QString::number(ui->fillingPointsCount->text().toInt()+1));

    if(ui->algoTab->currentIndex()==2)
        ui->clipPointCount->setText(QString::number(floor(ui->graph->recent.size()/2)));
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

void MainWindow::on_clearButton_clicked()
{
    ui->graph->points.clear();
    ui->graph->recent.clear();
    ui->graph->repaint();
    foreach(QLineEdit* le, findChildren<QLineEdit*>())
       le->clear();
    ui->gridBgColor->setText("#173C1B");
}

// Line Drawing Algorithms
//Parametric
void MainWindow::drawLineParametric(int x0, int y0, int x1, int y1){
    if(x0==x1){
        for(int iy = y0;iy<=y1; ++iy){
            insertPoint(x0,iy);
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
            if(y0>y1){
                int temp = x0;
                x0 = x1;
                x1 = temp;
                temp = y0;
                y0 = y1;
                y1 = temp;
            }
            for(int iy = y0;iy<=y1; ++iy){
                float fx = (iy - c)/m ; // x = (y-c)/m
                int ix = (int)(fx+0.5);
                insertPoint(ix,iy);
                ui->graph->repaint();
            }
        }
        else{
            for(int ix = x0;ix<=x1; ++ix){
                float fy = m*ix + c ; // y = mx + c
                int iy = (int)(fy+0.5);
                insertPoint(ix,iy);
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
        insertPoint(graphX,graphY);
        x += dx;
        y += dy;
        i++;
        ui->graph->repaint();
    }
}

// Bresenham
void MainWindow::bresenhamPlotLineLow(int x0,int y0,int x1, int y1, bool animate = true){
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
        insertPoint(x,y);
        if(animate) ui->graph->repaint();
        if(D>0){
            y += yi;
            D -= 2*dx;
        }
        D += 2*dy;
    }
}
void MainWindow::bresenhamPlotLineHigh(int x0,int y0,int x1, int y1, bool animate = true){
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
        insertPoint(x,y);
        if(animate) ui->graph->repaint();
        if(D>0){
            x += xi;
            D -= 2*dy;
        }
        D += 2*dx;
    }
}
void MainWindow::drawLineBresenham(float x0, float y0, float x1, float y1, bool animate = true){
    if (abs(y1-y0) < abs(x1-x0)) {
        if (x0 > x1)
            bresenhamPlotLineLow(x1,y1,x0,y0,animate);
        else
            bresenhamPlotLineLow(x0,y0,x1,y1,animate);
    }
    else {
        if (y0 > y1)
            bresenhamPlotLineHigh(x1,y1,x0,y0,animate);
        else
            bresenhamPlotLineHigh(x0,y0,x1,y1,animate);
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
        if(ui->graph->recent.size()>1){
            ui->dda_start_x->setText(ui->graph->recent[0].first);
            ui->dda_start_y->setText(ui->graph->recent[0].second);
            ui->dda_end_x->setText(ui->graph->recent[1].first);
            ui->dda_end_y->setText(ui->graph->recent[1].second);
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
    insertPoint(cx,cy);
    ui->graph->repaint();
    int ixR = cx;
    int ixL = cx-1;
    int iy = cy;
    float diff;
    do{
        diff = sqrt(r*r-(ixR-cx)*(ixR-cx));
        insertPoint(ixR,iy+diff);
        insertPoint(ixR,iy-diff);
        insertPoint(ixL,iy+diff);
        insertPoint(ixL,iy-diff);
        ui->graph->repaint();
        ixR++;
        ixL--;
    }
    while (ixR<=ceil((cx+r))); // root2 is 1.414 so took 1.4

    int iyU = cy;
    int iyD = cy-1;
    int ix = cx;
    do{
        diff = sqrt(r*r-(iyU-cy)*(iyU-cy));
        insertPoint(ix+diff,iyU);
        insertPoint(ix-diff,iyU);
        insertPoint(ix+diff,iyD);
        insertPoint(ix-diff,iyD);
        ui->graph->repaint();
        iyU++;
        iyD--;
    }
    while (iyU<=ceil((cy+r))); // root2 is 1.414 so took 1.4
}

// Polar Form
void MainWindow::drawCirclePolar(int cx, int cy, float r){
    insertPoint(cx,cy);
    ui->graph->repaint();
    int ix = cx;
    int iy = cy;
    float delTheta = 1/r;
    float theta = 0;
    do{
        float cosTheta = r*cos(theta);
        float sinTheta = r*sin(theta);
        insertPoint(ix+cosTheta,iy+sinTheta);
        insertPoint(ix+cosTheta,iy-sinTheta);
        insertPoint(ix-cosTheta,iy+sinTheta);
        insertPoint(ix-cosTheta,iy-sinTheta);
        ui->graph->repaint();
        theta += delTheta;
    }
    while (theta<=1.571); // pi = 3.141 => pi/2 = 1.570795
}
// Bresenham Mid Point
void MainWindow::drawCircleBresenhamMidPoint(int xc, int yc, float r){
    insertPoint(xc,yc); //center
    int x = 0, y = r;
    int d = 3 - 2 * r;
    // eight way symmetry
    insertPoint(xc+x, yc+y);
    insertPoint(xc-x, yc+y);
    insertPoint(xc+x, yc-y);
    insertPoint(xc-x, yc-y);
    insertPoint(xc+y, yc+x);
    insertPoint(xc-y, yc+x);
    insertPoint(xc+y, yc-x);
    insertPoint(xc-y, yc-x);
    ui->graph->repaint();
    while (y >= x)
    {
        x++;

        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        insertPoint(xc+x, yc+y);
        insertPoint(xc-x, yc+y);
        insertPoint(xc+x, yc-y);
        insertPoint(xc-x, yc-y);
        insertPoint(xc+y, yc+x);
        insertPoint(xc-y, yc+x);
        insertPoint(xc+y, yc-x);
        insertPoint(xc-y, yc-x);
        ui->graph->repaint();
    }
}

void MainWindow::drawCircleMidPoint(int cx, int cy, float r){
    int x = r, y = 0;
    insertPoint(cx,cy);
    insertPoint(x + cx,y + cy);

    if (r > 0)
    {
        insertPoint( x + cx, -y + cy);
        insertPoint( y + cx, x + cy);
        insertPoint( -y + cx, x + cy);
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

        insertPoint( x + cx, y + cy);
        insertPoint( -x + cx, y + cy);
        insertPoint( x + cx, -y + cy);
        insertPoint( -x + cx, -y + cy);

        if (x != y)
        {
            insertPoint( y + cx, x + cy);
            insertPoint( -y + cx, x + cy);
            insertPoint( y + cx, -x + cy);
            insertPoint( -y + cx, -x + cy);
        }
        ui->graph->repaint();
    }
}

void MainWindow::on_circleDrawButton_clicked()
{
    if( ui->circleCenterX->text() == "" || ui->circleCenterY->text() == "" )
    {
        if(ui->graph->recent.size()>1){
            ui->circleCenterX->setText(ui->graph->recent[1].first);
            ui->circleCenterY->setText(ui->graph->recent[1].second);
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
            statusBar()->showMessage("Radius not specified",2000);
            return;
        }
    }
    int cx = (ui->circleCenterX->text()).toInt();
    int cy = (ui->circleCenterY->text()).toInt();
    float r = abs((ui->circleRadius->text()).toFloat());
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
            drawCircleMidPoint(cx,cy,r);
            break;
        case 3:
            drawCircleBresenhamMidPoint(cx,cy,r);
            break;
    }
    statusBar()->showMessage("Time taken: "+QString::number(timer.elapsed()) + "ms",2000);
}

// Ellipse Drawing Algorithm

// Cartesian Form
void MainWindow::drawEllipseCartesian(int cx,int cy,float a, float b){
    insertPoint(cx,cy);
    ui->graph->repaint();
    float aSq = a*a;
    float bSq = b*b;
    float diff;
    int ixL,ixR;
    ixR = cx;
    ixL = cx;
    do {
        diff = sqrt(bSq*(1-((ixR-cx)*(ixR-cx))/aSq));                
        insertPoint( ixR, cy + diff);
        insertPoint( ixR, cy - diff);
        insertPoint( ixL, cy + diff);
        insertPoint( ixL, cy - diff);
        ui->graph->repaint();
        ixR++;
        ixL--;
    }
    while (ixR <= (cx + a));

    int iyD,iyU;
    iyD = cy;
    iyU = cy;
    do {
        diff = sqrt(aSq*(1-((iyU-cy)*(iyU-cy))/bSq));        
        insertPoint( cx + diff, iyU);
        insertPoint( cx - diff, iyU);
        insertPoint( cx + diff, iyD);
        insertPoint( cx - diff, iyD);
        ui->graph->repaint();
        iyU++;
        iyD--;
    }
    while (iyU <= (cy + b));
}
// Polar form
void MainWindow::drawEllipsePolar(int cx, int cy, float a, float b){
    insertPoint(cx,cy);
    ui->graph->repaint();
    int ix = cx;
    int iy = cy;
    float delTheta = 1/sqrt(a*a+b*b);
    float theta = 0;
    do{
        float cosTheta = a*cos(theta);
        float sinTheta = b*sin(theta);

        insertPoint(ix+cosTheta,iy+sinTheta);
        insertPoint(ix+cosTheta,iy-sinTheta);
        insertPoint(ix-cosTheta,iy+sinTheta);
        insertPoint(ix-cosTheta,iy-sinTheta);
        ui->graph->repaint();
        theta += delTheta;
    }
    while (theta<=1.571); // pi = 3.141 => pi/2 = 1.570795
}
// Bresenham mid point
void MainWindow::drawEllipseBresenham(int xc, int yc, float rx, float ry){
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy)
    {
        insertPoint(x + xc,y + yc);
        insertPoint(-x + xc,y + yc);
        insertPoint(x + xc,-y + yc);
        insertPoint(-x + xc,-y + yc);
        ui->graph->repaint();
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0)
    {
        insertPoint(x + xc,y + yc);
        insertPoint(-x + xc,y + yc);
        insertPoint(x + xc,-y + yc);
        insertPoint(-x + xc,-y + yc);
        ui->graph->repaint();
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

void MainWindow::on_ellipseDrawButton_clicked()
{
    if(
            ui->ellipseCenterX->text() == "" ||
            ui->ellipseCenterY->text() == "" ||
            ui->ellipseMajorAxisLen->text() == "" ||
            ui->ellipseMinorAxisLen->text() == ""
    )
    {
        statusBar()->showMessage("Data insufficient",2000);
        return;
    }
    int cx = (ui->ellipseCenterX->text()).toInt();
    int cy = (ui->ellipseCenterY->text()).toInt();
    float a = abs((ui->ellipseMajorAxisLen->text()).toFloat())/2; // Major axis = 2a
    float b = abs((ui->ellipseMinorAxisLen->text()).toFloat())/2; // Minor axis = 2b
    QTime timer;
    timer.start();
    switch(ui->ellipseDrawMethod->currentIndex()){
        case 0:
            drawEllipseCartesian(cx,cy,a,b);
            break;
        case 1:
            drawEllipsePolar(cx,cy,a,b);
            break;
        case 2:
            drawEllipseBresenham(cx,cy,a,b);
            break;
    }
    statusBar()->showMessage("Time taken: "+QString::number(timer.elapsed()) + "ms",2000);

}

void MainWindow::on_brushColor_currentIndexChanged(int index)
{
    ui->graph->brushColorIdx = index;
}

void MainWindow::on_gridBgColor_textEdited(const QString &arg)
{
    ui->graph->setStyleSheet("background-color: "+arg);
}


// Filling Algorithm
// Scanline
void MainWindow::fillingScanLine(int xMin,int xMax,int yMin, int yMax,bool animate, int pixel,int boundary){
    ui->graph->brushColorIdx = pixel;
    for(int y = yMin; y<=yMax; y++){
        bool start = false;
        int x1 = xMin;
        QVector< QPair< int, int > > pointPair;
        for(int x=xMin; x <=xMax; x++){
            if(ui->graph->linearSearch(x,y)==boundary){
                if(!start){
                    pointPair.push_back(QPair<int, int> (x1+1,x-1));
                    x1 = x;
                    start = true;
                }
            }
            else {
                start = false;
            }
        }
        for(int i = 1; i < pointPair.size() ; i += 2){
            for(int s = pointPair[i].first ; s<=pointPair[i].second ; s++){
                insertPoint(s,y);
            }
        }
        pointPair.clear();
        if(animate) ui->graph->repaint();
    }
    ui->graph->brushColorIdx = boundary;
    return;
}
// Boundary fill
void MainWindow::boundaryFill(int x,int y,bool animate, int pixel,int boundary){
    int current = ui->graph->linearSearch(x,y);
    if(current != boundary && current != pixel){
        insertPoint(x,y);
        boundaryFill(x,y+1,animate, pixel,boundary);
        boundaryFill(x+1,y,animate,pixel,boundary);
        boundaryFill(x-1,y,animate,pixel,boundary);
        boundaryFill(x,y-1,animate,pixel,boundary);
        if(animate) ui->graph->repaint();
    }
    return;
}
void MainWindow::floodFill(int x,int y,bool animate, int pixel,int old){
    int current = ui->graph->linearSearch(x,y);
    if(current == old){
        insertPoint(x,y);
        floodFill(x,y+1,animate, pixel,old);
        floodFill(x+1,y,animate,pixel,old);
        floodFill(x-1,y,animate,pixel,old);
        floodFill(x,y-1,animate,pixel,old);
        if(animate) ui->graph->repaint();
    }
    return;
}

void MainWindow::on_fillingButton_clicked()
{
    int startX=0,startY=0;
    int pointCount = (ui->fillingPointsCount->text()).toInt();
    int fillingMethod= (ui->fillingMethodAlgoBox->currentIndex());
    if((ui->graph->recent.size()>=pointCount || fillingMethod==1 ) && pointCount>0){
        int xMin,yMin,xMax,yMax,xTemp,yTemp;
        xMin = INT_MAX;
        yMin = INT_MAX;
        xMax = INT_MIN;
        yMax = INT_MIN;
        if(fillingMethod != 1){
            for(int i=0;i<pointCount-1;i++){
                drawLineBresenham(ui->graph->recent[i].first.toInt(),
                                  ui->graph->recent[i].second.toInt(),
                                  ui->graph->recent[i+1].first.toInt(),
                                  ui->graph->recent[i+1].second.toInt());
                xTemp = ui->graph->recent[i].first.toInt();
                yTemp = ui->graph->recent[i].second.toInt();
                startX += xTemp;
                startY += yTemp;
                if( xTemp<=xMin )
                    xMin = xTemp;
                if( yTemp<=yMin )
                    yMin = yTemp;
                if( xTemp>=xMax )
                    xMax = xTemp;
                if( yTemp>=yMax )
                    yMax = yTemp;
            }
            drawLineBresenham(ui->graph->recent[0].first.toInt(),
                              ui->graph->recent[0].second.toInt(),
                              ui->graph->recent[pointCount-1].first.toInt(),
                              ui->graph->recent[pointCount-1].second.toInt());

            xTemp = ui->graph->recent[pointCount-1].first.toInt();
            yTemp = ui->graph->recent[pointCount-1].second.toInt();
            startX += xTemp;
            startY += yTemp;
            if( xTemp<=xMin )
                xMin = xTemp;
            if( yTemp<=yMin )
                yMin = yTemp;
            if( xTemp>=xMax )
                xMax = xTemp;
            if( yTemp>=yMax )
                yMax = yTemp;

            for(int i = 0; i<pointCount;i++)
                ui->graph->recent.pop_front();

            startX /= pointCount;
            startY /= pointCount;
        }
        int pixelColor = ui->fillingColorComboBox->currentIndex();
        int boundaryColor = ui->brushColor->currentIndex();
        bool animation = ui->fillingAnimation->isChecked();
        ui->graph->brushColorIdx = pixelColor;
        QTime timer;
        timer.start();
        switch(fillingMethod){
            case 0:
                fillingScanLine(xMin,xMax,yMin,yMax,animation,pixelColor,boundaryColor);
                break;
            case 1:{
                int tempX = ui->graph->recent[0].first.toInt();
                int tempY = ui->graph->recent[0].second.toInt();
                floodFill(tempX,tempY,animation,pixelColor,ui->graph->linearSearch(tempX,tempY));
                break;
            }
            case 2:
                boundaryFill(startX,startY,animation,pixelColor,boundaryColor);
                break;
        }

        if(!animation) ui->graph->repaint();
        ui->graph->brushColorIdx = boundaryColor;
        ui->fillingPointsCount->setText("0");
        statusBar()->showMessage("Time taken: "+QString::number(timer.elapsed()) + "ms",2000);
    }
    else{
        statusBar()->showMessage("Insufficient Points\n",2000);
    }
}


void MainWindow::on_clipWindowButton_clicked()
{
    int width = ui->clipWindowWidth->text().toInt();
    int height = ui->clipWindowHeight->text().toInt();
    if(ui->graph->recent.size()>0 && width*height!=0){
        int tempBrushColor = ui->graph->brushColorIdx;
//        ui->graph->brushColorIdx = 4;
        clipWinX = ui->graph->recent[0].first.toInt();
        clipWinY = ui->graph->recent[0].second.toInt();
        ui->graph->recent.pop_front();
        drawLineBresenham(clipWinX,clipWinY,clipWinX+width,clipWinY);
        drawLineBresenham(clipWinX,clipWinY,clipWinX,clipWinY+height);
        drawLineBresenham(clipWinX+width,clipWinY,clipWinX+width,clipWinY+height);
        drawLineBresenham(clipWinX,clipWinY+height,clipWinX+width,clipWinY+height);
        ui->graph->brushColorIdx = tempBrushColor;
    }
}

//Clipping
// Linear clipping
int clipGetPointCode(int x, int y, int x_min, int y_min, int x_max, int y_max )
{
    // initialized as being inside
    int code = 0;

    if (x < x_min)       // to the left of rectangle
        code |= 1;
    else if (x > x_max)  // to the right of rectangle
        code |= 2;
    if (y < y_min)       // below the rectangle
        code |= 4;
    else if (y > y_max)  // above the rectangle
        code |= 8;

    return code;
}
void MainWindow::linearClip(){
    int width = ui->clipWindowWidth->text().toInt();
    int height = ui->clipWindowHeight->text().toInt();
    int xMin = clipWinX;
    int xMax = clipWinX + width;
    int yMin = clipWinY;
    int yMax = clipWinY + height;
    QVector< QPair < QVector< int > , QVector< int > > > lines;
    while(ui->graph->recent.size()!=0){
        QVector< int > a;
        a.push_back(ui->graph->recent[0].first.toInt());
        a.push_back(ui->graph->recent[0].second.toInt());
        a.push_back(clipGetPointCode(ui->graph->recent[0].first.toInt(),ui->graph->recent[0].second.toInt(),xMin,yMin,xMax,yMax));
        ui->graph->recent.pop_front();
        QVector< int > b;
        b.push_back(ui->graph->recent[0].first.toInt());
        b.push_back(ui->graph->recent[0].second.toInt());
        b.push_back(clipGetPointCode(ui->graph->recent[0].first.toInt(),ui->graph->recent[0].second.toInt(),xMin,yMin,xMax,yMax));
        ui->graph->recent.pop_front();
        lines.push_back(qMakePair(a,b));
    }
    for( int i = 0; i < lines.size();i++){
        QPair < QVector< int > , QVector< int > > line = lines[i];
        QVector< int > a = line.first;
        QVector< int > b = line.second;
        int sX = a[0];
        int sY = a[1];
        int s  = a[2];
        int eX = b[0];
        int eY = b[1];
        int e  = b[2];
        while (true)
            {
                if ((s == 0) && (e == 0))
                {
                    drawLineBresenham(sX,sY,eX,eY);
                    break;
                }
                else if (s & e)
                {
                    line.first[0] = -1;
                    line.first[1] = -1;
                    line.first[2] = -1;
                    line.second[0] = -1;
                    line.second[1] = -1;
                    line.second[2] = -1;
                    break;
                }
                else
                {
                    int code_out;
                    double x, y;

                    if (s != 0)
                        code_out = s;
                    else
                        code_out = e;

                    if (code_out & 8)
                    {
                        x = sX + (eX - sX) * (yMax - sY) / (eY - sY);
                        y = yMax;
                    }
                    else if (code_out & 4)
                    {
                        x = sX + (eX - sX) * (yMin - sY) / (eY - sY);
                        y = yMin;
                    }
                    else if (code_out & 2)
                    {
                        y = sY + (eY - sY) * (xMax - sX) / (eX - sX);
                        x = xMax;
                    }
                    else if (code_out & 1)
                    {
                        y = sY + (eY - sY) * (xMin - sX) / (eX - sX);
                        x = xMin;
                    }

                    if (code_out == s)
                    {
                        sX = x;
                        sY = y;
                        s = clipGetPointCode(sX,sY,xMin,yMin,xMax,yMax);
                        line.first[0] = sX;
                        line.first[0] = sY;
                        line.first[0] = s;
                    }
                    else
                    {
                        eX = x;
                        eY = y;
                        e = clipGetPointCode(eX,eY,xMin,yMin,xMax,yMax);
                        line.second[0] = eX;
                        line.second[0] = eY;
                        line.second[0] = e;
                    }
                }
            }
    }
}

// Polygon Clipping
void MainWindow::polygonClip(){
    int width = ui->clipWindowWidth->text().toInt();
    int height = ui->clipWindowHeight->text().toInt();
    int xMin = clipWinX;
    int xMax = clipWinX + width;
    int yMin = clipWinY;
    int yMax = clipWinY + height;
    QVector< QPair < QVector< int > , QVector< int > > > lines;
    QVector< int > first;
    first.push_back(ui->graph->recent[0].first.toInt());
    first.push_back(ui->graph->recent[0].second.toInt());
    first.push_back(clipGetPointCode(ui->graph->recent[0].first.toInt(),ui->graph->recent[0].second.toInt(),xMin,yMin,xMax,yMax));
    QVector< int > b;
    while(ui->graph->recent.size()>1){
        QVector< int > a;
        a.push_back(ui->graph->recent[0].first.toInt());
        a.push_back(ui->graph->recent[0].second.toInt());
        a.push_back(clipGetPointCode(ui->graph->recent[0].first.toInt(),ui->graph->recent[0].second.toInt(),xMin,yMin,xMax,yMax));
        ui->graph->recent.pop_front();
        b.clear();
        b.push_back(ui->graph->recent[0].first.toInt());
        b.push_back(ui->graph->recent[0].second.toInt());
        b.push_back(clipGetPointCode(ui->graph->recent[0].first.toInt(),ui->graph->recent[0].second.toInt(),xMin,yMin,xMax,yMax));
        lines.push_back(qMakePair(a,b));
    }
    lines.push_back(qMakePair(b,first));
    for( int i = 0; i < lines.size();i++){
        QPair < QVector< int > , QVector< int > > line = lines[i];
        QVector< int > a = line.first;
        QVector< int > b = line.second;
        int sX = a[0];
        int sY = a[1];
        int s  = a[2];
        int eX = b[0];
        int eY = b[1];
        int e  = b[2];
        while (true)
            {
                if ((s == 0) && (e == 0))
                {
                    drawLineBresenham(sX,sY,eX,eY);
                    break;
                }
                else if (s & e)
                {
                    line.first[0] = -1;
                    line.first[1] = -1;
                    line.first[2] = -1;
                    line.second[0] = -1;
                    line.second[1] = -1;
                    line.second[2] = -1;
                    break;
                }
                else
                {
                    int code_out;
                    double x, y;

                    if (s != 0)
                        code_out = s;
                    else
                        code_out = e;

                    if (code_out & 8)
                    {
                        x = sX + (eX - sX) * (yMax - sY) / (eY - sY);
                        y = yMax;
                    }
                    else if (code_out & 4)
                    {
                        x = sX + (eX - sX) * (yMin - sY) / (eY - sY);
                        y = yMin;
                    }
                    else if (code_out & 2)
                    {
                        y = sY + (eY - sY) * (xMax - sX) / (eX - sX);
                        x = xMax;
                    }
                    else if (code_out & 1)
                    {
                        y = sY + (eY - sY) * (xMin - sX) / (eX - sX);
                        x = xMin;
                    }

                    if (code_out == s)
                    {
                        sX = x;
                        sY = y;
                        s = clipGetPointCode(sX,sY,xMin,yMin,xMax,yMax);
                        line.first[0] = sX;
                        line.first[0] = sY;
                        line.first[0] = s;
                    }
                    else
                    {
                        eX = x;
                        eY = y;
                        e = clipGetPointCode(eX,eY,xMin,yMin,xMax,yMax);
                        line.second[0] = eX;
                        line.second[0] = eY;
                        line.second[0] = e;
                    }
                }
            }

    }
}
void MainWindow::on_clipButton_clicked()
{
    QTime timer;
    timer.start();
    switch(ui->clipMethodAlgoBox->currentIndex()){
        case 0:
            linearClip();
            break;
        case 1:
            polygonClip();
            break;
    }
    statusBar()->showMessage("Time taken: "+QString::number(timer.elapsed()) + "ms",2000);
}

void MainWindow::on_transShearBtn_clicked()
{
    float hX = ui->transShearX->text().toFloat();
    float hY = ui->transShearY->text().toFloat();
    for(int i = 0; i < ui->graph->points.size(); i++){
        int x = ui->graph->points[i].first.first;
        int y = ui->graph->points[i].first.second;
        ui->graph->points[i].first.first = x + hX*y;
        ui->graph->points[i].first.second = y + hY*x;
    }
    ui->graph->repaint();
}

void MainWindow::on_transScaleBtn_clicked()
{
    float sX = ui->transScaleX->text().toFloat();
    float sY = ui->transScaleY->text().toFloat();
    if(sX*sY==0){
        statusBar()->showMessage("Error: Scale cannot be 0",2000);
        return;
    }
    for(int i = 0; i < ui->graph->points.size(); i++){
        int x = ui->graph->points[i].first.first;
        int y = ui->graph->points[i].first.second;
        ui->graph->points[i].first.first = x*sX;
        ui->graph->points[i].first.second = y*sY;
    }
    ui->graph->repaint();
}

void MainWindow::on_transTranslateBtn_clicked()
{
    float tX = ui->transTranslateX->text().toFloat();
    float tY = ui->transTranslateY->text().toFloat();
    for(int i = 0; i < ui->graph->points.size(); i++){
        int x = ui->graph->points[i].first.first;
        int y = ui->graph->points[i].first.second;
        ui->graph->points[i].first.first = x + tX;
        ui->graph->points[i].first.second = y + tY;
    }
    ui->graph->repaint();
}

void MainWindow::on_transRotBtn_clicked()
{
    float rad = ui->transRotDeg->text().toFloat()*0.0174533;
    float c = cos(rad);
    float s = sin(rad);
    for(int i = 0; i < ui->graph->points.size(); i++){
        int x = ui->graph->points[i].first.first;
        int y = ui->graph->points[i].first.second;
        ui->graph->points[i].first.first = x*c - y*s;
        ui->graph->points[i].first.second = x*s + y*c;
    }
    ui->graph->repaint();
}

void MainWindow::reflectAboutLine(){
    if(ui->graph->recent.size()<2){
        statusBar()->showMessage("Error: Line not drawn",2000);
        return;
    }
    int x1 = ui->graph->recent[0].first.toInt();
    int y1 = ui->graph->recent[0].second.toInt();
    ui->graph->recent.pop_front();
    int x2 = ui->graph->recent[0].first.toInt();
    int y2 = ui->graph->recent[0].second.toInt();
    ui->graph->recent.pop_front();
    float constant = (y2*x1-y1*x2)/(y2-y1 + 0.0);
    float m = (y2-y1)/(x2-x1 + 0.0);
    float theta = qAtan(-1*m);
    float c = cos(theta);
    float s = sin(theta);
    for(int i = 0; i < ui->graph->points.size(); i++){
       int x = ui->graph->points[i].first.first-constant;
       int y = ui->graph->points[i].first.second;
       ui->graph->points[i].first.first = x*c - y*s;
       ui->graph->points[i].first.second = -1*(x*s + y*c);
    }
    s *= -1;
    for(int i = 0; i < ui->graph->points.size(); i++){
       int x = ui->graph->points[i].first.first;
       int y = ui->graph->points[i].first.second;
       ui->graph->points[i].first.first = x*c - y*s+constant;
       ui->graph->points[i].first.second = x*s + y*c;
    }
    int tempBrushColor = ui->graph->brushColorIdx;
    ui->graph->brushColorIdx++;
    ui->graph->brushColorIdx = ui->graph->brushColorIdx%5;
    drawLineBresenham(x1,y1,x2,y2,false);
    ui->graph->brushColorIdx = tempBrushColor;
    ui->graph->repaint();
}

void MainWindow::on_transRefBtn_clicked()
{
    int mX = -1;
    int mY = 1;
    switch(ui->transRefCombo->currentIndex()){
        case 0:
            mX = 1;
            mY = -1;
        case 1:
            for(int i = 0; i < ui->graph->points.size(); i++){
                ui->graph->points[i].first.first *= mX;
                ui->graph->points[i].first.second *= mY;
            }
            break;
        case 2:
            reflectAboutLine();
            break;
    }
    ui->graph->repaint();
}

void MainWindow::on_bezierBtn_clicked()
{
    if(ui->graph->recent.size() < 4){
        statusBar()->showMessage("Error: Insufficient Points");
    }
    else{
        int x1,x2,x3,x4,y1,y2,y3,y4;
        x1 = ui->graph->recent[0].first.toInt();
        y1 = ui->graph->recent[0].second.toInt();
        ui->graph->recent.pop_front();
        x2 = ui->graph->recent[0].first.toInt();
        y2 = ui->graph->recent[0].second.toInt();
        ui->graph->recent.pop_front();
        x3 = ui->graph->recent[0].first.toInt();
        y3 = ui->graph->recent[0].second.toInt();
        ui->graph->recent.pop_front();
        x4 = ui->graph->recent[0].first.toInt();
        y4 = ui->graph->recent[0].second.toInt();
        ui->graph->recent.pop_front();
        double xu = 0.0 , yu = 0.0, u = 0.0;
        for(u = 0.0 ; u <= 1.0 ; u += 0.0001)
        {
            xu = pow(1-u,3)*x1 + 3*u*pow(1-u,2)*x2 + 3*pow(u,2)*(1-u)*x3 + pow(u,3)*x4;
            yu = pow(1-u,3)*y1 + 3*u*pow(1-u,2)*y2 + 3*pow(u,2)*(1-u)*y3 + pow(u,3)*y4;
            insertPoint((int)xu , (int)yu);
        }
        ui->graph->repaint();
    }
}
