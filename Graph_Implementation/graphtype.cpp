#include <iostream>
#include <string>
using namespace std;

#include "graphtype.h"
//#include "pqtype.h"
#include "qtype.h"

GraphType::GraphType()
{
	vertices = new ItemType[MaxItem];
	maxVertices = MaxItem;
	numVertices = 0;
	totalDis = 0;
}

GraphType::~GraphType()
{
	delete [] vertices;
}

void GraphType::AddToGraph(ItemType NewItem, int IndexTo)
{
	vertices[IndexTo] = NewItem;
	numVertices++;
}

int GraphType::NumberOfVertices()
{
	return numVertices;
}


ostream& operator << (ostream& out, GraphType& graph)
{
	for(int i=0; i<7; i++)
	{
		out<<graph.vertices[i];
	}
	return out;
}

bool GraphType::DirectConnection(int from, int to)
{

	if (vertices[from].weight[to] == 0)
	{
		cout<<endl<<"No direct connection"<<endl;
		return false;
	}
	else
	{
		cout<<endl<<"Direct connection between: "<<vertices[from].name<<" & "<<vertices[to].name<<" - "<< vertices[from].weight[to]<<" Miles"<<endl<<endl;
		return true;
	}
}


//bool GraphType::IsMarked(int ix)
//{
//	return vertices[ix].mark;
//}

void GraphType::MarkVertex(int ix)
{
	vertices[ix].mark = true;
}

//int GraphType::WeightIs(int from, int to)
//{
//	return vertices[from].weight[to];
//}

void GraphType::ClearMarks()
{
	for(int i=0; i<MaxItem; i++)
	{
		vertices[i].mark = false;
	}
	totalDis = 0;
}

//bool GraphType::GetToVertices(ItemType VerTx, QType& adjVer)
//{
//	bool HaveVertices = false;
//	for(int x=0; x<numVertices;x++)
//	{
//		if(vertices[VerTx.indexOfCity].weight[x] != 0)
//		{
//			HaveVertices = true;
//			adjVer.Enqueue(vertices[x]);
//		}
//	}
//	return HaveVertices;
//}



void GraphType::recursion(ItemType City, int start, int end)
{

	MarkVertex(City.indexOfCity);
	
	StorageQ.Enqueue(City);

	//cout<<"Enqued "<<vertices[City.indexOfCity].name<<endl;

	if(City.indexOfCity == end)
	{
		//StorageQ.Enqueue(City);
		//cout<<endl<<"Before Cleaning"<<endl;
		//CleanQue(StorageQ);
		//StorageQ.ViewQ();
		ViewPaths(StorageQ);

		vertices[end].mark = false;

		//cout<<endl<<"After Cleaning"<<endl;
		
		CleanQue(StorageQ);

		//ViewPaths(StorageQ);
		//cout<<"Removing "<<vertices[end].name;
		//ViewPaths(StorageQ);

		
		//cout<<endl<<"After Cleaning"<<endl;
		//StorageQ.ViewQ();
		//system("pause");
		//cout<<endl<<"After Cleaning"<<endl;
		//ViewPaths(StorageQ);
		//ItemType N;
		//StorageQ.Dequeue(N);
		

		//cout<<"Path from "<<vertices[start].name<<" to "<<vertices[end].name<<" through";
		

		//vertices[end].mark = false;
		
		
		/*cout<<"Reached End"<<endl;*/
	}

	else
	{
		for(int index = 0; index<numVertices; index++)
		{
			if( vertices[City.indexOfCity].weight[index] != 0 && vertices[index].mark == false/* && City.indexOfCity != end*/)
			{

				//cout<<"Going to "<<vertices[index].name<<endl;
				//MarkVertex(index);

				//cout<<"Going to "<<vertices[index].name<<endl;
				//system("pause");
				//StorageQ.Enqueue(vertices[index]);
				recursion(vertices[index], start, end);
				/*vertices[index].mark = false;
				CleanQue(StorageQ);*/
				//CleanQue(StorageQ);
				//cout<<"Marked as false "<<vertices[index].name<<endl;
				//cout<<"Marked as FALSE "<<vertices[City.indexOfCity].name<<endl;
			}

		}
		vertices[City.indexOfCity].mark = false;
		CleanQue(StorageQ);
		//cout<<"Removing Marked as false "<<vertices[City.indexOfCity].name<<endl;
			/*vertices[City.indexOfCity].mark = false;
			CleanQue(StorageQ);*/
			//system("pause");
	}
}
void GraphType::CleanQue(QType& Storage)
{
	QType CopyQ;
	ItemType item;
	while(!Storage.IsEmpty())
	{
		Storage.Dequeue(item);
		//cout<<"QUEUCLEAN ADD: "<<item.name<<endl;
		if(vertices[item.indexOfCity].mark == true)
		{CopyQ.Enqueue(item);}
	}
	while (!CopyQ.IsEmpty())
	{
		CopyQ.Dequeue(item);
		//cout<<"DEQUEUE: "<<item.name<<endl;
		/*if(vertices[item.indexOfCity].mark != false)
		{*/
			Storage.Enqueue(item);
			//cout<<"ENQUEUE: "<<item.name<<endl;
			//cout<<"Enqued "<<item.name<<endl;
		//}
		/*else
			cout<<"Removed "<<item.name<<endl;*/
			
		
	}
	//system("pause");
}
void GraphType::ViewPaths(QType Storage)
{
	//QType CopyStorage, trackQ;
	//ItemType SEE, First, Next;
	//ItemType VerteciesArray[MaxItem];
	//int items = 0;
	//totalDis = 0;
	////int start;

	//int count=0;
	//CopyStorage.MakeEmpty();
	////cout<<endl;

	//Storage.Dequeue(First);
	////SEE = First;
	////start = First.indexOfCity;
	//CopyStorage.Enqueue(First);
	////trackQ.Enqueue(First);

	//VerteciesArray[items] = First;

	////cout<<"  "<<First.name;

	//while(!Storage.IsEmpty())
	//{
	//	
	//	count=0;
	//	Storage.Dequeue(Next);

	//	//trackQ.Enqueue(Next);

	//	if(vertices[First.indexOfCity].weight[Next.indexOfCity] != 0 && vertices[Next.indexOfCity].mark == true /*&& vertices[Next.indexOfCity].indexOfCity*/)
	//	{
	//		items++;
	//		VerteciesArray[items] = Next;

	//		for(int i=0; i<items+1; i++)
	//		{
	//			if(VerteciesArray[i].indexOfCity == Next.indexOfCity)
	//			{	
	//				
	//				count++;
	//			}
	//		}

	//		if(count<2)
	//		{
	//			CopyStorage.Enqueue(Next);
	//			totalDis += vertices[First.indexOfCity].weight[Next.indexOfCity];
	//			//cout<<"->"<<Next.name;
	//			First = Next;
	//		}
	//	}

	//}
	////cout<<" "<<SEE.name;
	//while(!CopyStorage.IsEmpty())
	//{

	//	CopyStorage.Dequeue(SEE);
	//	if(vertices[SEE.indexOfCity].mark = true)
	//	{
	//		cout<<SEE.name<<"->";
	//		Storage.Enqueue(SEE);
	//	}
	//}
	//cout<<"  Total Miles: "<<totalDis;
	////trackQ.ViewQ();
	//cout<<endl;

	int dis = 0;
	ItemType First, Next;
	QType Copy;

	Storage.Dequeue(First);
	cout<<endl<<First.name;
	while(!Storage.IsEmpty())
	{
		Storage.Dequeue(Next);
			cout<<" ->"<<Next.name;
			dis += vertices[First.indexOfCity].weight[Next.indexOfCity];
			First = Next;
	}
	cout<<" Total Miles: "<<dis<<endl;
	
}

