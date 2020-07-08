
#include "mainwindow.h"

#include "PointerItem.h"
#include "IQGraphicsScene.h"
#include "IQGraphicsView.h"
#include "LeastSquareMethod.h"

#include <QPainter>
#include <QBrush>
#include <QFile>
#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QMouseEvent>
#include<QFileDialog>


//重写的主窗口类
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(2000, 2000);//主窗口的大小

    //设置菜单栏
    QMenuBar* pmenubar = new QMenuBar();
    QMenu* pNewMenu = new QMenu("&File");
    QAction* pActionOpen = new QAction("&Open...", this);
    pNewMenu->addAction(pActionOpen);
    pmenubar->addMenu(pNewMenu);
    this->setMenuBar(pmenubar);
    pmenubar->show();

    //设置工具栏
    QToolBar* ptoolbar = new QToolBar();
    QAction* pActionBigger = new QAction("&Bigger", this);
    QAction* pActionSmaller = new QAction("&Smaller", this);
    QAction* pActionDelete = new QAction("&Delete", this);
    QAction* pActionFitting = new QAction("&Fitting", this);
    ptoolbar->addAction(pActionBigger);
    ptoolbar->addAction(pActionSmaller);
    ptoolbar->addAction(pActionDelete);
    ptoolbar->addAction(pActionFitting);
    this->addToolBar(ptoolbar);
    ptoolbar->show();

    this->update();


    //action匹配到槽函数
    connect(pActionBigger, SIGNAL(triggered()), this, SLOT(bigger()));
    connect(pActionSmaller, SIGNAL(triggered()), this, SLOT(smaller()));
    connect(pActionOpen, SIGNAL(triggered()), this, SLOT(open()));
    connect(pActionDelete, SIGNAL(triggered()), this, SLOT(del()));
    connect(pActionFitting, SIGNAL(triggered()), this, SLOT(fitting()));

    //设置scene_
    scene_ = new IQGraphicsScene();
    scene_->setSceneRect(-700, -700, 3000, 3000);//设置scene_大小

    //设置view_
    view_ = new IQGraphicsView();
    view_->resize(2000, 3000);//设置view_大小
    view_->setScene(scene_);//将view_绑定到scene_
    view_->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);//更新方式
    this->setCentralWidget(view_);//将view_加到主窗口中
    view_->setInteractive(true);
    view_->setDragMode(QGraphicsView::RubberBandDrag);
    view_->show();

}

MainWindow::~MainWindow()
{
}

void MainWindow::bigger(){

    qDebug() << "lalal";
    view_->scale(1.2,1.2);
}

void MainWindow::smaller(){

    qDebug() << "???????";
    view_->scale(1 / 1.2, 1 / 1.2);
}
void MainWindow::del(){
    for(auto it = isSelectedSet_.begin(); it != isSelectedSet_.end(); it++){
        scene_->removeItem(*it);//从scene中删除元素
        delete *it;//释放内存
    }
    isSelectedSet_.clear();//清空set;
}

void MainWindow::fitting(){
    if(isSelectedSet_.empty()) return;
    std::vector<double> X;
    std::vector<double> Y;
    for(auto it = isSelectedSet_.begin(); it != isSelectedSet_.end(); it++){
        X.push_back((*it)->getx());
        Y.push_back((*it)->gety());
    }
    LeastSquareMethod * leastsqaremethod = LeastSquareMethod::getInstance();
    leastsqaremethod->handle(Y, X, 5);
    std::vector<double> newX;
    for(double i = X[0]; i < X.back(); i+=2){
        newX.push_back(i);
    }
    for(unsigned long i = 0; i < newX.size(); i++){
        double y;
        y = leastsqaremethod->getY(newX[i]);
        PointerItem* mypointeritem = new PointerItem(newX[i], y);
        mypointeritem->setMainWindow(this);
        scene_->addItem(mypointeritem);
    }
    for(auto it = isSelectedSet_.begin(); it != isSelectedSet_.end(); it++){
        scene_->removeItem(*it);//从scene中删除元素
        delete *it;//释放内存
    }
    isSelectedSet_.clear();//清空set;
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if(event->angleDelta().y() > 0){
        qDebug() << "上";
    }
    else{
         qDebug() << "下";
    }
}

void MainWindow::open(){

    qDebug() << "open";
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "", "", nullptr);
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Can't open the file!"<< endl;
    }
    while(!file.atEnd()){
        QByteArray line = file.readLine();
        QString str(line);
        QString str1;
        QString str2;
        QString temp;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ' '){
                str1 = temp;
                temp.clear();

            }
            else{
                temp += str[i];
            }
        }
        str2 = temp;
        PointerItem* mypointeritem = new PointerItem(str1.toDouble(), str2.toDouble());
        mypointeritem->setMainWindow(this);
        scene_->addItem(mypointeritem);
    }

}
