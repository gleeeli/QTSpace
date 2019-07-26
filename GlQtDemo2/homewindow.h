#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include <QLineEdit> //单行文本控件类
#include <QPushButton> //按钮类
#include <colorselwindow.h>
#include <progresswindow.h>
#include <folderwindow.h>
#include <graphicswindow.h>
#include <imagewindow.h>
#include <systemwindow.h>
#include <networkwindow.h>
#include <handdrawwindow.h>

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

private:
    Ui::HomeWindow *ui;
    QLineEdit *filename;
    QPushButton *button;
    ColorSelWindow colorWindow;
    ProgressWindow progressWindow;
    FolderWindow folderWindow;
    GraphicsWindow graphicsWindow;
    ImageWindow imageWindow;
    SystemWindow systemWindow;
    NetWorkWindow netWorkWindow;
    HandDrawWindow handDrawWindow;
private slots:
    void showFiles();
    void showColorWindow();
    void showProgressWindow();
    void showFolderWindow();
    void showGraphicsWindow();
    void showImageWindow();
    void showSystemWindow();
    void showNetWorkWindow();
    void showHandDrawWindow();
};

#endif // HOMEWINDOW_H
