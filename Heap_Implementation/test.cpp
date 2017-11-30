//test.cpp
// Petin Evgeniy	CSIT-832 (Advanced Data Structures & Introduction to Data Bases)
//Section#:			7010
// Assignment #1


#include <iostream>
using namespace std;
#include "heap.h"
#include "pqtype.h"
#include "string"

enum PriorityEnum {Student, TA, Instructor}; //I could do it without global enum variable, but i decided to practice with enums. ENUMs are cool !!!
string ReturnRequestor (PriorityEnum); //I could do it without global enum function, but i decided to practice with enums. ENUMs are cool !!!

int main()
{
	int QueueLength = 99; //Simply change this number to adjust Queue Length
	int choice, JN=0/*For Job Number Tracking*/, OutputJN, OutputPN;
	char Priority;
	PriorityEnum Requestor ; //Cool ENUM for practice
	
	PQType<int> QPriority(QueueLength); //Priority Queue for Storage & Printing
	PQType<int> OutputQueue(QueueLength); //Priority Queue for Output in Order

	string ReturnRequestor(PriorityEnum); //Function for COOL ENUM to return requestor name in string format

	do
	{
		cout<<endl<<"Printer queue\n=========\n\n1. Add job\n2. Print job\n3. View jobs\n4. Exit"<<endl;
		cout<<endl<<"Enter choice: ";
		cin>>choice;
		cout<<endl;

		if(choice == 1)
		{
			if(QPriority.IsFull())
			{
				cout<<"Cannot add print job - Queue is full, maximum print jobs queue can accept is "<<QueueLength<<"."<<endl;
			}
			else
			{
				JN++; //Tracking Job Number

				cout<<"Instructor (I or i), TA (T or t), or Student (S or s)? ";
				cin>>Priority;

				if(Priority == 'I' || Priority == 'i')
				{
					QPriority.EnqueueP(JN, 10);	//(Not going to work with CHARACTERS, S begger than T. Assigning ints for priority)
				}
				else if(Priority == 'T' || Priority == 't')
				{
					QPriority.EnqueueP(JN, 6); //(Not going to work with CHARACTERS, S begger than T. Assigning ints for priority)
				}
				else if(Priority == 'S' || Priority == 's' )
				{
					QPriority.EnqueueP(JN, 2); //(Not going to work with CHARACTERS, S begger than T. Assigning ints for priority)
				}
				else
				{
					cout<<endl<<"Your choice does nothing, please try again"<<endl;
				}
			}
		}
		else if(choice == 2)
		{
			if(!QPriority.IsEmpty())
			{
				QPriority.Dequeue(OutputJN, OutputPN);

				if(OutputPN == 10)
				{
					Requestor = Instructor;
				}
				else if(OutputPN == 6)
				{
					Requestor = TA;
				}
				else if(OutputPN == 2)
				{
					Requestor = Student;
				}

				cout<<"Now printing job #"<<OutputJN<<": "<< ReturnRequestor(Requestor) <<endl;
				JN--; //Tracking Job Number
			}
			else
			{
				cout<<endl<<"No print jobs in queue."<<endl<<endl;
			}
		}
		else if(choice == 3)
		{
			OutputQueue = QPriority;
			if(!OutputQueue.IsEmpty())
			{
				while(!OutputQueue.IsEmpty())
				{
					OutputQueue.Dequeue(OutputJN, OutputPN);
					if(OutputPN == 10)
					{
						Requestor = Instructor;
					}
					else if(OutputPN == 6)
					{
						Requestor = TA;
					}
					else if(OutputPN == 2)
					{
						Requestor = Student;
					}

					cout<<"Job #"<<OutputJN<<" : "<< ReturnRequestor(Requestor) <<endl;
				}
			}
			else
			{
				cout<<endl<<"No print jobs in queue."<<endl<<endl;
			}
		}
		else
		{
			if(choice != 4)
			cout<<endl<<"Your choice does Nothing, please try again."<<endl<<endl;
		}
	}
	while(choice != 4);

	system("pause");
	return 0;
}

string ReturnRequestor(PriorityEnum R)
{
	if (R == Student)
	{
		return "Student";
	}
	else if(R == TA)
	{
		return "TA";
	}
	else if(R == Instructor)
	{
		return "Instructor";
	}
}