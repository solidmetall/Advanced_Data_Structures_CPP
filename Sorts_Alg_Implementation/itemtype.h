#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include <string>
using namespace std;

//const int MaxItem  = 50; //Number of Vertices on the Graph

struct ItemType
{
	int Number;
	int Section;

	void operator = (const ItemType& right);

};



#endif