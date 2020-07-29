#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
class SerialPort : public QSerialPort
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = nullptr, QString PortName = "COM1");
    // 发送数据
    void sendMessage(char ba[], int size);

};

#endif // SERIALPORT_H
