#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QSpinBox>
#include <QPushButton>
#include "gamewidget.h"

class gamewindow : public QWidget
{
    Q_OBJECT
public:
    explicit gamewindow(QWidget *parent = nullptr);

private:
    QGridLayout* layout;
    QSpinBox* spin;
    int val;
    QPushButton* push;

    gamewidget* widget;
};

#endif // GAMEWINDOW_H
