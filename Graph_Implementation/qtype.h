#ifndef QTYPE_H
#define QTYPE_H

#include <iostream>
using namespace std;
#include <string>

#include "itemtype.h"
//const int MAXx = 10;

class QType
{
private:
	int front;
	int rear;
	ItemType* items;

public:
	

	QType();
	bool IsEmpty(void);
	bool IsFull(void);
	void Enqueue(ItemType);
	ItemType Front(void);
	void Dequeue(ItemType&);
	void ViewQ();
	void Trim(int,int);
	void MakeEmpty();
	//void OutputQueu();
};
#endif