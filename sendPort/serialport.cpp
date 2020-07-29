#include "serialport.h"
#include <QDebug>
SerialPort::SerialPort(QObject *parent, QString PortName) : QSerialPort(parent)
{
    // 设置串口名称（后面可以扩展）
    this->setPortName(PortName);

    // 尝试打开串口
    if (!this->open(QIODevice::ReadWrite))
    {
        qDebug() << "open fail";
        return;
    }

    // 打开成功，参数配置
    // 波特率：115200
    this->setBaudRate(QSerialPort::Baud115200);
    // 数据位
    this->setDataBits(QSerialPort::Data8);
    // 流控制=无
    this->setFlowControl(QSerialPort::NoFlowControl);
    // 校验位
    this->setParity(QSerialPort::NoParity);
    // 停止位
    this->setStopBits(QSerialPort::OneStop);

}

// 发送数据
void SerialPort::sendMessage(char ba[], int size)
{
    this->write(ba, size);

}
