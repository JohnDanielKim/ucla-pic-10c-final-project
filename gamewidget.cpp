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
    timer->setInterval(300);

    map1 = new bool[val2 * val2];

    timer->callOnTimeout(
                [=] () {
        next();
    });
}

gamewidget::~gamewidget() {
    delete [] map1;
    delete [] map2;
}

void gamewidget::getVal(const int &v) {
    val1 = v;
    val2 = val1 + 2;
}

void gamewidget::clear () {
    for (int i = 0; i < val2; ++i) {
        for (int j = 0; j < val2; ++j) {
            map1[(i * val2) + j] = false;
        }
    }
    repaint();
}

bool gamewidget::cellState (int i, int j) {
    int neighbors = 0;
    neighbors += map1[((i - 1) * val2) + (j - 1)];
    neighbors += map1[(i * val2) + (j - 1)];
    neighbors += map1[((i + 1) * val2) + (j - 1)];
    neighbors += map1[((i - 1) * val2) + j];
    neighbors += map1[((i + 1) * val2) + j];
    neighbors += map1[((i - 1) * val2) + (j + 1)];
    neighbors += map1[(i * val2) + (j + 1)];
    neighbors += map1[((i + 1) * val2) + (j + 1)];
    if (map1[(i * val2) + j] == true) {
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
    for (int i = 1; i < val2; ++i) {
        for (int j = 1; j < val2; ++j) {
            map2[(i * val2) + j] = cellState(i, j);
        }
    }
    copy();
    repaint();
}

void gamewidget::copy() {
    for (int i = 1; i < val2; ++i) {
        for (int j = 1; j < val2; ++j) {
            map1[(i * val2) + j] = map2[(i * val2) + j];
            map2[(i * val2) + j] = false;
        }
    }
}

void gamewidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    color(p);
}

void gamewidget::color (QPainter &p) {
    double cellWidth = (double)width() / val1;
    double cellHeight = (double)height() / val1;

    p.setPen("white");

    for(double i = cellWidth; i <= width(); i += cellWidth)
        p.drawLine(i, 0, i, height());
    for(double i = cellHeight; i <= height(); i += cellHeight)
        p.drawLine(0, i, width(), i);

    p.drawRect(0, 0, width()-1, height()-1);
    for (int i = 0; i <= val1; ++i) {
        for (int j = 0; j <= val1; ++j) {
            if (map1[(i * val1) + j]) {
                qreal left = (qreal)(cellWidth * j - cellWidth);
                qreal top  = (qreal)(cellHeight * i - cellHeight);
                QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                p.fillRect(r, QBrush("white"));
            }
        }
    }
}

void gamewidget::mousePressEvent(QMouseEvent *event) {
    double cellWidth = (double)width() / val1;
    double cellHeight = (double)height() / val1;
    int i = qFloor(event->y() / cellHeight) + 1;
    int j = qFloor(event->x() / cellWidth) + 1;
    map1[(i * val1) + j] = !map1[i * val1 + j];
    repaint();
}

void gamewidget::startTimer() {
    timer->start();
}

void gamewidget::stopTimer() {
    timer->stop();
}
