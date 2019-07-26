#include "handdrawwindow.h"
#include "ui_handdrawwindow.h"

HandDrawWindow::HandDrawWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HandDrawWindow)
{
    ui->setupUi(this);

    resize(600,500);

    pix = QPixmap(200,200);
    pix.fill(Qt::white);

}

void HandDrawWindow::paintEvent(QPaintEvent *) {
    QPainter pp(&pix);
    pp.drawLine(lastPoint,endPoint);
    //根据鼠标指针前后两个位置就行绘制直线
    lastPoint = endPoint;
    //让前一个坐标值等于后一个坐标值，这样就能实现画出连续的线
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}

void HandDrawWindow::mousePressEvent(QMouseEvent *event) {
    if(event->button()==Qt::LeftButton) //鼠标左键按下
        lastPoint = event->pos();
}

void HandDrawWindow::mouseMoveEvent(QMouseEvent *event) {
    if(event->buttons()&Qt::LeftButton) //鼠标左键按下的同时移动鼠标
    {
        endPoint = event->pos();
        update();
    }
}

void HandDrawWindow::mouseReleaseEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) //鼠标左键释放
    {
        endPoint = event->pos();
        update(); }
}

HandDrawWindow::~HandDrawWindow()
{
    delete ui;
}
