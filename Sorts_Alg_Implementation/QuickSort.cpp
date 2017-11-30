#include <iostream>
#include "itemtype.h"
#include "InlineFunctions.h"

using namespace std;

inline void Split(ItemType values[], int first, int last, int& splitPoint)
{
	ItemType splitVal = values[first];

	int saveFirst = first;
	bool onCorrectSide;
	
	first++;

	do
	{
		onCorrectSide = true;
		while(onCorrectSide)
			if(values[first].Section > splitVal.Section)
				onCorrectSide = false;
			else
			{
				first++;
				onCorrectSide = (first <= last);
			}

			onCorrectSide = (first <= last);
			while(onCorrectSide)
				if(values[last].Section <= splitVal.Section)
					onCorrectSide = false;
				else
				{
					last--;
					onCorrectSide = (first <= last);
				}

				if(first < last)
				{
					Swap(values[first], values[last]);
					first++;
					last--;
				}
	}
	while(first <= last);

	splitPoint = last;
	Swap(values[saveFirst], values[splitPoint]);

}