#include "systemwindow.h"
#include "ui_systemwindow.h"
#include <QDesktopWidget>
#include <QLabel>
#include <QKeyEvent>

SystemWindow::SystemWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SystemWindow)
{
    ui->setupUi(this);

    //实例 QLabel
    QLabel *label0 = new QLabel(this); //QLabel 位置
    label0->setGeometry(QRect(50,50,200,25));
    //实例 QDesktopWidget
    QDesktopWidget *desktopWidget = QApplication::desktop();
    //实例 QRect 接收屏幕信息
    QRect screenRect = desktopWidget->screenGeometry();
    QString str = "屏幕分辨率为:"; //屏幕宽度
    int sWidth = screenRect.width(); //屏幕高度
    int sHeight = screenRect.height(); //输出结果
    label0->setText(str+QString::number(sWidth,10)+" X "+QString::number(sHeight,10));


    //********键盘事件
    //实例 QLabel
    label1 = new QLabel(this);
    label1->setGeometry(QRect(50,85,200,25));
    label1->setText("按 Q 键更改文字");
}

//键盘事件
void SystemWindow::keyPressEvent(QKeyEvent *event)
{
    //键值如果等于 Q
    if(event->key()==Qt::Key_Q)
    {
        label1->setText("你按了 Q 键");
    }
}

SystemWindow::~SystemWindow()
{
    delete ui;
}
