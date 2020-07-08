#include "IQGraphicsView.h"
#include<QDebug>
#include<QMouseEvent>
IQGraphicsView::IQGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    _isLBtnDown = false;
}


void IQGraphicsView::wheelEvent(QWheelEvent *event){
    QGraphicsView::wheelEvent(event);
//    this->update();
//    this->updatesEnabled();
//    this->updateGeometry();
//    this->viewport()->update();
//    this->update(-500,-500, 3000, 3000);


//    qDebug() << "sceneRect()" << sceneRect();
//    qDebug() << "IQGraphicsView::wheelEvent ";
}


void IQGraphicsView::mouseMoveEvent(QMouseEvent *event){
    QGraphicsView::mouseMoveEvent(event);
//    if (_isLBtnDown){
//        QPointF ptNow = mapToScene(event->pos());
//        QPointF movePt = ptNow - mapToScene(_mouseLBtnDown);

//        //根据鼠标当前的点作为定位点
////        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
//        QPointF nowCenter(-movePt.x(),  -movePt.y());
//        qDebug() << "nowCenter:" << nowCenter.x()<< "  "<< nowCenter.y();
////        setTransformationAnchor(QGraphicsView::AnchorViewCenter);
//        centerOn((nowCenter));

//    }
//    qDebug() << "IQGraphicsView::mouseMoveEvent";
}
void IQGraphicsView::mousePressEvent(QMouseEvent *event){
//    this->viewport()->update();
    QGraphicsView::mousePressEvent(event);
//    this->viewport()->update();
//    if (event->button() == Qt::LeftButton){
//        _mouseLBtnDown = event->pos();
//        _isLBtnDown = true;
//    }

//    qDebug() << "AAAGraphicsView:" << event->pos().x() << event->pos().y();
//    qDebug() << "IQGraphicsView::mousePressEvent";
}
void IQGraphicsView::mouseReleaseEvent(QMouseEvent *event){
    QGraphicsView::mouseReleaseEvent(event);
//    if (event->button() == Qt::LeftButton) {
//        _isLBtnDown = false;
//    }
//    qDebug() << "IQGraphicsView::mouseReleaseEvent";
}
