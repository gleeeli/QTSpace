#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QWidget>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //窗体标题
    this->setWindowTitle("Qt5.1 窗体应用");
    //窗体最大 300*300
    this->setMaximumSize(1000,400);
    //窗体最小 300*300
    this->setMinimumSize(1000,300);

    QLabel *label = new QLabel(this);
    label->setText("gleeeli Hello World");
    label->setGeometry(QRect(50,50,200,25));

    //默认窗体居中显示，如果想要更改用 move 或 setGeometry
    this->move(100,100); //背景红色
    this->setStyleSheet("background:gray");

    //窗体 ICO 图片，如图不起别名，后缀直接写图片全名。
    this->setWindowIcon(QIcon(":/new/prefix1/image/icon"));


    //标题名
    this->setWindowTitle("移动无边框窗体");
    //去掉标题栏
//    this->setWindowFlags(Qt::FramelessWindowHint);

    //关闭按钮失效
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint);
    //去掉最大化、最小化按钮，保留关闭按钮
//    this->setWindowFlags(Qt::WindowCloseButtonHint);

    //实例一个按钮控件，因为去掉标题栏后，窗体没有关闭按钮了。
    //所以自己添加一个按钮实现关闭功能。
    btClose = new QPushButton(this); btClose->setText("关闭");
    //按钮点击事件
    connect(btClose,SIGNAL(clicked()),this,SLOT(close()));

    //实例 QPushButonn 控件
    button = new QPushButton(this); //按钮显示位置
    button->setGeometry(QRect(50,100,100,25)); //按钮值
    button->setText("弹出窗口2"); //点击事件
    connect(button,SIGNAL(clicked()),this,SLOT(showMainwindow2()));


    //实例 QLabel 控件
    label2 = new QLabel("我是QLabel",this); //QLabel 位置
    //label->move(100,100);
    label2->setGeometry(QRect(150,100,200,30));
    //label 样式(CSS 样式表)
    //font-size 字号 //color 字体颜色 //font-weight 字宽 //font-style 字体样式
    label2->setStyleSheet("font-size:20px;color:green;font-weight:bold;font-style:italic");

    //创建 QLineEdit 控件
    lineEdit = new QLineEdit(this);
    //位置大小
    lineEdit->setGeometry(QRect(50,135,200,25)); //样式
    //border 边框线大小
    //border-style 边框样式 solid实线
    //border-color:blue red 上下蓝色 左右红色
    lineEdit->setStyleSheet("border:1px;border-style:solid;color:red;border-color: blue red;");
    //限制最长输入 12 位
    lineEdit->setMaxLength(12);
    //不可写入
    //lineEdit->setEchoMode(QLineEdit::NoEcho);
    //密码*号输入
    lineEdit->setEchoMode(QLineEdit::Password);

    //实例 QTextEdit 控件
    textEdit = new QTextEdit(this); //控件位置大小
    textEdit->setGeometry(QRect(50,160,200,150));
    //内容
    textEdit->setText("我是第一行<br/>我是第二行");

    //实例
    plainTextEdit = new QPlainTextEdit(this);
    //位置
    plainTextEdit->setGeometry(QRect(250,50,200,100)); //添加内容
    plainTextEdit->setPlainText("第一行第二行第二行第二行第二行第二行第二行第二行第二行第二行");

    //实例 QComboBox
    comboBox = new QComboBox(this); //控件显示位置大小
    comboBox->setGeometry(QRect(450,50,120,25));
    //定义字符串列表
    QStringList str;
    str << "数学" << "语文" << "地理"; //将字符串列表绑定 QComboBox 控件
    comboBox->addItems(str);


    //实例 QFontComboBox 选择字体
    fontComboBox = new QFontComboBox(this); //实例 QPushButton
    button3 = new QPushButton(this);

    //按钮名
    button3->setText("按钮");
    //位置
    button3->move(450,155);
    //事件
    connect(button3,SIGNAL(released()),this,SLOT(txtButton()));
    //QFontComboBox 控件位置
    fontComboBox->setGeometry(QRect(450,100,120,25));

    //实例 QLabel
    label3 = new QLabel(this);
    label3->setGeometry(QRect(450,130,300,25));

    //实例 QSpinBox 增加钱币
    spinBox = new QSpinBox(this);
    //位置
    spinBox->setGeometry(QRect(250,160,100,25));
    //值范围
    spinBox->setRange(0,200);
    //初始值
    spinBox->setValue(10);
    //后缀
    spinBox->setSuffix("元");
    //前缀
    spinBox->setPrefix("$");


    //实例 QTabWidget
    tabWidget = new QTabWidget(this);
    tabWidget->setGeometry(QRect(250,185,340,140));
    tabWidget->addTab(new tabA,"A栏目");
    tabWidget->addTab(new tabB,"B栏目");

    //实例 QPushButonn 控件
    QPushButton *button3 = new QPushButton(this); //按钮显示位置
    button3->setGeometry(QRect(580,50,100,25)); //按钮值
    button3->setText("弹出窗口3"); //点击事件
    connect(button3,SIGNAL(clicked()),this,SLOT(showMainwindow3()));

    //实例 QPushButonn 控件
    QPushButton *button4 = new QPushButton(this); //按钮显示位置
    button4->setGeometry(QRect(580,75,100,25)); //按钮值
    button4->setText("弹出窗口4"); //点击事件
    connect(button4,SIGNAL(clicked()),this,SLOT(showMainwindow4()));


    QPushButton *button5 = new QPushButton(this); //按钮显示位置
    button5->setGeometry(QRect(580,100,100,25)); //按钮值
    button5->setText("弹出窗口5"); //点击事件
    connect(button5,SIGNAL(clicked()),this,SLOT(showMainwindow5()));

}

//获取鼠标点定位窗体位置
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx,y()+dy);
}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

//调用方法 显示窗口2
void MainWindow::showMainwindow2()
{
    button->setText("按钮 B");
    //显示 MainWindow2 窗体
    w2.show();
}

//调用方法 显示窗口2
void MainWindow::showMainwindow3()
{
    //显示 MainWindow3 窗体
    w3.show();
}

//调用方法 显示窗口2
void MainWindow::showMainwindow4()
{
    w4.show();
}

void MainWindow::showMainwindow5()
{
    w5.show();
}

//方法
void MainWindow::txtButton()
{
    label3->setText("选择字体:"+fontComboBox->currentText());
}

tabA::tabA(QWidget *parent):QWidget(parent)
{
    QPushButton *buttonA = new QPushButton(this);
    buttonA->setText("页面 A");
}

tabB::tabB(QWidget *parent):QWidget(parent)
{
    QPushButton *buttonB = new QPushButton(this);
    buttonB->setText("页面 B");
}

MainWindow::~MainWindow()
{
    delete ui;
}
