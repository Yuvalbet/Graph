#include "PriorityQueue.hpp"
#include <iostream>

PriorityQueue::PriorityQueue(int capacity){
    this->capacity = capacity;
    heap = new PQNode[capacity];
    positions = new int[capacity];
    size = 0;
}

PriorityQueue::~PriorityQueue(){
    delete[] heap;
    delete[] positions;
}

void PriorityQueue::heapifyUp(int index){
    while (index > 0){
        int parant = (index - 1) / 2;
        if (heap[index].priority >= heap[parant].priority)
            break;
        std::swap(heap[index], heap[parant]);
        positions[heap[index].vertex] = index;
        positions[heap[parant].vertex] = parant;
        index = parant;
        
    }
    
    
}

void PriorityQueue::heapifyDown(int index){
    while (2* index+1 < size){
        int left = 2*index +1;
        int right = 2*index +2;
        int smallest = left;

        if(right < size && heap[right].priority < heap[left].priority)
        smallest = right;

        if(heap[index].priority <= heap[smallest].priority)
            break;

        std::swap(heap[index], heap[smallest]);
        positions[heap[index].vertex] = index;
        positions[heap[smallest].vertex] = smallest;
        index = smallest;
    } 
}

void PriorityQueue::push(int vertex, int priority){
    heap[size] = {vertex, priority};
    positions[vertex] = size;
    heapifyUp(size);
    size++;
}

int PriorityQueue::pop(){
    if(size == 0)
        return -1;

    int vertex = heap[0].vertex;
    heap[0] = heap[size-1];
    positions[heap[0].vertex] = 0;
    size--;
    heapifyDown(0);
    heap[size] = {};

    return vertex;
}

void PriorityQueue::decreaseKey(int vertex, int newPriority){
    if(vertex < 0 || vertex >= capacity || positions[vertex] >= size)
    return;
    int index = positions[vertex];
    heap[index].priority = newPriority;
    heapifyUp(index);
}

bool PriorityQueue::isEmpty() const{
    return size == 0;
}