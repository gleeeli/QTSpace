#include "mediawindow.h"
#include "ui_mediawindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>

MediaWindow::MediaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MediaWindow)
{
    ui->setupUi(this);
}

MediaWindow::~MediaWindow()
{
    delete ui;
}
