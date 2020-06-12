#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
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
    void copy();

    void paintEvent(QPaintEvent *);
    void color(QPainter &p);
    void mousePressEvent(QMouseEvent *event);

    void startTimer();
    void stopTimer();

private:
    QVBoxLayout* layout;
    int val1;
    int val2;

    QTimer* timer;
    bool* map1;
    bool* map2;
};

#endif // GAMEWIDGET_H
