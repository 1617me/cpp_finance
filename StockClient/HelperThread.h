#ifndef HELPERTHREAD_H
#define HELPERTHREAD_H

#include <QObject>
#include <QThread>

class HelperThread : public QThread
{
public:
    HelperThread(QObject *parent);
    void run();
};

#endif // HELPERTHREAD_H
