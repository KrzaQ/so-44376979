#include "mainwindow.hpp"
#include <QApplication>

#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<std::string>("string");
    MainWindow w;
    w.show();

    return a.exec();
}
