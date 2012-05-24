#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
private:
    double calculate();
    char currentOperation;
    bool changed;
    bool haveFirst;
    double savedValue;
    QVBoxLayout *layout;
    QLineEdit *lineEdit;
public slots:
    void keyPressed(int val);
};
