#include "updater.hpp"

#include <QThread>

Updater::Updater(QObject *parent):
    QObject(parent),
    finished{false}
{

}

void Updater::doStuff()
{
    while(!finished) {
        QThread::msleep(50);
        counter++;
        emit updateStuff(to_string(counter));
    }
//    this->moveToThread(nullptr);
}



