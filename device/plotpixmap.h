#ifndef PLOTPIXMAP_H
#define PLOTPIXMAP_H

#include <QWidget>
#include <QPixmap>

class PlotPixMap : public QWidget
{
    Q_OBJECT
public:
    explicit PlotPixMap(QWidget *parent = nullptr);

private:
    QPixmap *pix_;

public slots:
    void plot(int ecg1, int ecg2, int ecg3);
protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

};

#endif // PLOTPIXMAP_H
