#include <QPushButton>
#include <QString>
#include <QFont>
#include "keypad.h"

Keypad::Keypad(QWidget *parent) : QWidget(parent)
{
    grid = new QGridLayout();
    signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)), parent, SLOT(keyPressed(int)));
    for (int i = 1; i < 10; ++i)
        addButton(QString::number(i), i, (i - 1) / 3, (i - 1) % 3);

    addButton("0", 0, 3, 0);
    addButton("C", 'C', 3, 1);
    addButton("=", '=', 3, 2);
    addButton("/", '/', 3, 3);
    addButton("+", '+', 0, 3);
    addButton("-", '-', 1, 3);
    addButton("*", '*', 2, 3);
    grid->setSpacing(3);
    setLayout(grid);
}

void Keypad::addButton(QString caption, int val, int i, int j)
{
    QPushButton *digit = new QPushButton(caption, this);
    digit->setFont(QFont("Helvetica", 18));
    grid->addWidget(digit, i, j);
    signalMapper->setMapping(digit, val);
    connect(digit, SIGNAL(clicked()), signalMapper, SLOT(map()));
}
