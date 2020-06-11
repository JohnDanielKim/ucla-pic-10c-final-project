#include "gamewindow.h"
#include <string>
#include <QString>

gamewindow::gamewindow(QWidget *parent) : QWidget(parent)
{
    grid = new QGridLayout();
    int row = 0;
    int col = 0;
    label = new QLabel(
                QString::number(row) + " rows, " +
                QString::number(col) + " columns");
    grid->addWidget(label, 1, 1);

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

void gamewindow::getRow(int v) {
    row = v;
}

void gamewindow::getCol(int v) {
    col = v;
}
