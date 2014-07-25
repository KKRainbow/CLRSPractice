/*************************************************************************
    > File Name: graphalgorithms.h
# Author: Rainbow
# mail: 443152178@qq.com
    > Created Time: Thu 24 Jul 2014 11:48:43 AM CST
************************************************************************/
#ifndef GRAPHALGORITHMS_H
#define GRAPHALGORITHMS_H
#include"graphbase.h"
enum Color
{
	GREY,
	BLACK,
	WHITE
};
struct vertexforbfs 
{
	int value;
	Color color;
	int parent;
	int dist;
};
struct vertexfordfs
{
	int value;
	Color color;
	int parent;
	int dist;
	int finish;
};

void bfs(GraphBase &pGraph,int pSource,void (*pOpe)(vertexforbfs));
void dfsNonRecursion(GraphBase &pGraph,void (*pOpe)(vertexfordfs));
void dfsNonRecursionVisit(GraphBase &pGraph,int pSource,void (*pOpe)(vertexfordfs),vertexfordfs* v,int &time);
void dfsRecursion(GraphBase &pGraph,void (*pOpe)(vertexfordfs));
void dfsRecursionVisit(GraphBase &pGraph,int pSource,void (*pOpe)(vertexfordfs),vertexfordfs* v,int time);

#endif
