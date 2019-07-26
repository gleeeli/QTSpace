#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>

namespace Ui {
class MainWindow3;
}

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = nullptr);
    ~MainWindow3();

private:
    Ui::MainWindow3 *ui;
    QMenu *fileMenu, *editMenu, *helpMenu;
        QToolBar *fileToolBar, *editToolBar, *testToolBar;
        QAction *newAct;
        QAction *cutAct;
        QAction *copyAct;
        QAction *pasteAct;
        QAction *aboutQtAct;

private slots:
        void newFile();

};

#endif // MAINWINDOW3_H
