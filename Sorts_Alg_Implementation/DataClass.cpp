#include <iostream>
#include <string>
using namespace std;

#include "DataClass.h"
#include "SelectSort.cpp"
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#include "MergeSort.cpp"
#include "HeapSort.cpp"
#include "QuickSort.cpp"

DataClass::DataClass(int NItems)
{
	CSIT = new ItemType[NItems];
	NumLines = 0;
}

DataClass::~DataClass()
{
	delete [] CSIT;
}

void DataClass::AddClass(int numbr, int sect, int linen) //Adds Class to DATACLASS syntax (ClassNumber, Section, LineNumber)
{
	ItemType cell;
	cell.Number = numbr;
	cell.Section = sect;
	CSIT[linen] = cell;
	NumLines++;
}

void DataClass::ViewData()
{
	for (int x=0; x<NumLines; x++)
	{
		cout<<endl << CSIT[x].Number <<" "<<CSIT[x].Section;
	}
	cout<<endl;
}

void DataClass::LoadData(int lines)
{
	ifstream file;
	int num=0, sec=0, line=0;
	
	file.open("classes.txt");

	if(!file.is_open())
	{
		cout<<"Unable to Load from the file"<<endl;
	}
	else
	{
		for(int i = 0; i < lines; i++)
		{
			file >> num;
			file >> sec;
			AddClass(num, sec, line);
			line++;
		}
		file.close();
		cout<<endl<<"Loaded Total "<<line<<" Lines."<<endl<<endl;
	}
}

void DataClass::SelectSort()
{
	int EndIndex = NumLines - 1;

	for(int current = 0; current < EndIndex; current++)
		Swap(CSIT[current], CSIT[MinValIndex(CSIT, current, EndIndex)]);
}

void DataClass::BubbleSort()
{
	int current = 0;

	while(current < NumLines - 1)
	{
		BubbleUp (CSIT, current, NumLines-1);
		current++;
	}
}

void DataClass::InsertionSort()
{
	for (int count = 0; count < NumLines; count++)
	{
		InsertItem(CSIT, 0, count);
	}
}

void DataClass::MergeSort(int first, int last)
{
	if(first < last)
	{
		int middle = (first+last)/2;
		MergeSort(first, middle);
		MergeSort(middle + 1, last);
		Merge (CSIT, first, middle, middle+1, last);
	}
}

void DataClass::HeapSort()
{
	int index;

	//Converting the array into heap by order and value
	for(index = NumLines/2 - 1; index >= 0; index--)
		{
			ReheapDown(CSIT, index, NumLines-1);
		}

	//Sorting the array by value
	for(index = NumLines-1; index >= 1; index--)
	{
		Swap(CSIT[0], CSIT[index]);
		ReheapDown(CSIT, 0, index-1);
	}
}

void DataClass::QuickSort(int first, int last)
{
	if(first < last)
	{
		int splitPoint;

		Split(CSIT, first, last, splitPoint);

		//values[first] .. values[splitPoint-1] <= splitVal
		//values[splitPoint] = splitVal
		//values[splitPoint+1] .. values[last] > splitVal

		QuickSort(first, splitPoint-1);
		QuickSort(splitPoint+1, last);
	}
}