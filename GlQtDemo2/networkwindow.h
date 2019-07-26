#ifndef NETWORKWINDOW_H
#define NETWORKWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QLabel>
#include<QTextBrowser>

namespace Ui {
class NetWorkWindow;
}

class NetWorkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NetWorkWindow(QWidget *parent = nullptr);
    ~NetWorkWindow();

private:
    Ui::NetWorkWindow *ui;
    QNetworkAccessManager *manager;
    QLabel *contentLabel;
    QTextBrowser *textBrowser;

private slots:
    void replyFinished(QNetworkReply *);
};

#endif // NETWORKWINDOW_H
