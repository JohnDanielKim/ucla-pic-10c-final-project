#include "gamewidget.h"
#include <string>
#include <QString>
#include <QPainter>
#include <QColor>
#include <QMouseEvent>
#include <QtMath>

gamewidget::gamewidget(QWidget *parent) :
    QWidget(parent)
{
    timer = new QTimer(this);
    timer->setInterval(500);

    map = new bool[val * val];

    timer->callOnTimeout(
                [=] () {
        next ();
        repaint();
    });
}

gamewidget::~gamewidget() {
    delete [] map;
}

void gamewidget::getVal(const int &v) {
    val = v;
}

void gamewidget::clear () {
    for (int i = 0; i <= val; ++i) {
        for (int j = 0; j <= val; ++j) {
            map[(i * val) + j] = false;
        }
    }
}

bool gamewidget::cellState (int i, int j) {
    int neighbors = 0;
    neighbors += map[((i - 1) * val) + (j - 1)];
    neighbors += map[(i * val) + (j - 1)];
    neighbors += map[((i + 1) * val) + (j - 1)];
    neighbors += map[((i - 1) * val) + j];
    neighbors += map[((i + 1) * val) + j];
    neighbors += map[((i - 1) * val) + (j + 1)];
    neighbors += map[(i * val) + (j + 1)];
    neighbors += map[((i + 1) * val) + (j + 1)];
    if (map[(i * val) + j] == true) {
        switch (neighbors) {
            case 2:
            case 3:
                return true;
                break;
            default:
                return false;
        }
    } else {
        switch (neighbors) {
            case 3:
                return true;
                break;
            default:
                return false;
        }
    }
}

void gamewidget::next () {
    for (int i = 0; i <= val; ++i) {
        for (int j = 0; j <= val; ++j) {
            map[(i * val) + j] = cellState(i, j);
        }
    }
}

void gamewidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    color(p);
}

void gamewidget::color (QPainter &p) {
    double cellWidth = (double)width() / val;
    double cellHeight = (double)height() / val;

    p.setPen("white");

    for(double i = cellWidth; i <= width(); i += cellWidth)
        p.drawLine(i, 0, i, height());
    for(double i = cellHeight; i <= height(); i += cellHeight)
        p.drawLine(0, i, width(), i);

    p.drawRect(0, 0, width()-1, height()-1);
    for (int i = 0; i <= val; ++i) {
        for (int j = 0; j <= val; ++j) {
            if (map[(i * val) + j]) {
                qreal left = (qreal)(cellWidth * j - cellWidth);
                qreal top  = (qreal)(cellHeight * i - cellHeight);
                QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                p.fillRect(r, QBrush("white"));
            }
        }
    }
}

void gamewidget::mousePressEvent(QMouseEvent *event) {
    double cellWidth = (double)width() / val;
    double cellHeight = (double)height() / val;
    int i = qFloor(event->y() / cellHeight) + 1;
    int j = qFloor(event->x() / cellWidth) + 1;
    map[(i * val) + j] = !map[i * val + j];
    repaint();
}

void gamewidget::startTimer() {
    timer->start();
}

void gamewidget::stopTimer() {
    timer->stop();
}
