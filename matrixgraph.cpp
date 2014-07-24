#include "matrixgraph.h"
#include<iostream>
using namespace std;
MatrixGraph::MatrixGraph(unsigned int num,bool isDirected)
{
	iVertexNum = num;
	bIsDirected = isDirected;
	Matrix = new int[num*num];
}
void MatrixGraph::addEdge(int from,int to,int value)
{
	deleteEdge(from,to);
	addSingleEdge(from,to,value);
	if(bIsDirected == false)
	{
		addSingleEdge(to,from,value);
	}
}
void MatrixGraph::deleteEdge(int from,int to)
{
	deleteSingleEdge(from,to);
	if(!bIsDirected)
	{
		deleteSingleEdge(to,from);
	}
}
void MatrixGraph::addSingleEdge(int from,int to,int value)
{
	setMatrixValue(from,to,value);
}
void MatrixGraph::deleteSingleEdge(int from,int to){
	setMatrixValue(from,to,EMPTY);
}
int MatrixGraph::getValue(int from,int to)
{
	return getMatrixValue(from,to);
}
void MatrixGraph::setMatrixValue(int row,int column,int value)
{
	Matrix[(row-1)*iVertexNum+column-1] = value;
}
int MatrixGraph::getMatrixValue(int row,int column)
{
	return Matrix[(row-1)*iVertexNum+column-1];
}
void MatrixGraph::print()
{
	for(int i=1;i<=iVertexNum;i++)
	{
		for(int j=1;j<=iVertexNum;j++)cout<<getMatrixValue(i,j)<<"   ";
		cout<<endl;
	}
}
