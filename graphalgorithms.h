/*************************************************************************
    > File Name: graphalgorithms.h
# Author: Rainbow
# mail: 443152178@qq.com
    > Created Time: Thu 24 Jul 2014 11:48:43 AM CST
************************************************************************/
#ifndef GRAPHALGORITHMS_H
#define GRAPHALGORITHMS_H
#include"graphbase.h"
#include<list>
#include<vector>
enum Color
{
	GREY,
	BLACK,
	WHITE
};
struct vertexforbfs 
{
	int value = -1;
	Color color;
	int parent;
	int dist;
};
struct vertexfordfs
{
	int value = -1;
	Color color;
	int parent;
	int dist;
	int finish;
};
vertexforbfs* bfs(GraphBase &pGraph,int pSource,void (*pOpe)(vertexforbfs));
vertexfordfs* dfsNonRecursion(GraphBase &pGraph,void (*pOpe)(vertexfordfs));
void dfsNonRecursionVisit(GraphBase &pGraph,int pSource,void (*pOpe)(vertexfordfs),vertexfordfs* v,int &time);
vertexfordfs* dfsRecursion(GraphBase &pGraph,void (*pOpe)(vertexfordfs));
void dfsRecursionVisit(GraphBase &pGraph,int pSource,void (*pOpe)(vertexfordfs),vertexfordfs* v,int &time);
std::list<int> topologicalSort(GraphBase &pGraph);
void topologicalSortHelper(vertexfordfs v);
std::list<std::vector<int>> getStronglyConnectedComponent(GraphBase& pGraph);
GraphBase* getGraphTransposition(GraphBase&a);
#endif
