#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    centralWidget = new MainWidget(this);
    setCentralWidget(centralWidget);
    setWindowTitle(tr("Tic Tac Toe"));
    setFixedSize(150, 180);
}
