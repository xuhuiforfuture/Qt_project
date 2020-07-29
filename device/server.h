#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <tcpsocket.h>
#include <QTcpServer>

class Server : public QObject
{
    Q_OBJECT
public:
    static Server* getServerInstance();

    // 启动服务器
    bool start(quint16 port);

    // 关闭服务器
    void stop();

    // 添加
    void addClient(TcpSocket* c);

    // 获取socket
    QList<TcpSocket*> getClients();

public slots:
    void acceptNewConnection();

private:
    explicit Server(QObject *parent = nullptr);

private:
    QTcpServer* pTcpServer;
    QList<TcpSocket*> clients;

};

#endif // SERVER_H
