#include <QCoreApplication>
#include <QtGlobal>
#include <assert.h>
#include <QThread>
#include <QDebug>
#include <zmq.h>
//#include <../l_common/StockMsg.h>
//Qt 可以指定头文件目录
//pro INCLUDEPATH+=../l_common/
#include "StockMsg.h"


int main(int argc, char *argv[])
{
    /*
     * 1. 创建链接
     * 2. 接受数据返回内容。
     * 3. 解析数据。
     */
    //创建环境 链接服务器
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);
    int rt = zmq_connect(subscriber, "tcp://localhost:5558");
    assert(rt == 0);
    // 设置过滤器， “不做任何过滤接受”
    rt = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, NULL, 0);
    // 建立message;
    zmq_msg_t msg;
    zmq_msg_init(&msg);

    int i = 0;

    while(1){
        // 开始接受消息。 非阻塞模式：w。
        int ret = zmq_msg_recv(&msg, subscriber, 0);

        qDebug() << "recieving data.... " << i++
                 << " ret: " << ret
                 << endl;
        QThread::sleep(1);
        if (ret < 0){
            if (errno == EAGAIN)
                continue;
            else
                break;
        }
        else
            break;

    }
    // 解释收到的数据
    qDebug() << "========= client recieved message ========" << endl;
    StockTick *msg_recv = (StockTick *)zmq_msg_data(&msg);
    qDebug() << "zcode:" << msg_recv->StockCode  << " | "
             << "stemp:" << msg_recv->TimeStamp << " | "
             << "price:" << msg_recv->LastPrice << endl;
    qDebug() << "==========================================" << endl;
    zmq_msg_close(&msg);
    zmq_close(subscriber);
    zmq_ctx_destroy(context);
    return 0;
}

