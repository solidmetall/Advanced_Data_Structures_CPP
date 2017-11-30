#ifndef INLINEFUNCTIONS_H
#define INLINEFUNCTIONS_H

#include <iostream>
#include "itemtype.h"

using namespace std;

inline void Swap (ItemType& item1, ItemType& item2)
{
	ItemType temp;

	temp = item1;
	item1 = item2;
	item2 = temp;
}
#endif