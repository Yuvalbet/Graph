/*
Email: yuvali532@gmail.com
*/
#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue{

private:

    //Array for storing data
    int *arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    
    //constructor
    Queue(int capacity);
    //Destractor
    ~Queue();

    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
    bool isFull() const;

};

#endif