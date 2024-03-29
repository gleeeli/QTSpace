#include "mainwindow5.h"
#include "ui_mainwindow5.h"

MainWindow5::MainWindow5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow5)
{
    ui->setupUi(this);

    this->setWindowTitle("1.1 日历组件");

    //实例 QLabel 控件
    label = new QLabel(this);
    label->setText("选择日期:");
    //位置
    label->setGeometry(QRect(50,50,100,25));
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(QRect(110,50,150,22));
    //事件
    connect(lineEdit,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(showTime())); //实例时间控件
    calendarWidget = new QCalendarWidget(this);
    //位置
    calendarWidget->setGeometry(20,75,350,180);
    //隐藏时间控件
    calendarWidget->setHidden(true);
    //时间控件点击事件
    connect(calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(setData()));
}

void MainWindow5::showTime()
{
    calendarWidget->setHidden(false);
}

void MainWindow5::setData()
{
    //接收选择时间
    QDate date = calendarWidget->selectedDate();
    //时间格式化
    QString str = date.toString("yyyy-MM-dd");
    //赋值
    lineEdit->setText(str);
    //日期控件隐藏
    calendarWidget->setHidden(true);
}

MainWindow5::~MainWindow5()
{
    delete ui;
}
