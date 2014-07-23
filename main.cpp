/*************************************************************************
    > File Name: main.cpp
# Author: Rainbow
# mail: 443152178@qq.com
    > Created Time: Wed 23 Jul 2014 05:57:57 PM CST
 ************************************************************************/

#include<iostream>
#include"linkgraph.h"
#include"matrixgraph.h"
#define GRAPH MatrixGraph 
using namespace std;

int main()
{
	GRAPH a(5,false);
	a.addEdge(1,4,1);
	a.addEdge(1,5,3);
	a.addEdge(2,4,2);
	a.addEdge(4,5,2);
	a.print();
	a.deleteEdge(1,4);
	cout<<endl;
	a.print();
	cout<<endl;
	cout<<a.getValue(2,4)<<endl;
	return 0;
}
