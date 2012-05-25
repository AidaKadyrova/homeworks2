#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QSignalMapper>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
private:
    enum state {CROSS_WINS, CIRCLE_WINS, DRAW, NOTHING};

    void addButton(QString caption, int val, int i, int j);
    void showMessage(QString msg);
    void clearField();
    state gameStatus();

    QGridLayout *layout;
    QSignalMapper *signalMapper;
    bool currentPlayer;
    int left;
public slots:
    void keyPressed(int val);
};
