#include "plotpixmap.h"
#include <QPainter>
#include <QDebug>

PlotPixMap::PlotPixMap(QWidget *parent) : QWidget(parent)
{
    this->resize(600, 150);
    pix_ = new QPixmap(this->width(), this->height());
    pix_->fill(Qt::black);

}

// 使用静态变量
static int init = 1;
static int temp = 0;

// 优化画图
void PlotPixMap::plot(int ecg1, int ecg2, int ecg3)
{
    // 这里的painter不能通过new来创建 new是一次创建，多处使用
    // 应该采用栈空间的方法创建对象，频繁使用的地方用栈空间，一定注意
    QPainter painter(pix_); // 对画布进行绘制
    painter.setPen(QPen(Qt::green, 2));

    ecg1 = round(pix_->height() /2.0 - ((double)(ecg1 - 2048) * pix_->height() / 2 / 600));
    ecg2 = round(pix_->height() /2.0 - ((double)(ecg2 - 2048) * pix_->height() / 2 / 600));
    ecg3 = round(pix_->height() /2.0 - ((double)(ecg3 - 2048) * pix_->height() / 2 / 600));

    static int PointX = 0;
    // 擦除列
    if(!init){
        temp = ecg1;
        init = 1;
    }
    painter.save();
    painter.setPen(Qt::black);
    painter.drawLine(PointX+1, 0, PointX+1, pix_->height());
    painter.drawLine(PointX+2, 0, PointX+2, pix_->height());
    painter.drawLine(PointX+3, 0, PointX+3, pix_->height());
    painter.drawLine(PointX+4, 0, PointX+4, pix_->height());
    painter.restore();

    QPoint LineStart, LineEnd;
    LineStart.setX(PointX); LineStart.setY(temp);
    PointX += 2;
    LineEnd.setX(PointX); LineEnd.setY(ecg2);
    painter.drawLine(LineStart, LineEnd);
    temp = ecg2;

    if (PointX > pix_->width()){
        PointX = 0;
    }

    this->update();

}

void PlotPixMap::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, pix_->width(), pix_->height(), *pix_);

}

// 这个为什么实现不了呢
void PlotPixMap::resizeEvent(QResizeEvent *event)
{
    *pix_ = pix_->scaled(this->size()); // 自适应修改大小
    pix_->fill(Qt::black);

}

