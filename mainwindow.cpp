#include "mainwindow.h"
#include <string>
#include <QString>

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
{
    layout = new QVBoxLayout();


    label = new QLabel("\"The Game of Life\" by John Conway");
    layout->addWidget(label);
    label = new QLabel("Rules:");
    layout->addWidget(label);
    label = new QLabel("1. Any live cell with one or no live neighbors dies (underpopulation)");
    layout->addWidget(label);
    label = new QLabel("2. Any live cell with two or three live neighbors lives on to the next generation");
    layout->addWidget(label);
    label = new QLabel("3. Any live cell with over three live neighbors dies (overpopulation)");
    layout->addWidget(label);
    label = new QLabel("4. Any dead cell with three live neighbors becomes a live cell (reproduction)");
    layout->addWidget(label);


    push = new QPushButton("GO");
    layout->addWidget(push);
    window2 = new gamewindow();
    connect(push, &QPushButton::clicked,
            [=] () {
        window2->show();
    });


    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

mainwindow::~mainwindow() {}
