#ifndef BUSSINESS_H
#define BUSSINESS_H

#include <QObject>
#include "database.h"

/* 这个Bussiness是处理所有与数据库相关的业务
 *
 * */

class Bussiness : public QObject
{
    Q_OBJECT
public:
    explicit Bussiness(QObject *parent = nullptr);

public:
    bool deviceLogin(QString serial);
    bool sendEcgWaveData(unsigned short int ecgWave[]);
    unsigned short int* getEcgWaveData(int device_id);
    bool doctorLogin(QString phoneNumber, QString password);
    bool doctorRegister(QString phoneNumber, QString password, QString doctorName);

};

#endif // BUSSINESS_H
