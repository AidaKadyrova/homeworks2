#include <QFont>
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
        if (val == '=')
        {
            if (currentOperation)
            {
                lineEdit->setText(QString::number(calculate()));
                currentOperation = 0;
                changed = true;
            }
        }
        else
        {
            if (val == 'C')
            {
                lineEdit->setText("0");
            }
            else
            {
                savedValue = lineEdit->text().toInt();
                currentOperation = val;
                changed = true;
            }
        }
    }
}

double MainWidget::calculate()
{
    switch (currentOperation)
    {
        case '+':
            return savedValue + lineEdit->text().toInt();
        case '-':
            return savedValue - lineEdit->text().toInt();
        case '*':
            return savedValue * lineEdit->text().toInt();
        case '/':
            return 1.0 * savedValue / lineEdit->text().toInt();
    }
    return -1;
}
