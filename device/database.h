#ifndef DATABASE_H
#define DATABASE_H

#include <QWidget>
#include <QSqlDatabase>
class DataBase
{
public:
    explicit DataBase(QString dbName, QString connectName);
    static DataBase* getDataBaseInstance(QString dbName, QString connectName);

private:
    QSqlDatabase db;
public:
    bool selectDeviceBySerial(QString Serial, QString password);
    bool insertDeviceBySerial(QString Serial, QString password);
    bool updateLoginTimeBySerial(QString Serial);
    bool insertEcgWaveData(QString serial, QByteArray ba);
    QByteArray selectEcgWaveData(int device_id);

    QSqlDatabase getDataBase();

};

#endif // DATABASE_H
