#include "gamewindow.h"
#include <string>
#include <QString>

gamewindow::gamewindow(QWidget *parent) :
    QWidget(parent)
{
    layout = new QVBoxLayout();
    widget = new gamewidget();

    spin = new QSpinBox;
    spin->setRange(5, 50);
    spin->setSuffix(" rows by columns");
    connect(spin,
            QOverload<int>::of(&QSpinBox::valueChanged),
            [=] (int value) {
        widget->getVal(value);
    });
    layout->addWidget(spin);


    push = new QPushButton("Play");
    layout->addWidget(push);
    connect(push, &QPushButton::clicked,
            [=] () { widget->startTimer(); });
    push = new QPushButton("Pause");
    layout->addWidget(push);
    connect(push, &QPushButton::clicked,
            [=] () { widget->stopTimer(); });
    push = new QPushButton("Clear");
    layout->addWidget(push);
    connect(push, &QPushButton::clicked,
            [=] () { widget->clear(); });
    push = new QPushButton("Return");
    layout->addWidget(push);
    connect(push, &QPushButton::clicked,
            [=] () { hide(); });


    layout->addWidget(widget);
    setLayout(layout);
}

gamewindow::~gamewindow() {}
