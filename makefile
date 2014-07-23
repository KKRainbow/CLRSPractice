OBJECTS=base.o link.o main.cpp
CC=g++ -std=c++11
main:$(OBJECTS)
	$(CC) -o main $(OBJECTS) 
	
base.o:graphbase.cpp
	$(CC) -c -o base.o graphbase.cpp
link.o:linkgraph.cpp
	$(CC) -c -o link.o linkgraph.cpp

clean:
	rm -rf $(OBJECTS)
