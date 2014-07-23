#ifndef GRAPHBASE_H
#define GRAPHBASE_H

class GraphBase
{
public:
    GraphBase();
	virtual void addEdge(int from,int to,int value)=0;
	virtual void deleteEdge(int from,int to)=0;
	virtual int getValue(int from,int to)=0;
	virtual bool isDirected();
private:
	bool bIsDirected;
    
};

#endif // GRAPHBASE_H
