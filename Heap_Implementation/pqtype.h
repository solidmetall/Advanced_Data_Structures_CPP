
//pqtype.h
// Petin Evgeniy	CSIT-832 (Advanced Data Structures & Introduction to Data Bases)
//Section#:			7010
// Assignment #1

template<class ItemType>
class PQType
{
public:
  PQType(int);
  ~PQType();
  void MakeEmpty();
  bool IsEmpty();
  bool IsFull();
  void EnqueueP(ItemType newNumber, ItemType newPrint); //To enqueue JobNumber & PrintPriority by requestors
  void Dequeue(ItemType&, ItemType&); //Dequeue for output or printing

  void PQType::operator=(const PQType &right)
  {
	  for(int x=0; x<this->MaxNumber; x++)
	  {
		  this->items.elements[x] = right.items.elements[x];
		  this->items.numElement[x] = right.items.numElement[x];
	  }
	  
	  this->length = right.length;
  }

private:
  int length, MaxNumber;//= 99;
  HeapType <ItemType> items;
};

#include "pqtype.cpp"