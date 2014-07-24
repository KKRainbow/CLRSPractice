/*************************************************************************
    > File Name: graphalgorithms.cpp
# Author: Rainbow
# mail: 443152178@qq.com
    > Created Time: Thu 24 Jul 2014 11:56:20 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include"graphalgorithms.h"
#define INFINITE 99999999
using namespace std;

struct vertex
{
	int color;
	int parent;
	int dist;
};

void bfs(GraphBase &pGraph,int pSource,void (*pOper)(int))
{
	int iVertexNum = pGraph.getVertexNum();
	const int GREY = 0,BLACK = 1,WHITE = 2;
	if(pSource<1||pSource>iVertexNum)return;
	vertex* v = new vertex[iVertexNum+1];	
	for(int i=1;i<=iVertexNum;i++)
	{
		v[i].color = WHITE;
		v[i].parent = 0;
		v[i].dist = INFINITE;
	}
	queue<int> q;
	v[pSource].color = GREY;
	v[pSource].parent = 0;
	v[pSource].dist = 0;
	q.push(pSource);
	while(!q.empty())
	{
		int u = q.front();
		(*pOper)(u);
		q.pop();
		for(int i=1;i<=iVertexNum;i++)
		{
			if(i==u)continue;
			if(pGraph.getValue(u,i)==GraphBase::NONEVALUE)continue;
			if(v[i].color == WHITE)
			{
				v[i].color = GREY;
				v[i].parent = u;
				v[i].dist = v[u].dist + 1;
				q.push(i);
			}
		}
		v[u].color = BLACK;
	}
}
