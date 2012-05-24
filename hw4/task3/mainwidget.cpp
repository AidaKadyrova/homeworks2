#include <cmath>
#include <QFont>
#include <QDebug>
#include "mainwidget.h"
#include "keypad.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout;

    lineEdit = new QLineEdit("0", this);
    lineEdit->setReadOnly(true);
    lineEdit->setFont(QFont("Helvetica", 18));

    Keypad *keypad = new Keypad(this);
    layout->addWidget(lineEdit);
    layout->addWidget(keypad);
    setLayout(layout);
    currentOperation = 0;
    haveFirst = false;
    changed = false;
}

void MainWidget::keyPressed(int val)
{
    if (0 <= val && val <= 9)
    {
        if (changed)
        {
            changed = false;
            lineEdit->setText("");
        }
        if (lineEdit->text() == "0")
            lineEdit->setText("");
        lineEdit->setText(lineEdit->text() + QString::number(val));
    }
    else
    {
        switch (val)
        {
            case '.':
                if (lineEdit->text().count('.') == 0 && !changed) {
                    lineEdit->setText(lineEdit->text() + ".");
                }
                break;
            case '=':
                if (currentOperation)
                {
                    lineEdit->setText(QString::number(calculate()));
                    currentOperation = 0;
                    changed = true;
                    haveFirst = false;
                }
                break;
            case 'C':
                lineEdit->setText("0");
                haveFirst = false;
                break;
            case 's':
                lineEdit->setText(QString::number(sqrt(lineEdit->text().toDouble())));
                changed = true;
                break;
            default:
                if (haveFirst && !changed) {
                    lineEdit->setText(QString::number(calculate()));
                }
                savedValue = lineEdit->text().toDouble();
                currentOperation = val;
                haveFirst = true;
                changed = true;
        }
    }
}

double MainWidget::calculate()
{
    switch (currentOperation)
    {
        case '+':
            return savedValue + lineEdit->text().toDouble();
        case '-':
            return savedValue - lineEdit->text().toDouble();
        case '*':
            return savedValue * lineEdit->text().toDouble();
        case '/':
            return 1.0 * savedValue / lineEdit->text().toDouble();
    }
    return -1;
}
