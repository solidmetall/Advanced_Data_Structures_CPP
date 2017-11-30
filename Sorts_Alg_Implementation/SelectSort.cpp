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

inline int MinValIndex (ItemType values[], int StartIndex, int EndIndex)
{
	int MinIn = StartIndex;

	for(int index = StartIndex+1; index <= EndIndex; index++)
	{
		if(values[index].Section < values[MinIn].Section)
		{
			MinIn=index;
		}
	}
	return MinIn;
}