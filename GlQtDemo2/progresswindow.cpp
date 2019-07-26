#include "progresswindow.h"
#include "ui_progresswindow.h"
#include <QDateTime>

ProgressWindow::ProgressWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProgressWindow)
{
    ui->setupUi(this);

    progress = 0;

    //实例 QProgressBar 控件
    bar = new QProgressBar(this);
    //位置
    bar->setGeometry(QRect(50,50,200,20));
    //范围值
    bar->setRange(0,100000-1);
    //初始值
    bar->setValue(progress);
    //实例 Button
    button = new QPushButton(this);
    //位置
    button->setGeometry(QRect(270,50,80,25));
    //值
    button->setText("添加进度");
    //事件
    connect(button,SIGNAL(clicked()),this,SLOT(startBar()));


    //实时更新时间
    //实例 QLabel 控件
    label = new QLabel(this);
    //位置
    label->setGeometry(QRect(50,85,200,25));
    //实例 QTimer 控件
    timer = new QTimer;
    //timer 时间
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTime())); //执行
    timer->start(1000);
}

void ProgressWindow::startBar()
{
    progress += 1000;
    bar->setValue(progress);
//    for(int i=0;i<100000;i++)
//    {
//        //100%结束
//        if(i == 99999)
//        {
//            button->setText("结束");
//        }
//        //赋值
//        bar->setValue(i);
//    }
}

void ProgressWindow::timerTime()
{
    //获取系统时间
    QDateTime sysTime = QDateTime::currentDateTime();
    label->setText(sysTime.toString());
}

ProgressWindow::~ProgressWindow()
{
    delete ui;
}
