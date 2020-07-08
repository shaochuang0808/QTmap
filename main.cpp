#include "mainwindow.h"
#include "PointerItem.h"
#include "IQGraphicsScene.h"
#include "IQGraphicsView.h"
#include "Utils.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QDebug>
#include <QFileDialog>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;//定义主窗口

    w.show();


    return a.exec();
}
