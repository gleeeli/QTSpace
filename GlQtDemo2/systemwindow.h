#ifndef SYSTEMWINDOW_H
#define SYSTEMWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class SystemWindow;
}

class SystemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemWindow(QWidget *parent = nullptr);
    ~SystemWindow();

private:
    Ui::SystemWindow *ui;
    //键盘事件方法
    void keyPressEvent(QKeyEvent *event);
    QLabel *label1;
};

#endif // SYSTEMWINDOW_H
