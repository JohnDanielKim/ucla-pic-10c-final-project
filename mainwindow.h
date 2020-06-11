#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QVector>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include "gamewindow.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

public slots:
    // not planning to have anything here at this point

private:
    QVBoxLayout* layout;
    QVector<int>* vec;
    QLabel* label;
    QSpinBox* spin;
    QPushButton* push;
    gamewindow* window2;
};
#endif // MAINWINDOW_H
