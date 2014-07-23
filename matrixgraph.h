#ifndef MatrixGraph_H
#define MatrixGraph_H

#define EMPTY 0

#include"graphbase.h"
class MatrixGraph : public GraphBase
{
public:
    MatrixGraph(unsigned int num,bool isDirected);
	void addEdge(int from,int to,int value);
	void deleteEdge(int from,int to);
	int getValue(int from,int to);
	void print();
private:
	unsigned int iVertexNum;
	int *Matrix;
	void setMatrixValue(int row,int column,int value);
	int getMatrixValue(int row,int column);
	void addSingleEdge(int from,int to,int value);
	void deleteSingleEdge(int from,int to);
};

#endif // MatrixGraph_H
