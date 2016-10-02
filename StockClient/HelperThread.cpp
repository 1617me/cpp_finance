#include "clientapp.h"
#include "MESendEvent.h"
#include "HelperThread.h"

#include <zmq.h>
#include <QEvent>
#include <QDebug>
#include <QThread>

HelperThread::HelperThread(QObject *parent):
    QThread(parent)
{

}



void
HelperThread::run(){

    void *sub = zmq_socket(CLIENT_APP->context, ZMQ_SUB);
    Q_ASSERT(sub);
    int rc = zmq_setsockopt(sub, ZMQ_SUBSCRIBE, nullptr, 0);
    Q_ASSERT(rc == 0);
    rc = zmq_connect(sub,"tcp://localhost:10008");
    Q_ASSERT(rc == 0);
    qDebug() << "helloooooooooooooooo" << endl;
    while(1){
        zmq_msg_t msg;
        zmq_msg_init(&msg);
        zmq_recvmsg(sub, &msg, 0);

        MESendEvent *se = new MESendEvent(QEvent::User);
        // 发送事件
        QCoreApplication::sendEvent(parent(), se);
        zmq_msg_close(&msg);
    }

    // do sth;
}
