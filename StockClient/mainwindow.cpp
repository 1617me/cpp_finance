#include "StockMsg.h"
#include "clientapp.h"
#include "mainwindow.h"
#include "HelperThread.h"
#include "ui_mainwindow.h"

#include <zmq.h>
#include <QDebug>
#include <errno.h>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
//    subscriber(zmq_socket(CLIENT_APP->context, ZMQ_SUB))
{


    HelperThread *helpThread = new HelperThread;
    helpThread->start();


#if 0
//    zmq_socket
    // use Timer
    Q_ASSERT(subscriber);
    int rc = zmq_setsockopt(subscriber,ZMQ_SUBSCRIBE,nullptr,0);
    Q_ASSERT(rc == 0);
    rc = zmq_connect(subscriber,"tcp://localhost:5555");
        Q_ASSERT(rc == 0);
    startTimer(1000);

    count = 0;
#endif

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    zmq_close(subscriber);
    delete ui;
}
void MainWindow::timerEvent(QTimerEvent *event)
{
    qDebug()<<"------------------------------------------"<<count++<<"-------------------------------------------"<<endl;

    qDebug()<<"recv from server..."<<endl;
//    if(rc == -1)
//        return;

    zmq_setsockopt(subscriber,ZMQ_SUBSCRIBE,"",0);

    StockTick tmp;

    zmq_msg_t recv;
    int rc = zmq_msg_init(&recv);
    Q_ASSERT(rc == 0);


    while(1)
    {
        rc = zmq_msg_recv(&recv,subscriber,ZMQ_DONTWAIT);
        if(rc == -1)
            break;
//        if(errno == EAGAIN)
//            return;
//        Q_ASSERT(rc != -1);
        memcpy(&tmp,zmq_msg_data(&recv),sizeof(tmp));
        Q_ASSERT(rc == sizeof(tmp));

        printf("st:%d, ti:%d, la:%.2f\n",tmp.StockCode,tmp.TimeStamp,tmp.LastPrice);

        //        rc = zmq_getsockopt(subscriber,ZMQ_RCVMORE,)

    }

    zmq_msg_close(&recv);
//    zmq_close(subscriber);
    qDebug()<<__FUNCTION__;
}

