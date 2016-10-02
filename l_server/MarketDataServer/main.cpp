#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QDateTime>
#include <QSqlQuery>
#include <QTimeZone>
#include <assert.h>
#include <QThread>
#include <QObject>
#include <QDebug>
#include <zmq.h>

#include "StockMsg.h"
#include "QApp.h"



#if 0
int main(int argc, char *argv[]){
//    run_query();
    QApp app(argc, argv);



    app.exec();
}

#endif




/* 9.16 */
// msg初始化指定的毁掉函数。

void my_free(void *data, void *hint){
    qDebug()<< "------------ i'm free ----------" << endl;
    free(data);
}



int main(int argc, char *argv[])
{
    // 搭建socket publisher环境
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    int rt = zmq_bind(publisher, "tcp://*:10008");
    assert(rt == 0);

    //创建传送msg数据
    StockTick *msg_tick = new StockTick;
    msg_tick->StockCode = 145192; // 数据可以随机
    msg_tick->TimeStamp = 925;
    msg_tick->LastPrice = 666;

    zmq_msg_t msg;
    rt = zmq_msg_init_data(&msg, msg_tick, sizeof(StockTick), my_free, NULL);
    assert(rt == 0);

    int i = 0;
    // 创建一个连续发送到拷贝 --> caution 一定要初始化
    zmq_msg_t msg_cp;
    zmq_msg_init(&msg_cp);
    while(1){
        // 连续发送到内容一定要拷贝一份，发送一次后，就清空了内容。
        zmq_msg_copy(&msg_cp,&msg);
        qDebug() << "msg size:" << zmq_msg_size(&msg_cp)<< endl;
        // 当send后 zmq会自动进行close， 无须在手动close：
        zmq_msg_send(&msg_cp, publisher, 0);
        printf("sending..message.... %d | size: %d\n", i++, zmq_msg_size(&msg_cp));
        QThread::sleep(1);
//        if (i > 15)
//                break;
    }

    qDebug() << "============== sizeof(struct):" << sizeof(msg_tick) << endl;
    // 发送后关闭msg， 这样就会调用回调函数。 释放掉之前申请的空间。
    zmq_msg_close(&msg);
    zmq_close(publisher);
    zmq_ctx_destroy(context);
    return 0;
}


