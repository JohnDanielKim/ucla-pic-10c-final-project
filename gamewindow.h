#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPushButton>

class gamewindow : public QWidget
{
    Q_OBJECT
public:
    explicit gamewindow(QWidget *parent = nullptr);

public slots:
    void receiveValue(int);

private:
    QPushButton* push;
};

#endif // GAMEWINDOW_H
