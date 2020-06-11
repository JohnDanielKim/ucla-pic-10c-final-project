#include "gamewindow.h"
#include <string>
#include <QString>

gamewindow::gamewindow(QWidget *parent) : QWidget(parent)
{
    grid = new QGridLayout();

    label = new QLabel(QString::number(row) + " rows");
    grid->addWidget(label, 1, 1);
    label = new QLabel(QString::number(col) + " columns");
    grid->addWidget(label, 1, 2);


    push = new QPushButton("Play");
    grid->addWidget(push, 2, 1);
    connect(push, &QPushButton::clicked,
            [=] () {
        // must start cell-holding object's processes
    });

    push = new QPushButton("Pause");
    grid->addWidget(push, 2, 2);
    connect(push, &QPushButton::clicked,
            [=] () {
        // must stop cell-holding object's processes
    });

    push = new QPushButton("Clear");
    grid->addWidget(push, 2, 3);
    connect(push, &QPushButton::clicked,
            [=] () {
        // must set all cells to dead
    });

    push = new QPushButton("Return");
    grid->addWidget(push, 2, 4);
    connect(push, &QPushButton::clicked,
            [=] () {
        hide();
    });


    setLayout(grid);
}


void gamewindow::sendRow(int* v) {
    row = *v;
}


void gamewindow::sendCol(int* v) {
    col = *v;
}
