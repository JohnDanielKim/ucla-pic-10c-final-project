#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

/* Plan: two windows
 * Start window: title, rules,
 *  spinboxes for rows and cols,
 *  start button
 * Game window:
 *  grid: click to make squares alive
 *  start, stop, clear buttons
 *      start: start all game functions,
 *          stop clicks
 *      stop: pause all game functions
 *      clear: stop all game functions,
 *          return to main window
 */
