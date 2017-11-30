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
											//Always 0		Loop from 0 to End each call "++"
inline void InsertItem (ItemType values[], int StartIndex, int EndIndex)
{
	bool finished = false;
	int current = EndIndex;
	bool MoreToSearch = (current != StartIndex);

	while (MoreToSearch && !finished)
	{
		if(values[current].Section < values[current-1].Section)
		{
			Swap(values[current], values[current-1]);
			current--;
			MoreToSearch = (current != StartIndex);
		}
		else
			finished = true;
	}
}