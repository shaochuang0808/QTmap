#include "MyCompare.h"

MyCompare::MyCompare()
{

}

bool MyCompare::operator()(const PointerItem* item1,const PointerItem* item2) const{
   return item1->getx() < item2->getx();
}
