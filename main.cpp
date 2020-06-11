#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow w;
    w.show();
    return a.exec();
}

/* Plan: two windows
 * Start window: title, rules,
 *  spinboxes for rows and cols,
 *  start button
 * Game window:
 *  grid: click to make cells alive
 *  start, stop, clear, return buttons
 *      start: start all game functions,
 *          stop clicks
 *      stop: pause all game functions
 *      clear: clear the board (set all cells to dead)
 *      return: return to main window
 */
