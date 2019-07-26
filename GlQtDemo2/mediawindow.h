#ifndef MEDIAWINDOW_H
#define MEDIAWINDOW_H

#include <QMainWindow>
#include <QAxWidget>
#include <QToolButton>
#include <QSlider>
#include <QWidget>

//Q_ENUMS()宏的参数是枚举类型。
Q_ENUMS(ReadyStateConstants)

namespace Ui {
class MediaWindow;
}

class MediaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MediaWindow(QWidget *parent = nullptr);
    ~MediaWindow();

private:
    Ui::MediaWindow *ui;


};

#endif // MEDIAWINDOW_H
