#include <QApplication>
#include <QtWidgets>
#include <QtWebKit/QtWebKit>
#include "mainwindow.h"

int main( int argc , char * argv[] )
{
    QApplication a( argc, argv );
    MainWindoW test;
    test.showMaximized();

    return a.exec();
}
