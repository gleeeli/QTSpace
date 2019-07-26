#ifndef PROGRESSWINDOW_H
#define PROGRESSWINDOW_H

#include <QMainWindow>
#include <QPushButton> //按钮类
#include <QProgressBar> //进度条类

#include <QLabel>
#include <QTimer>

namespace Ui {
class ProgressWindow;
}

class ProgressWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProgressWindow(QWidget *parent = nullptr);
    ~ProgressWindow();

private:
    Ui::ProgressWindow *ui;
    QPushButton *button;
    QProgressBar *bar;
    int progress;
    QLabel *label;
    QTimer *timer;

private slots:
    void startBar();
    void timerTime();
};

#endif // PROGRESSWINDOW_H
