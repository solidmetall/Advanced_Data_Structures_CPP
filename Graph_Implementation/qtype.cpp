#include <iostream>
#include <string>
using namespace std;
#include "qtype.h"

QType::QType()
{
	items = new ItemType[MaxItem];
	front = MaxItem-1;
	rear = MaxItem-1;
}

void QType::Dequeue(ItemType& it)
{
	it = items[(front + 1) % MaxItem];
	if (front == MaxItem-1)
	{front = 0;}
	else
	{front++;}// = (front+1)%MAX;}
}

void QType::Enqueue(ItemType City)
{
	
	if (rear == MaxItem-1)
	{	
		rear = (rear + 1) % MaxItem;
	}
	else	
	{rear++;}// = (rear+1)%MAX;}
	
		items[rear] = City;
}

ItemType QType::Front()
{
	return items[(front + 1) % MaxItem];
}

bool QType::IsEmpty()
{
	return (front == rear);
}

bool QType::IsFull()
{
	if((rear + 1) % MaxItem == front)
		return true;
	else
		return false;
}

void QType::ViewQ()
{
	int dis = 0;
	ItemType SEE;
	QType Storage;
	
	while(!IsEmpty())
	{
		Dequeue(SEE);
		Storage.Enqueue(SEE);
	}

	while(!Storage.IsEmpty())
	{
		Storage.Dequeue(SEE);
		cout<<SEE.name<<"->";
		//dis+=SEE.
		Enqueue(SEE);
	}

	
}

void QType::Trim(int from, int to)
{

}
void QType::MakeEmpty()
{
	front = MaxItem-1;
	rear = MaxItem-1;
}