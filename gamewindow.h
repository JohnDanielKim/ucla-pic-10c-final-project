#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>

class gamewindow : public QWidget
{
    Q_OBJECT
public:
    explicit gamewindow(QWidget *parent = nullptr);

public slots:

private:
    QGridLayout* grid;
    QLabel* label;
    QSpinBox* spin;
    QPushButton* push;
};

#endif // GAMEWINDOW_H
