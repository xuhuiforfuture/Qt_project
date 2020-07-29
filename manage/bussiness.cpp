#include "bussiness.h"
#include <QDebug>

Bussiness::Bussiness(QObject *parent) : QObject(parent)
{

}


// 根据给定的设备序列号登陆设备
bool Bussiness::deviceLogin(QString serial)
{
    // 获取数据库实例
    QString dataBaseAddress = "D:/Program Files (x86)/dB_Libray/project";
    QString connectName = "device_0";
    DataBase* pdb = DataBase::getDataBaseInstance(dataBaseAddress, connectName);

    qDebug() << serial;

    // 查询当前设备是否存在
    bool ret = pdb->selectDeviceBySerial(serial);
    // 没有则创建一个新的设备
    if(!ret){
        ret = pdb->insertDeviceBySerial(serial);
    }
    // 有，则更新登陆时间
    else{
        ret = pdb->updateLoginTimeBySerial(serial);
    }
    return ret;

}

bool Bussiness::sendEcgWaveData(unsigned short ecgWave[])
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
    if(!pdb->insertEcgWaveData(ba)){
        qDebug() << "insert fail";
        ret = false;
        return ret;
    }
    qDebug() << "insert true";
    return ret;

}
static unsigned short ecgWaveData[500];

unsigned short *Bussiness::getEcgWaveData(int device_id)
{

    QString dataBaseAddress = "D:/Program Files (x86)/dB_Libray/project";
    QString connectName = "device";
    DataBase* pdb = DataBase::getDataBaseInstance(dataBaseAddress, connectName);
    QByteArray ba = pdb->selectEcgWaveData(device_id);

    unsigned short int value = 0;
    for(int i = 0; i < ba.size(); i += 2){
        value = 0;
        value |= ba[i] << 8;
        value |= ba[i+1];
        ecgWaveData[i/2] = value;
    }
    return ecgWaveData;

}

bool Bussiness::doctorLogin(QString phoneNumber, QString password)
{
    // 获取数据库实例
    QString dataBaseAddress = "D:/Program Files (x86)/dB_Libray/project";
    QString connectName = "doctor";
    DataBase* pdb = DataBase::getDataBaseInstance(dataBaseAddress, connectName);

    return pdb->selectDoctor(phoneNumber, password);

}

bool Bussiness::doctorRegister(QString phoneNumber, QString password, QString doctorName)
{
    // 获取数据库实例
    QString dataBaseAddress = "D:/Program Files (x86)/dB_Libray/project";
    QString connectName = "doctor";
    DataBase* pdb = DataBase::getDataBaseInstance(dataBaseAddress, connectName);

    return pdb->insertDoctor(phoneNumber, password, doctorName);
}
