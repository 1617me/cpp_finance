#ifndef QAPP_H
#define QAPP_H

#include <QCoreApplication>
class SendMsg;

class QApp : public QCoreApplication
{
    SendMsg *_pSend_msg;
public:
    QApp(int &argc, char **argv);
};

#endif // QAPP_H
