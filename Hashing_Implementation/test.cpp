//test.cpp
// Petin Evgeniy	CSIT-832 (Advanced Data Structures & Introduction to Data Bases)
//Section#:			7010
// Assignment #4
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Student.h"
#include "HashTable.h"



int main()
{
	fstream file;
	file.open("Students.txt");
	HashTable list;
	int count=0;
	int choice;
	
	bool space;

	if(!file.is_open())
	{
		cout<<"Unable to Read or Open the file"<<endl;
	}
	else
	{
		while(!file.eof())
		{
			space = false;
			string id ="", Name="";
			string buffer="";

			getline(file, buffer);
			int L = buffer.length();
			int placement = buffer.find_first_of(' ', 0);

			//cout<<endl<<placement;

			int length = buffer.length();
			
			for(int i=0; i < L; i++)
			{
				if(buffer[i] == ' ' && space == false)
				{
					space=true;
					i++;
				}

				if(space==false)
				{
					id += buffer[i];
				}
				else
				{
					Name += buffer[i];
				}
			}
			list.Insert(id, Name);
			count++;
		}
		file.close();
		cout<<"Loaded "<<count<<" records\n\n";
		do
		{
			string UID;
			cout<<"1. Find a student by ID\n";
			cout<<"2. Exit\n\n";
			cout<<"Enter your choice ";
			cin>>choice;
			cout<<endl;

			if(choice == 2)
			{
				break;
			}
			else if(choice == 1)
			{
				cout<<"Please enter user ID ";
				cin>> UID;
				cout<<endl;
				if(UID.length() > 4)
				{
					cout<<"\n Cannot be longer than 4 chars, try again\n\n";
				}
				else if(UID.length() < 4)
				{
					cout<<"\n Cannot be shorter than 4 chars, try again\n\n";
				}
				else
				{
					string found = list.Retrieve(UID);
					cout<<found<<endl<<endl;
				}
			}
			else
			{
				cout<<"No command for "<<choice<<" please try again\n\n";
			}
		}
		while(choice != 2);
	}


	system ("pause");
	return 0;
}