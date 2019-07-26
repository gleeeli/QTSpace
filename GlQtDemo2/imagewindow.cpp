#include "imagewindow.h"
#include "ui_imagewindow.h"
#include <QPushButton>
#include <QPainter>
#include <QTimer>
#include <QMovie>
#include <QMatrix>
#include <QGraphicsBlurEffect>

ImageWindow::ImageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("图片相关");


    //实例 QLabel
    QLabel *label = new QLabel(this);
    label->setGeometry(QRect(50,50,88,51));
    //实例 QMovie
    QMovie *movie = new QMovie(":/new/prefix1/icon"); //3 秒后图片消失
    QTimer::singleShot( 3*1000, label, SLOT(close()));
    label->setMovie(movie);
    movie->start();

    //****图片水平移动
    //实例 QLabel
    label1 = new QLabel(this);
    label1->setGeometry(QRect(250,70,75,77));
    //实例 QImage
    QImage *img1 = new QImage;
    //QImage 加载图片
    img1->load(":/new/prefix1/icon");
    //label 显示图片
    label1->setPixmap(QPixmap::fromImage(*img1));

    //实例 button
    QPushButton *button1 = new QPushButton(this);
    button1->setGeometry(QRect(250,150,80,25));
    button1->setText("移动");
    connect(button1,SIGNAL(clicked()),this,SLOT(moveImg()));

    //******水平翻转
    //实例 QLabel
    label2 = new QLabel(this);
    label2->setGeometry(QRect(160,200,119,77));
    //实例 QImage
    img2 = new QImage;
    //QImage 加载图片
    img2->load(":/new/prefix1/icon");
    //label 显示图片
    label2->setPixmap(QPixmap::fromImage(*img2));
    label2->setScaledContents(true);
    //实例水平操作按钮
    hBt = new QPushButton(this);

    hBt->setGeometry(QRect(50,277,80,25));
    hBt->setText("水平翻转");
    connect(hBt,SIGNAL(clicked()),this,SLOT(hShow()));
    //实例垂直操作按钮
    vBt = new QPushButton(this);
    vBt->setGeometry(QRect(160,277,80,25));
    vBt->setText("垂直操作");
    connect(vBt,SIGNAL(clicked()),this,SLOT(vShow()));
    //实例角度操作按钮 88°
    angleBt = new QPushButton(this);
    angleBt->setGeometry(QRect(270,277,80,25));
    angleBt->setText("角度操作");
    connect(angleBt,SIGNAL(clicked()),this,SLOT(angleShow()));

    //****图片缩放
    //实例放大按钮
    QPushButton *bigBt = new QPushButton(this);
    bigBt->setGeometry(QRect(340,50,80,25));
    bigBt->setText("放大");
    connect(bigBt,SIGNAL(clicked()),this,SLOT(bShow()));

    //实例缩小按钮
    QPushButton *smallBt = new QPushButton(this);
    smallBt->setGeometry(QRect(340,75,80,25));
    smallBt->setText("缩小");
    connect(smallBt,SIGNAL(clicked()),this,SLOT(sShow()));

    //***************图片上写字
    //实例 QImage
    int scalei  = 1;
    int width3 = scalei * 150;
    int height3 = scalei * 150;
    QImage image3 = QPixmap(":/new/prefix1/quan").toImage();
//    image3.scaledToWidth(width3);
//    image3.scaledToHeight(height3);

    //实例 QPainter
    QPainter painter(&image3);
    //设置画刷模式
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    //改变画笔和字体
    QPen pen = painter.pen();
    pen.setColor(Qt::red);

    QFont font = painter.font();
    font.setBold(true);
    //加粗
    font.setPixelSize(50);
    //改变字体大小
    painter.setPen(pen);
    painter.setFont(font);
    //将文字绘制在图片中心位置
    painter.drawText(image3.rect(),Qt::AlignCenter,"你好，朋友。");
    //这个为图片的压缩度。0/100
    int n = 100;
    //保存图片
    image3.save("text.jpg","JPG",n);


    QLabel *wordImgLabel = new QLabel(this);
    wordImgLabel->setGeometry(QRect(340,100,width3,height3));
    wordImgLabel->setPixmap(QPixmap::fromImage(image3));
    wordImgLabel->setScaledContents(true);

    //*****模糊效果
    QLabel *blurLabel = new QLabel(this);
    blurLabel->setGeometry(QRect(340,100 + height3 + 10,150,90));
    blurLabel->setScaledContents(true);
    //实例 QImage
    QImage *blurimg = new QImage;
    //加载图片
    blurimg->load(":/new/prefix1/icon");
    blurLabel->setPixmap(QPixmap::fromImage(*blurimg));

    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect(this);
    //模糊值，值越大越模糊
    effect->setBlurRadius(5);
    blurLabel->setGraphicsEffect(effect);
}

void ImageWindow::paintEvent(QPaintEvent *)
{
    //***绘制静态图 无效？
    //实例 QPixmap
    QPixmap image(":/new/prefix1/icon");
    //实例 QPainter 绘制类
    QPainter painter(this);
    //绘制图片
    painter.drawPixmap(20,100,200,100,image);
}

//点击移动
int i = 250;
void ImageWindow::moveImg()
{
    //移动 label 控件
    label1->move(i,70);
    i += 10;
}

//水平操作
void ImageWindow::hShow()
{
    //水平翻转
    *img2 = img2->mirrored(true,false);
    //显示图片
    label2->setPixmap(QPixmap::fromImage(*img2));
}

//垂直操作
void ImageWindow::vShow()
{
    //垂直翻转
    *img2 = img2->mirrored(false,true);
    //显示图片
    label2->setPixmap(QPixmap::fromImage(*img2));
}

//角度操作
void ImageWindow::angleShow()
{
    QMatrix matrix;
    //88 度角
    matrix.rotate(88);
    *img2 = img2->transformed(matrix);
    label2->setPixmap(QPixmap::fromImage(*img2));
}

//放大操作
void ImageWindow::bShow()
{
    *img2 = img2->scaled(100,100,Qt::IgnoreAspectRatio);
    label2->setPixmap(QPixmap::fromImage(*img2));
}
//缩小操作
void ImageWindow::sShow()
{
    *img2 = img2->scaled(60,60,Qt::IgnoreAspectRatio);
    label2->setPixmap(QPixmap::fromImage(*img2));
}

ImageWindow::~ImageWindow()
{
    delete ui;
}
