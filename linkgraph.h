#ifndef LINKGRAPH_H
#define LINKGRAPH_H
#include"graphbase.h"
#include"vertex.h"
class LinkGraph : public GraphBase
{
public:
    LinkGraph(unsigned int num);
	void addEdge(int from,int to,int value);
	void deleteEdge(int from,int to);
	int getValue(int from,int to);
	void print();
private:
	unsigned int iVertexNum;
	Vertex* pVertexHeads;
};

#endif // LINKGRAPH_H
