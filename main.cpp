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
	return 0;
}
void print(vertexforbfs v)
{
	cout<<v.value<<"  ";
}
