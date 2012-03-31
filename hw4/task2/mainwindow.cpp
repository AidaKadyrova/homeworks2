#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("+");
    ui->comboBox->addItem("-");
    ui->comboBox->addItem("*");
    ui->comboBox->addItem("/");
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(calculate()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(calculate()));
    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(calculate()));

}

double MainWindow::operation(int const value1, int const value2) const
{
    if (ui->comboBox->currentText() == "+")
        return value1 + value2;
    else if (ui->comboBox->currentText() == "-")
        return value1 - value2;
    else if (ui->comboBox->currentText() == "*")
        return value1 * value2;
    else if (ui->comboBox->currentText() == "/")
        return static_cast<double>(value1) / static_cast<double>(value2);
}

void MainWindow::calculate()
{
    ui->result->setText(QString::number(operation(ui->spinBox->value(), ui->spinBox_2->value())));
}

MainWindow::~MainWindow()
{
    delete ui;
}
