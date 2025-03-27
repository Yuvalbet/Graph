#include "Queue.hpp"
#include <iostream>

Queue::Queue(int capacity){
    this->capacity = capacity;
    arr = new int[capacity];
    front = 0;
    rear = -1;
    size = 0;
}

Queue::~Queue(){
    delete[]arr;
}

void Queue::enqueue(int value){
    if (isFull()){
        std::cerr << "Queue is full!" << std::endl;
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    size++;
}

int Queue::dequeue(){
    if (isEmpty()){
        std::cerr << "Queue is empty!" <<std::endl;
        return -1;
    }
    int value = arr[front];
    front = (front + 1) % capacity;
    size--;
    return value;
}

bool Queue::isEmpty() const{
    return size == 0;
}

bool Queue::isFull() const{
    return size == capacity;
}