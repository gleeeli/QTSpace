#include "colorselwindow.h"
#include "ui_colorselwindow.h"
#include <QColorDialog> //引用 QColorDialog 类

ColorSelWindow::ColorSelWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ColorSelWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("1.4 颜色选择对话框");

    //实例按钮
    button = new QPushButton(this);
    //位置
    button->setGeometry(QRect(200,50,80,25)); //按钮值
    button->setText("选择颜色");
    //按钮事件
    connect(button,SIGNAL(clicked()),this,SLOT(editText()));
    //实例 QLabel
    label = new QLabel(this);
    //label 位置
    label->setGeometry(QRect(50,50,100,25));
    //label 值
    label->setText("我的颜色可以改变");
}

//修改方法
void ColorSelWindow::editText()
{
    //颜色对话框设置
    QColorDialog::setCustomColor(0,QRgb(0x0000FF));
    //定义 QColor 接收值
    QColor color = QColorDialog::getColor(QColor(0,255,0));
    //定义 QPalette(调色板类)
    QPalette p = palette();
    //调色板接收颜色
    p.setColor(QPalette::WindowText,QColor(color));
    //给 label 绑定颜色
    label->setPalette(p);
}

ColorSelWindow::~ColorSelWindow()
{
    delete ui;
}
