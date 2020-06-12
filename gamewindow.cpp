#include "gamewindow.h"
#include <string>
#include <QString>
#include <QPainter>

gamewindow::gamewindow(QWidget *parent) :
    QWidget(parent)
{
    layout = new QVBoxLayout();
    timer = new QTimer(this);


    label = new QLabel("Rows by columns [5-50]:");
    layout->addWidget(label);
    spin = new QSpinBox;
    spin->setRange(5, 50);
    label = new QLabel();
    connect(spin,
            QOverload<int>::of(&QSpinBox::valueChanged),
            [=] (int value) {
        val = value;
        map = new bool[val * val];
    });
    layout->addWidget(spin);
    label = new QLabel("Simulation speed (ms) [100-500]:");
    layout->addWidget(label);
    slide = new QSlider(Qt::Horizontal);
    slide->setRange(100, 500);
    slide->setTickInterval(100);
    connect(slide,
            QOverload<int>::of(&QSlider::valueChanged),
            [=] (int value) {
        timer->setInterval(value);
    });
    layout->addWidget(slide);


    push = new QPushButton("Play");
    layout->addWidget(push);
    connect(push, &QPushButton::clicked,
            [=] () { timer->start(); });

    push = new QPushButton("Pause");
    layout->addWidget(push);
    connect(push, &QPushButton::clicked,
            [=] () { timer->stop(); });

    push = new QPushButton("Clear");
    layout->addWidget(push);
    connect(push, &QPushButton::clicked,
            [=] () { clear (); });

    push = new QPushButton("Return");
    layout->addWidget(push);
    connect(push, &QPushButton::clicked,
            [=] () {
        hide();
    });


    setLayout(layout);
}

void gamewindow::clear () {
    for (int i = 0; i < val; ++i) {
        for (int j = 0; j < val; ++j) {
            map[i * val + j] = false;
        }
    }
}

bool gamewindow::cellState (int i, int j) {
    int neighbors = 0;
    neighbors += map[(i - 1) * val + (j - 1)];
    neighbors += map[i * val + (j - 1)];
    neighbors += map[(i + 1) * val + (j - 1)];
    neighbors += map[(i - 1) * val + j];
    neighbors += map[(i + 1) * val + j];
    neighbors += map[(i - 1) * val + (j + 1)];
    neighbors += map[i * val + (j + 1)];
    neighbors += map[(i + 1) * val + (j + 1)];
    if ((neighbors == 2) || (neighbors == 2)) {
        if (map[i * val + j]) {
            return true;
        }
    }
    return false;
}

void gamewindow::next () {
    for (int i = 0; i < val; ++i) {
        for (int j = 0; j < val; ++j) {
            map[i * val + j] = cellState(i, j);
        }
    }
}

void gamewindow::color () {

}
