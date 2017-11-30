#include <iostream>
#include <string>
using namespace std;
#include "Student.h"
#include "HashTable.h"


int Hash(string n)
{
	//int Number = atoi(n);
	int N = stoi(n);
	return N%100;
}


HashTable::HashTable()
{
	Data = new Students[100];

	for(int i=0; i < 100; i++)
	{
		Data[i].ID = "";
		Data[i].name = "";
	}
}

HashTable::~HashTable()
{
	delete [] Data;
}

void HashTable::Insert(string id, string name)
{
	int HashKey = Hash(id);

	if(Data[HashKey].ID != "")
	{
		int i = HashKey;
		while(Data[i].ID != "")
		{
			i++;
			if(i > 99)
			{
				i=0;
			}
		}

		Data[i].ID = id;
		Data[i].name = name;
	}
	else
	{
		Data[HashKey].ID = id;
		Data[HashKey].name = name;
	}
}

string HashTable::Retrieve(string id)
{
	int HashKey = Hash(id);
	int stop  = HashKey;
	bool found=true;

	while(Data[HashKey].ID != id)
	{
		HashKey++;
		if(HashKey == stop)
		{
			found = false;
			break;
		}
		if(HashKey > 99)
		{
			HashKey = 0;
		}
	}
	
	if(found)
		return Data[HashKey].name;
	else
		return "Not found";
}

