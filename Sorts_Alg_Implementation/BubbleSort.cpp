#include <iostream>
#include "itemtype.h"
#include "InlineFunctions.h"

using namespace std;

//inline void Swap (ItemType& item1, ItemType& item2)
//{
//	ItemType temp;
//
//	temp = item1;
//	item1 = item2;
//	item2 = temp;
//}

inline void BubbleUp(ItemType values[], int start, int end)
{
	for(int index = end; index > start; index--)
	{
		if(values[index].Section < values [index-1].Section)
		{
			Swap(values[index], values[index-1]);
		}
	}
}

