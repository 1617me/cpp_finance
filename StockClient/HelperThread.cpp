#include "HelperThread.h"
#include "clientapp.h"
#include <zmq.h>

HelperThread::HelperThread()
{

}



void
HelperThread::run(){

    void *sub = zmq_sock(CLIENT_APP->context, ZMQ_SUB);
    Q_ASSERT(sub);
    int rc = zmq_setsockopt(sub, ZMQ_SUBSCRIBE, nullptr, 0);
    Q_ASSERT(rc == 0);
    rc = connect(sub, "tcp://localhost:8888");
    Q_ASSERT(rc == 0);


    // do sth;
}
