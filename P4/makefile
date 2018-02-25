make: main.o process.o heap.o node.o 
	g++ -o naive main.o process.o heap.o node.o 

run: 
	./naive
	
main.o:	main.cpp heap.h
	g++ -c main.cpp

node.o: node.cpp node.h process.h
	g++ -c node.cpp
	
process.o: process.cpp process.h
	g++ -c process.cpp

heap.o: heap.cpp heap.h node.h
	g++ -c heap.cpp
	
	
	