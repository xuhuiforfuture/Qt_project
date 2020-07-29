#ifndef TCPSOCKET_H
#define TCPSOCKET_H
#include <QTcpSocket>

class TcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    TcpSocket(QObject *parent = nullptr);
    // 发送数据
    void sendMessage(char* buffer);

public slots:

signals:
    void dealMessage(char* buffer);
};

#endif // TCPSOCKET_H
