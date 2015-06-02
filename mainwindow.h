#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
<<<<<<< HEAD
#include <QTextEdit>//new
=======
=======
>>>>>>> origin/master
#include <QTextEdit>

>>>>>>> origin/master
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

    void Undo();
    void Redo();
    void Cut();
    void Copy();
    void Paste();

    void About();

    QTextEdit *TextEdit;

    QAction *NewAction;
    QAction *OpenAction;
    QAction *SaveAction;
    QAction *SaveasAction;
    QAction *CloseAction;

    QAction *UndoAction;
    QAction *RedoAction;
    QAction *CutAction;
    QAction *CopyAction;
    QAction *PasteAction;

    QAction *AboutAction;

    QTextEdit *text;//new

};

#endif // MAINWINDOW_H
