#include <iostream>
#include "itemtype.h"

inline void Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
{
	ItemType tempArray[22];
	int index = leftFirst;
	int saveFirst = leftFirst;

	while((leftFirst <= leftLast) && (rightFirst <= rightLast))
	{
		if(values[leftFirst].Section < values[rightFirst].Section)
		{
			tempArray[index] = values[leftFirst];
			leftFirst++;
		}
		else
		{
			tempArray[index] = values[rightFirst];
			rightFirst++;
		}
		index++;
	}
	
	while(leftFirst <= leftLast)
	{//Copy remaining items from left half
		tempArray[index] = values[leftFirst];
		leftFirst++;
		index++;
	}

	while(rightFirst <= rightLast)
	{//Copy remaining items from right half
		tempArray[index] = values[rightFirst];
		rightFirst++;
		index++;
	}

	for(index = saveFirst; index <= rightLast; index++)
	values[index] = tempArray[index];
}