/*
Email: yuvali532@gmail.com
*/
#ifndef STACK_HPP
#define STACK_HPP

class Stack{
private:
    //Array for storing data
    int *arr;
    int top;
    int capacity;

public:
    //constructor
    Stack(int capacity);
    //Destractor
    ~Stack();

    void push(int value);
    int pop();
    bool isEmpty() const;
};

#endif