#ifndef FOLDERWINDOW_H
#define FOLDERWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

namespace Ui {
class FolderWindow;
}

class FolderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FolderWindow(QWidget *parent = nullptr);
    ~FolderWindow();

private:
    Ui::FolderWindow *ui;
    QLineEdit *folderEdit;
    QPushButton *button;
    QLineEdit *content;
    QTextEdit *contentText;
    QTextEdit *fileText;
    QPushButton *saveBt;
    QLineEdit *renameEdit;
    bool checkFileisExits();

private slots:
    void createFolder();
    void createFile();
    void saveFile();
    void browseFile();
    void showFileContent();
    void deleteFile();
    void renameFile();
};

#endif // FOLDERWINDOW_H
