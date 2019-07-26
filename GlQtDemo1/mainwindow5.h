#ifndef MAINWINDOW5_H
#define MAINWINDOW5_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QCalendarWidget>

namespace Ui {
class MainWindow5;
}

class MainWindow5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow5(QWidget *parent = nullptr);
    ~MainWindow5();

private:
    Ui::MainWindow5 *ui;
    QLabel *label;
    QLineEdit * lineEdit;
    QCalendarWidget *calendarWidget;
private slots:
    void showTime();
    void setData();
};

#endif // MAINWINDOW5_H
