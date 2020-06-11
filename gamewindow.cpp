#include "gamewindow.h"
#include <string>
#include <QString>

gamewindow::gamewindow(QWidget *parent) : QWidget(parent)
{
    vec = new QVector<int>(2);

    grid = new QGridLayout();
    label = new QLabel(
                QString::number(vec->at(0)) + " rows, " +
                QString::number(vec->at(1)) + " columns");
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

void gamewindow::receiveValue(QVector<int>* v) {
    for (int i = 0; i < v->size(); ++i) {
        vec->insert(i, v->at(i));
    }
}
