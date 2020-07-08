#ifndef IQGRAPHICSVIEW_H
#define IQGRAPHICSVIEW_H

#include<QGraphicsView>
class IQGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    IQGraphicsView(QWidget *parent = nullptr);


protected:
    void wheelEvent(QWheelEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QPoint _mouseLBtnDown;
    bool _isLBtnDown;
};

#endif // IQGRAPHICSVIEW_H
