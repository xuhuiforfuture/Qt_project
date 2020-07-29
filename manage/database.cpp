#include "database.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <QDateTime>
#include <QString>

DataBase::DataBase(QString dbName, QString connectName)
{
    //0. 判断数据库是否已经添加
    if(QSqlDatabase::contains(connectName)){
        db = QSqlDatabase::database(connectName);
    }
    else{
        // 加载驱动
        db = QSqlDatabase::addDatabase("QSQLITE", connectName);
    }

    // 指定数据库
    db.setDatabaseName(dbName);

}

DataBase* DataBase::getDataBaseInstance(QString dbName, QString connectName)
{
    static DataBase database(dbName, connectName);
    return &database;

}

bool DataBase::selectDeviceBySerial(QString Serial)
{
    bool ret = true;

    if (!db.open()){
        qDebug() << "open fail" << db.lastError().text();
        ret = false;
        return ret;
    }
    qDebug() << db.databaseName();
    QString sql = "select * from device where serial_port =:Serial;";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":Serial", QVariant(Serial));

    if(!query.exec()){
        qDebug() << "select fail:" << query.lastError().text();
        ret = false;
        db.close();
        return ret;
    }
    // 如果没有数据，则返回false
    if(!query.next()){
        ret = false;
    }

    db.close();
    return ret;

}

bool DataBase::insertDeviceBySerial(QString Serial)
{
    bool ret = true;

    if (!db.open()){
        qDebug() << "open fail" << db.lastError().text();
        ret = false;
        return ret;
    }

    QString sql = "insert into device values(null, :Serial, datetime('now','localtime'));";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":Serial", QVariant(Serial));

    if(!query.exec()){
        qDebug() << "insert fail:" << query.lastError().text();
        ret = false;
        db.close();
        return ret;
    }

    db.close();
    return ret;

}

bool DataBase::updateLoginTimeBySerial(QString Serial)
{
    bool ret = true;

    if (!db.open()){
        qDebug() << "open fail" << db.lastError().text();
        ret = false;
        return ret;
    }

    QString sql = "update device set login_time = datetime('now', 'localtime') where serial_port = :Serial;";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":Serial", QVariant(Serial));

    if(!query.exec()){
        qDebug() << "update fail:" << query.lastError().text();
        ret = false;
        db.close();
        return ret;
    }

    db.close();
    return ret;

}

bool DataBase::insertEcgWaveData(QByteArray ba)
{
    bool ret = true;

    if (!db.open()){
        qDebug() << "open fail" << db.lastError().text();
        ret = false;
        return ret;
    }

    QString sql = "insert into EcgWaveData values(null, 1, :ecgData, datetime('now', 'localtime'));";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":ecgData", QVariant(ba));

    if(!query.exec()){
        qDebug() << "insert fail: " << query.lastError().text();
        ret = false;
        db.close();
        return ret;
    }

    db.close();
    return ret;

}

bool DataBase::selectDoctor(QString phoneNum, QString password)
{
    bool ret = true;

    if (!db.open()){
        qDebug() << "open fail" << db.lastError().text();
        ret = false;
        return ret;
    }

    QString sql = "select * from doctor where phoneNum =:str1 and password = :str2;";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":str1", QVariant(phoneNum));
    query.bindValue(":str2", QVariant(password));

    if(!query.exec()){
        qDebug() << "select fail:" << query.lastError().text();
        ret = false;
        db.close();
        return ret;
    }
    // 如果没有数据，则返回false
    if(!query.next()){
        ret = false;
    }

    db.close();
    return ret;

}

bool DataBase::insertDoctor(QString phoneNum, QString password, QString name)
{
    bool ret = true;

    if (!db.open()){
        qDebug() << "open fail" << db.lastError().text();
        ret = false;
        return ret;
    }

    QString sql = "insert into doctor values(null, :str1, :str2, :str3);";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":str1", phoneNum);
    query.bindValue(":str2", name);
    query.bindValue(":str3", password);

    if(!query.exec()){
        qDebug() << "insert fail: " << query.lastError().text();
        ret = false;
        db.close();
        return ret;
    }

    db.close();
    return ret;

}

QByteArray DataBase::selectEcgWaveData(int device_id)
{
    if (!db.open()){
        qDebug() << "open fail" << db.lastError().text();
    }

    QString sql = "select * from EcgWaveData where device_id = :device_id;";
    QSqlQuery query(db);
    query.prepare(sql);
    query.bindValue(":device_id", QVariant(device_id));

    if(!query.exec()){
        qDebug() << "select fail: " << query.lastError().text();
        db.close();
    }

    QByteArray ba;
    if(query.next()){
        qDebug() << query.value("device_id").toInt();
        qDebug() << query.value("get_time").toDateTime().toString("yyyy-MM-dd hh:mm:ss");
        ba = query.value("ecgdata").toByteArray();
    }

    db.close();
    return ba;

}
