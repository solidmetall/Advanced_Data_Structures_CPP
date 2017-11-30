//#ifndef INLINEFUNCTIONS_H
//#define INLINEFUNCTIONS_H

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

inline void CreateFiles ()
{
	//clock_t start, finish;

	int RandNumber;
	//double duration;
	srand((unsigned)time(0));
		
	ofstream myfile ("DataFile1.txt");
	myfile.clear();
	
	if(myfile.is_open())
	{
		//start = clock();
		for(int x = 0; x<100; x++)
		{
			RandNumber = (rand()%1000)+1;
			myfile<<RandNumber<<endl;
		}
		//finish = clock();
		myfile.close();
		//duration = (double)(finish - start) / CLOCKS_PER_SEC;
		//cout<<endl<<"DataFile1.txt Created";//<<duration;
	}
	else
	{
		cout<<endl<<"Could not open/create file!"<<endl;
	}

	myfile.open("DataFile2.txt");
	myfile.clear();

	
	if(myfile.is_open())
	{
		for(int x = 0; x<1000; x++)
		{
			RandNumber = (rand()%10000)+1;
			myfile<<RandNumber<<endl;
		}
		myfile.close();
		//cout<<endl<<"DataFile2.txt Created";
	}
	else
	{
		cout<<endl<<"Could not open/create file!"<<endl;
	}
}



inline void Swap (int values[], int curr, int index)
{
	int temp;

	temp = values[curr];
	values[curr] = values[index];
	values[index] = temp;
}

inline int MinValIndex (int values[], int StartIndex, int EndIndex, int& comp)
{
	int MinIn = StartIndex;
	
	for(int index = StartIndex+1; index <= EndIndex; index++)
	{
		comp++;

		if(values[index] < values[MinIn])
		{
			MinIn=index;
		}
	}
	return MinIn;
}

inline void BubbleUp(int values[], int start, int end, int& comp, int& sw)
{
	//int swaps = 0;
	//int comparisons = 0;

	for(int index = end; index > start; index--)
	{
		comp++;
		if(values[index] < values [index-1])
		{
			Swap(values, index, index-1);
			sw++;
		}
	}

	
}

inline void InsertItem(int values[], int StartIndex, int EndIndex, int& comp, int& sw)
{
	bool finished = false;
	int current = EndIndex;
	bool MoreToSearch = (current != StartIndex);

	while (MoreToSearch && !finished)
	{
		comp++;
		if(values[current] < values[current-1])
		{
			sw++;
			Swap(values, current, current-1);
			current--;
			MoreToSearch = (current != StartIndex);
		}
		else
			finished = true;
	}
}

inline void Merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast, int size, int& comp, int& sw)
{
	//int comp, int sw;

	int *tempArray;
	tempArray = new int [size];

	int index = leftFirst;
	int saveFirst = leftFirst;

	while((leftFirst <= leftLast) && (rightFirst <= rightLast))
	{
		comp++;
		if(values[leftFirst] < values[rightFirst])
		{
			
			tempArray[index] = values[leftFirst];
			leftFirst++;
		}
		else
		{
			sw++;
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

	delete [] tempArray;
}

inline void ReheapDown(int values[], int root, int bottom, int& Comp, int& Sw)
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
			Comp++;
			if(values[leftChild] <= values[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		Comp++;
		if(values[root] < values[maxChild])
		{
			Sw++;
			Swap(values, root, maxChild);
			ReheapDown( values, maxChild, bottom, Comp, Sw);
		}
	}
}

inline void CreateHeap(int values[], int root, int bottom)
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
			
			if(values[leftChild] <= values[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		
		if(values[root] < values[maxChild])
		{
			
			Swap(values, root, maxChild);
			CreateHeap( values, maxChild, bottom);
		}
	}
}

inline void Split(int values[], int first, int last, int& splitPoint, int& C, int& S)
{
	int splitVal = values[first];

	int saveFirst = first;
	bool onCorrectSide;
	
	first++;

	do
	{
		onCorrectSide = true;
		while(onCorrectSide)
		{
			C++;
			if(values[first] > splitVal)
				onCorrectSide = false;
			else
			{
				first++;
				onCorrectSide = (first <= last);
			}
		}
			onCorrectSide = (first <= last);
			while(onCorrectSide)
			{	C++;
				if(values[last] <= splitVal)
					onCorrectSide = false;
				else
				{
					last--;
					onCorrectSide = (first <= last);
				}
			}
				if(first < last)
				{
					S++;
					Swap(values, first, last);
					first++;
					last--;
				}
	}
	while(first <= last);

	splitPoint = last;
	S++;
	Swap(values, saveFirst, splitPoint);

}

//#endif