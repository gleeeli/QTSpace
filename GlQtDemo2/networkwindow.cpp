#include "networkwindow.h"
#include "ui_networkwindow.h"
#include <QtDebug>

NetWorkWindow::NetWorkWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NetWorkWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("网络请求");

    contentLabel = new QLabel(this);
    contentLabel->setText("请求中。。。");
    contentLabel->setGeometry(QRect(370,10,200,150));

    textBrowser = new QTextBrowser(this);
    textBrowser->setGeometry(QRect(0,10,200,150));
    textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条显示


    manager = new QNetworkAccessManager(this);
    //新建QNetworkAccessManager对象
    connect(manager,SIGNAL(finished(QNetworkReply*)), //关联信号和槽
            this,SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("https://www.baidu.com/"))); //发送GET请求
}

//请求回调
void NetWorkWindow::replyFinished(QNetworkReply *reply) //当回复结束后
{
    QTextCodec *codec = QTextCodec::codecForName("utf8"); //使用 utf8 编码，这样才可以显示中文
    QString all = codec->toUnicode(reply->readAll());

    contentLabel->setText("内容：<html"+all);
    qDebug()<<("内容："+all);
    textBrowser->setText(all);
//    textBrowser->show();
    reply->deleteLater(); //最后要释放 reply 对象
}

NetWorkWindow::~NetWorkWindow()
{
    delete ui;
}
