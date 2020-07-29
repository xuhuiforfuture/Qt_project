#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <serialport.h>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void sendEcgpkg();

private:
    int ecgDataIndex;  // 索引
    SerialPort *sendDataPort;

};
#endif // WIDGET_H
