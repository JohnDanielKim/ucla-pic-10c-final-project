#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QTimer>
#include <QSlider>

class gamewindow : public QWidget
{
    Q_OBJECT
public:
    explicit gamewindow(QWidget *parent = nullptr);

public slots:
    void clear ();

    bool cellState (int i, int j);
    void next ();

    void color ();

private:
    QVBoxLayout* layout;
    QLabel* label;
    QSpinBox* spin;
    int val;
    QPushButton* push;
    QSlider* slide;

    QTimer* timer;
    bool* map;
};

#endif // GAMEWINDOW_H
