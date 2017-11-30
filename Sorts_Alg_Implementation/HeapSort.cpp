#include <iostream>
#include "itemtype.h"
#include "InlineFunctions.h"

 inline void ReheapDown(ItemType values[], int root, int bottom)
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if(leftChild <= bottom)
	{
		if(leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if(values[leftChild].Section <= values[rightChild].Section)
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if(values[root].Section < values[maxChild].Section)
		{
			Swap(values[root], values[maxChild]);
			ReheapDown( values, maxChild, bottom);
		}
	}
}