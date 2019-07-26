#ifndef MAINWINDOW4_H
#define MAINWINDOW4_H

#include <QMainWindow>
#include <QSystemTrayIcon>//任务栏类
#include <QMenu>//菜单类

namespace Ui {
class MainWindow4;
}

class MainWindow4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow4(QWidget *parent = nullptr);
    ~MainWindow4();

private:
    Ui::MainWindow4 *ui;
    QSystemTrayIcon *myTrayIcon;
    QMenu *myMenu;
    QAction *restoreWinAction;
    QAction *quitAction;
    void createMenu();

private slots:
    void showNormal();
};

#endif // MAINWINDOW4_H
