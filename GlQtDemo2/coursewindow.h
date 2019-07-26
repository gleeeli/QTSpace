#ifndef COURSEWINDOW_H
#define COURSEWINDOW_H

#include <QMainWindow>

namespace Ui {
class CourseWindow;
}

class CourseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CourseWindow(QWidget *parent = nullptr);
    ~CourseWindow();

private:
    Ui::CourseWindow *ui;

    QString cPid;

};

#endif // COURSEWINDOW_H
