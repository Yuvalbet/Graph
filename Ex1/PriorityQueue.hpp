/*
Email: yuvali532@gmail.com
*/
#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

struct PQNode{
    int vertex;
    int priority;
};

class PriorityQueue{
private:
    //Array representing the minimum stack
    PQNode* heap;
    //Array that stores the positions of the vertices in the stack
    int* positions;
    //Current stack size
    int size;
    int capacity;

    void heapifyUp(int index);
    void heapifyDown(int index);


public:
    //constructor
    PriorityQueue(int capacity);
    //Destroys
    ~PriorityQueue();

    //Adding an element to the priority queue
    void push(int vertex,int priority);
    //Extract the vertex with the highest priority (lowest value)
    int pop();
    //Check if the queue is empty
    bool isEmpty() const;
};

#endif