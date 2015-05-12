#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("vedit"));

    OpenAction = new QAction(tr("&Open..."), this);
    OpenAction->setShortcuts(QKeySequence::Open);
    OpenAction->setStatusTip(tr("Open an existing file"));
    connect(OpenAction, &QAction::triggered, this, &MainWindow::Open);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(OpenAction);

    statusBar();
}

MainWindow::~MainWindow()
{
}

void MainWindow::Open()
{
    QMessageBox::information(this, tr("Information"), tr("Open"));
}
