/*
Email: yuvali532@gmail.com
*/
#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue{

private:

    //Array for storing data
    int *arr;
    //Maximum queue size
    int capacity;
    //Starting index of the queue
    int front;
    //End index of the queue
    int rear;
    //Number of elements in the queue
    int size;

public:
    
    //constructor
    Queue(int capacity);
    //Destroys
    ~Queue();

    //Add to queue
    void enqueue(int value);
    //Remove from queue
    int dequeue();
    //Check if the queue is empty
    bool isEmpty() const;
    //Check if the queue is full
    bool isFull() const;

};

#endif