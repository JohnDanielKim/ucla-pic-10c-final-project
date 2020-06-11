#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QVector>
#include <QLabel>
#include <QPushButton>

class gamewindow : public QWidget
{
    Q_OBJECT
public:
    explicit gamewindow(QWidget *parent = nullptr);

public slots:
    void receiveValue(QVector<int>* v);

private:
    QVector<int>* vec;
    QGridLayout* grid;
    QLabel* label;
    QPushButton* push;
};

#endif // GAMEWINDOW_H
