#ifndef SAFEWINDOW_H
#define SAFEWINDOW_H

#include <QMainWindow>

namespace Ui {
class SafeWindow;
}

class SafeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SafeWindow(QWidget *parent = nullptr);
    ~SafeWindow();

private:
    Ui::SafeWindow *ui;
};

#endif // SAFEWINDOW_H
