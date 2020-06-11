#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

class gamewindow : public QWidget
{
    Q_OBJECT
public:
    explicit gamewindow(QWidget *parent = nullptr);

public slots:
    void sendRow(int* v);
    void sendCol(int* v);

private:
    QGridLayout* grid;
    int row;
    int col;
    QLabel* label;
    QPushButton* push;
};

#endif // GAMEWINDOW_H
