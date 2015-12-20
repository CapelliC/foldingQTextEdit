/**
 * example code to complete my answer to my question on StackOverflow: see
 *  http://stackoverflow.com/questions/19232882/nice-text-formatting-in-qtextedit-like-qtcreator-does
 * author: CapelliC @2015
 * license: MIT
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
