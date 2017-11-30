
//heap.h
// Petin Evgeniy	CSIT-832 (Advanced Data Structures & Introduction to Data Bases)
//Section#:			7010
// Assignment #1

// Assumes ItemType either a built-in simple data
// type or a class with overloaded relational operators.

template< class  ItemType >
struct  HeapType
{
  void   ReheapDown ( int  root ,  int  bottom ) ;
  void   ReheapUp ( int  root,  int  bottom ) ;
  void   Swap (ItemType&, ItemType&);

  ItemType* elements; //array to be allocated dynamically
  ItemType*  numElement ;
};

#include "heap.cpp"
