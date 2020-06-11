#include "gamewindow.h"
#include <string>
#include <QString>

gamewindow::gamewindow(QWidget *parent) : QWidget(parent)
{
    grid = new QGridLayout();
    row = new int;
    col = new int;

    label = new QLabel(QString::number(getVal(row)) + " rows");
    grid->addWidget(label, 1, 1);
    label = new QLabel(QString::number(getVal(col)) + " columns");
    grid->addWidget(label, 1, 2);

    push = new QPushButton("Play");
    grid->addWidget(push, 2, 1);
    connect(push, &QPushButton::clicked,
            [=] () {

    });

    push = new QPushButton("Pause");
    grid->addWidget(push, 2, 2);
    connect(push, &QPushButton::clicked,
            [=] () {

    });

    push = new QPushButton("Clear");
    grid->addWidget(push, 2, 3);
    connect(push, &QPushButton::clicked,
            [=] () {

    });

    push = new QPushButton("Return");
    grid->addWidget(push, 2, 4);
    connect(push, &QPushButton::clicked,
            [=] () {
        close();
    });

    setLayout(grid);
}

void gamewindow::sendRow(int* v) {
    row = v;
}

void gamewindow::sendCol(int* v) {
    col = v;
}

int gamewindow::getVal(int* v) {
    return *v;
}
