/*
Email: yuvali532@gmail.com
*/
#include "Queue.hpp"
#include <iostream>

//Constructor of the Queue class - initializes a queue of a given size
Queue::Queue(int capacity){
    this->capacity = capacity;
    //Allocate memory for the array that holds the data
    arr = new int[capacity];
    front = 0;
    rear = -1;
    //Number of elements in the queue
    size = 0;
}

//Destractor
Queue::~Queue(){
    delete[]arr;
}

//Function to add a value to the end of the queue
void Queue::enqueue(int value){
    //Check if the queue is full
    if (isFull()){
        std::cerr << "Queue is full!" << std::endl; //לבדוק  מה המשמעות של CERR במקום COUT
        return;
    }
    //Moving the rear in a circular motion
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    size++;
}
//Function to retrieve the value from the head of the queue and remove it
int Queue::dequeue(){
    //Check if the queue is empty
    if (isEmpty()){
        std::cerr << "Queue is empty!" <<std::endl;
        return -1;
    }
    int value = arr[front];
    //Moving the front in a circular manner
    front = (front + 1) % capacity;
    size--;
    //Return the deleted value
    return value;
}

bool Queue::isEmpty() const{
    return size == 0;
}

//Function that checks if the queue is full
bool Queue::isFull() const{
    //Returns true if the queue has reached maximum capacity
    return size == capacity;
}