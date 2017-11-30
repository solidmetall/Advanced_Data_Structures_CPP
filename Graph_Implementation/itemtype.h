#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include <string>
using namespace std;

const int MaxItem  = 50; //Number of Vertices on the Graph

struct ItemType
{
	string name;
	int indexOfCity;
	int weight[MaxItem];
	bool mark;
	int cost;

	int fromVertex;
	int toVertex;

	ItemType();

	void AddItemType(string, int, int[], bool);

	friend ostream& operator << (ostream&, ItemType&);
	void operator = (const ItemType& right);
	friend bool operator == (ItemType l, ItemType r);
	friend bool operator <= (ItemType l, ItemType r);
	friend bool operator < (ItemType l, ItemType r);
	bool IfDeadEnd();
};



#endif