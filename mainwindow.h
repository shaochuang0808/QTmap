#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "Utils.h"


#include <QMainWindow>
#include <set>

//前置声明
class PointerItem;
class IQGraphicsScene;
class IQGraphicsView;
class MyCompare;




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void wheelEvent(QWheelEvent *event);
private slots:
    void bigger();
    void smaller();
    void open();
    void del();
    void fitting();
private:
    IQGraphicsView* view_;
    IQGraphicsScene* scene_;
    std::set<PointerItem*, MyCompare> isSelectedSet_;
    friend class PointerItem;
};
#endif // MAINWINDOW_H
