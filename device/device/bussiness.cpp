#include "bussiness.h"
#include <QDebug>
#include <QSqlError>
bussiness::bussiness(QObject *parent) : QObject(parent)
{
}

// 根据给定的设备序列号登陆设备
bool bussiness::deviceLogin(QString serial, QString password)
{
    // 获取数据库实例
    QString dataBaseAddress = "D:/Program Files (x86)/dB_Libray/project";
    QString connectName = "device_0";
    DataBase* pdb = DataBase::getDataBaseInstance(dataBaseAddress, connectName);

    // 查询当前设备是否存在
    if (pdb->selectDeviceBySerial(serial, password))
    {
        return pdb->updateLoginTimeBySerial(serial);
    }
    else{
        return false;
    }

}

bool bussiness::deviceRegiste(QString serial, QString password)
{
    // 获取数据库实例
    QString dataBaseAddress = "D:/Program Files (x86)/dB_Libray/project";
    QString connectName = "device_0";
    DataBase* pdb = DataBase::getDataBaseInstance(dataBaseAddress, connectName);

    return pdb->insertDeviceBySerial(serial, password);

}

bool bussiness::sendEcgWaveData(QString serial, unsigned short ecgWave[])
{
    bool ret = true;
    // 讲ecgWave数据转发成byte类型
    QByteArray ba;
    unsigned char ch;
    for (int i = 0; i < 500; i++){
        ch = (ecgWave[i] >> 8) & 0xff;
        ba.append(ch);   // 取高八位
        ch = ecgWave[i] & 0xff;
        ba.append(ch);
    }
    // 获取数据库实例
    QString dataBaseAddress = "D:/Program Files (x86)/dB_Libray/project";
    QString connectName = "device";
    DataBase *pdb = DataBase::getDataBaseInstance(dataBaseAddress, connectName);
    if(!pdb->insertEcgWaveData(serial, ba)){
        qDebug() << "insert fail";
        ret = false;
        return ret;
    }
    qDebug() << "insert true";
    return ret;

}

QSqlQueryModel* bussiness::selectPatientModel(QString serial)
{
    // 获取数据库实例
    QString dataBaseAddress = "D:/Program Files (x86)/dB_Libray/project";
    QString connectName = "device";
    DataBase* pdb = DataBase::getDataBaseInstance(dataBaseAddress, connectName);
    if (!pdb->getDataBase().open()){
        qDebug() << "open fail" << pdb->getDataBase().lastError().text();
    }
    model = new QSqlQueryModel;
    // 关联表格及数据库
    // 这里需要字符拼接方法，才能实现根据serial指定serial_port
    model->setQuery("select * from patient where patientId = (select patientId from device_patient where serial_port = 'dev-01');", pdb->getDataBase());

    return model;



}
