#ifndef DATACLASS_H
#define DATACLASS_H

#include <iostream>
#include <fstream>
using namespace std;

#include <string>

class DataClass
{

private:
	int *IntData;
	int NumLines;

public:
	DataClass(int);
	~DataClass();
	void LoadData(string);
	void VewData();
	int ReturnNumLines();
	void Clear();

	void SelectSort(); //Done
	void BubbleSort(); //Done
	void InsertionSort(); //Done
	void MergeSort(int, int, int&, int&); //Done
	void HeapSort(); //Done
	void QuickSort(int, int, int&, int&);
};

#endif