#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

#include "DataClass.h"
#include "InlineFunctions.h"

//int comparisons = 0;
//int swaps = 0;

DataClass::DataClass(int NItems)
{
	IntData = new int[NItems];
	NumLines = NItems;
}

void DataClass::Clear()
{
	delete [] IntData;
	IntData = new int[NumLines];
}

DataClass::~DataClass()
{
	delete [] IntData;
}


void DataClass::LoadData(string FileName)
{
	int x = 0;
	ifstream file;
	file.open(FileName);
	if(file.is_open())
	{
		for(int x=0; x<NumLines; x++)
		{
			if(!file.eof())
			file >> IntData[x];
		}
	}
	else
	{
		cout<<"Unable to Load from the file"<<endl;
	}
}

void DataClass::VewData()
{
	for (int x=0; x<NumLines; x++)
	{
		cout<<endl << IntData[x];
	}
	cout<<endl;
}

int DataClass::ReturnNumLines()
{
	return NumLines;
}

void DataClass::SelectSort()
{
	int swaps=0;
	int comparisons=0;

	int EndIndex = NumLines - 1;

	for(int current = 0; current < EndIndex; current++)
	{
		Swap(IntData, current, MinValIndex(IntData, current, EndIndex, comparisons));
		swaps++;
	}
	//cout<<endl<<"Total Comparisons: "<<comparisons;
	cout<<endl<<left<<setw(16)<<"Selection Sort: "<<setw(4)<<NumLines<<setw(27)<<" Entries in file.  Swaps: "<<setw(6)<<swaps;
	cout<<"   Comparisons: "<<comparisons;
}

void DataClass::BubbleSort()
{
	int current = 0;

	int swaps = 0;
	int comparisons = 0;

	while(current < NumLines - 1)
	{
		//comparisons++;
		BubbleUp (IntData, current, NumLines-1, comparisons, swaps);
		current++;
	}
	cout<<endl<<left<<setw(16)<<"Bubble Sort: "<<setw(4)<<NumLines<<setw(27)<<" Entries in file.  Swaps: "<<setw(6)<<swaps;
	cout<<"   Comparisons: "<<comparisons;
}

void DataClass::InsertionSort()
{
	int swaps = 0;
	int comparisons = 0;

	for (int count = 0; count < NumLines; count++)
	{
		InsertItem(IntData, 0, count, comparisons, swaps);
	}

	cout<<endl<<left<<setw(16)<<"Insertion Sort: "<<setw(4)<<NumLines<<setw(27)<<" Entries in file.  Swaps: "<<setw(6)<<swaps;
	cout<<"   Comparisons: "<<comparisons;
}

void DataClass::MergeSort(int first, int last, int& COM, int& SW)
{
	//int Comparisons = 0, Swaps=0;

	if(first < last)
	{
		int middle = (first+last)/2;
		MergeSort(first, middle, COM, SW);
		MergeSort(middle + 1, last, COM, SW);
		Merge (IntData, first, middle, middle+1, last, NumLines, COM, SW);
	}
	/*cout<<endl<<"Merge Sort |   Swaps: "<<Swaps;
	cout<<"   Comparisons: "<<Comparisons;
	cout<<endl;*/
}

void DataClass::HeapSort()
{
	int Comparisons=0, Swaps=0;
	int index;

	//Converting the array into heap by order and value
	for(index = NumLines/2 - 1; index >= 0; index--)
		{
			CreateHeap(IntData, index, NumLines-1);
		}

	//Sorting the array by value
	for(index = NumLines-1; index >= 1; index--)
	{
		Swaps++;
		Swap(IntData, 0, index);
		ReheapDown(IntData, 0, index-1, Comparisons, Swaps);
	}

	cout<<endl<<left<<setw(16)<<"Heap Sort: "<<setw(4)<<NumLines<<setw(27)<<" Entries in file.  Swaps: "<<setw(6)<<Swaps;
	cout<<"   Comparisons: "<<Comparisons;
}

void DataClass::QuickSort(int first, int last, int& COM, int& SW)
{
	if(first < last)
	{
		int splitPoint;

		Split(IntData, first, last, splitPoint, COM, SW);

		//values[first] .. values[splitPoint-1] <= splitVal
		//values[splitPoint] = splitVal
		//values[splitPoint+1] .. values[last] > splitVal

		QuickSort(first, splitPoint-1, COM, SW);
		QuickSort(splitPoint+1, last, COM, SW);
	}
}