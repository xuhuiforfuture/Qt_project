#include "widget.h"
#include "ui_widget.h"
#include <server.h>
#include <tcpsocket.h>
#include <QLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    // 设置布局
    ui->setupUi(this);
    this->resize(800, 600);
    this->setWindowTitle("一起来看刘新宇组~");
    ui->stackedWidget->setCurrentIndex(0);  // 设置登陆界面

    QVBoxLayout *pvbotton = new QVBoxLayout;
    pEcg = new QLabel("ECG");
    pEcg->setStyleSheet("color:black;background:red;font-size: 12pt");;
    pEcg->setAlignment(Qt::AlignVCenter);
    pixmap = new PlotPixMap;
    pvbotton->addWidget(pEcg);
    pvbotton->addWidget(pixmap);
    pvbotton->setStretchFactor(pEcg, 1);
    pvbotton->setStretchFactor(pixmap, 9);
    pvbotton->setSpacing(0);    // 考虑两组间之间的距离为0
    ui->Wavewidget->setLayout(pvbotton);

    getDataPort = new SerialPort(this, "COM4");     // 收端口"COM4"
    // 读取数据信号-连接
    connect(getDataPort, SIGNAL(readyRead()),
            getDataPort, SLOT(readMessage()));

    // 绘图信号-连接
    connect(getDataPort, SIGNAL(sigDealMessage(int, int ,int)),
            pixmap, SLOT(plot(int, int, int)));

    // 保存数据-连接
    connect(getDataPort, SIGNAL(storeMessage(int, int, int)),
            this, SLOT(storeData(int, int, int)));

    bs = new bussiness(this);

    model = bs->selectPatientModel(ui->loginIdEdit->text().toUtf8());
    ui->tableView->setModel(model);
    // 修改视图的显示方式
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID号"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("姓名"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("性别"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("年龄"));

}

Widget::~Widget()
{
    delete ui;

}

void Widget::on_startButton_clicked()
{
    // 获取服务器对象
    Server* ser = Server::getServerInstance();
    quint16 port = ui->portLineEdit->text().toUInt();

    if (ser->start(port)){
        // 修改界面
        ui->startButton->setEnabled(false);
        ui->stopButton->setEnabled(true);
    }
    else return;

}

void Widget::on_stopButton_clicked()
{
    // 获取服务器对象
    Server* ser = Server::getServerInstance();
    ser->stop();

    // 修改界面
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);

}

// 接收来自串口的数据
static int dataIndex = 0;
static unsigned short int EcgData[500] = {0};    // 数组不好使
void Widget::storeData(int ecg1, int ecg2, int ecg3)
{
    if (dataIndex < 500) {

        EcgData[dataIndex] = ecg1;
        dataIndex += 1;
        if (dataIndex < 500) EcgData[dataIndex] = ecg2;
        else return;
        dataIndex += 1;
        if (dataIndex < 500) EcgData[dataIndex] = ecg3;
        else return;
        dataIndex += 1;
    }
    return;
}

void Widget::on_sendButton_clicked()
{
    // 获取服务器对象
    char* buffer = new char[1024];
    char serial[24] = "dev-01";

    // 内存处理字节,大小端（忽略）
    memcpy(buffer, serial, 24);
    memcpy(buffer+24, EcgData, 1000);

    // 获取服务器对象
    Server* ser = Server::getServerInstance();
    // 得到套接字socket
    TcpSocket* socket = ser->getClients().at(0);
    socket->sendMessage(buffer);

}

void Widget::on_loginButton_clicked()
{
    // 响应登陆事件
    bool ret = bs->deviceLogin(ui->loginIdEdit->text().toUtf8(),
                               ui->loginpwdEdit->text().toUtf8());
    if (ret)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else ui->stackedWidget->setCurrentIndex(1);

}

void Widget::on_registeButton_clicked()
{
    // 响应注册事件
    bool ret = bs->deviceRegiste(ui->registeIdEdit->text().toUtf8(),
                                 ui->registepwdEdit->text().toUtf8());

    if (ret)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else qDebug() << "注册失败~";

}

// 将数据保存到数据库中
void Widget::on_pushButton_clicked()
{
    bool ret = bs->sendEcgWaveData(ui->registeIdEdit->text().toUtf8(), EcgData);
    if(ret){
        qDebug() << "数据保存成功~";
    }
    else qDebug() << "保存失败";
    ui->pushButton->setEnabled(false);
}
