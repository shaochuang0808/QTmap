#include "IQGraphicsScene.h"
#include <QtDebug>
#include <QGraphicsSceneMouseEvent>
IQGraphicsScene::IQGraphicsScene(QObject *parent) : QGraphicsScene(parent){

}


void IQGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent *event){
    QGraphicsScene::wheelEvent(event);
    qDebug() << "IQGraphicsScene::wheelEvent ";
}

void IQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mousePressEvent(event);
//    this->update(-500, -500, 3000, 3000);
//    this->update();

    qDebug() << "QGraphicsSceneMouseEvent" << event->scenePos().x() << event->scenePos().y();
}

void IQGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mouseMoveEvent(event);
    qDebug() << "QGraphicsScene::mouseMoveEvent";
}

void IQGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mouseReleaseEvent(event);
    qDebug() << "QGraphicsScene::mouseReleaseEvent";
}
