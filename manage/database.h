#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>

/* DataBase对数据库进行了封装
 *
 * */
class DataBase
{
public:
    explicit DataBase(QString dbName, QString connectName);
    static DataBase* getDataBaseInstance(QString dbName, QString connectName);

private:
    QSqlDatabase db;
public:
    bool selectDeviceBySerial(QString Serial);
    bool insertDeviceBySerial(QString Serial);
    bool updateLoginTimeBySerial(QString Serial);
    bool insertEcgWaveData(QByteArray ba);
    bool selectDoctor(QString phoneNum, QString password);
    bool insertDoctor(QString phoneNum, QString password, QString name);
    QByteArray selectEcgWaveData(int device_id);



};

#endif // DATABASE_H
