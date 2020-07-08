#ifndef IQGRAPHICSSCENE_H
#define IQGRAPHICSSCENE_H

#include<QGraphicsScene>

class IQGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    IQGraphicsScene(QObject *parent = nullptr);

private:
    virtual void wheelEvent(QGraphicsSceneWheelEvent *event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // IQGRAPHICSSCENE_H
