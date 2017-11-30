
//heap.cpp
// Petin Evgeniy	CSIT-832 (Advanced Data Structures & Introduction to Data Bases)
//Section#:			7010
// Assignment #1

//  IMPLEMENTATION  OF RECURSIVE HEAP MEMBER FUNCTIONS
template< class  ItemType >
void   HeapType<ItemType>::Swap (ItemType& a, ItemType& b)
{
	ItemType temp;
	temp = a;
	a = b;
	b = temp;
}

template< class  ItemType >
void   HeapType<ItemType>::ReheapDown ( int root, int  bottom )
	// Pre:  root is the index of the node that may violate the
	// heap order property
	// Post: Heap order property is restored between root and bottom
{
	int  maxChild ;
      int  rightChild ;
      int  leftChild ;

      leftChild  =  root * 2 + 1 ;
      rightChild  =  root * 2 + 2 ;

		if  ( leftChild  <=  bottom )
		 {
			if ( leftChild  == bottom )
			 maxChild  =  leftChild ;
			else
			{
			  if (elements [ leftChild ] <= elements [ rightChild ] )
				maxChild  =  rightChild ;
			  else
				maxChild  =  leftChild ;
			}
			if  ( elements [ root ] <= elements [ maxChild ] )
			{
				Swap ( elements [ root ] , elements [ maxChild ] ) ;
				Swap ( numElement[root], numElement[maxChild] );

				ReheapDown ( maxChild, bottom ) ;
			}
		  }
}

template< class  ItemType >
void   HeapType<ItemType>::ReheapUp ( int  root,  int  bottom )

	//  Pre:  bottom is the index of the node that may violate the heap
	//  order property.  The order property is satisfied from root to
	//  next-to-last node.
	//  Post:  Heap order property is restored between root and bottom

{
	 int  parent ;

    if  ( bottom  > root )
    {
	parent = ( bottom - 1 ) / 2;

	if ( elements [ parent ]  <  elements [ bottom ] )
	{
	   Swap ( elements [ parent ], elements [ bottom ] ) ;
	   Swap ( numElement[parent], numElement[bottom] );

	   ReheapUp ( root, parent ) ;
	}
}
}