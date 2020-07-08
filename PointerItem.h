#ifndef POINTERITEM_H
#define POINTERITEM_H
//#include "mainwindow.h"
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QObject>
#include<QGraphicsObject>
#include<list>

class MainWindow;

//自定义的item类
class PointerItem : public QGraphicsObject
{
    Q_OBJECT

public:
    PointerItem(qreal, qreal);
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;//绘画出item的具体样子
    QRectF boundingRect() const override;//返回的QRectF为item接收事件的矩形区域
    QPainterPath shape() const override;//item的大致形状
    void setMainWindow(MainWindow* w);
    qreal getx() const;
    qreal gety() const;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
private:
    qreal x_;//item在sense中的坐标
    qreal y_;
    bool isSelected_;
    MainWindow* w_;
};

#endif // POINTERITEM_H
