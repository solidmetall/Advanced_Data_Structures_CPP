//test.cpp
// Petin Evgeniy	CSIT-832 (Advanced Data Structures & Introduction to Data Bases)
//Section#:			7010
// Assignment #2


#include <iostream>
#include <string>
using namespace std;
#include <fstream>

#include "graphtype.h"
#include "itemtype.h"
#include "qtype.h"

#include <string>

int main()
{
	string AnyKey;
	int choice;
	int from, to;
	int index = 0, edge;
	int edges[10];
	bool DirCon;

	GraphType graph;
	ItemType ITEM;
	ifstream file;
	string str, name;
	

	file.open("load.txt");

	if(!file.is_open())
	{
		cout<<"Unable to read file"<<endl;
	}
	else
	{
		while(!file.eof())
		{
			file >> name;

			for(int i = 0; i < 7; i++)
			{
				file>>edge;
				edges[i] = edge;
			}

			ITEM.AddItemType(name, index, edges, false);
			graph.AddToGraph(ITEM, index);
			index ++;
		}
		file.close();

		for(;;)
		{
			cout<<"1. Choose departure city"<<endl;
			cout<<"2. Exit"<<endl;

			cout<<"Enter your choice ";
			cin>>choice;

			if(choice == 2)
				break;

			cout<<endl;

			for( int Y = 0; Y < graph.NumberOfVertices(); Y++)
			{
				graph.ViewCity(Y);
			}

			cout<<endl<<"Please enter Departure: ";
			cin>>from;
			cout<<endl;

			for( int Y = 0; Y < graph.NumberOfVertices(); Y++)
			{
				if(Y!=from-1)
					graph.ViewCity(Y);
			}
			cout<<endl<<"Please enter destination: ";
			cin>>to;
			cout<<endl;

			graph.ClearMarks();

			DirCon = graph.DirectConnection(from-1, to-1);

			if(DirCon == false)
			{
				graph.FindAllPaths(from-1, to-1);
				system("pause");
				system("cls");
			}
			else
			{
				system("pause");
				system("cls");
			}
		}
	}

	return 0;
}


