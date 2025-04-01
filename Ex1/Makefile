CC = g++
CFLAGS = -std=c++11 -Wall -g


all: Main Test

Main: Graph.o Algorithms.o PriorityQueue.o Queue.o Stack.o UnionFind.o BubbleSort.o main.o
	$(CC) $(CFLAGS) -o Main Graph.o Algorithms.o PriorityQueue.o Queue.o Stack.o UnionFind.o BubbleSort.o main.o

main.o: main.cpp Graph.hpp Algorithms.hpp 
	$(CC) $(CFLAGS) -c main.cpp 

Graph.o: Graph.cpp Graph.hpp
	$(CC) $(CFLAGS) -c Graph.cpp 

Algorithms.o: Algorithms.cpp Algorithms.hpp Graph.hpp UnionFind.hpp BubbleSort.hpp Queue.hpp Stack.hpp PriorityQueue.hpp
	$(CC) $(CFLAGS) -c Algorithms.cpp

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.hpp
	$(CC) $(CFLAGS) -c PriorityQueue.cpp

Queue.o: Queue.cpp Queue.hpp
	$(CC) $(CFLAGS) -c Queue.cpp 

Stack.o: Stack.cpp Stack.hpp
	$(CC) $(CFLAGS) -c Stack.cpp

UnionFind.o: UnionFind.cpp UnionFind.hpp
	$(CC) $(CFLAGS) -c UnionFind.cpp

BubbleSort.o: BubbleSort.cpp BubbleSort.hpp
	$(CC) $(CFLAGS) -c BubbleSort.cpp 

Test: Test.o Graph.o Algorithms.o PriorityQueue.o Queue.o Stack.o UnionFind.o BubbleSort.o
	$(CC) $(CFLAGS) -o Test Test.o Graph.o Algorithms.o PriorityQueue.o Queue.o Stack.o UnionFind.o BubbleSort.o

Test.o: Tests.cpp doctest.h Algorithms.hpp Graph.hpp UnionFind.hpp BubbleSort.hpp Queue.hpp Stack.hpp PriorityQueue.hpp
	$(CC) $(CFLAGS) -c Tests.cpp -o Test.o


test: Test
	./Test

clean:
	rm -f main.o Graph.o Algorithms.o PriorityQueue.o Queue.o Stack.o UnionFind.o BubbleSort.o Main Test *.o

valgrind: Main
	valgrind --leak-check=full --show-leak-kinds=all ./Main

.PHONY: all clean valgrind 
