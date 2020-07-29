#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <serialport.h>
#include <QLabel>
#include <plotpixmap.h>
#include <bussiness.h>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_sendButton_clicked();
    void storeData(int ecg1, int ecg2, int ecg3);

    void on_loginButton_clicked();

    void on_registeButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    int ecgDataIndex;  // 索引
    SerialPort *sendDataPort;
    SerialPort *getDataPort;
    QLabel *pEcg;
    PlotPixMap *pixmap;
    bussiness *bs;
    QSqlQueryModel *model;
};
#endif // WIDGET_H
