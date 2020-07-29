#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDebug>
#include <QLayout>
#include <QLabel>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    bs = new Bussiness(this);

    socket = new TcpSocket(this);

    connect(socket, SIGNAL(dealMessage(char*)),
            this, SLOT(storeEcgData(char*)));

    ui->ipEdit->setText("127.0.0.1");

}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_docLoginButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

// 处理登陆事件
void MainWidget::on_loginButton_clicked()
{
    bool loginFlag = true;
    // 医生登陆界面，如果设备成功登陆，让所有的按钮生效
    // 否则，转到注册页，注册新的账号同时将医生的数据写入数据库

    loginFlag = bs->doctorLogin(ui->loginPhoneEdit->text().toUtf8(), ui->loginpwdEdit->text().toUtf8());

    if (loginFlag){
        ui->stackedWidget->setCurrentIndex(5);  // 跳到实时波型页里去
        ui->patientButton->setEnabled(true);
        ui->bindButton->setEnabled(true);
        ui->deviceButton->setEnabled(true);
        ui->realtimeButton->setEnabled(true);
        ui->historyButton->setEnabled(true);
        ui->docLoginButton->setEnabled(false);

    }

    else {
        ui->stackedWidget->setCurrentIndex(1);  // 转到注册页

    }

}

void MainWidget::on_registerButton_clicked()
{
    bool ret = true;
    // 响应注册事件
    // 需要将医生数据写入到数据库当中去
    ret = bs->doctorRegister(ui->registerPhoneEdit->text().toUtf8(),
                             ui->registerPwdlineEdit->text().toUtf8(),
                             ui->registerDocNamelineEdit->text().toUtf8());

    // 注册成功，各个按钮有效，跳到实时波型页中去
    if (ret){
        ui->stackedWidget->setCurrentIndex(5);
        ui->patientButton->setEnabled(true);
        ui->bindButton->setEnabled(true);
        ui->deviceButton->setEnabled(true);
        ui->realtimeButton->setEnabled(true);
        ui->historyButton->setEnabled(true);

    }

}

void MainWidget::on_patientButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWidget::on_deviceButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWidget::on_bindButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWidget::on_realtimeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWidget::on_historyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

// 绑定
void MainWidget::on_bindOpButton_clicked()
{
//    // 病人id
//    int patientId = ui->patientComboBox->currentText().toInt();


//    // 设备id
//    int devId;
//    QString serial = ui->deviceCombox->currentText();
//    QSqlQuery query(db);
//    query.prepare("select dev_id from device where dev_serial = :serial;");
//    query.bindValue(":serial", QVariant(serial));
//    if (!query.exec())
//    {
//        qDebug() << "绑定失败！";
//        QMessageBox::warning(this, "提示", "绑定失败", QMessageBox::Ok);
//        return;
//    }
//    if (query.next())
//    {
//        devId = query.value(0).toInt();
//    }

//    // 绑定
//    query.prepare("insert into patient_device values(null, :patientId, :devId);");
//    query.bindValue(":patientId", patientId);
//    query.bindValue(":devId", devId);
//    if (!query.exec())
//    {
//        qDebug() << "绑定失败";
//        return ;
//    }
//    qDebug() << "绑定成功";

//    // 刷新绑定列表模型

//    // 刷新病人comboBox模型 // 刷新设备comboBox模型
//    patientComboBoxModel->setQuery("select patientId from patient where patientId not in (select patientId from patient_device);", db);
//    deviceComboBoxModel->setQuery("select dev_serial from device where dev_id not in (select devId from patient_device);", db);

}


// 连接设备服务器
void MainWidget::on_connectButton_clicked()
{
    QString strIp = ui->ipEdit->text().toUtf8();
    quint16 port = ui->portEdit->text().toUInt();
    int ret = socket->connectToServer(strIp, port);
    if (ret)
    {
       qDebug() << "连接成功";
       ui->connectButton->setEnabled(false);
       ui->dispButton->setEnabled(true);
    }
    else
    {
        qDebug() << "连接失败";
    }
}

// 显示实时波型
void MainWidget::on_dispButton_clicked()
{
    QLabel *ecg = new QLabel("ECG");
    ecg->setStyleSheet("color:black; background: red;font-size:9pt;");
    QVBoxLayout *pvlayout = new QVBoxLayout;
    pix = new PlotPixMap;
    pvlayout->addWidget(ecg);
    pvlayout->addWidget(pix);
    pvlayout->setStretchFactor(ecg, 1);
    pvlayout->setStretchFactor(pix, 12);
    pvlayout->setSpacing(0);
    ui->widget_4->setLayout(pvlayout);
    ui->dispButton->setEnabled(false);

}

unsigned short int ecgData[500] = {0};
// 接收来自设备通过TCP发送的数据
void MainWidget::storeEcgData(char *content)
{
    // 内存复制来接收数据，这个时候需要确保设备端和PC机上的大小端一致

    /* 大端小端模式是由CPU架构决定的
     * 设备ARM架构是小端模式保存字节序列的，即第一位是低字节，如数字8，在小端保存为：0001，大端则相反，8保存为：1000
     * 而x86架构的PC机也是小端模式保存的
     * 因此，本次处理方法合理。
     */
    char idName[24];
    memcpy(idName, content, 24);
    qDebug() << idName;
    memcpy(ecgData, content + 24, 1000);

}
