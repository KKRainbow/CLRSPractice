#include "linkgraph.h"
#include<iostream>
LinkGraph::LinkGraph(unsigned int num,bool isDirected):iVertexNum(num)
{
	bIsDirected = isDirected;
	pVertexHeads = new Vertex[num+1];
	for(int i=1;i<num;i++){
		pVertexHeads[i].value = 0;
		pVertexHeads[i].to = i;
		pVertexHeads[i].next = new Vertex{
			NIL,
				NIL,
				nullptr
		};
	}
}
void LinkGraph::addEdge(int from,int to,int value)
{
	deleteEdge(from,to);
	addSingleEdge(from,to,value);
	if(bIsDirected == false)
	{
		addSingleEdge(to,from,value);
	}
}
void LinkGraph::deleteEdge(int from,int to)
{
	deleteSingleEdge(from,to);
	if(!bIsDirected)
	{
		deleteSingleEdge(to,from);
	}
}
void LinkGraph::addSingleEdge(int from,int to,int value){
	pVertexHeads[from].next = new Vertex{
		value,
			to,
			pVertexHeads[from].next
	};
}
void LinkGraph::deleteSingleEdge(int from,int to){
	Vertex* tmp = pVertexHeads+from;
	if(to!=from)
		while(tmp->next!=nullptr){
			if(tmp->next->to == to){
				break;
			}
			tmp = tmp->next;
		}
	if(tmp->next==nullptr)return;
	else{
		auto del = tmp->next;
		tmp->next = del->next;
		delete del;
	}
	return;
}
int LinkGraph::getValue(int from,int to){
	auto tmp = pVertexHeads + from;
	while(tmp->next!=nullptr)
	{
		if(tmp->to == to)
			return tmp->value;
		tmp = tmp->next;
	}
	return NIL;
}
void LinkGraph::print()
{
	int i;
	for(i=1;i<iVertexNum;i++)
	{
		auto tmp = pVertexHeads + i;
		while(tmp->next!=nullptr)
		{
			std::cout<<tmp->to<<"  ";
			tmp = tmp->next;
		}
		std::cout<<std::endl;
	}
}
