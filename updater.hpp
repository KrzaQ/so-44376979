#ifndef UPDATER_HPP
#define UPDATER_HPP

#include <string>
#include <atomic>

#include <QObject>

using namespace std;

class Updater : public QObject
{
    Q_OBJECT
public:
    Updater(QObject*);

public slots:

    void doStuff();

signals:
    void updateStuff(string);

public:
    atomic_bool finished;
    unsigned counter = 0;
};

#endif // UPDATER_HPP
