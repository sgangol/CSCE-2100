make: main.o Node.o BST.o 
	g++ -o BSTree  main.o Node.o BST.o 

run: 
	./BSTree
	
main.o:	main.cpp BST.h Node.h
	g++ -c main.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp
	
BST.o: BST.cpp BST.h 
	g++ -c BST.cpp
	

	
	