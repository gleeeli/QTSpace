#include "graphicswindow.h"
#include "ui_graphicswindow.h"
#include <QPainter>
#include <QTimer>
#include <QMovie>
#include <QPushButton>

GraphicsWindow::GraphicsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphicsWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("1.1 绘制文字");

    //实例 QGraphicsScene
    QGraphicsScene *scene = new QGraphicsScene;
    //背景色
    scene->setForegroundBrush(QColor(0, 255, 255, 127));

    //******画字
    //字体设置
    QFont font("黑体",60); //添加文字
    scene->addSimpleText("图形图像",font);


    //*****画线
    QPen pen;
    pen.setStyle(Qt::DashDotLine);
    pen.setWidth(2);
    pen.setBrush(Qt::black);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    //绘制线条
    scene->addLine(30,80,200,80,pen);

    //绘制椭圆
    scene->addEllipse(50,50,100,120);

    //网格
    //scene->setForegroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));

    //实例 QGraphicsView
    QGraphicsView *view = new QGraphicsView(scene);

    //显示
    this->setCentralWidget(view);


}



GraphicsWindow::~GraphicsWindow()
{
    delete ui;
}
