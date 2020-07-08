#include "PointerItem.h"
#include "mainwindow.h"
#include <QPainter>
#include <QBrush>
#include<QtDebug>

PointerItem::PointerItem(qreal x, qreal y)
{

    x_ = x;
    y_ = y;
    setPos(x_, y_);
    setFlags(QGraphicsItem::ItemIsSelectable);
    isSelected_ = false;
}

void  PointerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QBrush qbrush(Qt::red);//设置笔刷的颜色
    if(isSelected()){
        w_->isSelectedSet_.insert(this);
        isSelected_ = true;
    }
    if(isSelected_){
        qbrush.setColor(Qt::blue);
    }

    painter->setPen( QPen(qbrush, 0.1, Qt::SolidLine, Qt::RoundCap ) );//设置画笔
    painter->drawRect(QRectF(-0.1, -0.1, 0.2, 0.2));//item是一个方形的框

}

QRectF PointerItem::boundingRect() const{
    return QRectF(-0.1, -0.1, 0.2, 0.2);
}

QPainterPath PointerItem::shape() const{
    QPainterPath path;
    path.addRect(QRectF(-0.1, -0.1, 0.2, 0.2));
    return path;
}

void PointerItem::setMainWindow(MainWindow* w){
    w_ = w;
}
void PointerItem::mousePressEvent(QGraphicsSceneMouseEvent* event){
    Q_UNUSED(event)
    qDebug() << "PointerItem::mousePressEvent" << endl;
}

qreal PointerItem::getx() const {return x_;}
qreal PointerItem::gety() const {return y_;}
