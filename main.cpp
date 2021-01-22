#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int ret;
    try{
        ret = a.exec();
    }
    catch(const std::bad_alloc &){
        qDebug()<<"EXIT_FAILURE";
        return EXIT_FAILURE;
    }
    return ret;
}
