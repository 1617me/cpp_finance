#ifndef HELPERTHREAD_H
#define HELPERTHREAD_H

#include <QObject>
#include <QThread>

class HelperThread : public QThread
{
public:
    HelperThread();
    void run();
};

#endif // HELPERTHREAD_H
