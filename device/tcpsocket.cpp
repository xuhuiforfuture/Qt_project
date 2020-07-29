#include "tcpsocket.h"

TcpSocket::TcpSocket(QObject *parent) : QTcpSocket(parent)
{
}

// 发送波形数据给管理端口
void TcpSocket::sendMessage(char* buffer)
{
    int nwrite = this->write(buffer, 1024);
    if (nwrite != 1024)
    {
        qDebug() << "发送失败！";
    }
    else
    {
        qDebug() << "发送成功！";
    }

}

