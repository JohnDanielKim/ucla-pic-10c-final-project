#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QTimer>

class gamewidget : public QWidget
{
    Q_OBJECT
public:
    explicit gamewidget(QWidget *parent = nullptr);
    ~gamewidget();

public slots:
    void getVal(const int &v);

    void clear();
    bool cellState(int i, int j);
    void next();

    void paintEvent(QPaintEvent *);
    void color(QPainter &p);
    void mousePressEvent(QMouseEvent *event);

    void startTimer();
    void stopTimer();

private:
    QVBoxLayout* layout;
    QLabel* label;
    QSpinBox* spin;
    int val;
    QPushButton* push;

    QTimer* timer;
    bool* map;
};

#endif // GAMEWIDGET_H
