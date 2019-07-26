#include "mainwindow4.h"
#include "ui_mainwindow4.h"
#include <QtDebug>

MainWindow4::MainWindow4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow4)
{
    ui->setupUi(this);

    //窗体标题
    this->setWindowTitle("1.22 任务栏托盘菜单");

    //菜单
    createMenu();
    //判断系统是否支持托盘图标
    if(!QSystemTrayIcon::isSystemTrayAvailable())
    {
        qDebug()<<"system is unValiable";
        return;
    }

    qDebug()<<"normal run";

    //实例 QSystemTrayIcon
    myTrayIcon = new QSystemTrayIcon(this);
    //设置图标
    myTrayIcon->setIcon(QIcon(":/new/prefix1/icon"));
    //鼠标放托盘图标上提示信息
    myTrayIcon->setToolTip("Qt 托盘图标功能");
    //设置消息
    myTrayIcon->showMessage("托盘","托盘管理",QSystemTrayIcon::Information,10000);
    //托盘菜单
    myTrayIcon->setContextMenu(myMenu);
    //显示
    myTrayIcon->show();
}

//绘制菜单
void MainWindow4::createMenu()
{
    restoreWinAction = new QAction("恢复(&R)",this);
    quitAction = new QAction("退出(&Q)",this);
    //恢复
    connect(restoreWinAction,SIGNAL(triggered()),this,SLOT(showNormal())); //退出
    connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));
    myMenu = new QMenu((QWidget*)QApplication::desktop()); //添加菜单
    myMenu->addAction(restoreWinAction);
    //分隔符
    myMenu->addSeparator();
    myMenu->addAction(quitAction);
}

//恢复
void MainWindow4::showNormal()
{
    this->show();
}

//点击最小化按钮隐藏界面
void QWidget::changeEvent(QEvent *e)
{
    if((e->type()==QEvent::WindowStateChange)&&this->isMinimized())
    {
        //QTimer::singleShot(100, this, SLOT(hide()));
        this->hide();
      }
}

MainWindow4::~MainWindow4()
{
    delete ui;
}
