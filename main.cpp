/*************************************************************************
    > File Name: main.cpp
# Author: Rainbow
# mail: 443152178@qq.com
    > Created Time: Wed 23 Jul 2014 05:57:57 PM CST
 ************************************************************************/

#include<iostream>
#include"linkgraph.h"
#include"matrixgraph.h"
#include"graphalgorithms.h"
//#define GRAPH LinkGraph
#define GRAPH MatrixGraph
using namespace std;
void print(vertexforbfs);
void printd(vertexfordfs);
int main()
{
	GRAPH a(6,true);
	a.addEdge(1,2,1);
	a.addEdge(1,4,3);
	a.addEdge(2,5,2);
	a.addEdge(3,5,2);
	a.addEdge(3,6,2);
	a.addEdge(4,2,2);
	a.addEdge(5,4,2);
	a.print();
	cout<<endl;
	cout<<a.getValue(2,4)<<endl;

	bfs(a,1,print);
	cout<<endl;
	dfsNonRecursion(a,printd);
	cout<<endl;
	dfsRecursion(a,printd);
	cout<<endl;
	list<int> l = topologicalSort(a);
	for(auto i = l.begin();i!=l.end();i++)
	{
		cout<<*i<<"   ";
	}
	cout<<endl;
	GRAPH b(8,true);
	b.addEdge(1,2,1);
	b.addEdge(2,3,1);
	b.addEdge(2,6,1);
	b.addEdge(2,5,1);
	b.addEdge(3,7,1);
	b.addEdge(3,4,1);
	b.addEdge(4,3,1);
	b.addEdge(4,8,1);
	b.addEdge(5,1,1);
	b.addEdge(5,6,1);
	b.addEdge(6,7,1);
	b.addEdge(7,6,1);
	b.addEdge(7,8,1);
	b.addEdge(8,8,1);
	auto c = getStronglyConnectedComponent(b);
	for(auto i = c.begin();i!=c.end();i++)
	{
		for(auto j=i->begin();j!=i->end();j++)
		{
			cout<<*j<<"   ";
		}
		cout<<endl;
	}
	return 0;
}
void print(vertexforbfs v)
{
	cout<<v.value<<"  ";
}
void printd(vertexfordfs v)
{
	cout<<v.value<<":finish:"<<v.finish<<":discover:"<<v.dist<<"  ";
}