void GraphType::FindAllPaths(int Start, int End)
{
	ClearMarks();
	StorageQ.MakeEmpty();
	ItemType Item;
	Item = vertices[Start];
	MarkVertex(Item.indexOfCity);
	recursion(Item, Start, End);
}



//void GraphType::BreadthFirstSearch(/*GraphType GRAPH,*/ int startVertex, int endVertex)
//{
//
//	cout<<endl<<endl<<"BFS"<<endl<<endl;
//
//	QType queue, vertexQ;
//	bool found = false;
//	ItemType vertex, item;
//	ClearMarks();
//
//	queue.Enqueue(vertices[startVertex]);
//	
//
//	do
//	{
//		queue.Dequeue(vertex);
//		if(vertex.indexOfCity == vertices[endVertex].indexOfCity)
//		{
//			cout<<endl<<vertex.name<<endl;
//			found=true;
//		}
//		else
//		{
//			if(!IsMarked(vertex.indexOfCity))
//			{
//				MarkVertex(vertex.indexOfCity);
//				cout<<endl<< vertex.name<<endl;
//				GetToVertices(vertex, vertexQ);
//
//				while(!vertexQ.IsEmpty())
//				{
//					vertexQ.Dequeue(item);
//					if(!IsMarked(item.indexOfCity))
//						queue.Enqueue(item);
//				}
//			}
//		}
//	} while (!queue.IsEmpty() && !found);
//	if(!found)
//		cout<<"No through connection between "<<vertices[startVertex].name<<" and "<<vertices[endVertex].name<<endl;
//}
//void GraphType::DepthFirstSearch(int startVertex, int endVertex)
//{
//	//ClearMarks();
//	cout<<endl<<endl<<"DFS"<<endl<<endl;
//	QType stack, vertexQ, Store;
//
//	bool found = false;
//	ItemType vertex, item;
//
//	ClearMarks();
//	stack.Enqueue(vertices[startVertex]);
//	do
//	{
//		stack.Dequeue(vertex);
//
//		if (vertex.indexOfCity == endVertex)
//		{
//			Store.Enqueue(vertex);
//			cout<<vertex.name<<endl;
//			found = true;
//		}
//		else
//		{
//			if (!IsMarked(vertex.indexOfCity))
//			{
//				MarkVertex(vertex.indexOfCity);
//				cout<<vertex.name<<endl;
//				Store.Enqueue(vertex);
//				bool HaveVertex = GetToVertices(vertex, vertexQ);
//				while (!vertexQ.IsEmpty())
//				{
//					vertexQ.Dequeue(item);
//					if (!IsMarked(item.indexOfCity))
//						stack.Enqueue(item);
//				}
//			}
//		}
//	} while (!stack.IsEmpty() && !found);
//	Store.ViewQ();
//	if (!found)
//		cout<<"Path not found."<<endl;
//
//
//
//
//}
void GraphType::ViewCity(int number)
{
	cout<<vertices[number].indexOfCity + 1<<". "<<vertices[number].name<<endl;
}

//void GraphType::ViewFromToWay(QType QUE)
//{
//	QType CopyQ;
//	ItemType item;
//}