//pqtype.cpp
// Petin Evgeniy	CSIT-832 (Advanced Data Structures & Introduction to Data Bases)
//Section#:			7010
// Assignment #1

template<class ItemType>
PQType <ItemType>::PQType(int max)
{
  items.elements = new ItemType[max];
  items.numElement = new ItemType[max];
  length = 0;
  MaxNumber = max;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
  delete [] items.elements;
  delete [] items.numElement;
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
  length = 0;
  items.elements = NULL;
  items.numElement = NULL;
  MaxNumber = 0;
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty()
{
  return (length == 0);
}

template<class ItemType>
bool PQType<ItemType>::IsFull()
{
  return (length == MaxNumber);
}

template<class ItemType>
void PQType<ItemType>::EnqueueP(ItemType newNumber, ItemType newPrint)
{
	length++;
    items.elements[length-1] = newPrint;
	items.numElement[length-1] = newNumber;
    items.ReheapUp(0, length-1);
}

template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& JN, ItemType& PN)
{
	PN = items.elements[0];
	JN = items.numElement[0];

    items.elements[0] = items.elements[length-1];
	items.numElement[0] = items.numElement[length-1];

    length--;
    items.ReheapDown(0, length-1);
}

