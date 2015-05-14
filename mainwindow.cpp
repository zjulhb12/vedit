#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextEdit>
//#include <QMessageBox>
//#include <QStatusBar>
//#include <QToolBar>
#include <QDebug>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("vedit"));
    resize(400, 300);

    NewAction = new QAction(tr("New"), this);
    NewAction->setShortcuts(QKeySequence::New);
    NewAction->setStatusTip(tr("Create a new document"));
    connect(NewAction, &QAction::triggered, this, &MainWindow::New);
    OpenAction = new QAction(tr("Open"), this);
    OpenAction->setShortcuts(QKeySequence::Open);
    OpenAction->setStatusTip(tr("Open an existing file"));
    connect(OpenAction, &QAction::triggered, this, &MainWindow::Open);
    SaveAction = new QAction(tr("Save"), this);
    SaveAction->setShortcuts(QKeySequence::Save);
    SaveAction->setStatusTip(tr("Save the current file"));
    connect(SaveAction, &QAction::triggered, this, &MainWindow::Save);
    SaveasAction = new QAction(tr("Save As"), this);
    SaveasAction->setStatusTip(tr("Save the file in another location"));
    SaveasAction->setShortcuts(QKeySequence::SaveAs);
    connect(SaveasAction, &QAction::triggered, this, &MainWindow::Saveas);
    CloseAction = new QAction(tr("Close"), this);
    CloseAction->setShortcuts(QKeySequence::Close);
    CloseAction->setStatusTip(tr("Close document"));
    connect(CloseAction, &QAction::triggered, this, &MainWindow::Close);

    QMenu *menufile = menuBar()->addMenu(tr("File"));
    menufile->addAction(NewAction);
    menufile->addAction(OpenAction);
    menufile->addSeparator();
    menufile->addAction(SaveAction);
    menufile->addAction(SaveasAction);
    menufile->addSeparator();
    menufile->addAction(CloseAction);

    UndoAction = new QAction(tr("Undo"), this);
    UndoAction->setShortcuts(QKeySequence::Undo);
    connect(UndoAction, &QAction::triggered, this, &MainWindow::Undo);
    RedoAction = new QAction(tr("Redo"), this);
    RedoAction->setShortcuts(QKeySequence::Redo);
    connect(RedoAction, &QAction::triggered, this, &MainWindow::Redo);
    CutAction = new QAction(tr("Cut"), this);
    CutAction->setShortcuts(QKeySequence::Cut);
    connect(CutAction, &QAction::triggered, this, &MainWindow::Cut);
    CopyAction = new QAction(tr("Copy"), this);
    CopyAction->setShortcuts(QKeySequence::Copy);
    connect(CopyAction, &QAction::triggered, this, &MainWindow::Copy);
    PasteAction = new QAction(tr("Paste"), this);
    PasteAction->setShortcuts(QKeySequence::Paste);
    connect(PasteAction, &QAction::triggered, this, &MainWindow::Paste);

    QMenu *menuedit = menuBar()->addMenu(tr("Edit"));
    menuedit->addAction(UndoAction);
    menuedit->addAction(RedoAction);
    menuedit->addSeparator();
    menuedit->addAction(CutAction);
    menuedit->addAction(CopyAction);
    menuedit->addAction(PasteAction);

    AboutAction = new QAction(tr("About"), this);
    connect(AboutAction, &QAction::triggered, this, &MainWindow::About);

    QMenu *menuhelp = menuBar()->addMenu(tr("help"));
    menuhelp->addAction(AboutAction);

    statusBar();

}

MainWindow::~MainWindow()
{
}

void MainWindow::New()
{
    TextEdit = new QTextEdit(this);
    setCentralWidget(TextEdit);
}

void MainWindow::Open()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt)"));
    if(!path.isEmpty()) {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        TextEdit->setText(in.readAll());
        file.close();
    } else {
    }
}

void MainWindow::Save()
{
    qDebug() << "save";
}


void MainWindow::Saveas()
{
    qDebug() << "save as";
}

void MainWindow::Close()
{
    qDebug() << "close";
}

void MainWindow::Undo()
{
    qDebug() << "undo";
}

void MainWindow::Redo()
{
    qDebug() << "redo";
}

void MainWindow::Cut()
{
    qDebug() << "cut";
}

void MainWindow::Copy()
{
    qDebug() << "copy";
}

void MainWindow::Paste()
{
    qDebug() << "paste";
}

void MainWindow::About()
{
    QMessageBox::about(this, tr("About Vedit"), tr("find online\nhttps://github.com/bingzhangdai/vedit"));
}
