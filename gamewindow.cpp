#include "gamewindow.h"
#include <string>
#include <QString>
#include <QPainter>
#include <QColor>

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
        clear();
        repaint();
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
            [=] () {
        clear();
        repaint();
    });

    push = new QPushButton("Return");
    layout->addWidget(push);
    connect(push, &QPushButton::clicked,
            [=] () {
        hide();
    });


    timer->callOnTimeout(
                [=] () {
        next ();
        repaint();
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

void gamewindow::paintEvent(QPaintEvent *) {
    QPainter p(this);
    color(p);
}

void gamewindow::color (QPainter &p) {
    double cellWidth = (double)width()/val;
    double cellHeight = (double)height()/val;

    p.setPen("white");

    for(double i = cellWidth; i <= width(); i += cellWidth)
        p.drawLine(i, 0, i, height());
    for(double i = cellHeight; i <= height(); i += cellHeight)
        p.drawLine(0, i, width(), i);

    p.drawRect(0, 0, width()-1, height()-1);
    for (int i = 0; i < val; ++i) {
        for (int j = 0; j < val; ++j) {
            if (map[i * val + j]) {
                qreal left = (qreal)(cellWidth * j - cellWidth);
                qreal top  = (qreal)(cellHeight * i - cellHeight);
                QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                p.fillRect(r, QBrush("white"));
            }
        }
    }
}
