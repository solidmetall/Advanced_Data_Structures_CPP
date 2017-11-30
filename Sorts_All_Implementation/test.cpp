//test.cpp
// Petin Evgeniy	CSIT-832 (Advanced Data Structures & Introduction to Data Bases)
//Section#:			7010
// Assignment #5
//

#include <iostream>
//include <string>
//#include <fstream>
#include "DataClass.h"
#include "InlineFunctions.h"
#include <iomanip>
#include <chrono>


//setw();
using namespace std;
using namespace std::chrono;

int main()
{

	CreateFiles();

	DataClass for100(100);
	DataClass for1000(1000);

	for100.LoadData("DataFile1.txt");
	for1000.LoadData("DataFile2.txt");

	//for100.VewData();
	//system("pause");
	//int Comparisons = 0, Swaps = 0;
	////for100.MergeSort(0,99);
	//for100.QuickSort(0,99);
	//for100.VewData();
	
	//cout<<endl<<"100 Entries in file";
	for100.SelectSort();
	//cout<<endl<<"1000 Entries in file";
	for1000.SelectSort();

	cout<<endl<<endl;
	for100.Clear();
	for1000.Clear();
	//CreateFiles();
	for100.LoadData("DataFile1.txt");
	for1000.LoadData("DataFile2.txt");

	//cout<<endl<<"100 Entries in file";
	for100.BubbleSort();
	//cout<<endl<<"1000 Entries in file";
	for1000.BubbleSort();

	cout<<endl<<endl;
	for100.Clear();
	for1000.Clear();
	//CreateFiles();
	for100.LoadData("DataFile1.txt");
	for1000.LoadData("DataFile2.txt");

	//cout<<endl<<"100 Entries in file";
	for100.InsertionSort();
	//cout<<endl<<"1000 Entries in file";
	for1000.InsertionSort();

	cout<<endl<<endl;
	for100.Clear();
	for1000.Clear();
	//CreateFiles();
	for100.LoadData("DataFile1.txt");
	for1000.LoadData("DataFile2.txt");

	//cout<<endl<<"100 Entries in file";
	int CC = 0;
	int SS = 0;
	for100.MergeSort(0, 99, CC, SS);
	cout<<endl<<left<<setw(16)<<"Merge Sort: "<<setw(4)<<for100.ReturnNumLines()<<setw(27)<<" Entries in file.  Swaps: "<<setw(6)<<SS;
	cout<<"   Comparisons: "<<CC;
	CC = 0;
	SS = 0;
	//cout<<endl<<"1000 Entries in file";
	for1000.MergeSort(0,99, CC, SS);
	cout<<endl<<left<<setw(16)<<"Merge Sort: "<<setw(4)<<for1000.ReturnNumLines()<<setw(27)<<" Entries in file.  Swaps: "<<setw(6)<<SS;
	cout<<"   Comparisons: "<<CC;

	cout<<endl<<endl;
	for100.Clear();
	for1000.Clear();
	
	for100.LoadData("DataFile1.txt");
	for1000.LoadData("DataFile2.txt");

	//cout<<endl<<"100 Entries in file";
	for100.HeapSort();
	//cout<<endl<<"1000 Entries in file";
	for1000.HeapSort();

	cout<<endl<<endl;
	for100.Clear();
	for1000.Clear();
	//CreateFiles();
	for100.LoadData("DataFile1.txt");
	for1000.LoadData("DataFile2.txt");
	int CO =0;
	int SW=0;
	//cout<<endl<<"100 Entries in file";
	for100.QuickSort(0,99, CO, SW);
	cout<<endl<<left<<setw(16)<<"Quick Sort: "<<setw(4)<<for100.ReturnNumLines()<<setw(27)<<" Entries in file.  Swaps: "<<setw(6)<<SW;
	cout<<"   Comparisons: "<<CO;
	CO = 0;
	SW = 0;
	//cout<<endl<<"1000 Entries in file";
	for1000.QuickSort(0, 99, CO, SW);
	cout<<endl<<left<<setw(16)<<"Quick Sort: "<<setw(4)<<for1000.ReturnNumLines()<<setw(27)<<" Entries in file.  Swaps: "<<setw(6)<<SW;
	cout<<"   Comparisons: "<<CO;
	cout<<endl<<endl;
	
	//high_resolution_clock::time_point EndTime = high_resolution_clock::now();
	//duration<double> AmountOfTime = duration_cast<duration<double>>(EndTime - StartTime);
	//cout<<AmountOfTime.count() * 1000 <<" Milliseconds";

	system("pause");
	return 0;
}