#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include "gamewindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

private:
    QVBoxLayout* layout;
    QLabel* label;
    QSpinBox* spin;
    QPushButton* push;
    gamewindow* window2;
};
#endif // MAINWINDOW_H
