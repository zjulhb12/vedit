#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void New();
    void Open();
    void Save();
    void Saveas();
    void Close();

    QAction *NewAction;
    QAction *OpenAction;
    QAction *SaveAction;
    QAction *SaveasAction;
    QAction *CloseAction;
};

#endif // MAINWINDOW_H
