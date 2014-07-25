/*************************************************************************
    > File Name: graphalgorithms.cpp
# Author: Rainbow
# mail: 443152178@qq.com
    > Created Time: Thu 24 Jul 2014 11:56:20 AM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<stack>
#include"graphalgorithms.h"
#define INFINITE 99999999
using namespace std;


void bfs(GraphBase &pGraph,int pSource,void (*pOper)(vertexforbfs))
{
	int iVertexNum = pGraph.getVertexNum();
	if(pSource<1||pSource>iVertexNum)return;
	vertexforbfs* v = new vertexforbfs[iVertexNum+1];	
	for(int i=1;i<=iVertexNum;i++)
	{
		v[i].value = i;
		v[i].color = Color::WHITE;
		v[i].parent = 0;
		v[i].dist = INFINITE;
	}
	queue<int> q;
	v[pSource].color = Color::GREY;
	v[pSource].parent = 0;
	v[pSource].dist = 0;
	q.push(pSource);
	while(!q.empty())
	{
		int u = q.front();
		(*pOper)(v[u]);
		q.pop();
		for(int i=1;i<=iVertexNum;i++)
		{
			if(i==u)continue;
			if(pGraph.getValue(u,i)==GraphBase::NONEVALUE)continue;
			if(v[i].color == Color::WHITE)
			{
				v[i].color = Color::GREY;
				v[i].parent = u;
				v[i].dist = v[u].dist + 1;
				q.push(i);
			}
		}
		v[u].color = Color::BLACK;
	}
}

void dfsNonRecursion(GraphBase &pGraph,void (*pOpe)(vertexfordfs))
{
	int iVertexNum = pGraph.getVertexNum();
	vertexfordfs* v = new vertexfordfs[iVertexNum+1];	
	int time = 0;
	for(int i=1;i<=iVertexNum;i++)
	{
		v[i].value = i;
		v[i].color = Color::WHITE;
		v[i].parent = 0;
		v[i].dist = INFINITE;
	}
	for(int i=1;i<=iVertexNum;i++)
	{
		dfsNonRecursionVisit(pGraph,i,pOpe,v,time);
	}
	
}
void dfsNonRecursionVisit(GraphBase &pGraph,int pSource,void (*pOpe)(vertexfordfs),vertexfordfs* v,int &time)
{
	stack<int> s;
	int num = pGraph.getVertexNum();
	if(v[pSource].color == Color::WHITE)
	{
		s.push(pSource);
		v[pSource].color = GREY;
	}
	while(!s.empty())
	{
		int u = s.top();
		bool hasPushAllVertex = true;
		for(int i = 1;i<=num;i++)
		{
			if(pGraph.getValue(u,i)==GraphBase::NONEVALUE)
			{
				continue;
			}
			if(v[i].color == Color::WHITE)
			{
				hasPushAllVertex = false;
				s.push(i);
				v[i].color = Color::GREY;
				v[i].parent = u;
			}
		}
		if(hasPushAllVertex == true)
		{
			int top = s.top();
			s.pop();
			v[top].color = Color::BLACK;
			v[top].dist = v[top].finish = time++;
			(*pOpe)(v[top]);
		}
	}
}



void dfsRecursion(GraphBase &pGraph,void (*pOpe)(vertexfordfs))
{
	int iVertexNum = pGraph.getVertexNum();
	vertexfordfs* v = new vertexfordfs[iVertexNum+1];	
	int time = 1;
	for(int i=1;i<=iVertexNum;i++)
	{
		v[i].value = i;
		v[i].color = Color::WHITE;
		v[i].parent = 0;
		v[i].dist = INFINITE;
	}
	for(int i=1;i<=iVertexNum;i++)
	{
		if(v[i].color == Color::WHITE)
			dfsRecursionVisit(pGraph,i,pOpe,v,time);
	}
	
}
void dfsRecursionVisit(GraphBase &pGraph,int pSource,void (*pOpe)(vertexfordfs),vertexfordfs* v,int time)
{
	time++;
	v[i].dist = 
}
