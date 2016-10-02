#include "SendMsg.h"

SendMsg::SendMsg(QObject *parent) : QObject(parent)
{

}

/* 9.17更新，
 * 需求,,,
 * 1. 指定日期开始播放行情，
 * 2. 从当前时刻 10：00：00 开始播放， 使用QDateime
 * 3. 同步播放行情， 当前时刻播放当前时刻到行情。
 */

/* 打开数据库 */
bool open_db(const QString &driver, const QString &path, QSqlDatabase &db){
    db = QSqlDatabase::addDatabase(driver);
    db.setDatabaseName(path);
    return db.open();
}

//void exec_sql(const QString &sql){

//}

void run_query(){
    QSqlDatabase db;
    if(!open_db("QSQLITE", "md.db", db)){
        qDebug() << "open sqlite database error!" << endl;
        return ;
    }

    QString sql = "select * from md where rowid<10";
    QSqlQuery sql_que;
    sql_que.exec(sql);
    QSqlRecord rc = sql_que.record();
    int no_id = rc.indexOf("security_id");
    int stamp_id = rc.indexOf("stamp");
    int price_id = rc.indexOf("last_price");

//    QTime cur_time()
    QDate date(2016, 1, 15);
    /* select * from md where stamp>%ld */

    while (sql_que.next()){
        QString stamp_str = sql_que.value(stamp_id).toString();
        QDateTime stamp;
        stamp.setTime_t(stamp_str.toUInt());
        qDebug() << sql_que.value(no_id).toString() << " | "
//                 << stamp.time() <<  " | "
                 << stamp.date() << " | "
                 << sql_que.value(price_id).toString() << " | "
                 << endl;
    }
}



/***************** 9.17 end ****************/
