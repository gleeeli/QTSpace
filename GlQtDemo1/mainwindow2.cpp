#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    //去掉标题栏
//    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowOpacity(1);
    //设置背景透明
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //窗体添加样式，样式为 CSS 样式表
    // background-image:url 添加图片
    // background-repeat:no-repeat 不平铺
    this->setStyleSheet("background-image:url(:/new/prefix1/image/airplane);background-repeat:no-repeat;");
}

MainWindow2::~MainWindow2()
{
    delete ui;
}
