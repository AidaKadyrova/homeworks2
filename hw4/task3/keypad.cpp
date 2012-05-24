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

    addButton("0", 0, 3, 1);
    addButton(".", '.', 3, 0);
    addButton(QChar(0x221A), 's', 3, 2);
    addButton("C", 'C', 0, 3, 1, 2);
    addButton("=", '=', 3, 3, 1, 2);
    addButton("*", '*', 1, 4);
    addButton("/", '/', 2, 4);
    addButton("+", '+', 1, 3);
    addButton("-", '-', 2, 3);
    grid->setSpacing(3);
    setLayout(grid);
}

void Keypad::addButton(QString caption, int val, int i, int j, int row, int column)
{
    QPushButton *button = new QPushButton(caption, this);
    button->setFont(QFont("Helvetica", 18));
    grid->addWidget(button, i, j, row, column);
    signalMapper->setMapping(button, val);
    connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
}
