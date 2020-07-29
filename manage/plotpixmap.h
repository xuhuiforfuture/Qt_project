#ifndef PLOTPIXMAP_H
#define PLOTPIXMAP_H

#include <QObject>
#include <QPixmap>
#include <QWidget>
class PlotPixMap : public QWidget
{
    Q_OBJECT
public:
    explicit PlotPixMap(QWidget *parent = nullptr);

public slots:
    void refreshPixmap();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QPixmap *pix_;

};

#endif // PLOTPIXMAP_H
