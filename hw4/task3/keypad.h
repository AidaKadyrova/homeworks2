#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QSignalMapper>

class Keypad : public QWidget
{
    Q_OBJECT
public:
    Keypad(QWidget *parent = 0);
private:
    void addButton(QString caption, int val, int i, int j, int row = 1, int column = 1);
    QGridLayout *grid;
    QSignalMapper *signalMapper;
};
