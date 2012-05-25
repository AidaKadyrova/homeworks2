#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QMessageBox>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout();
    signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(keyPressed(int)));
    for (int i = 0; i < 9; ++i)
        addButton("", i, i / 3, i % 3);
    layout->setSpacing(3);
    setLayout(layout);
    left = 9;
    currentPlayer = true;
}

void MainWidget::keyPressed(int val)
{
    int x = val / 3;
    int y = val % 3;
    QPushButton *button = static_cast<QPushButton*>(layout->itemAtPosition(x, y)->widget());
    if (button->text() == "") {
        if (currentPlayer) {
            button->setText("X");
        } else {
            button->setText("O");
        }
        left--;
        switch (gameStatus()) {
            case CROSS_WINS:
                showMessage(tr("X wins. Play again?"));
                return;
            case CIRCLE_WINS:
                showMessage(tr("O wins. Play again?"));
                return;
            case DRAW:
                showMessage(tr("Draw. Play again?"));
                return;
        }
        currentPlayer = !currentPlayer;
    }
}

void MainWidget::showMessage(QString msg)
{
    QMessageBox* msgBox = new QMessageBox(this);
    msgBox->setWindowTitle(tr("Game over"));
    msgBox->setText(msg);
    msgBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int res = msgBox->exec();
    delete msgBox;
    if (res == QMessageBox::Ok) {
        clearField();
    } else {
        qApp->exit();
    }
}

void MainWidget::clearField()
{
    currentPlayer = true;
    left = 9;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QPushButton *button = static_cast<QPushButton*>(layout->itemAtPosition(i, j)->widget());
            button->setText("");
        }
    }
}

void MainWidget::addButton(QString caption, int val, int i, int j)
{
    QPushButton *button = new QPushButton(caption, this);
    button->setFont(QFont("Helvetica", 18));
    layout->addWidget(button, i, j);
    signalMapper->setMapping(button, val);
    connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
}

MainWidget::state MainWidget::gameStatus()
{
    for (int i = 0; i < 3; ++i) {
        int crossCnt = 0;
        int circleCnt = 0;
        for (int j = 0; j < 3; ++j) {
            QPushButton *button = static_cast<QPushButton*>(layout->itemAtPosition(i, j)->widget());
            if (button->text() == "X") {
                crossCnt++;
            }
            if (button->text() == "O") {
                circleCnt++;
            }
        }
        if (crossCnt == 3) {
            return CROSS_WINS;
        }
        if (circleCnt == 3) {
            return CIRCLE_WINS;
        }
    }
    for (int j = 0; j < 3; ++j) {
        int crossCnt = 0;
        int circleCnt = 0;
        for (int i = 0; i < 3; ++i) {
            QPushButton *button = static_cast<QPushButton*>(layout->itemAtPosition(i, j)->widget());
            if (button->text() == "X") {
                crossCnt++;
            }
            if (button->text() == "O") {
                circleCnt++;
            }
        }
        if (crossCnt == 3) {
            return CROSS_WINS;
        }
        if (circleCnt == 3) {
            return CIRCLE_WINS;
        }
    }
    int crossCnt = 0;
    int circleCnt = 0;
    for (int i = 0; i < 3; ++i) {
        QPushButton *button = static_cast<QPushButton*>(layout->itemAtPosition(i, i)->widget());
        if (button->text() == "X") {
            crossCnt++;
        }
        if (button->text() == "O") {
            circleCnt++;
        }
    }
    if (crossCnt == 3) {
        return CROSS_WINS;
    }
    if (circleCnt == 3) {
        return CIRCLE_WINS;
    }
    crossCnt = 0;
    circleCnt = 0;
    for (int i = 0; i < 3; ++i) {
        QPushButton *button = static_cast<QPushButton*>(layout->itemAtPosition(i, 2 - i)->widget());
        if (button->text() == "X") {
            crossCnt++;
        }
        if (button->text() == "O") {
            circleCnt++;
        }
    }
    if (crossCnt == 3) {
        return CROSS_WINS;
    }
    if (circleCnt == 3) {
        return CIRCLE_WINS;
    }
    if (left == 0) {
        return DRAW;
    }
    return NOTHING;
}
