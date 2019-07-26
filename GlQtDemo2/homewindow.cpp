#include "homewindow.h"
#include "ui_homewindow.h"
#include <QFileDialog> //引用文件浏览对话框类

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("1.3 文件浏览对话框");

    //实例单行文本控件
    filename = new QLineEdit(this);
    //位置
    filename->setGeometry(QRect(50,50,230,25));
    //实例按钮
    button = new QPushButton(this);
    //按钮位置
    button->setGeometry(QRect(280,50,80,25));
    //按钮名
    button->setText("浏览");
    //按钮点击事件
    connect(button,SIGNAL(clicked()),this,SLOT(showFiles()));

    //实例按钮
    QPushButton *button1 = new QPushButton(this);
    //按钮位置
    button1->setGeometry(QRect(50,90,150,25));
    //按钮名
    button1->setText("跳转颜色选择窗口");
    //按钮点击事件
    connect(button1,SIGNAL(clicked()),this,SLOT(showColorWindow()));

    //实例按钮
    QPushButton *button2 = new QPushButton(this);
    //按钮位置
    button2->setGeometry(QRect(50,125,150,25));
    //按钮名
    button2->setText("跳转进度条窗口");
    //按钮点击事件
    connect(button2,SIGNAL(clicked()),this,SLOT(showProgressWindow()));

    //实例按钮
    QPushButton *button3 = new QPushButton(this);
    //按钮位置
    button3->setGeometry(QRect(50,160,150,25));
    //按钮名
    button3->setText("操作文件夹");
    //按钮点击事件
    connect(button3,SIGNAL(clicked()),this,SLOT(showFolderWindow()));

    //实例按钮
    QPushButton *button4 = new QPushButton(this);
    //按钮位置
    button4->setGeometry(QRect(50,160,150,25));
    //按钮名
    button4->setText("绘字");
    //按钮点击事件
    connect(button4,SIGNAL(clicked()),this,SLOT(showGraphicsWindow()));

    //实例按钮
    QPushButton *button5 = new QPushButton(this);
    //按钮位置
    button5->setGeometry(QRect(50,160,150,25));
    //按钮名
    button5->setText("图片显示");
    //按钮点击事件
    connect(button5,SIGNAL(clicked()),this,SLOT(showImageWindow()));

    //实例按钮
    QPushButton *button6 = new QPushButton(this);
    //按钮位置
    button6->setGeometry(QRect(50,195,150,25));
    //按钮名
    button6->setText("系统操作");
    //按钮点击事件
    connect(button6,SIGNAL(clicked()),this,SLOT(showSystemWindow()));

    //实例按钮
    QPushButton *button7 = new QPushButton(this);
    //按钮位置
    button7->setGeometry(QRect(50,230,150,25));
    //按钮名
    button7->setText("网络请求");
    //按钮点击事件
    connect(button7,SIGNAL(clicked()),this,SLOT(showNetWorkWindow()));

    //实例按钮
    QPushButton *button8 = new QPushButton(this);
    //按钮位置
    button8->setGeometry(QRect(50,265,150,25));
    //按钮名
    button8->setText("涂鸦");
    //按钮点击事件
    connect(button8,SIGNAL(clicked()),this,SLOT(showHandDrawWindow()));

}

//按钮点击方法
void HomeWindow::showFiles()
{
//定义变量 str 接收 QFileDialog 对话框获取的文件路径
    QString str = QFileDialog::getOpenFileName(this,"open file","/","textfile(*.txt);;C file(*.cpp);;All file(*.*)");
//将变量绑定 QLineEdit 控件
    filename->setText(str.toUtf8());
}

void HomeWindow::showColorWindow()
{
    colorWindow.show();
}

void HomeWindow::showProgressWindow()
{
    progressWindow.show();
}

void HomeWindow::showFolderWindow()
{
    folderWindow.show();
}

void HomeWindow::showGraphicsWindow()
{
    graphicsWindow.show();
}
void HomeWindow::showImageWindow()
{
    imageWindow.show();
}

void HomeWindow::showSystemWindow()
{
    systemWindow.show();
}

void HomeWindow::showNetWorkWindow()
{
    netWorkWindow.show();
}

void HomeWindow::showHandDrawWindow() {
    handDrawWindow.show();
}


HomeWindow::~HomeWindow()
{
    delete ui;
}
