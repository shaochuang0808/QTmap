#ifndef UTILS_H
#define UTILS_H

//用到的各种小工具
class PointerItem;

class MyCompare{
public:
//    MyCompare();
//    int i;
    bool operator()(const PointerItem* item1,const PointerItem* item2) const;
};

#endif // UTILS_H
