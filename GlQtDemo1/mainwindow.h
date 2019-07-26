#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton> //引用按钮类头文件
#include <mainwindow2.h>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QFontComboBox>
#include <QSpinBox>
#include <QTabWidget>
#include <mainwindow3.h>
#include <mainwindow4.h>
#include <mainwindow5.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *btClose;
    QPoint last;
    QPushButton *button;
    MainWindow2 w2;
    QLabel *label2;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPlainTextEdit *plainTextEdit;
    QComboBox *comboBox;
    QFontComboBox *fontComboBox;
    QPushButton *button3;
    QLabel *label3;
    QSpinBox *spinBox;
    QTabWidget *tabWidget;
    MainWindow3 w3;
    MainWindow4 w4;
    MainWindow5 w5;

private slots:
    void showMainwindow2();
    void showMainwindow3();
    void showMainwindow4();
    void showMainwindow5();
    void txtButton();

protected:
    //鼠标按下
    void mousePressEvent(QMouseEvent *e);
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *e);
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent *e);
};

//tabA 类
class tabA:public QWidget
{
Q_OBJECT
public:
    tabA(QWidget *parent=nullptr);
};

//tabB 类
class tabB:public QWidget
{
Q_OBJECT
public:
    tabB(QWidget *parent=nullptr);
};

#endif // MAINWINDOW_H
