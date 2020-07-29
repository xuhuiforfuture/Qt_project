#ifndef BUSSINESS_H
#define BUSSINESS_H

#include <QObject>
#include "database.h"
#include <QSqlQueryModel>
class bussiness : public QObject
{
    Q_OBJECT
public:
    explicit bussiness(QObject *parent = nullptr);

public:
    bool deviceLogin(QString serial, QString password);
    bool deviceRegiste(QString serial, QString password);
    bool sendEcgWaveData(QString serial, unsigned short int ecgWave[]);
    QSqlQueryModel* selectPatientModel(QString serial);


public:
    QSqlQueryModel *model;

};

#endif // BUSSINESS_H
