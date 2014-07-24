#ifndef GRAPHBASE_H
#define GRAPHBASE_H
class GraphBase
{
public:
    GraphBase()
	{
	
	}
	virtual void addEdge(int from,int to,int value)=0;
	virtual void deleteEdge(int from,int to)=0;
	virtual int getValue(int from,int to)=0;
	virtual bool isDirected();
	virtual void print()=0;
	int getVertexNum();
protected:
	unsigned int iVertexNum;
	bool bIsDirected;
};
#endif // GRAPHBASE_H
