/*************************************************************************
  > File Name: graphalgorithms.cpp
# Author: Rainbow
# mail: 443152178@qq.com
> Created Time: Thu 24 Jul 2014 11:56:20 AM CST
 ************************************************************************/
#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
#include"matrixgraph.h"
#include"graphalgorithms.h"
#define INFINITE 99999999
using namespace std;
vertexforbfs* bfs(GraphBase &pGraph,int pSource,void (*pOper)(vertexforbfs))
{
	int iVertexNum = pGraph.getVertexNum();
	vertexforbfs* v = new vertexforbfs[iVertexNum+1];	
	if(pSource<1||pSource>iVertexNum)return nullptr;
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
		if(pOper!=nullptr)(*pOper)(v[u]);
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
	return v;
}
vertexfordfs* dfsNonRecursion(GraphBase &pGraph,void (*pOpe)(vertexfordfs))
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
	return v;
}
void dfsNonRecursionVisit(GraphBase &pGraph,int pSource,void (*pOpe)(vertexfordfs),vertexfordfs* v,int &time)
{
	stack<int> s;
	int num = pGraph.getVertexNum();
	if(v[pSource].color == Color::WHITE)
	{
		s.push(pSource);
	}
	while(!s.empty())
	{
		int u = s.top();
		if(v[u].color == Color::BLACK)
		{
			s.pop();
			continue;
		}
		if(v[u].color == Color::WHITE)
		{
			v[u].dist = ++time;
			v[u].color = Color::GREY;
		}
		bool hasPushAllVertex = true;
		for(int i = num;i>=1;i--)
		{
			if(pGraph.getValue(u,i)==GraphBase::NONEVALUE)
			{
				continue;
			}
			if(v[i].color == Color::WHITE)
			{
				hasPushAllVertex = false;
				s.push(i);
				v[i].parent = u;
			}
		}
		if(hasPushAllVertex == true)
		{
			int top = s.top();
			s.pop();
			v[top].color = Color::BLACK;
			v[top].finish = ++time;
			if(pOpe!=nullptr)(*pOpe)(v[top]);
		}
	}
}
vertexfordfs* dfsRecursion(GraphBase &pGraph,void (*pOpe)(vertexfordfs))
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
		if(v[i].color == Color::WHITE)
			dfsRecursionVisit(pGraph,i,pOpe,v,time);
	}
	return v;
}
void dfsRecursionVisit(GraphBase &pGraph,int current,void (*pOpe)(vertexfordfs),vertexfordfs* v,int &time)
{
	if(v[current].color==Color::BLACK)return;
	time++;
	v[current].dist = time;
	v[current].color = Color::GREY;
	int num = pGraph.getVertexNum();
	for(int i=1;i<=num;i++)
	{
		if(v[i].color==Color::WHITE&&pGraph.getValue(current,i)!=GraphBase::NONEVALUE)
		{
			v[i].color = Color::GREY;
			dfsRecursionVisit(pGraph,i,pOpe,v,time);
		}
	}
	v[current].color = Color::BLACK;
	time++;
	v[current].finish = time;
	if(pOpe!=nullptr)(*pOpe)(v[current]);
}
static list<int> * pLinkedlist;
list<int> topologicalSort(GraphBase &pGraph)
{
	pLinkedlist = new list<int>;
	dfsNonRecursion(pGraph,topologicalSortHelper);
	list<int> temp = *pLinkedlist;
	delete pLinkedlist;
	return temp;
}
void topologicalSortHelper(vertexfordfs v)
{
	pLinkedlist->insert(pLinkedlist->begin(),v.value);
}


list<std::vector<int>> getStronglyConnectedComponent(GraphBase& pGraph)
{
	vertexfordfs* v = dfsRecursion(pGraph,nullptr);
	GraphBase* TGraph = getGraphTransposition(pGraph);
	int num = pGraph.getVertexNum();
	list<vector<int>> result;
	for(int i= 2;i<=num;i++)
	{
		vertexfordfs temp = v[i];
		int j = i-1;
		for(;v[j].finish<temp.finish&&j>=0;j--)
		{
			v[j+1] = v[j];
		}
		if(j+1!=i)
			v[j+1] = temp;
	}
	vertexfordfs* component = new vertexfordfs[num+1];
	for(int i=1;i<=num;i++)
	{
		component[i].value = i;
		component[i].color = Color::WHITE;
		component[i].parent = 0;
		component[i].dist = INFINITE;
	}
	int temp= 0,test =0;
	result.push_back(*(new vector<int>(0)));
	auto iter = result.begin();
	for(int i=1;i<=num;i++)
	{
		dfsRecursionVisit(*TGraph,v[i].value,nullptr,component,temp);
		if(test==temp)continue;
		for(int j=1;j<=num;j++)
		{
			if(component[j].finish<=temp&&component[j].finish>test)
			{
				(*iter).push_back(j);	
			}
		}
		result.push_back(*(new vector<int>(0)));
		iter++;
		test = temp;
	}
	result.pop_back();
	return result;
}

GraphBase* getGraphTransposition(GraphBase &a)
{
	int num = a.getVertexNum();
	MatrixGraph* graph =new MatrixGraph(num,true); 
	int value = 0;
	for(int i=1;i<=num;i++)
		for(int j=1;j<=num;j++)
		{
			if((value=a.getValue(i,j))!=GraphBase::NONEVALUE)
			{
				graph->addEdge(j,i,value);	
			}
		}
	return graph;
}
