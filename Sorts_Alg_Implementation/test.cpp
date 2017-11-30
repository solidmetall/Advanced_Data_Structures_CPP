//test.cpp
// Petin Evgeniy	CSIT-832 (Advanced Data Structures & Introduction to Data Bases)
//Section#:			7010
// Assignment #3
//22 in file

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "DataClass.h"

int main()
{
	char choice;
	fstream file;
	string StringBuffer;
	int NumberOfLines=0;

	file.open("classes.txt");

	if(!file.is_open())
	{
		cout<<"Unable to Read or Open the file"<<endl;
	}
	else
	{
		while(!file.eof())
		{
			getline(file, StringBuffer);
			NumberOfLines++;
		}
		file.close();
		StringBuffer.clear();
	}
		
		do
		{
			cout<<endl<<"A"<<" Selection"<<endl;
			cout<<"B"<<" Bubble"<<endl;
			cout<<"C"<<" Insertion"<<endl;
			cout<<"D"<<" Heap"<<endl;
			cout<<"E"<<" Quick"<<endl;
			cout<<"F"<<" Merge"<<endl;
			cout<<"G"<<" Exit"<<endl<<endl;
			cout<<"X"<<" View Unsorted"<<endl<<endl;
			cout<<"Enter Choice: ";
			//cout<<21/2;
			cin >> choice;

			if (choice == 'a' || choice == 'A')
			{
				DataClass CompScience(NumberOfLines);
				CompScience.LoadData(NumberOfLines);
				CompScience.SelectSort();
				CompScience.ViewData();
			}

			else if (choice == 'b' || choice == 'B')
			{
				DataClass CompScience(NumberOfLines);
				CompScience.LoadData(NumberOfLines);
				CompScience.BubbleSort();
				CompScience.ViewData();
			}

			else if (choice == 'x' || choice == 'X')
			{
				DataClass CompScience(NumberOfLines);
				CompScience.LoadData(NumberOfLines);
				CompScience.ViewData();
			}

			else if (choice == 'c' || choice == 'C')
			{
				DataClass CompScience(NumberOfLines);
				CompScience.LoadData(NumberOfLines);
				CompScience.InsertionSort();
				CompScience.ViewData();
			}

			else if (choice == 'f' || choice == 'F')
			{
				DataClass CompScience(NumberOfLines);
				CompScience.LoadData(NumberOfLines);
				CompScience.MergeSort(0, NumberOfLines-1);
				CompScience.ViewData();
			}

			else if (choice == 'd' || choice == 'D')
			{
				DataClass CompScience(NumberOfLines);
				CompScience.LoadData(NumberOfLines);
				CompScience.HeapSort();
				CompScience.ViewData();
			}

			else if (choice == 'e' || choice == 'E')
			{
				DataClass CompScience(NumberOfLines);
				CompScience.LoadData(NumberOfLines);
				CompScience.QuickSort(0, NumberOfLines-1);
				CompScience.ViewData();
			}

			else
			{
				cout<<endl<<"Unknown choice, "<<choice<<" please try again."<<endl;
			}
		}
		while(choice != 'g');

	system("pause");
	return 0;
}