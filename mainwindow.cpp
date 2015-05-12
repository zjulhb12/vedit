#include <QAction>
#include <QMenuBar>
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
    NewAction = new QAction(tr("&New"), this);
    NewAction->setShortcuts(QKeySequence::New);
    connect(NewAction, &QAction::triggered, this, &MainWindow::New);


    OpenAction = new QAction(tr("&Open"), this);
    OpenAction->setShortcuts(QKeySequence::Open);
//    OpenAction->setStatusTip(tr("Open an existing file"));
    connect(OpenAction, &QAction::triggered, this, &MainWindow::Open);

    SaveAction = new QAction(tr("&Save"), this);
    SaveAction->setShortcuts(QKeySequence::Save);
    connect(SaveAction, &QAction::triggered, this, &MainWindow::Save);

    SaveasAction = new QAction(tr("&Save As"), this);
    SaveasAction->setShortcuts(QKeySequence::SaveAs);
    connect(SaveasAction, &QAction::triggered, this, &MainWindow::Saveas);

    CloseAction = new QAction(tr("&Close"), this);
    CloseAction->setShortcuts(QKeySequence::Close);
    connect(CloseAction, &QAction::triggered, this, &MainWindow::Close);

    QMenu *menufile = menuBar()->addMenu(tr("&File"));
    menufile->addAction(NewAction);
    menufile->addAction(OpenAction);
    menufile->addSeparator();
    menufile->addAction(SaveAction);
    menufile->addAction(SaveasAction);
    menufile->addSeparator();
    menufile->addAction(CloseAction);

    //statusBar();
}

MainWindow::~MainWindow()
{
}

void MainWindow::New()
{
   qDebug() << "new";
}

void MainWindow::Open()
{
    qDebug() << "open";
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








