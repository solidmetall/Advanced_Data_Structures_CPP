#include <iostream>
#include <string>
using namespace std;

#include "itemtype.h"
//const int MAXITEMS = 10;

ItemType::ItemType()
{
	//toVertex = 0;
	mark=false;
	cost = 0;
}
void ItemType::operator = (const ItemType& right)
{
	this->name = right.name;
	//fromVertex = right.fromVertex;
	this->indexOfCity = right.indexOfCity;
	this->mark = right.mark;
	//toVertex = right.toVertex;
	this->cost = right.cost;
	
	for (int i=0; i<MaxItem; i++)
	{ this->weight[i] = right.weight[i]; }
}

ostream& operator << (ostream& out, ItemType& vertex)
{
	out<<endl<<vertex.indexOfCity+1<<". "<<vertex.name;
	return out;
}

void ItemType::AddItemType(string n, int index, int w[MaxItem], bool m)
{
	name = n;
	indexOfCity = index;
	for (int i=0; i<MaxItem; i++)
	{ weight[i] = w[i]; }
	mark = m;
}

bool operator==(ItemType l, ItemType r)
{
	return l.indexOfCity == r.indexOfCity;
}

bool operator<=(ItemType l, ItemType r)
{
	return l.cost <= r.cost;
}

bool operator<(ItemType l, ItemType r)
{
	return l.cost < r.cost;
}

bool ItemType::IfDeadEnd()
{
	bool answer = false;
	for(int i=0; i<MaxItem; i++)
	{
		if(weight[i] != 0 && mark == false)
			answer = true;
	}
	return answer;
}

