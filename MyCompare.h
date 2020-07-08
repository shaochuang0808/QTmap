#ifndef MYCOMPARE_H
#define MYCOMPARE_H
#include"PointerItem.h"
class PointerItem;
class MyCompare
{
public:
    MyCompare();
    bool operator()(const PointerItem* item1,const PointerItem* item2) const;
};

#endif // MYCOMPARE_H
