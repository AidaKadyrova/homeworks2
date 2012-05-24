#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    centralWidget = new MainWidget(this);
    setCentralWidget(centralWidget);
    setWindowTitle(tr("Calculator"));
    setFixedSize(300, 300);
}
