#include "gamewindow.h"
#include <string>
#include <QString>

gamewindow::gamewindow(QWidget *parent) :
    QWidget(parent)
{
    layout = new QGridLayout();
    widget = new gamewidget();

    spin = new QSpinBox;
    spin->setRange(5, 50);
    spin->setSuffix(" rows by columns");
    connect(spin,
            QOverload<int>::of(&QSpinBox::valueChanged),
            [=] (int value) {
        widget->getVal(value);
        widget->clear();
        widget->repaint();
    });
    layout->addWidget(spin, 2, 0);


    push = new QPushButton("Play");
    layout->addWidget(push, 3, 0);
    connect(push, &QPushButton::clicked,
            [=] () { widget->startTimer(); });
    push = new QPushButton("Pause");
    layout->addWidget(push, 4, 0);
    connect(push, &QPushButton::clicked,
            [=] () { widget->stopTimer(); });
    push = new QPushButton("Clear");
    layout->addWidget(push, 5, 0);
    connect(push, &QPushButton::clicked,
            [=] () {
        widget->stopTimer();
        widget->clear();
        widget->repaint();
    });
    push = new QPushButton("Return");
    layout->addWidget(push, 6, 0);
    connect(push, &QPushButton::clicked,
            [=] () {
        widget->hide();
    });


    layout->addWidget(widget, 7, 0);
    setLayout(layout);
}

gamewindow::~gamewindow() {}
