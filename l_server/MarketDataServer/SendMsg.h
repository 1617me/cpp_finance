#ifndef SENDMSG_H
#define SENDMSG_H

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

class SendMsg : public QObject
{
    Q_OBJECT
    bool open_db(const QString &driver, const QString &path, QSqlDatabase &db);
    void runQueue();
public:
    explicit SendMsg(QObject *parent = 0);

signals:

public slots:
};

#endif // SENDMSG_H
