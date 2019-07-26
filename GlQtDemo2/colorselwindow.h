#ifndef COLORSELWINDOW_H
#define COLORSELWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class ColorSelWindow;
}

class ColorSelWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ColorSelWindow(QWidget *parent = nullptr);
    ~ColorSelWindow();

private:
    Ui::ColorSelWindow *ui;
    QPushButton *button;
    QLabel *label;
private slots:
    void editText();
};

#endif // COLORSELWINDOW_H
