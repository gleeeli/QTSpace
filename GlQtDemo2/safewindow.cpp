#include "safewindow.h"
#include "ui_safewindow.h"
//MD5 加密类
#include <QCryptographicHash>
#include <QLabel>

SafeWindow::SafeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SafeWindow)
{
    ui->setupUi(this);

    QLabel *label = new QLabel(this);
    label->setGeometry(QRect(50,50,200,25));
    //被加密字符串
    QString pwd = "nihao"; //加密后字符串
    QString MD5;
    //QByteArray
    QByteArray ba,bb;
    //实例 QCryptographicHash
    QCryptographicHash md(QCryptographicHash::Md5);
    ba.append(pwd);
    md.addData(ba);
    bb = md.result(); MD5.append(bb.toHex());
    //MD5 号称是不可逆推，所以暂时没有解密 //MD5 用法:将加密字符就行比对。 //输出加密后字符串
    label->setText(MD5);
}

SafeWindow::~SafeWindow()
{
    delete ui;
}
