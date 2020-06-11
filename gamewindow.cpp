#include "gamewindow.h"
#include <string>
#include <QString>

gamewindow::gamewindow(QWidget *parent) : QWidget(parent)
{
    grid = new QGridLayout();

    label = new QLabel("Rows by columns (max 50)");
    grid->addWidget(label, 1, 1);
    spin = new QSpinBox;
    spin->setRange(5, 50);
    label = new QLabel();
    connect(spin,
            QOverload<int>::of(&QSpinBox::valueChanged),
            [=] (int value) {
        label->setText(
                    QString::number(value) + " rows by columns"
                    );
        grid->addWidget(label, 2, 2);
    });
    grid->addWidget(spin, 2, 1);


    push = new QPushButton("Play");
    grid->addWidget(push, 3, 1);
    connect(push, &QPushButton::clicked,
            [=] () {
        // must start cell-holding object's processes
    });

    push = new QPushButton("Pause");
    grid->addWidget(push, 3, 2);
    connect(push, &QPushButton::clicked,
            [=] () {
        // must stop cell-holding object's processes
    });

    push = new QPushButton("Clear");
    grid->addWidget(push, 3, 3);
    connect(push, &QPushButton::clicked,
            [=] () {
        // must set all cells to dead
    });

    push = new QPushButton("Return");
    grid->addWidget(push, 3, 4);
    connect(push, &QPushButton::clicked,
            [=] () {
        hide();
    });


    setLayout(grid);
}
