#include "coursewindow.h"
#include "ui_coursewindow.h"
#include <QDebug>


CourseWindow::CourseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CourseWindow)
{
    ui->setupUi(this);


}

CourseWindow::~CourseWindow()
{
    delete ui;
}
