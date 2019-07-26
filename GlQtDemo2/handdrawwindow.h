#ifndef HANDDRAWWINDOW_H
#define HANDDRAWWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class HandDrawWindow;
}

class HandDrawWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HandDrawWindow(QWidget *parent = nullptr);
    ~HandDrawWindow();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    Ui::HandDrawWindow *ui;
    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;
};

#endif // HANDDRAWWINDOW_H
