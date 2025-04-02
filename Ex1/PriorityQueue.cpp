/*
Email: yuvali532@gmail.com
*/
#include "PriorityQueue.hpp"
#include <iostream>

//Constructor of the priority queue class - Initialize the stack with a certain capacity and allocate memory for internal structures
PriorityQueue::PriorityQueue(int capacity){
    this->capacity = capacity;
    //array-based minimum stack
    heap = new PQNode[capacity];
    //Array for storing node locations on the stack
    positions = new int[capacity];
    size = 0;

    //Throw an error if memory allocation fails
    if(!heap || !positions){
        std::cout << "Error: Memory allocation failed in PriorityQueue .\n";
        delete[] heap;
        delete[] positions;
        heap = nullptr;
        positions = nullptr;
    }
        
}
    

//Destructor that releases the dynamic memory
PriorityQueue::~PriorityQueue(){
    delete[] heap;
    delete[] positions;
}

//Push an element up the stack until its position is correct according to minimum priority
void PriorityQueue::heapifyUp(int index){
    while (index > 0){
        int parant = (index - 1) / 2;
        if (heap[index].priority >= heap[parant].priority)
            break;
        
        //Swap between node and parent
        std::swap(heap[index], heap[parant]);
        positions[heap[index].vertex] = index;
        positions[heap[parant].vertex] = parant;
        index = parant;
        
    }
    
}

//Removing an element from the stack until its position is correct according to priority
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

//Adding a node to the priority queue
void PriorityQueue::push(int vertex, int priority){
    if(size >= capacity){
        //Throwing an error because the capacity is already full and no more members can be added
        std::cout << "Error: PriorityQueue is full.\n";
        return;
    }
        
    heap[size] = {vertex, priority};
    positions[vertex] = size;
    heapifyUp(size);
    size++;
}

//Removing the node with the highest priority (smallest value)
int PriorityQueue::pop(){
    if(size == 0)
        return -1;

    int vertex = heap[0].vertex;
    size--;  // Reduce the size first

    if (size > 0) {  // Ensure there is still an element before accessing heap[0]
        heap[0] = heap[size];  // Move the last element to the root
        positions[heap[0].vertex] = 0;
        heapifyDown(0);
    }
    
    return vertex;
}

//Check if the queue is empty
bool PriorityQueue::isEmpty() const{
    return size == 0;
}