OBJECTS=base.o link.o 
CC=g++ -std=c++11 -g
main:$(OBJECTS) main.cpp
	$(CC) -o main $(OBJECTS) main.cpp 
	make clean
	
base.o:graphbase.cpp
	$(CC) -c -o base.o graphbase.cpp 
link.o:linkgraph.cpp
	$(CC) -c -o link.o linkgraph.cpp

clean:
	rm -rf $(OBJECTS)
