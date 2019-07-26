#include "folderwindow.h"
#include "ui_folderwindow.h"
#include <QDir>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCodec>
#include <QLabel>

FolderWindow::FolderWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FolderWindow)
{
    ui->setupUi(this);

    //文件夹路径
    folderEdit = new QLineEdit(this);
    //位置
    folderEdit->setGeometry(QRect(50,50,200,25)); //值
    folderEdit->setText("/Users/xiaoningmeng/Documents/WorkSpace/QtSpace/TestFolder"); //实例按钮

    QLabel *fileLabel = new QLabel(this);
    fileLabel->setText("文件路径:");
    fileLabel->setGeometry(QRect(370,10,80,50));

    //文件路径
    fileText = new QTextEdit(this);
    fileText->setGeometry(QRect(470,10,320,150));
    fileText->setText("/Users/xiaoningmeng/Documents/WorkSpace/QtSpace/test.txt");

    QPushButton *changeFileBt = new QPushButton(this);
    changeFileBt->setGeometry(QRect(370,60,100,25));
    changeFileBt->setText("选择文件");
    connect(changeFileBt,SIGNAL(clicked()),this,SLOT(browseFile()));

    QPushButton *deleteFileBt = new QPushButton(this);
    deleteFileBt->setGeometry(QRect(370,95,100,25));
    deleteFileBt->setText("删除文件");
    connect(deleteFileBt,SIGNAL(clicked()),this,SLOT(deleteFile()));

    renameEdit = new QLineEdit(this);
    //位置
    renameEdit->setGeometry(QRect(470,170,200,25));
    renameEdit->setText("新名字.txt");

    QPushButton *renameFileBt = new QPushButton(this);
    renameFileBt->setGeometry(QRect(370,130,100,25));
    renameFileBt->setText("重命名文件");
    connect(renameFileBt,SIGNAL(clicked()),this,SLOT(renameFile()));

    //实例 QLineEdit 控件
    content = new QLineEdit(this);
    //位置
    content->setGeometry(QRect(50,75,200,25)); //值
    content->setText("add content gleeeli"); //实例按钮

    button = new QPushButton(this);
    //按钮位置、大小
    button->setGeometry(QRect(280,50,100,25));
    //值
    button->setText("创建文件夹");
    //按钮事件
    connect(button,SIGNAL(clicked()),this,SLOT(createFolder()));

    QPushButton *button1 = new QPushButton(this);
    //按钮位置、大小
    button1->setGeometry(QRect(280,75,80,25));
    //值
    button1->setText("创建文件");
    //按钮事件
    connect(button1,SIGNAL(clicked()),this,SLOT(createFile()));

    //****修改文件
    //显示文件内容
    contentText = new QTextEdit(this);
    contentText->setGeometry(QRect(50,110,320,150));

    QPushButton *showBt = new QPushButton(this);
    showBt->setGeometry(QRect(50,270,120,25));
    showBt->setText("显示文件内容");
    connect(showBt,SIGNAL(clicked()),this,SLOT(showFileContent()));

    //修改完毕后，保存文件
    saveBt = new QPushButton(this);
    saveBt->setGeometry(QRect(180,270,80,25));
    saveBt->setText("保存修改");
    connect(saveBt,SIGNAL(clicked()),this,SLOT(saveFile()));


}

void FolderWindow::createFolder()
{
    //实例 QDir
    QDir *folder = new QDir; //判断创建文件夹是否存在
    bool exist = folder->exists(folderEdit->text()); if(exist)
    {
        QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹已经存在!")); }else
    {
        //创建文件夹
        bool ok = folder->mkdir(folderEdit->text());
        //判断是否成功
        if(ok) {
            QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建成功!"));
        }else
        {
            QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建失败!"));
        }
    }
}

void FolderWindow::createFile()
{
    QString str = fileText->toPlainText();

    qDebug()<<"文件路径：";
    qDebug()<<str;
    //实例 QFile
    QFile file(str);
    //判断文件是否存在
    if(file.exists())
    {
        QMessageBox::warning(this,"创建文件","文件已经存在!");
    }
    else {
        //存在打开，不存在创建
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        //写入内容,这里需要转码，否则报错。
        QByteArray str = content->text().toUtf8();
        //写入 QByteArray 格式字符串
        file.write(str);

        QMessageBox::warning(this,"创建文件","文件创建成功!");
    }

    //关闭文件
    file.close();
}

//浏览文件
void FolderWindow::browseFile()
{
    //定义变量 str 接收 QFileDialog 对话框获取的文件路径
    QString str = QFileDialog::getOpenFileName(this,"open file","/","textfile(*.txt);;C file(*.cpp);;All file(*.*)");
    //将变量绑定 QTextEdit 控件
    fileText->setText(str.toUtf8());
}

void FolderWindow::showFileContent() {
    //判断是否选择文件
    if(fileText->toPlainText().isEmpty()) {
        QMessageBox::warning(this,"检查文件","文件为空或不存在");
        return;
    }

    QFile file(fileText->toPlainText()); //判断文件是否打开成功
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)) {
        QMessageBox::warning(this,"打开文件","打开文件失败!");
        return;
    }
    QTextStream ts(&file); //循环文档数据至结尾 while(!ts.atEnd())
    {
        //将全部数据绑定至 content 控件
        contentText->setPlainText(ts.readAll());
    }

    //关闭文档
    file.close();
}

//保存文件
void FolderWindow::saveFile()
{
    if(!(FolderWindow::checkFileisExits()))
    {
       QMessageBox::warning(this,"检查文件","文件不存在");
       return;
    }

    QFile file(fileText->toPlainText());
    file.open(QIODevice::ReadWrite | QIODevice::Text); //写入内容,这里需要转码，否则报错。
    QByteArray str = contentText->toPlainText().toUtf8(); //写入 QByteArray 格式字符串
    file.write(str);
    //提示成功
    QMessageBox::warning(this,"修改文件","文件修改成功!");
    file.close();
}

void FolderWindow::deleteFile()
{
    QFile::remove(fileText->toPlainText());
    QMessageBox::warning(this,"删除文件","文件删除成功!");
}

bool FolderWindow::checkFileisExits(){
    QFile filec(fileText->toPlainText());
    //判断文件是否存在
    if(filec.exists())
    {

        filec.close();
        return true;
    }
    filec.close();
    return false;
}

void FolderWindow::renameFile()
{

    if(!(FolderWindow::checkFileisExits()))
    {
       QMessageBox::warning(this,"检查文件","文件不存在");
       return;
    }

    QString str = fileText->toPlainText();
    QString pathStr=str.left(str.lastIndexOf("/"));
    QString nameTxt=str.right(str.length()-str.lastIndexOf("/")-1);
    QString rename = renameEdit->text();
    QString newFilePath = pathStr+"/"+rename;

    qDebug()<<"所在路径："+pathStr;
    qDebug()<<"原名字："+nameTxt;
    qDebug()<<"新路径："+newFilePath;

    //实例 QFileInfo 函数
    QFileInfo file(str);
    //获取文件路径
    QString path = file.absolutePath();
    qDebug()<<"path："+path;
    bool x = QFile::rename(str,path + "/" + rename);
    if(x) {
        fileText->setText(newFilePath);
        QMessageBox::warning(this,"重命名文件","文件重命名成功!");
    }else {
        QMessageBox::warning(this,"重命名文件","文件重命名失败!");
    }

}

FolderWindow::~FolderWindow()
{
    delete ui;
}
