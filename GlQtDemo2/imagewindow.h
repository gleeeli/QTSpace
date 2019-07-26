#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QPushButton>

namespace Ui {
class ImageWindow;
}

class ImageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageWindow(QWidget *parent = nullptr);
    ~ImageWindow();

private:
    Ui::ImageWindow *ui;
    QLabel *label1;
    QLabel *label2;
    QImage *img2;
    QPushButton *hBt;
    QPushButton *vBt;
    QPushButton *angleBt;
private slots:
    void moveImg();
    void hShow();
    void vShow();
    void angleShow();
    void bShow();
    void sShow();
protected:
    void paintEvent(QPaintEvent *);
};

#endif // IMAGEWINDOW_H
