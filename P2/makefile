make: main.o Node.o NodeString.o SkipList.o SkipListString.o
	g++ -o skiplist main.o Node.o NodeString.o SkipList.o SkipListString.o

run: 
	./skiplist
	
main.o:	main.cpp SkipList.h SkipListString.h
	g++ -c main.cpp

Node.o: Node.cpp 
	g++ -c Node.cpp
	
NodeString.o: NodeString.cpp 
	g++ -c NodeString.cpp
	
SkipList.o: SkipList.cpp 
	g++ -c SkipList.cpp
	
SkipListString.o: SkipListString.cpp 
	g++ -c SkipListString.cpp
	

	
	