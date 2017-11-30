#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H

#include <iostream>
using namespace std;

#include <string>
#include "itemtype.h"
#include "qtype.h"

class GraphType
{
public:
	GraphType();
	~GraphType();

	void AddToGraph(ItemType, int);
	int NumberOfVertices();
	bool DirectConnection(int, int);
	//bool IsMarked(int);
	void MarkVertex(int);
	void ClearMarks();
	//int WeightIs(int,int);
	//void BreadthFirstSearch(/*GraphType,*/ int, int);
	//void DepthFirstSearch(int, int);
	//bool GetToVertices(ItemType, QType&);
	void recursion(ItemType, int, int);
	void FindAllPaths(int, int);
	void ViewPaths (QType);
	void ViewCity(int);
	void CleanQue(QType&);
	

private:
	ItemType* vertices;
	int numVertices;
	int maxVertices;
	QType StorageQ;
	int totalDis;

	friend ostream& operator << (ostream&, GraphType&);
};



#endif