#ifndef DATACLASS_H
#define DATACLASS_H

#include <iostream>
#include <fstream>
using namespace std;

#include <string>
#include "itemtype.h"

class DataClass
{
private:
	ItemType* CSIT;
	int NumLines;
public:
	
	DataClass(int);
	~DataClass();

	void AddClass(int, int, int); //Adds Class to DATACLASS syntax (ClassNumber, Section, LineNumber)
	void ViewData();
	void LoadData(int);
	void SelectSort();
	void BubbleSort();
	void InsertionSort();
	void MergeSort(int, int);
	void HeapSort();
	void QuickSort(int, int);
};

#endif