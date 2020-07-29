#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "bussiness.h"
#include "tcpsocket.h"
#include "plotpixmap.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();


private slots:
    void on_patientButton_clicked();

    void on_deviceButton_clicked();

    void on_realtimeButton_clicked();

    void on_historyButton_clicked();

    void on_bindButton_clicked();

    void on_bindOpButton_clicked();

    void on_loginButton_clicked();

    void on_docLoginButton_clicked();

    void on_registerButton_clicked();

    void on_connectButton_clicked();

    void on_dispButton_clicked();

    void storeEcgData(char* content);

private:
    Ui::MainWidget *ui;
    Bussiness *bs;
    TcpSocket* socket;
    PlotPixMap *pix;

};

#endif // MAINWIDGET_H
