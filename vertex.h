#ifndef VERTEX_H
#define VERTEX_H
#define NIL -99999999
struct Vertex{
	int value;
	int to;
	Vertex* next;
};
#endif // VERTEX_H
