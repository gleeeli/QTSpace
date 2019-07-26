#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>

namespace Ui {
class GraphicsWindow;
}

class GraphicsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphicsWindow(QWidget *parent = nullptr);
    ~GraphicsWindow();

private:
    Ui::GraphicsWindow *ui;
    QLabel *label1;

};

#endif // GRAPHICSWINDOW_H
