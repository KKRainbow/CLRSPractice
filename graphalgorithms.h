/*************************************************************************
    > File Name: graphalgorithms.h
# Author: Rainbow
# mail: 443152178@qq.com
    > Created Time: Thu 24 Jul 2014 11:48:43 AM CST
************************************************************************/
#ifndef GRAPHALGORITHMS_H
#define GRAPHALGORITHMS_H
#include"graphbase.h"
struct vertexforbfs 
{
	int value;
	int color;
	int parent;
	int dist;
};

void bfs(GraphBase &pGraph,int pSource,void (*pOpe)(vertexforbfs));


#endif
