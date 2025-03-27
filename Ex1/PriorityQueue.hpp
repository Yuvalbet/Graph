#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

struct PQNode{
    int vertex;
    int priority;
};

class PriorityQueue{
private:
    PQNode* heap;
    int* positions;
    int size;
    int capacity;

    void heapifyUp(int index);
    void heapifyDown(int index);


public:
    PriorityQueue(int capacity);
    ~PriorityQueue();

    void push(int vertex,int priority);
    int pop();
    void decreaseKey(int vertex, int newPriority);
    bool isEmpty() const;
};

#endif
