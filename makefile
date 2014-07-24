OBJECTS=base.o link.o matrix.o algorithms.o
CC=g++ -std=c++11 -g
main:$(OBJECTS) main.cpp
	$(CC) -o main $(OBJECTS) main.cpp 
	make clean
	
base.o:graphbase.cpp
	$(CC) -c -o base.o graphbase.cpp 
link.o:linkgraph.cpp
	$(CC) -c -o link.o linkgraph.cpp
matrix.o:matrixgraph.cpp
	$(CC) -c -o matrix.o matrixgraph.cpp
algorithms.o:graphalgorithms.cpp
	$(CC) -c -o algorithms.o graphalgorithms.cpp
clean:
	rm -rf $(OBJECTS)
